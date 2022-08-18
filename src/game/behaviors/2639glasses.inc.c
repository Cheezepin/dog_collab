
void bhv_2639glasses_init(void) {
	
}
void bhv_2639glasses_loop(void) {
	if (o->oDistanceToMario <= 50) {
		if (gMarioState->action == ACT_GROUND_POUND_LAND) {
			_2639_BoB_A1_SunglassesCollected = 1;
			MakeCoinWithModel(o, 1, MODEL_SUNGLASSES2639);
			mark_obj_for_deletion(o);
		}
	}
}
