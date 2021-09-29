void bhv_carousel_init(void) {

}

void bhv_carousel_loop(void) {
    o->oFaceAngleYaw -= 0x200;
    o->oMoveAngleYaw -= 0x200;
}

Gfx *geo_carousel_billboard(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    if (callContext == GEO_CONTEXT_RENDER) {
        ((struct GraphNodeTranslationRotation *) node->next)->rotation[1] = gLakituState.yaw;
    }
    return 0;
}