void bhv_2639cane_init(void) {
	
}
void bhv_2639cane_loop(void) {
	if (o->oDistanceToMario <= 100) {
		if (gMarioState->action == ACT_GROUND_POUND_LAND) {
			_2639_BoB_A1_CaneCollected = 1;
			MakeCoinWithModel(o, 1, MODEL_CANE2639);
			mark_obj_for_deletion(o);
		}
	}
}
