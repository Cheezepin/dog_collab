#include "thecozies_helpers.inc.c"

void geo_shyguy_scuba_tank_update(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    Gfx *dlStart, *dlHead;
    struct Object *objectGraphNode;
    struct GraphNodeGenerated *currentGraphNode;
    s32 objectOpacity;

    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER) {
        objectGraphNode = (struct Object *) gCurGraphNodeObject;
        currentGraphNode = (struct GraphNodeGenerated *) node;

        objectOpacity = objectGraphNode->oOpacity;
        COND_BIT(objectOpacity > 0, ((struct GraphNodeDisplayList *) node->next)->node.flags, GRAPH_RENDER_ACTIVE);

        if (objectOpacity == 0) {
            return NULL;
        }

        dlStart = alloc_display_list(sizeof(Gfx) * 3);

        dlHead = dlStart;

        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_TRANSPARENT);

        gDPSetEnvColor(dlHead++, 255, 255, 255, objectOpacity);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}
