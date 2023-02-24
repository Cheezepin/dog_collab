#define oColFlags OBJECT_FIELD_S16(0x1B, 0)
void bhv_2639FinalPresent_init(void) {
	o->oColFlags = 0;
}
void bhv_2639FinalPresent_loop(void) {
    // o->oColFlags = object_step();
	switch(o->oHeldState) {
        case HELD_FREE:
            break;

        case HELD_HELD:
            cur_obj_unrender_set_action_and_anim(-1, 0);
            obj_copy_pos(o, gMarioObject);
            break;

        case HELD_THROWN:
        case HELD_DROPPED:
            cur_obj_get_dropped();
            break;
    }
    cur_obj_move_standard(78);
}
