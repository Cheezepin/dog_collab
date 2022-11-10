
void bhv_2639A2HiddenStar_init(void) {
    s16 remainingTriggers;
    struct Object *starObj;

    // remainingTriggers = count_objects_with_behavior(bhvHiddenStarTrigger);
    // if (remainingTriggers == 0) {
    //     starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0);
    //     starObj->oBehParams = o->oBehParams;
    //     o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    // }

    o->oHiddenStarTriggerCounter = 0;
}
void spawn_cutscene_star_get_outta_here(u32 bp, f32 x, f32 y, f32 z);
void bhv_2639A2HiddenStar_loop(void) {
    switch (o->oAction) {
        case 0:
            if (o->oHiddenStarTriggerCounter == 5)
                o->oAction = 1;
            break;

        case 1:
            if (o->oTimer > 2) {
                spawn_cutscene_star_get_outta_here(
                    STAR_BP_ACT_2,
                    o->oPosX,
                    o->oPosY,
                    o->oPosZ
                );
                spawn_mist_particles();
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            }
            break;
    }
}
