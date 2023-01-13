ALIGNED8 const u8 life_meter_full[] = {
	#include "actors/life_meter_new/life_meter_full_rounded.ia8.inc.c"
};

ALIGNED8 const u8 life_meter_half[] = {
	#include "actors/life_meter_new/life_meter_half_rounded.ia8.inc.c"
};

ALIGNED8 const u8 life_meter_empty[] = {
	#include "actors/life_meter_new/life_meter_empty_rounded.ia8.inc.c"
};

// #define NEW_LIFE_METER_SIZE 32
#define NEW_LIFE_METER_SIZE 16

#define NEW_LIFE_METER_DIAG ((s16)(NEW_LIFE_METER_SIZE * (.75)))

#define NEW_LIFE_METER_CENTER_INTENSITY (71)
#define NEW_LIFE_METER_CENTER_COL NEW_LIFE_METER_CENTER_INTENSITY, NEW_LIFE_METER_CENTER_INTENSITY, NEW_LIFE_METER_CENTER_INTENSITY
#define NEW_LIFE_METER_CORNER_INTENSITY (0)
#define NEW_LIFE_METER_CORNER_COL NEW_LIFE_METER_CORNER_INTENSITY, NEW_LIFE_METER_CORNER_INTENSITY, NEW_LIFE_METER_CORNER_INTENSITY

Vtx life_meter_quad_vtx_0[5] = {
	{{ {-NEW_LIFE_METER_SIZE, 0, 0}, 0, {4080, 2030}, {0, 0, 0, 0} }},
	{{ {0, 0, 0}, 0, {2032, 2032}, {NEW_LIFE_METER_CENTER_COL, 255} }},
	{{ {-NEW_LIFE_METER_DIAG, NEW_LIFE_METER_DIAG, 0}, 0, {3552, 512}, {NEW_LIFE_METER_CORNER_COL, 254} }},
	{{ {-NEW_LIFE_METER_DIAG, NEW_LIFE_METER_DIAG, 0}, 0, {3552, 512}, {NEW_LIFE_METER_CORNER_COL, 254} }},
	{{ {0, NEW_LIFE_METER_SIZE, 0}, 0, {2032, -16}, {0, 0, 0, 254} }},
};

