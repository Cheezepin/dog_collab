void bhv_2639cane_init(void) {
	
}
void bhv_2639cane_loop(void) {
	if (o->oDistanceToMario <= 50) {
		_2639_BoB_A1_CaneCollected = 1;
		mark_obj_for_deletion(o);
	}
}
