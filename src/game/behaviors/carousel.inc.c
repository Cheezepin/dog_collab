void bhv_carousel_init(void) {
    if (o->oBehParams2ndByte != 1) {
        cur_obj_init_animation(0);
    }
}

void bhv_carousel_loop(void) {
    if (o->oBehParams2ndByte != 1) {
    o->oFaceAngleYaw -= 0x200;
    o->oMoveAngleYaw -= 0x200;
    }
    
}

Gfx *geo_carousel_billboard(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        ((struct GraphNodeTranslationRotation *) node->next)->rotation[1] = gLakituState.yaw;
    }
    return 0;
}