
void bhv_2639FinalPresent_init(void) {
}
void bhv_2639FinalPresent_loop(void) {
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
