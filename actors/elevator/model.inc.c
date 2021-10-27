Lights1 elevator_f3d_material_004_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx elevator__elevator_model_mesh_layer_1_vtx_cull[8] = {
	{{{-142, 0, 181},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-142, 368, 181},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-142, 368, -187},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-142, 0, -187},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{152, 0, 181},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{152, 368, 181},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{152, 368, -187},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{152, 0, -187},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx elevator__elevator_model_mesh_layer_1_vtx_0[20] = {
	{{{-142, 0, 181},0, {368, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-142, 0, -187},0, {368, 752},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-142, 368, -187},0, {624, 752},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-142, 368, 181},0, {624, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-142, 0, -187},0, {368, 752},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{152, 0, -187},0, {368, 496},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{152, 368, -187},0, {624, 496},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-142, 368, -187},0, {624, 752},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{152, 0, 181},0, {368, 240},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-142, 0, 181},0, {368, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-142, 368, 181},0, {624, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{152, 368, 181},0, {624, 240},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-142, 0, -187},0, {112, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-142, 0, 181},0, {112, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{152, 0, 181},0, {368, 240},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{152, 0, -187},0, {368, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{152, 368, -187},0, {624, 496},{0x0, 0x81, 0x0, 0xFF}}},
	{{{152, 368, 181},0, {624, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-142, 368, 181},0, {880, 240},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-142, 368, -187},0, {880, 496},{0x0, 0x81, 0x0, 0xFF}}},
};

Gfx elevator__elevator_model_mesh_layer_1_tri_0[] = {
	gsSPVertex(elevator__elevator_model_mesh_layer_1_vtx_0 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSPEndDisplayList(),
};


Gfx mat_elevator_f3d_material_004[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(elevator_f3d_material_004_lights),
	gsSPEndDisplayList(),
};

Gfx elevator__elevator_model_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(elevator__elevator_model_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_elevator_f3d_material_004),
	gsSPDisplayList(elevator__elevator_model_mesh_layer_1_tri_0),
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

