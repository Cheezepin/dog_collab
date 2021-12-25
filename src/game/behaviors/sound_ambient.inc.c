// sound_ambient.inc.c

void bhv_ambient_sounds_init(void) {
    if (gCamera->mode == CAMERA_MODE_BEHIND_MARIO)
        return;

    play_sound(SOUND_AIR_CASTLE_OUTDOORS_AMBIENT, gGlobalSoundSource);
}

void bhv_wind_sound_loop(void) {
    if (gCamera->mode == CAMERA_MODE_BEHIND_MARIO)
        return;
    if (gMarioState->pos[1] > -7250.0f)
        return;

    cur_obj_play_sound_1(SOUND_AIR_HOWLING_WIND);
}
