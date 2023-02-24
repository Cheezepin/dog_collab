void bhv_2639cane_init(void) {
	
}
void bhv_2639cane_loop(void) {
	struct Object *doge = cur_obj_nearest_object_with_behavior(bhvDoginlobby);

	if (doge == NULL) return;

	if (o->oDistanceToMario <= 100) {
		if (gMarioState->action == ACT_GROUND_POUND_LAND

		&& doge->oAction == 4) { // only gp if doggo
			_2639_BoB_A1_CaneCollected = 1;
			MakeCoinWithModel(o, 1, MODEL_CANE2639);
			mark_obj_for_deletion(o);
		}
	}
}
