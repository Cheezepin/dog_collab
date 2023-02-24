/**
 * @brief      yoooooo
 *
 * @param[in]  a     an integer
 * @param[in]  b     an outeger
 */
#define StartedScene OBJECT_FIELD_S32(0x1B)
#define FixedMario OBJECT_FIELD_S32(0x1C)
void bhv_2639PresentEater_init() {
	o->StartedScene = 0;
	o->FixedMario = 0;
}
#define oColFlags OBJECT_FIELD_S16(0x1B, 0)
void bhv_2639PresentEater_loop(void) {
	float superdist;
	struct Object *obj = cNearestObj_Bhv(bhv2639FinalPresent, &superdist);


	if (obj && o->StartedScene == 0) {
		if (superdist < 800.0f && obj->oHeldState == HELD_FREE) {
			gCamera->cutscene = CUTSCENE_2639FINALCUTSCENE;
			o->StartedScene = 1;
			vec3f_copy(&obj->oPosX, &o->oPosX);
			mark_obj_for_deletion(o);
		}
	}
	// char dbg[50];
	// sprintf(dbg, "FF %d %d", o->StartedScene, gCamera->cutscene);
	// print_text_fmt_int(50, 50, dbg);

	if (o->FixedMario == 0) {
		if (gCamera->cutscene == 0 && o->StartedScene == 1) {
			o->FixedMario = 1;
			gMarioState->action = ACT_IDLE;
		}
	}
}