Gfx life_meter_quad_tri_0[] = {
	gsSPVertex(life_meter_quad_vtx_0 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 4, 0),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Vtx life_meter_quad_vtx_1[5] = {
	{{ {0, 0, 0}, 0, {2032, 2032}, {NEW_LIFE_METER_CENTER_COL, 255} }},
	{{ {-NEW_LIFE_METER_DIAG, -NEW_LIFE_METER_DIAG, 0}, 0, {3552, 512}, {NEW_LIFE_METER_CORNER_COL, 140} }},
	{{ {0, -NEW_LIFE_METER_SIZE, 0}, 0, {4080, 2030}, {0, 0, 0, 254} }},
	{{ {-NEW_LIFE_METER_DIAG, -NEW_LIFE_METER_DIAG, 0}, 0, {3552, 512}, {NEW_LIFE_METER_CORNER_COL, 140} }},
	{{ {-NEW_LIFE_METER_SIZE, 0, 0}, 0, {2032, -16}, {0, 0, 0, 0} }},
};

Gfx life_meter_quad_tri_1[] = {
	gsSPVertex(life_meter_quad_vtx_1 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 4, 0),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Vtx life_meter_quad_vtx_2[5] = {
	{{ {0, 0, 0}, 0, {2032, 2032}, {NEW_LIFE_METER_CENTER_COL, 255} }},
	{{ {NEW_LIFE_METER_DIAG, -NEW_LIFE_METER_DIAG, 0}, 0, {3552, 512}, {NEW_LIFE_METER_CORNER_COL, 254} }},
	{{ {NEW_LIFE_METER_SIZE, 0, 0}, 0, {4080, 2030}, {0, 0, 0, 254} }},
	{{ {0, -NEW_LIFE_METER_SIZE, 0}, 0, {2032, -16}, {0, 0, 0, 254} }},
	{{ {NEW_LIFE_METER_DIAG, -NEW_LIFE_METER_DIAG, 0}, 0, {3552, 512}, {NEW_LIFE_METER_CORNER_COL, 254} }},
};

Gfx life_meter_quad_tri_2[] = {
	gsSPVertex(life_meter_quad_vtx_2 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 0, 0),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Vtx life_meter_quad_vtx_3[5] = {
	{{ {NEW_LIFE_METER_DIAG, NEW_LIFE_METER_DIAG, 0}, 0, {3552, 512}, {NEW_LIFE_METER_CORNER_COL, 254} }},
	{{ {0, NEW_LIFE_METER_SIZE, 0}, 0, {4080, 2030}, {0, 0, 0, 254} }},
	{{ {0, 0, 0}, 0, {2032, 2032}, {NEW_LIFE_METER_CENTER_COL, 255} }},
	{{ {NEW_LIFE_METER_SIZE, 0, 0}, 0, {2032, -16}, {0, 0, 0, 254} }},
	{{ {NEW_LIFE_METER_DIAG, NEW_LIFE_METER_DIAG, 0}, 0, {3552, 512}, {NEW_LIFE_METER_CORNER_COL, 254} }},
};

Gfx life_meter_quad_tri_3[] = {
	gsSPVertex(life_meter_quad_vtx_3 + 0, 5, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 4, 0),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Gfx *life_meter_tex_lut[] = {
	life_meter_quad_tri_0,
	life_meter_quad_tri_1,
	life_meter_quad_tri_2,
	life_meter_quad_tri_3
};

Gfx life_meter_new_init[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(
		PRIMITIVE, 0, TEXEL0, SHADE,
		0, 0, 0, TEXEL0,
		// 1, 0, PRIMITIVE, TEXEL0,
		PRIMITIVE, 0, TEXEL0, SHADE,
		0, 0, 0, TEXEL0
		// 1, 0, PRIMITIVE, TEXEL0
	),
	gsSPGeometryMode(G_ZBUFFER | G_LIGHTING, 0),
	gsDPSetRenderMode(G_RM_CLD_SURF, G_RM_CLD_SURF2),
	gsDPSetTextureFilter(G_TF_BILERP),
	// gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
	// gsDPSetAlphaCompare(G_AC_THRESHOLD),
	// gsDPSetBlendColor(0, 0, 0, 76),
	// gsDPSetRenderMode(G_RM_AA_TEX_EDGE | IM_RD, G_RM_AA_TEX_EDGE2 | IM_RD),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

// gsDPSetPrimColor(0, 0, 0, 133, 255, 255),

// #define LIFE_METER_NEW_FORMAT G_IM_FMT_I
#define LIFE_METER_NEW_FORMAT G_IM_FMT_IA

Gfx life_meter_tex_init_full[] = {
	gsDPSetTextureImage(LIFE_METER_NEW_FORMAT, G_IM_SIZ_8b_LOAD_BLOCK, 1, life_meter_full),
	gsDPSetTile(LIFE_METER_NEW_FORMAT, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(LIFE_METER_NEW_FORMAT, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayList(),
};

Gfx life_meter_tex_init_half[] = {
	gsDPSetTextureImage(LIFE_METER_NEW_FORMAT, G_IM_SIZ_8b_LOAD_BLOCK, 1, life_meter_half),
	gsDPSetTile(LIFE_METER_NEW_FORMAT, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(LIFE_METER_NEW_FORMAT, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayList(),
};

Gfx life_meter_tex_init_empty[] = {
	gsDPSetTextureImage(LIFE_METER_NEW_FORMAT, G_IM_SIZ_8b_LOAD_BLOCK, 1, life_meter_empty),
	gsDPSetTile(LIFE_METER_NEW_FORMAT, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(LIFE_METER_NEW_FORMAT, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayList(),
};

Gfx life_meter_revert_material[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_ZBUFFER | G_LIGHTING),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsDPSetBlendColor(0, 0, 0, 255),
	gsDPSetTextureFilter(G_TF_POINT),
	gsSPEndDisplayList(),
};
