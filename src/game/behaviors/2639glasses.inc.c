
void bhv_2639glasses_init(void) {
	
}
void bhv_2639glasses_loop(void) {
	struct Object *doge = cur_obj_nearest_object_with_behavior(bhvDoginlobby);

	if (doge == NULL) return;
	if (o->oDistanceToMario <= 100) {
		if (gMarioState->action == ACT_GROUND_POUND_LAND

			&& doge->oAction == 8) { // only gp if doggo
			_2639_BoB_A1_SunglassesCollected = 1;
			MakeCoinWithModel(o, 1, MODEL_SUNGLASSES2639);
			mark_obj_for_deletion(o);
		}
	}
}
