
void bhv_2639BallEater_init(void) {
	o->oAction = 0;
}

// struct abBox {

// }

int ab_boxCheck(struct Object *a) {
	if (a->oPosZ < -4000) {
		if (a->oPosX < 1300 && a->oPosX > -100) {
			return 1;
		}
	}

	return 0;
}

void bhv_2639BallEater_loop(void) {
	float throwaawy;
	struct Object *obj = cNearestObj_Bhv(bhv2639SoccerBall, &throwaawy);

	if (obj) {
		if (ab_boxCheck(obj)) {
			makeSecret();
			mark_obj_for_deletion(obj);
		}
	}
}
