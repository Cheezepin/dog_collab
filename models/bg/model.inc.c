Vtx bg_Plane_mesh_vtx_0[4] = {
	{{{-200, 20000, 0}, 0, {-16, 1008}, {0x0, 0x0, 0x0, 0x0}}},
	{{{32200, 20000, 0}, 0, {1008, 1008}, {0x0, 0x0, 0x0, 0x0}}},
	{{{32200, 24200, 0}, 0, {1008, -16}, {0x0, 0x0, 0x0, 0x0}}},
	{{{-200, 24200, 0}, 0, {-16, -16}, {0x0, 0x0, 0x0, 0x0}}},
};

Gfx bg_Plane_mesh_tri_0[] = {
	gsSPVertex(bg_Plane_mesh_vtx_0 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_bg_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bg_f3dlite_material[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx bg_Plane_mesh[] = {
	gsSPDisplayList(mat_bg_f3dlite_material),
	gsSPDisplayList(bg_Plane_mesh_tri_0),
	gsSPDisplayList(mat_revert_bg_f3dlite_material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};

