#include "thecozies_helpers.h"

Gfx *geo_reflect_light_panel(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx) {
    struct GraphNodeGenerated *currentGraphNode;
    Gfx *dlStart, *dlHead;
    dlStart = NULL;

    if (callContext == GEO_CONTEXT_RENDER && gReadyForLookAt) {
        currentGraphNode = (struct GraphNodeGenerated *) node;
        // if (currentGraphNode->parameter == 69) SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_TRANSPARENT_DECAL);
        // else if (currentGraphNode->parameter != 0) SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, currentGraphNode->parameter);
        SET_GRAPH_NODE_LAYER(currentGraphNode->fnNode.node.flags, LAYER_TRANSPARENT_DECAL);

        dlStart = alloc_display_list(sizeof(Gfx) * 3);
        dlHead = dlStart;

        Vec3f lightDir = { 0, 0, -1 };
        f32 lookDirX = 0;
        f32 lookDirY = 0;
        f32 lookDirZ = 1.0f;
        f32 up = -1.0f;
        if (currentGraphNode->parameter != 69) {
            // lookDirX = lightDir[0] * mtx[0][0] + lightDir[1] * mtx[1][0] + lightDir[2] * mtx[2][0];
            // lookDirY = lightDir[0] * mtx[0][1] + lightDir[1] * mtx[1][1] + lightDir[2] * mtx[2][1];
            // lookDirZ = lightDir[0] * mtx[0][2] + lightDir[1] * mtx[1][2] + lightDir[2] * mtx[2][2];
            lookDirX = (lightDir[0] * (*viewMat)[0][0] + lightDir[1] * (*viewMat)[1][0] + lightDir[2] * (*viewMat)[2][0]);
            lookDirY = (lightDir[0] * (*viewMat)[0][1] + lightDir[1] * (*viewMat)[1][1] + lightDir[2] * (*viewMat)[2][1]);
            lookDirZ = (lightDir[0] * (*viewMat)[0][2] + lightDir[1] * (*viewMat)[1][2] + lightDir[2] * (*viewMat)[2][2]);
            // char buff[100];
            // sprintf(buff, "%.2f %.2f %.2f", lookDirX, lookDirY, lookDirZ);
            // print_text(10, 40, buff);
            up = 1.0f;
        }

        Mtx *lMtx = alloc_display_list(sizeof(Mtx));
        LookAt *tLookAt = alloc_display_list(sizeof(LookAt));
        guLookAtReflect(
            lMtx,
            tLookAt,
            0.0f, 0.0f, 0.0f, /* eye */
            lookDirX, lookDirY, lookDirZ, /* at */
            0.0f, -1.0f, 0.0f /* up */
        );
        gSPLookAt(dlHead++, tLookAt);
        gSPEndDisplayList(dlHead);
    }

    return dlStart;
}
