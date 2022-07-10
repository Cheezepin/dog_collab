Lights1 elevator_nothing_f3d_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx elevator__THE_actual_elevator_mesh_layer_1_vtx_0[8] = {
	{{{-642, 0, -642},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-642, 0, 642},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{642, 0, 642},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{642, 0, -642},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-642, 1000, -642},0, {-16, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{642, 1000, -642},0, {-16, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{642, 1000, 642},0, {-16, 1008},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-642, 1000, 642},0, {-16, 1008},{0x0, 0x81, 0x0, 0xFF}}},
};

Gfx elevator__THE_actual_elevator_mesh_layer_1_tri_0[] = {
	gsSPVertex(elevator__THE_actual_elevator_mesh_layer_1_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSPEndDisplayList(),
};


Gfx mat_elevator_nothing_f3d[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(elevator_nothing_f3d_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_elevator_nothing_f3d[] = {
	gsDPPipeSync(),
	gsSPGeometryMode(0, G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx elevator__THE_actual_elevator_mesh_layer_1[] = {
	gsSPDisplayList(mat_elevator_nothing_f3d),
	gsSPDisplayList(elevator__THE_actual_elevator_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_elevator_nothing_f3d),
	gsSPEndDisplayList(),
};

Gfx elevator_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

