void bhv_cephie_init(void) {
    u8 anim = 0;
    if (o->oBehParams2ndByte == 1 || o->oBehParams2ndByte == 2) {
        anim = 1;
    }
    cur_obj_init_animation(anim);
    o->oGravity = 2.5;
    o->oFriction = 0.8;
    o->oBuoyancy = 1.3;
    o->oInteractionSubtype = INT_SUBTYPE_NPC;
}

void cephie_act_idle(void) {
    o->oCephieStartYaw = o->oMoveAngleYaw;

    if (o->oInteractStatus == INT_STATUS_INTERACTED) {
        o->oAction = CEPHIE_ACT_TURN_TO_TALK;
        cur_obj_play_sound_2(SOUND_ACTION_READ_SIGN);
    }
}

void cephie_act_talk(void) {
    if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_FRONT) == MARIO_DIALOG_STATUS_SPEAK) {
        o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;

        if (cutscene_object_with_dialog(CUTSCENE_DIALOG, o, o->oBehParams2ndByte) != DIALOG_RESPONSE_NONE) {
            set_mario_npc_dialog(MARIO_DIALOG_STOP);

            o->activeFlags &= ~ACTIVE_FLAG_INITIATED_TIME_STOP;
            o->oCephieTalked = TRUE;
            o->oInteractStatus = 0;
            o->oAction = CEPHIE_ACT_TURN_FROM_TALK;
        }
    }
}

void cephie_act_turn_to_talk(void) {
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0xC00);
    if ((s16) o->oMoveAngleYaw == (s16) o->oAngleToMario) {
        o->oAction = CEPHIE_ACT_TALK;
    }
}

void cephie_act_turn_from_talk(void) {
    o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oCephieStartYaw, 0xC00);
    if ((s16) o->oMoveAngleYaw == (s16) o->oCephieStartYaw) {
        o->oAction = CEPHIE_ACT_IDLE;
    }
}

void cephie_actions(void) {
    switch (o->oAction) {
        case CEPHIE_ACT_IDLE:
            cephie_act_idle();
            break;

        case CEPHIE_ACT_TURN_TO_TALK:
            cephie_act_turn_to_talk();
            break;

        case CEPHIE_ACT_TALK:
            cephie_act_talk();
            break;

        case CEPHIE_ACT_TURN_FROM_TALK:
            cephie_act_turn_from_talk();
            break;
    }

    set_object_visibility(o, 3000);
}

void bhv_cephie_loop(void) {
    cephie_actions();

    o->oInteractStatus = 0;
}

Gfx *geo_switch_cephie_hold(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;

        if (obj->oBehParams2ndByte == 1 || obj->oBehParams2ndByte == 2) {
            switchCase->selectedCase = 1; // Uno cards
        }
        else {
            switchCase->selectedCase = 0;
        }
    }
    return NULL;
}