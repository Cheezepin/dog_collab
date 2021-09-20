Lights1 lightning_bolt_Billboard_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 lightning_bolt_Yellow_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Vtx lightning_bolt_bb_mesh_layer_5_vtx_0[10] = {
	{{{0, 0, -150},0, {-16, 1008},{0x0, 0x7F, 0x0, 0x0}}},
	{{{-130, 0, -75},0, {-16, 1008},{0x0, 0x7F, 0x0, 0x0}}},
	{{{0, 0, 0},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xBF}}},
	{{{130, 0, -75},0, {-16, 1008},{0x0, 0x7F, 0x0, 0x0}}},
	{{{130, 0, 75},0, {-16, 1008},{0x0, 0x7F, 0x0, 0x0}}},
	{{{-130, 0, -75},0, {-16, 1008},{0x0, 0x7F, 0x0, 0x0}}},
	{{{-130, 0, 75},0, {-16, 1008},{0x0, 0x7F, 0x0, 0x0}}},
	{{{0, 0, 0},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xBF}}},
	{{{0, 0, 150},0, {-16, 1008},{0x0, 0x7F, 0x0, 0x0}}},
	{{{130, 0, 75},0, {-16, 1008},{0x0, 0x7F, 0x0, 0x0}}},
};

Gfx lightning_bolt_bb_mesh_layer_5_tri_0[] = {
	gsSPVertex(lightning_bolt_bb_mesh_layer_5_vtx_0 + 0, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(4, 3, 2, 0, 5, 6, 7, 0),
	gsSP2Triangles(6, 8, 7, 0, 8, 9, 7, 0),
	gsSPEndDisplayList(),
};

Vtx lightning_bolt_bolt_mesh_layer_1_vtx_0[6] = {
	{{{45, 0, 174},0, {1008, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{20, 0, 55},0, {1008, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-78, 0, 55},0, {-16, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{78, 0, -55},0, {1008, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-20, 0, -55},0, {-16, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-45, 0, -174},0, {-16, -16},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx lightning_bolt_bolt_mesh_layer_1_tri_0[] = {
	gsSPVertex(lightning_bolt_bolt_mesh_layer_1_vtx_0 + 0, 6, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(2, 3, 4, 0, 4, 3, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_lightning_bolt_Billboard[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 254, 0, 255),
	gsSPSetLights1(lightning_bolt_Billboard_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_lightning_bolt_Billboard[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx mat_lightning_bolt_Yellow[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, ENVIRONMENT, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(254, 254, 0, 255),
	gsSPSetLights1(lightning_bolt_Yellow_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_lightning_bolt_Yellow[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx lightning_bolt_bb_mesh_layer_5[] = {
	gsSPDisplayList(mat_lightning_bolt_Billboard),
	gsSPDisplayList(lightning_bolt_bb_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_lightning_bolt_Billboard),
	gsSPEndDisplayList(),
};

Gfx lightning_bolt_bolt_mesh_layer_1[] = {
	gsSPDisplayList(mat_lightning_bolt_Yellow),
	gsSPDisplayList(lightning_bolt_bolt_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_lightning_bolt_Yellow),
	gsSPEndDisplayList(),
};

Gfx lightning_bolt_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

