Vtx icon_icon_mesh_vtx_0[4] = {
	{{{0, 0, 0},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{25, 0, 0},0, {1008, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{25, 38, 0},0, {1008, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{0, 38, 0},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx icon_icon_mesh_tri_0[] = {
	gsSPVertex(icon_icon_mesh_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_icon_f3d_material_002[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, ENVIRONMENT, 0, 0, 0, 1, 0, 0, 0, ENVIRONMENT, 0, 0, 0, 1),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetEnvColor(0, 37, 52, 255),
	gsSPEndDisplayList(),
};

Gfx icon_icon_mesh[] = {
	gsSPDisplayList(mat_icon_f3d_material_002),
	gsSPDisplayList(icon_icon_mesh_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

