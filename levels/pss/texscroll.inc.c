void scroll_sts_mat_pss_dl_f3d_material_062() {
	static int intervalTex0 = 12;
	static int curInterval0 = 12;
	Gfx *mat = segmented_to_virtual(mat_pss_dl_f3d_material_062);

	if (--curInterval0 <= 0) {
		shift_t_down(mat, 13, PACK_TILESIZE(0, 64));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_pss_dl_f3d_material_015() {
	static int intervalTex0 = 45;
	static int curInterval0 = 45;
	Gfx *mat = segmented_to_virtual(mat_pss_dl_f3d_material_015);

	if (--curInterval0 <= 0) {
		shift_t(mat, 13, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_pss_dl_f3d_material_021() {
	static int intervalTex0 = 45;
	static int curInterval0 = 45;
	Gfx *mat = segmented_to_virtual(mat_pss_dl_f3d_material_021);

	if (--curInterval0 <= 0) {
		shift_t(mat, 8, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_pss_dl_Beam2_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 256 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(pss_dl_Beam2_mesh_layer_5_vtx_0);

	deltaX = (int)(6.279999732971191 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_pss_dl_Plane_005_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 131;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_Plane_005_mesh_layer_0_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;
	deltaY = (int)(0.03999999910593033 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_pss_dl_inner_torus_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 360;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_inner_torus_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_pss_dl_inner_torus_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 360;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_inner_torus_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_pss_dl_shock_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 60;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_shock_mesh_layer_5_vtx_0);

	deltaX = (int)(1.959999918937683 * 0x20) % width;
	deltaY = (int)(1.9900003671646118 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_sts_mat_pss_dl_electricity_layer5() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_electricity_layer5);
	shift_s(mat, 10, PACK_TILESIZE(0, 5));
	shift_t_down(mat, 10, PACK_TILESIZE(0, 4));
	shift_s_down(mat, 15, PACK_TILESIZE(0, 3));
	shift_t(mat, 15, PACK_TILESIZE(0, 8));
};

void scroll_pss_dl_shock_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 60;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_shock_001_mesh_layer_5_vtx_0);

	deltaX = (int)(1.959999918937683 * 0x20) % width;
	deltaY = (int)(1.9900003671646118 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_sts_mat_pss_dl_f3d_material_v4_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_f3d_material_v4_layer1);
	shift_t(mat, 11, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_pss_dl_former_metal_v4_001_layer5() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_former_metal_v4_001_layer5);
	shift_s(mat, 14, PACK_TILESIZE(0, 1));
};

void scroll_pss_dl_Torus_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_Torus_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_pss_dl_Torus_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_Torus_003_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_pss_dl_Torus_004_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_Torus_004_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_pss_dl_Torus_005_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_Torus_005_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_pss_dl_Torus_006_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_Torus_006_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_pss_dl_Torus_007_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(pss_dl_Torus_007_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_pss_dl_nebula_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_nebula_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_pss_dl_nebula_not_slippery_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_nebula_not_slippery_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_pss_dl_slide_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_slide_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_pss_dl_nebula_hangable_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_nebula_hangable_001_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_pss_dl_lava_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_lava_layer1);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_pss_dl_Lava_layer1_area5() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_Lava_layer1_area5);
	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 17, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_pss_dl_goooooooop_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_goooooooop_layer1);
	shift_t_down(mat, 10, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_pss() {
	scroll_sts_mat_pss_dl_f3d_material_062();
	scroll_sts_mat_pss_dl_f3d_material_015();
	scroll_sts_mat_pss_dl_f3d_material_021();
	scroll_pss_dl_Beam2_mesh_layer_5_vtx_0();
	scroll_pss_dl_Plane_005_mesh_layer_0_vtx_0();
	scroll_pss_dl_inner_torus_mesh_layer_1_vtx_0();
	scroll_pss_dl_inner_torus_001_mesh_layer_1_vtx_0();
	scroll_pss_dl_shock_mesh_layer_5_vtx_0();
	scroll_sts_mat_pss_dl_electricity_layer5();
	scroll_pss_dl_shock_001_mesh_layer_5_vtx_0();
	scroll_sts_mat_pss_dl_f3d_material_v4_layer1();
	scroll_sts_mat_pss_dl_former_metal_v4_001_layer5();
	scroll_pss_dl_Torus_001_mesh_layer_1_vtx_0();
	scroll_pss_dl_Torus_003_mesh_layer_1_vtx_0();
	scroll_pss_dl_Torus_004_mesh_layer_1_vtx_0();
	scroll_pss_dl_Torus_005_mesh_layer_1_vtx_0();
	scroll_pss_dl_Torus_006_mesh_layer_1_vtx_0();
	scroll_pss_dl_Torus_007_mesh_layer_1_vtx_0();
	scroll_sts_mat_pss_dl_nebula_layer1();
	scroll_sts_mat_pss_dl_nebula_not_slippery_layer1();
	scroll_sts_mat_pss_dl_slide_layer1();
	scroll_sts_mat_pss_dl_nebula_hangable_001_layer1();
	scroll_sts_mat_pss_dl_lava_layer1();
	scroll_sts_mat_pss_dl_Lava_layer1_area5();
	scroll_sts_mat_pss_dl_goooooooop_layer1();
}
