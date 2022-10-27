/**
 * @brief      yoooooo
 *
 * @param[in]  a     an integer
 * @param[in]  b     an outeger
 */
#define StartedScene OBJECT_FIELD_S32(0x1B)
void bhv_2639PresentEater_init() {
	o->StartedScene = 0;
}
void bhv_2639PresentEater_loop(void) {
	float throwaawy;
	struct Object *obj = cNearestObj_Bhv(bhv2639FinalPresent, &throwaawy);

	if (obj) {
		if (throwaawy < 800.0f && obj->oHeldState == HELD_FREE && o->StartedScene == 0) {
			gCamera->cutscene = CUTSCENE_2639FINALCUTSCENE;
			o->StartedScene = 1;
			// mark_obj_for_deletion(obj);
		}
	}
	// char dbg[50];
	// sprintf(dbg, "FF %f", throwaawy);
	// print_text_fmt_int(50, 50, dbg);
}
