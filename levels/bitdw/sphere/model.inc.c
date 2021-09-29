Lights1 sphere_sphere_layer1_lights = gdSPDefLights1(
	0x7F, 0x0, 0xA,
	0xFE, 0x0, 0x15, 0x28, 0x28, 0x28);

Vtx sphere_000_displaylist_mesh_layer_1_vtx_0[31] = {
	{{{0, -517, 0},0, {524, 1008},{0x0, 0x17, 0x71, 0xFF}}},
	{{{409, -259, 298},0, {482, 764},{0xFF, 0x9, 0x51, 0xFF}}},
	{{{-146, -236, 450},0, {366, 881},{0x0, 0x18, 0x74, 0xFF}}},
	{{{391, -242, -284},0, {721, 868},{0x0, 0x2D, 0xDA, 0xFF}}},
	{{{664, 326, -11},0, {721, 570},{0x0, 0x15, 0x67, 0xFF}}},
	{{{180, 296, 567},0, {430, 608},{0xFF, 0x22, 0x7F, 0xFF}}},
	{{{0, -517, 0},0, {510, 279},{0x0, 0x17, 0x71, 0xFF}}},
	{{{-146, -236, 450},0, {366, 421},{0x0, 0x18, 0x74, 0xFF}}},
	{{{-462, -231, 0},0, {543, 520},{0x90, 0x14, 0x71, 0xFF}}},
	{{{-143, -231, -440},0, {736, 371},{0xC0, 0x17, 0x6F, 0xFF}}},
	{{{-374, 231, -272},0, {736, 570},{0xFF, 0x17, 0x6F, 0xFF}}},
	{{{391, -242, -284},0, {686, 170},{0x0, 0x2D, 0xDA, 0xFF}}},
	{{{-146, -236, 450},0, {17, 380},{0x0, 0x18, 0x74, 0xFF}}},
	{{{409, -259, 298},0, {-16, 520},{0xFF, 0x9, 0x51, 0xFF}}},
	{{{180, 296, 567},0, {240, 543},{0xFF, 0x22, 0x7F, 0xFF}}},
	{{{-382, 236, 277},0, {239, 267},{0x0, 0x19, 0x7B, 0xFF}}},
	{{{-462, -231, 0},0, {36, 141},{0x90, 0x14, 0x71, 0xFF}}},
	{{{-146, -236, 450},0, {17, 380},{0x0, 0x18, 0x74, 0xFF}}},
	{{{-382, 236, 277},0, {239, 267},{0x0, 0x19, 0x7B, 0xFF}}},
	{{{-374, 231, -272},0, {240, 107},{0xFF, 0x17, 0x6F, 0xFF}}},
	{{{180, 296, 567},0, {772, 674},{0xFF, 0x22, 0x7F, 0xFF}}},
	{{{664, 326, -11},0, {721, 1008},{0x0, 0x15, 0x67, 0xFF}}},
	{{{-5, 594, -4},0, {1008, 859},{0x0, 0x19, 0x79, 0xFF}}},
	{{{-382, 236, 277},0, {1008, 646},{0x0, 0x19, 0x7B, 0xFF}}},
	{{{-374, 231, -272},0, {181, 543},{0xFF, 0x17, 0x6F, 0xFF}}},
	{{{-382, 236, 277},0, {-15, 543},{0x0, 0x19, 0x7B, 0xFF}}},
	{{{-5, 594, -4},0, {-16, 704},{0x0, 0x19, 0x79, 0xFF}}},
	{{{147, 238, -452},0, {240, 775},{0xFF, 0x15, 0x69, 0xFF}}},
	{{{664, 326, -11},0, {56, 1008},{0x0, 0x15, 0x67, 0xFF}}},
	{{{391, -242, -284},0, {310, 894},{0x0, 0x2D, 0xDA, 0xFF}}},
	{{{-143, -231, -440},0, {366, 654},{0xC0, 0x17, 0x6F, 0xFF}}},
};

Gfx sphere_000_displaylist_mesh_layer_1_tri_0[] = {
	gsSPVertex(sphere_000_displaylist_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 0, 3, 0),
	gsSP1Triangle(1, 3, 4, 0),
	gsSP1Triangle(1, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(6, 8, 9, 0),
	gsSP1Triangle(9, 8, 10, 0),
	gsSP1Triangle(6, 9, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(sphere_000_displaylist_mesh_layer_1_vtx_0 + 16, 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(7, 4, 6, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(11, 8, 10, 0),
	gsSP1Triangle(12, 11, 10, 0),
	gsSP1Triangle(13, 11, 12, 0),
	gsSP1Triangle(13, 14, 11, 0),
	gsSP1Triangle(14, 8, 11, 0),
	gsSPEndDisplayList(),
};


Gfx mat_sphere_sphere_layer1[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(1, 0, PRIMITIVE, 0, 1, 0, PRIMITIVE, 0, 1, COMBINED, SHADE, COMBINED, 1, COMBINED, SHADE, COMBINED),
	gsSPSetGeometryMode(G_FOG),
	gsSPClearGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
	gsDPSetCycleType(G_CYC_2CYCLE),
	gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 0, 0, 0, 255),
	gsSPSetLights1(sphere_sphere_layer1_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_sphere_sphere_layer1[] = {
	gsDPPipeSync(),
	gsSPClearGeometryMode(G_FOG),
	gsSPSetGeometryMode(G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
	gsDPSetCycleType(G_CYC_1CYCLE),
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
	gsSPEndDisplayList(),
};

Gfx sphere_000_displaylist_mesh_layer_1[] = {
	gsSPDisplayList(mat_sphere_sphere_layer1),
	gsSPDisplayList(sphere_000_displaylist_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_sphere_sphere_layer1),
	gsSPEndDisplayList(),
};

Gfx sphere_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

