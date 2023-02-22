

static struct ObjectHitbox sSoccerBallHitbox = {
    .interactType =        INTERACT_COIN,
    .downOffset =          0,
    .damageOrCoinValue =   0,
    .health =              0,
    .numLootCoins =        0,
    .radius =              140,
    .height =              100,
    .hurtboxRadius =       140,
    .hurtboxHeight =       100,
};

#define SBALL_DIAMETER 160.0f
#define SBALL_RADIUS (SBALL_DIAMETER / 2.0f)
#define SBALL_GRAV -4.0f
#define SBALL_TERMINAL_VEL -50.0f
#define SBALL_BOTTOM(b) (b->oPosY - SBALL_RADIUS)

static const s16 sCourtBoundsX[] = { -1702 + SBALL_RADIUS, 2821 - SBALL_RADIUS };
static const s16 sCourtBoundsZ[] = { -4000 + SBALL_RADIUS, 3426 - SBALL_RADIUS };
static const s16 sCourtMaxY = 430;

void reflect_vec3f(Vec3f res, Vec3f d, Vec3f n, f32 bounciness, f32 friction) {
	f32 dp2 = 2.0f * vec3f_dot(d, n);
	Vec3f funkyResult;
	vec3f_copy(funkyResult, n);
	vec3_mul_val(funkyResult, dp2);
	vec3f_diff(res, d, funkyResult);
	res[1] *= bounciness;
	res[0] *= friction;
	res[2] *= friction;
}

s16 calculate_rotation(f32 xz_velocity) {
    f32 scaling_factor = (f32)(180.0 / (3.14159 * (f64)SBALL_RADIUS)); // scaling factor based on ball radius
    f32 rotation_amount = xz_velocity * scaling_factor;
    s16 rotation = (s16)(rotation_amount * 182.04f);
    return rotation;
}

void soccerball_surface_collisions(struct Object *ball) {
	Vec3f velocityDir;
	vec3f_copy(velocityDir, &ball->oVelX);

	if (ball->oSoccerBallGrounded && ball->oVelY > 0.01f) {
		ball->oSoccerBallGrounded = FALSE;
	}
	
	// check if barely moving
	f32 vel_sq = vec3_sumsq(velocityDir);
	f32 vel = 0;
	if (vel_sq > 0.01f) {
		vel = sqrtf(vel_sq);
		vec3f_normalize(velocityDir);

		Vec3f velDirPlusVel;
		vec3f_copy(velDirPlusVel, velocityDir);
		vec3_mul_val(velDirPlusVel, SBALL_RADIUS);
		vec3f_add(velDirPlusVel, &ball->oVelX);

		struct Surface *surf;
		Vec3f hitPos;
		find_surface_on_ray(&ball->oPosX, velDirPlusVel, &surf, hitPos, (RAYCAST_FIND_FLOOR | RAYCAST_FIND_WALL | RAYCAST_FIND_CEIL));
		if (surf) {
			Vec3f surfNormal = {surf->normal.x, surf->normal.y, surf->normal.z};
			f32 absorbtion = 0.8f;
			if (surf->normal.y > COS15 && ball->oVelY < 6.1f) absorbtion = 0.4f;
			reflect_vec3f(&ball->oVelX, velocityDir, surfNormal, absorbtion * vel, 0.85f * vel);

			if (surf->normal.y > COS15 && absf(ball->oVelY) < 8.1f) {
				ball->oSoccerBallGrounded = TRUE;
				ball->oVelY = 0;
			}
		}
	}

	// prepare next step
	Vec3f nextPos;
	vec3f_sum(nextPos, &ball->oPosX, &ball->oVelX);

	struct Surface *pfloor = NULL;
	f32 floorHeight = find_floor(nextPos[0], nextPos[1] + SBALL_RADIUS + 30, nextPos[2], &pfloor);

	if (SBALL_BOTTOM(ball) < floorHeight) {
		nextPos[1] = floorHeight + SBALL_RADIUS + 0.1f;
		Vec3f surfNormal = {pfloor->normal.x, pfloor->normal.y, pfloor->normal.z};
		if (vel > 0.01f) {
			f32 absorbtion = 0.8f;
			if (ball->oVelY < 6.1f) absorbtion = 0.4f;

			reflect_vec3f(&ball->oVelX, velocityDir, surfNormal, absorbtion * vel, 0.85f * vel);
			ball->header.gfx.scale[1] = get_relative_position_between_ranges(vel, 0, -(SBALL_TERMINAL_VEL), 1.0f, 0.8f);

			if (pfloor->normal.y > COS15 && absf(ball->oVelY) < 8.1f) {
				ball->oSoccerBallGrounded = TRUE;
				ball->oVelY = 0;
			}
		} else {
			ball->oSoccerBallGrounded = TRUE;
			nextPos[1] = floorHeight + SBALL_RADIUS;
		}
	} else if (!ball->oSoccerBallGrounded) {
		ball->oVelY += SBALL_GRAV;
		if (ball->oVelY < SBALL_TERMINAL_VEL) ball->oVelY = SBALL_TERMINAL_VEL;
	} else if (ball->oSoccerBallGrounded) {
		ball->oVelX *= 0.98f;
		ball->oVelZ *= 0.98f;
		if (absf(ball->oVelX) + absf(ball->oVelZ) < 2.0f) ball->oVelZ = ball->oVelX = 0;
	}

	// set next step
	vec3f_copy(&ball->oPosX, nextPos);
	// extra bounds checks: dont affect vel
	if (     ball->oPosX < sCourtBoundsX[0]) ball->oPosX = sCourtBoundsX[0];
	else if (ball->oPosX > sCourtBoundsX[1]) ball->oPosX = sCourtBoundsX[1];

	if (ball->oPosZ < sCourtBoundsZ[0] && ball->oPosY > sCourtMaxY) {
		ball->oPosZ = sCourtBoundsZ[0];
		Vec3f bNorm = { 0, 0, 1 };
		reflect_vec3f(&ball->oVelX, velocityDir, bNorm, 0.8f * vel, 0.85f * vel);
	}
	else if (ball->oPosZ > sCourtBoundsZ[1]) ball->oPosZ = sCourtBoundsZ[1];

	// rotate based on velocity
	if (vel > 0.1f) {
		f32 xzVel = sqrtf(sqr(o->oVelZ) + sqr(o->oVelX));
		if (xzVel > 0.1f) {
			ball->oAngleVelPitch = calculate_rotation(xzVel);
			ball->oFaceAngleYaw = approach_s16_asymptotic(ball->oFaceAngleYaw, atan2s(o->oVelZ, o->oVelX), 4);
		} else {
			ball->oAngleVelPitch = 0;
		}
		ball->oFaceAnglePitch += ball->oAngleVelPitch;
	}
}

