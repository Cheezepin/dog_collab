/**
 * Update function for Koko triplet spawner.
 */
void bhv_koko_triplet_spawner_update(void) {
    s16 goombaFlag;
    s32 angle;

    // If mario is close enough and the Kokos aren't currently loaded, then
    // spawn them
    if (o->oAction == GALOOMBA_TRIPLET_SPAWNER_ACT_UNLOAD) {
        if (o->oDistanceToMario < 3000.0f) {
            // The spawner is capable of spawning more than 3 Kokos, but this
            // is not used in the game
            s32 dAngle =
                0x10000
                / (((o->oBehParams2ndByte & GOOMBA_TRIPLET_SPAWNER_BP_EXTRA_GOOMBAS_MASK) >> 2) + 3);

            for (angle = 0, goombaFlag = 1 << 8; angle < 0xFFFF; angle += dAngle, goombaFlag <<= 1) {
                // Only spawn goombas which haven't been killed yet
                if (!(o->oBehParams & goombaFlag)) {
                    s16 dx = 500.0f * coss(angle);
                    s16 dz = 500.0f * sins(angle);
                    spawn_object_relative((o->oBehParams2ndByte & GOOMBA_TRIPLET_SPAWNER_BP_SIZE_MASK) | (goombaFlag >> 6),
                                          dx, 0, dz, o, MODEL_KOKO, bhvGaloomba);
                }
            }

            o->oAction = 1;
        }
    } else if (o->oDistanceToMario > 4000.0f) {
        // If mario is too far away, enter the unloaded action. The Kokos
        // will detect this and unload themselves
        o->oAction = GALOOMBA_TRIPLET_SPAWNER_ACT_UNLOAD;
    }
}