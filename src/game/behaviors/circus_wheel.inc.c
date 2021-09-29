void bhv_circus_wheel_init(void) {
    struct Object *platform;
    s32 i;

    //o->collisionData = segmented_to_virtual(sFerrisWheelProperties[o->oBehParams2ndByte].axleCollision);

    for (i = 0; i < 12; i++) {
        platform = spawn_object_relative(i, 0, 0, 0, o,
                                         MODEL_CABLE_CAR,
                                         bhvCircusWheelPlatform);

        if (platform != NULL) {
            //platform->collisionData =
                //segmented_to_virtual(sFerrisWheelProperties[o->oBehParams2ndByte].platformCollision);
        }
    }
}

void bhv_circus_wheel_loop(void) {
    
}

void bhv_circus_wheel_platform_update(void) {
    f32 offsetXZ;
    s16 offsetAngle;

    //obj_perform_position_op(POS_OP_SAVE_POSITION);

    offsetAngle = o->parentObj->oFaceAngleRoll + o->oBehParams2ndByte * 0x1555;
    offsetXZ = 2400.0f * coss(offsetAngle);

    o->oPosX = o->parentObj->oPosX + offsetXZ * sins(o->parentObj->oMoveAngleYaw)
               + 300.0f * coss(o->parentObj->oMoveAngleYaw);

    o->oPosY = o->parentObj->oPosY + 2400.0f * sins(offsetAngle) - 300.0f;

    o->oPosZ = o->parentObj->oPosZ + offsetXZ * coss(o->parentObj->oMoveAngleYaw)
               + 300.0f * sins(o->parentObj->oMoveAngleYaw);

    //obj_perform_position_op(POS_OP_COMPUTE_VELOCITY);

    if (gMarioState->action != ACT_SHOCKED) {
        load_object_collision_model();
    }
}

void bhv_wheel_wind_loop(void) {
    cur_obj_play_sound_1(SOUND_AIR_BLOW_WIND);
    cur_obj_spawn_strong_wind_particles(12, 3.0f, 0.0f, -50.0f, 120.0f);
}