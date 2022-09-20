Vtx bar_mesh_mesh_vtx_cull[8] = {
	{{{-400, 0, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-400, 0, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-400, 16, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-400, 16, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{12, 0, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{12, 0, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{12, 16, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{12, 16, 0},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx bar_mesh_mesh_vtx_0[4] = {
	{{{-400, 0, 0},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{12, 0, 0},0, {1008, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{12, 16, 0},0, {1008, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-400, 16, 0},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx bar_mesh_mesh_tri_0[] = {
	gsSPVertex(bar_mesh_mesh_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_bar_mat_layer1[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
	gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bar_mat_layer1[] = {
	gsDPPipeSync(),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsSPEndDisplayList(),
};

Gfx bar_mesh_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(bar_mesh_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_bar_mat_layer1),
	gsSPDisplayList(bar_mesh_mesh_tri_0),
	gsSPDisplayList(mat_revert_bar_mat_layer1),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