//! function may or may not have been written by a robot
void resolve_ball_v_ball(struct Object* ball1, struct Object* ball2) {
    Vec3f v_rel = {
		(ball2->oVelX - ball1->oVelX),
		(ball2->oVelY - ball1->oVelY),
		(ball2->oVelZ - ball1->oVelZ)
	};  // relative velocity before collision

    ball1->oVelX = (ball1->oVelX + v_rel[0]);  // update velocity of ball 1
    ball1->oVelY = (ball1->oVelY + v_rel[1]);
    ball1->oVelZ = (ball1->oVelZ + v_rel[2]);
    ball2->oVelX = (ball2->oVelX - v_rel[0]);  // update velocity of ball 2
    ball2->oVelY = (ball2->oVelY - v_rel[1]);
    ball2->oVelZ = (ball2->oVelZ - v_rel[2]);
}

void soccerball_update_physics(struct Object *ball, struct MarioState *m) {
	f32 goalScale = 1.0f;
	s32 slideKicking = m->action == ACT_SLIDE_KICK;
	s32 canKick = m->action == ACT_WALKING;

	// mario v ball
	f32 distSq;
	Vec3f marioCenter = { m->pos[0], m->pos[1] + 80.0f, m->pos[2] };
	if (slideKicking) marioCenter[1] -= 40.0f;

	vec3f_get_dist_squared(&o->oPosX, marioCenter, &distSq);
	if (ball->oSoccerBallTimeout <= 0 && distSq < sqr(SBALL_RADIUS + 60)) {
		Vec3f vel = {0,0,0};
		Vec3f marioToBallDir;
		vec3f_diff(marioToBallDir, &ball->oPosX, m->pos);
		vec3f_normalize(marioToBallDir);

		f32 speed = m->moveSpeed;

		if (speed > 0.01f) {
			vec3f_diff(vel, gMarioState->pos, gMarioState->prevPos);
			if (slideKicking) speed *= 2.0f;
			else if (canKick) {
				speed *= 1.5f;
				set_mario_action(m, ACT_JUMP_KICK, 0);
				vel[1] += m->vel[1] * 0.75f;
				m->pos[1] += m->vel[1];
			}
	
			vec3f_normalize(vel);
			speed = speed * get_relative_position_between_ranges(m->moveSpeed, 0, 50, 2.5f, 2.0f);
			if (speed > 120) speed = 120;
		} else {
			Vec3f velDir;
			vec3f_copy(velDir, &ball->oVelX);
			f32 ballVel = vec3_sumsq(velDir);
			if (ballVel > 0.1f) {
				vec3f_normalize(velDir);
				reflect_vec3f(vel, velDir, marioToBallDir, 1.0f, 1.0f);
				speed = sqrtf(ballVel);
			}
		}

		ball->oVelX += vel[0] * speed;
		ball->oVelZ += vel[2] * speed;

		f32 yAdditive = slideKicking ? 30.0f : 10.0f;
		ball->oVelY += (vel[1] * speed) + yAdditive;
		if (slideKicking || canKick) ball->oVelY = MAX(yAdditive, ball->oVelY);

		ball->oPosY += 20.0f + ball->oVelY;

		f32 displacement = (SBALL_RADIUS + 60) - sqrtf(distSq);
		vec3_mul_val(marioToBallDir, -displacement);
		vec3f_add(m->pos, marioToBallDir);

		if (speed > 40) {
			freeze_game_frames(lroundf(lerp(0.6f, 3.0f, speed / 120.0f)));
		} else if (canKick || slideKicking) {
			cur_obj_play_sound_2(SOUND_GENERAL_SHORT_POUND6);
		}
		s32 strength = lroundf(get_relative_position_between_ranges(speed, 0, 120.0f, 0, 5));
		cur_obj_play_sound_2(SOUND_GENERAL_SHORT_POUND1 + (strength << 16));
		ball->oSoccerBallTimeout = 5;
	}

	// ball v ball
	f32 otherBallDist;
	struct Object *otherBall = cur_obj_find_nearest_object_with_behavior(bhv2639SoccerBall, &otherBallDist);
	if (otherBall && otherBallDist < SBALL_RADIUS*2) {
		resolve_ball_v_ball(ball, otherBall); // bounce balls off of each other (pool physics)
		
		// move balls away from each other so they arent touching,
		// but use velocity so theres some natural springiness
		f32 resDist = (((SBALL_RADIUS*2) - otherBallDist) / 2.0f) + 2.0f;
		Vec3f p_rel;
		vec3f_diff(p_rel, &ball->oPosX, &otherBall->oPosX);
		vec3f_normalize(p_rel);
		ball->oVelX += p_rel[0] * resDist;
		ball->oVelY += p_rel[1] * resDist;
		ball->oVelZ += p_rel[2] * resDist;
		resDist *= -1;
		otherBall->oVelX += p_rel[0] * resDist;
		otherBall->oVelY += p_rel[1] * resDist;
		otherBall->oVelZ += p_rel[2] * resDist;
	}

	soccerball_surface_collisions(ball);

	goalScale = get_relative_position_between_ranges(absf(ball->oVelY), 0, -(SBALL_TERMINAL_VEL), 1, 1.2f);

	ball->header.gfx.scale[1] = approach_f32_symmetric(ball->header.gfx.scale[1], goalScale, 0.2f);
	ball->header.gfx.scale[0] = ball->header.gfx.scale[2] = 1.0f + (1.0f - ball->header.gfx.scale[1]);
}


void bhv_2639SoccerBall_init(void) {
	o->oAction = 0;
	o->oWallHitboxRadius = 140.0f;
	o->oVelY = 100;
	o->oPosY += 200;
	o->oFaceAngleYaw = random_u16();
	o->oFaceAnglePitch = random_u16();
}
void bhv_2639SoccerBall_loop(void) {
	if (o->oSoccerBallTimeout > 0) {
		o->oSoccerBallTimeout--;
	}
	soccerball_update_physics(o, gMarioState);

	// goal
	if (o->oAction == 1){ 
		create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
		obj_explode_and_spawn_coins(46.0f, 0);
	}
	// dog hit ball
	if (o->oAction == 3) {
		f32 overallStrength = lerp(0.5f, 1.0f, random_float());
		o->oVelX = overallStrength * ((random_float() - 0.5f) * 40.0f);
		o->oVelY = overallStrength * ((random_float() * 20.0f) + 70.0f);
		o->oVelZ = overallStrength * ((random_float() * 20.0f) + 70.0f);
		o->oAction = 0;
		cur_obj_play_sound_2(SOUND_GENERAL_SHORT_POUND4);
	}
}
