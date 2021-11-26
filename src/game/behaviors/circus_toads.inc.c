void bhv_kid_toad_init(void) {
    switch (o->oBehParams2ndByte) {
        case 0:
        case 1:
         cur_obj_init_animation(0);
        break;
        case 2:
        cur_obj_init_animation(2);
        break;
        case 3:
        case 4:
        cur_obj_init_animation(1);
        break;
    }
}

void bhv_clown_toad_loop(void) {
    if (o->oBehParams2ndByte == 0x6E && o->oTalkedToMario == 0) {
        o->oTalkedToMario = 1;
        o->oAction = BOBOMB_BUDDY_ACT_TURN_TO_TALK;
    }
}

Gfx *geo_switch_kid_toad_holding(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        struct Object *obj = (struct Object *) gCurGraphNodeObject;
        struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node;
        switchCase->selectedCase = 0;

        // timer logic for blinking. uses cases 0-2.
        s32 timer = gGlobalTimer % 50;
        switch (obj->oBehParams2ndByte) {
            case 0:
            switchCase->selectedCase = 0;
            break;
            case 1:
            case 4:
            switchCase->selectedCase = 1;
            break;
            case 2:
            switchCase->selectedCase = 2;
            break;
            default:
            switchCase->selectedCase = 0;
            break;
        
        }
        
        
    }
    return NULL;
}
