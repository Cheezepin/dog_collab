Vtx sl_backdrop_Backdrop_mesh_vtx_cull[8] = {
	{{{-10000, -275, -10000},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-10000, -275, 10000},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-10000, -275, 10000},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-10000, -275, -10000},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{10000, -275, -10000},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{10000, -275, 10000},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{10000, -275, 10000},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{10000, -275, -10000},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx sl_backdrop_Backdrop_mesh_vtx_0[8] = {
	{{{-1635, -275, -1635},0, {240, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-10000, -275, -10000},0, {-16, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-10000, -275, 10000},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{1635, -275, -1635},0, {752, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{10000, -275, -10000},0, {1008, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{1635, -275, 1635},0, {752, 752},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{10000, -275, 10000},0, {1008, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-1635, -275, 1635},0, {240, 752},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx sl_backdrop_Backdrop_mesh_tri_0[] = {
	gsSPVertex(sl_backdrop_Backdrop_mesh_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 0, 3, 0),
	gsSP2Triangles(1, 3, 4, 0, 4, 3, 5, 0),
	gsSP2Triangles(4, 5, 6, 0, 2, 6, 5, 0),
	gsSP2Triangles(2, 5, 7, 0, 0, 2, 7, 0),
	gsSPEndDisplayList(),
};

Gfx mat_sl_backdrop_Backdrop_Water_layer1[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(0, 141, 254, 127),
	gsSPEndDisplayList(),
};

Gfx mat_revert_sl_backdrop_Backdrop_Water_layer1[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsSPEndDisplayList(),
};

Gfx sl_backdrop_Backdrop_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(sl_backdrop_Backdrop_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_sl_backdrop_Backdrop_Water_layer1),
	gsSPDisplayList(sl_backdrop_Backdrop_mesh_tri_0),
	gsSPDisplayList(mat_revert_sl_backdrop_Backdrop_Water_layer1),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

