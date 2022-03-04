Lights1 bowser_2_dl_f3d_material_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx bowser_2_dl_Plane_001_mesh_layer_1_vtx_cull[8] = {
	{{{-2126, 0, 2126},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-2126, 0, 2126},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-2126, 0, -2126},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-2126, 0, -2126},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{2126, 0, 2126},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{2126, 0, 2126},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{2126, 0, -2126},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{2126, 0, -2126},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx bowser_2_dl_Plane_001_mesh_layer_1_vtx_0[4] = {
	{{{-2126, 0, 2126},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{2126, 0, 2126},0, {1008, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{2126, 0, -2126},0, {1008, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-2126, 0, -2126},0, {-16, -16},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx bowser_2_dl_Plane_001_mesh_layer_1_tri_0[] = {
	gsSPVertex(bowser_2_dl_Plane_001_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_bowser_2_dl_f3d_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(bowser_2_dl_f3d_material_lights),
	gsSPEndDisplayList(),
};

Gfx bowser_2_dl_Plane_001_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(bowser_2_dl_Plane_001_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_bowser_2_dl_f3d_material),
	gsSPDisplayList(bowser_2_dl_Plane_001_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx bowser_2_dl_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

