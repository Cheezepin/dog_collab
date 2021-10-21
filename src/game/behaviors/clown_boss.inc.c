void bhv_clown_boss_init(void) {

}

void bhv_clown_boss_loop(void) {

}

Gfx *geo_clown_head_scaler(s32 callContext, struct GraphNode *node, UNUSED Mat4 *mtx) {
    struct GraphNodeGenerated *asGenerated = (struct GraphNodeGenerated *) node;
    struct GraphNodeScaleBetter *scaleNode = (struct GraphNodeScaleBetter *) node->next;

    if (callContext == GEO_CONTEXT_RENDER) {
        scaleNode->scaleX = 1.0f;
        scaleNode->scaleY += 0.1f;
        scaleNode->scaleZ = 1.0f;
        
    }
    return NULL;
}