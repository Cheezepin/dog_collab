Vtx center_light_CenterLight_mesh_layer_5_vtx_0[24] = {
	{{{-845, 0, -1930},0, {-16, 1008},{0xA7, 0x0, 0xA5, 0xFF}}},
	{{{-1690, 0, -1100},0, {-16, 1008},{0xA7, 0x0, 0xA5, 0xFF}}},
	{{{-1690, 3191, -1100},0, {-16, 1008},{0xA7, 0x0, 0xA5, 0xFF}}},
	{{{-845, 3191, -1930},0, {-16, 1008},{0xA7, 0x0, 0xA5, 0xFF}}},
	{{{1690, 0, -1100},0, {-16, 1008},{0x59, 0x0, 0xA5, 0xFF}}},
	{{{845, 0, -1930},0, {-16, 1008},{0x59, 0x0, 0xA5, 0xFF}}},
	{{{845, 3191, -1930},0, {-16, 1008},{0x59, 0x0, 0xA5, 0xFF}}},
	{{{1690, 3191, -1100},0, {-16, 1008},{0x59, 0x0, 0xA5, 0xFF}}},
	{{{-1340, 0, -270},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{1340, 0, -270},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{1340, 3191, -270},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-1340, 3191, -270},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{845, 0, -1930},0, {-16, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-845, 0, -1930},0, {-16, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-845, 3191, -1930},0, {-16, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{845, 3191, -1930},0, {-16, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{1340, 0, -270},0, {-16, 1008},{0x75, 0x0, 0x31, 0xFF}}},
	{{{1690, 0, -1100},0, {-16, 1008},{0x75, 0x0, 0x31, 0xFF}}},
	{{{1690, 3191, -1100},0, {-16, 1008},{0x75, 0x0, 0x31, 0xFF}}},
	{{{1340, 3191, -270},0, {-16, 1008},{0x75, 0x0, 0x31, 0xFF}}},
	{{{-1690, 0, -1100},0, {-16, 1008},{0x8B, 0x0, 0x31, 0xFF}}},
	{{{-1340, 0, -270},0, {-16, 1008},{0x8B, 0x0, 0x31, 0xFF}}},
	{{{-1340, 3191, -270},0, {-16, 1008},{0x8B, 0x0, 0x31, 0xFF}}},
	{{{-1690, 3191, -1100},0, {-16, 1008},{0x8B, 0x0, 0x31, 0xFF}}},
};

Gfx center_light_CenterLight_mesh_layer_5_tri_0[] = {
	gsSPVertex(center_light_CenterLight_mesh_layer_5_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSPEndDisplayList(),
};


Gfx mat_center_light_CenterLight[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 254, 0, 102),
	gsSPEndDisplayList(),
};

Gfx mat_revert_center_light_CenterLight[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx center_light_CenterLight_mesh_layer_5[] = {
	gsSPDisplayList(mat_center_light_CenterLight),
	gsSPDisplayList(center_light_CenterLight_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_center_light_CenterLight),
	gsSPEndDisplayList(),
};

Gfx center_light_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

