Lights1 electric_spinner_f3d_material_lights = gdSPDefLights1(
	0x7F, 0x0, 0x10,
	0xFE, 0x0, 0x21, 0x28, 0x28, 0x28);

Vtx electric_spinner_000_displaylist_mesh_layer_1_vtx_0[26] = {
	{{{-97, -170, 50},0, {240, 506},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-1061, -501, 50},0, {453, 629},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-963, -670, 50},0, {240, 506},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-195, -1, 50},0, {453, 629},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-98, 169, 50},0, {453, 875},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{197, 0, 50},0, {27, 875},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{99, -170, 50},0, {27, 629},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{965, -670, 50},0, {27, 629},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{1063, -500, 50},0, {27, 875},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{99, 170, 50},0, {240, 998},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{99, 1170, 50},0, {240, 998},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-98, 1169, 50},0, {453, 875},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-195, -1, -50},0, {965, 629},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-963, -670, -50},0, {752, 506},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-1061, -501, -50},0, {965, 629},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-97, -170, -50},0, {752, 506},{0x0, 0x0, 0x81, 0xFF}}},
	{{{99, -170, -50},0, {539, 629},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-97, -170, -50},0, {752, 506},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-195, -1, -50},0, {965, 629},{0x0, 0x0, 0x81, 0xFF}}},
	{{{99, 170, -50},0, {752, 998},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-98, 169, -50},0, {965, 875},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-98, 1169, -50},0, {965, 875},{0x0, 0x0, 0x81, 0xFF}}},
	{{{99, 1170, -50},0, {752, 998},{0x0, 0x0, 0x81, 0xFF}}},
	{{{197, 0, -50},0, {539, 875},{0x0, 0x0, 0x81, 0xFF}}},
	{{{1063, -500, -50},0, {539, 875},{0x0, 0x0, 0x81, 0xFF}}},
	{{{965, -670, -50},0, {539, 629},{0x0, 0x0, 0x81, 0xFF}}},
};

Gfx electric_spinner_000_displaylist_mesh_layer_1_tri_0[] = {
	gsSPVertex(electric_spinner_000_displaylist_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 3, 0, 0),
	gsSP1Triangle(0, 5, 4, 0),
	gsSP1Triangle(0, 6, 5, 0),
	gsSP1Triangle(5, 6, 7, 0),
	gsSP1Triangle(5, 7, 8, 0),
	gsSP1Triangle(5, 9, 4, 0),
	gsSP1Triangle(4, 9, 10, 0),
	gsSP1Triangle(4, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 15, 13, 0),
	gsSPVertex(electric_spinner_000_displaylist_mesh_layer_1_vtx_0 + 16, 10, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(2, 4, 3, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(3, 5, 6, 0),
	gsSP1Triangle(3, 7, 0, 0),
	gsSP1Triangle(0, 7, 8, 0),
	gsSP1Triangle(0, 8, 9, 0),
	gsSPEndDisplayList(),
};


Gfx mat_electric_spinner_f3d_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPSetLights1(electric_spinner_f3d_material_lights),
	gsSPEndDisplayList(),
};

Gfx electric_spinner_000_displaylist_mesh_layer_1[] = {
	gsSPDisplayList(mat_electric_spinner_f3d_material),
	gsSPDisplayList(electric_spinner_000_displaylist_mesh_layer_1_tri_0),
	gsSPEndDisplayList(),
};

Gfx electric_spinner_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

