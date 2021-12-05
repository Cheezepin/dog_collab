Lights1 missile_rocket_white_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 missile_rocket_red_lights = gdSPDefLights1(
	0x7F, 0x0, 0x2,
	0xFE, 0x0, 0x5, 0x28, 0x28, 0x28);

Vtx missile_Cube_043_mesh_layer_1_vtx_cull[8] = {
	{{{-48, -48, 117},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-48, 48, 117},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-48, 48, -108},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-48, -48, -108},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{48, -48, 117},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{48, 48, 117},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{48, 48, -108},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{48, -48, -108},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx missile_Cube_043_mesh_layer_1_vtx_0[14] = {
	{{{-23, 0, 72},0, {368, 1008},{0x98, 0x0, 0x49, 0xFF}}},
	{{{0, 23, 72},0, {624, 1008},{0x0, 0x68, 0x49, 0xFF}}},
	{{{0, 23, -74},0, {624, 752},{0x0, 0x7B, 0xE0, 0xFF}}},
	{{{-23, 0, -74},0, {368, 752},{0x85, 0x0, 0xE0, 0xFF}}},
	{{{0, -23, 72},0, {368, 240},{0x0, 0x98, 0x49, 0xFF}}},
	{{{0, 23, 72},0, {624, -16},{0x0, 0x68, 0x49, 0xFF}}},
	{{{-23, 0, 72},0, {368, -16},{0x98, 0x0, 0x49, 0xFF}}},
	{{{23, 0, 72},0, {624, 240},{0x68, 0x0, 0x49, 0xFF}}},
	{{{0, -23, -74},0, {368, 496},{0x0, 0x85, 0xE0, 0xFF}}},
	{{{-23, 0, -74},0, {112, 496},{0x85, 0x0, 0xE0, 0xFF}}},
	{{{-23, 0, 72},0, {112, 240},{0x98, 0x0, 0x49, 0xFF}}},
	{{{23, 0, -74},0, {624, 496},{0x7B, 0x0, 0xE0, 0xFF}}},
	{{{0, 23, 72},0, {880, 240},{0x0, 0x68, 0x49, 0xFF}}},
	{{{0, 23, -74},0, {880, 496},{0x0, 0x7B, 0xE0, 0xFF}}},
};

Gfx missile_Cube_043_mesh_layer_1_tri_0[] = {
	gsSPVertex(missile_Cube_043_mesh_layer_1_vtx_0 + 0, 14, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 7, 4, 0, 9, 8, 4, 0),
	gsSP2Triangles(9, 4, 10, 0, 8, 11, 7, 0),
	gsSP2Triangles(11, 12, 7, 0, 11, 13, 12, 0),
	gsSPEndDisplayList(),
};

Vtx missile_Cube_043_mesh_layer_1_vtx_1[26] = {
	{{{-23, 0, -74},0, {368, 752},{0x85, 0x0, 0xE0, 0xFF}}},
	{{{0, 23, -74},0, {624, 752},{0x0, 0x7B, 0xE0, 0xFF}}},
	{{{0, 0, -108},0, {368, 752},{0x0, 0x0, 0x81, 0xFF}}},
	{{{23, 0, -74},0, {624, 496},{0x7B, 0x0, 0xE0, 0xFF}}},
	{{{0, -23, -74},0, {368, 496},{0x0, 0x85, 0xE0, 0xFF}}},
	{{{0, 0, -108},0, {624, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-23, 0, -74},0, {112, 496},{0x85, 0x0, 0xE0, 0xFF}}},
	{{{0, 0, -108},0, {368, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{0, 23, -74},0, {880, 496},{0x0, 0x7B, 0xE0, 0xFF}}},
	{{{0, 0, -108},0, {880, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{0, -23, 95},0, {624, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{0, -23, 27},0, {624, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{0, -48, 49},0, {624, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{0, -48, 117},0, {624, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{48, 0, 49},0, {624, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{48, 0, 117},0, {624, 752},{0x0, 0x81, 0x0, 0xFF}}},
	{{{23, 0, 95},0, {624, 752},{0x0, 0x81, 0x0, 0xFF}}},
	{{{23, 0, 27},0, {624, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{0, 23, 95},0, {624, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 23, 27},0, {624, 752},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 48, 49},0, {624, 752},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{0, 48, 117},0, {624, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-23, 0, 95},0, {624, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-23, 0, 27},0, {624, 752},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-48, 0, 49},0, {624, 752},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-48, 0, 117},0, {624, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx missile_Cube_043_mesh_layer_1_tri_1[] = {
	gsSPVertex(missile_Cube_043_mesh_layer_1_vtx_1 + 0, 26, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(4, 6, 7, 0, 8, 3, 9, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 12, 13, 0),
	gsSP2Triangles(14, 15, 16, 0, 14, 16, 17, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 24, 25, 0),
	gsSPEndDisplayList(),
};


Gfx mat_missile_rocket_white[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(missile_rocket_white_lights),
	gsSPEndDisplayList(),
};

Gfx mat_missile_rocket_red[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(missile_rocket_red_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_missile_rocket_red[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx missile_Cube_043_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(missile_Cube_043_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_missile_rocket_white),
	gsSPDisplayList(missile_Cube_043_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_missile_rocket_red),
	gsSPDisplayList(missile_Cube_043_mesh_layer_1_tri_1),
	gsSPDisplayList(mat_revert_missile_rocket_red),
	gsSPEndDisplayList(),
};

Gfx missile_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

