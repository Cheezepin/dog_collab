
#define elevLocked OBJECT_FIELD_S32(0x1D)

void bhv_2639ElevatorKey_init(void) {
	
}
void bhv_2639ElevatorKey_loop(void) {
	f32 dist;
	struct Object *p = cNearestObj_Bhv(bhv2639elevator, &dist);
	if (o->oDistanceToMario < 100.0f) {
		p->elevLocked = 0;
		mark_obj_for_deletion(o);
		play_sound(SOUND_GENERAL_DOOR_TURN_KEY, gGlobalSoundSource);
	}
}
