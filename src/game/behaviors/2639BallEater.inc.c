
void bhv_2639BallEater_init(void) {
	o->oAction = 0;
}
void bhv_2639BallEater_loop(void) {
	float throwaawy;
	struct Object *obj = cNearestObj_Bhv(bhv2639SoccerBall, &throwaawy);

	if (obj) {
		if (dist_between_objects(o, obj) < 400) {
			makeSecret();
			mark_obj_for_deletion(obj);
		}
	}
}
