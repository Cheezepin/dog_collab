
void bhv_2639SoccerBall_init(void) {
	o->oAction = 0;
}
void bhv_2639SoccerBall_loop(void) {
	if (o->oBehParams2ndByte == 1) {
		cur_obj_scale(0.5f);
	}
	// vec3f_set(&o->oPosX, o-)
	o->oPosY = o->oHomeY;
	// cur_obj_move_using_fvel_and_gravity();
	// object_step();
	cur_obj_update_floor_and_walls();
	cur_obj_resolve_wall_collisions();

	// cur_obj_move_standard(78);
	if (o->oDistanceToMario < 160.f){
		o->oForwardVel = gMarioState->forwardVel * 4;
		o->oMoveAngleYaw = gMarioObject->header.gfx.angle[1];
		o->oFaceAngleYaw = gMarioObject->header.gfx.angle[1];
		// if (o->oBehParams2ndByte == 1) {
		// 	o->oVelY = 30.f;
		// }
	}
	o->oForwardVel-=5.f;
	// o->oVelY -= 5.f;
	if (o->oForwardVel < 0.f)
		o->oForwardVel = 0;
	else
		o->oFaceAnglePitch += 50;

	// if (o->oVelY <= 0.f)
	// 	o->oVelY = 0.f;

	if (o->oPosY < o->oFloorHeight)
		o->oPosY = o->oFloorHeight;

	if (o->oAction == 1){ 
		obj_explode_and_spawn_coins(46.0f, 0);
	}
	if (o->oAction == 3) {
		o->oMoveAngleYaw = 0;
		o->oFaceAngleYaw = 0;
		o->oForwardVel = 100.0f;
		o->oAction = 0;
	}
	// char dbg[50];
	// sprintf(dbg, "D %f", o->oDistanceToMario);
	// print_text(50, 50, dbg);
}
