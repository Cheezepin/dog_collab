Lights1 sl_dl_sm64_material_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx sl_dl_Cube_mesh_vtx_cull[8] = {
	{{{-400, -100, 400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-400, 100, 400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-400, 100, -400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-400, -100, -400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{400, -100, 400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{400, 100, 400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{400, 100, -400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{400, -100, -400},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx sl_dl_Cube_mesh_vtx_0[24] = {
	{{{400, 100, -400},0, {624, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-400, 100, -400},0, {880, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-400, 100, 400},0, {880, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{400, 100, 400},0, {624, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{400, -100, 400},0, {368, 240},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{400, 100, 400},0, {624, 240},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-400, 100, 400},0, {624, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-400, -100, 400},0, {368, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-400, -100, 400},0, {368, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-400, 100, 400},0, {624, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-400, 100, -400},0, {624, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-400, -100, -400},0, {368, 752},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-400, -100, -400},0, {112, 496},{0x0, 0x81, 0x0, 0xFF}}},
	{{{400, -100, -400},0, {368, 496},{0x0, 0x81, 0x0, 0xFF}}},
	{{{400, -100, 400},0, {368, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-400, -100, 400},0, {112, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{400, -100, -400},0, {368, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{400, 100, -400},0, {624, 496},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{400, 100, 400},0, {624, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{400, -100, 400},0, {368, 240},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-400, -100, -400},0, {368, 752},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-400, 100, -400},0, {624, 752},{0x0, 0x0, 0x81, 0xFF}}},
	{{{400, 100, -400},0, {624, 496},{0x0, 0x0, 0x81, 0xFF}}},
	{{{400, -100, -400},0, {368, 496},{0x0, 0x0, 0x81, 0xFF}}},
};

Gfx sl_dl_Cube_mesh_tri_0[] = {
	gsSPVertex(sl_dl_Cube_mesh_vtx_0 + 0, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSPEndDisplayList(),
};

Vtx sl_dl_Water_Bottom_mesh_layer_5_vtx_cull[8] = {
	{{{-16384, 0, 16384},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-16384, 0, 16384},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-16384, 0, -16384},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-16384, 0, -16384},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{16384, 0, 16384},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{16384, 0, 16384},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{16384, 0, -16384},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{16384, 0, -16384},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx sl_dl_Water_Bottom_mesh_layer_5_vtx_0[4] = {
	{{{-16384, 0, 16384},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{16384, 0, 16384},0, {1008, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{16384, 0, -16384},0, {1008, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-16384, 0, -16384},0, {-16, -16},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx sl_dl_Water_Bottom_mesh_layer_5_tri_0[] = {
	gsSPVertex(sl_dl_Water_Bottom_mesh_layer_5_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_sl_dl_sm64_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(sl_dl_sm64_material_lights),
	gsSPEndDisplayList(),
};

Gfx mat_sl_dl_Water_Bottom[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(0, 141, 254, 127),
	gsSPEndDisplayList(),
};

Gfx mat_revert_sl_dl_Water_Bottom[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx sl_dl_Cube_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(sl_dl_Cube_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_sl_dl_sm64_material),
	gsSPDisplayList(sl_dl_Cube_mesh_tri_0),
	gsSPEndDisplayList(),
};

Gfx sl_dl_Water_Bottom_mesh_layer_5[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(sl_dl_Water_Bottom_mesh_layer_5_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_sl_dl_Water_Bottom),
	gsSPDisplayList(sl_dl_Water_Bottom_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_sl_dl_Water_Bottom),
	gsSPEndDisplayList(),
};

Gfx sl_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

