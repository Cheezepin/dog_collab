
void bhv_2639glasses_init(void) {
	
}
void bhv_2639glasses_loop(void) {
	if (o->oDistanceToMario <= 50) {
		_2639_BoB_A1_SunglassesCollected = 1;
		mark_obj_for_deletion(o);
	}
}
