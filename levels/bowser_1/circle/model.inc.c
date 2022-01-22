Vtx circle_Circle_mesh_layer_1_vtx_0[14] = {
	{{{0, 0, -100},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-43, 0, -90},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-78, 0, -62},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-97, 0, 22},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-97, 0, -22},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{78, 0, -62},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{43, 0, -90},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{43, 0, 90},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-43, 0, 90},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-78, 0, 62},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 100},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{78, 0, 62},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{97, 0, 22},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{97, 0, -22},0, {-16, 1008},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx circle_Circle_mesh_layer_1_tri_0[] = {
	gsSPVertex(circle_Circle_mesh_layer_1_vtx_0 + 0, 14, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(2, 4, 3, 0),
	gsSP1Triangle(5, 0, 3, 0),
	gsSP1Triangle(5, 6, 0, 0),
	gsSP1Triangle(3, 7, 5, 0),
	gsSP1Triangle(3, 8, 7, 0),
	gsSP1Triangle(3, 9, 8, 0),
	gsSP1Triangle(8, 10, 7, 0),
	gsSP1Triangle(7, 11, 12, 0),
	gsSP1Triangle(7, 12, 5, 0),
	gsSP1Triangle(12, 13, 5, 0),
	gsSPEndDisplayList(),
};


Gfx mat_circle_f3d_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(0, 0, 0, 255),
	gsSPEndDisplayList(),
};

Gfx circle_Circle_mesh_layer_1[] = {
	gsSPDisplayList(mat_circle_f3d_material),
	gsSPDisplayList(circle_Circle_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx circle_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

