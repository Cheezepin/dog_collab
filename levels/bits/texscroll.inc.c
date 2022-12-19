void scroll_sts_mat_bits_dl_laser_002() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_laser_002);
	shift_t_down(mat, 11, PACK_TILESIZE(0, 1));
};

void scroll_bits_dl_inner_torus_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 360;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_inner_torus_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_inner_torus_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 360;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_inner_torus_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_shock_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 60;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_shock_mesh_layer_5_vtx_0);

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

void scroll_sts_mat_bits_dl_electricity_layer5() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_electricity_layer5);
	shift_s(mat, 13, PACK_TILESIZE(0, 5));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 4));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 3));
	shift_t(mat, 21, PACK_TILESIZE(0, 8));
};

void scroll_bits_dl_shock_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 60;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_shock_001_mesh_layer_5_vtx_0);

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

void scroll_sts_mat_bits_dl_f3d_material_v4_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_f3d_material_v4_layer1);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_bits_dl_former_metal_v4_001_layer5() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_former_metal_v4_001_layer5);
	shift_s(mat, 20, PACK_TILESIZE(0, 1));
};

void scroll_bits_dl_Torus_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Torus_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Torus_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Torus_003_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Torus_004_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Torus_004_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Torus_005_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Torus_005_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Torus_006_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Torus_006_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Torus_007_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Torus_007_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_bits_dl_Lava_layer1_area6() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_Lava_layer1_area6);
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 23, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 23, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_bits_dl_atoll_water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_atoll_water_layer5);
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 4));
};

void scroll_sts_mat_bits_dl_atoll_floor_layer5() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_atoll_floor_layer5);
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 4));
};

void scroll_bits_dl_Cube_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_001_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_005_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_005_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_007_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_007_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_008_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_008_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_009_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_009_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_011_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_011_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_013_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_013_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_bits_dl_f3d_material_062() {
	static int intervalTex0 = 12;
	static int curInterval0 = 12;
	Gfx *mat = segmented_to_virtual(mat_bits_dl_f3d_material_062);

	if (--curInterval0 <= 0) {
		shift_t_down(mat, 18, PACK_TILESIZE(0, 64));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_bits_dl_f3d_material_015() {
	static int intervalTex0 = 45;
	static int curInterval0 = 45;
	Gfx *mat = segmented_to_virtual(mat_bits_dl_f3d_material_015);

	if (--curInterval0 <= 0) {
		shift_t(mat, 18, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_bits_dl_f3d_material_021() {
	static int intervalTex0 = 45;
	static int curInterval0 = 45;
	Gfx *mat = segmented_to_virtual(mat_bits_dl_f3d_material_021);

	if (--curInterval0 <= 0) {
		shift_t(mat, 11, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_bits_dl_nebula_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_nebula_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_bits_dl_nebula_not_slippery_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_nebula_not_slippery_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_bits_dl_slide_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_slide_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_bits_dl_nebula_hangable_001_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_nebula_hangable_001_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_bits_dl_lava_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_lava_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_bits() {
	scroll_sts_mat_bits_dl_laser_002();
	scroll_bits_dl_inner_torus_mesh_layer_1_vtx_0();
	scroll_bits_dl_inner_torus_001_mesh_layer_1_vtx_0();
	scroll_bits_dl_shock_mesh_layer_5_vtx_0();
	scroll_sts_mat_bits_dl_electricity_layer5();
	scroll_bits_dl_shock_001_mesh_layer_5_vtx_0();
	scroll_sts_mat_bits_dl_f3d_material_v4_layer1();
	scroll_sts_mat_bits_dl_former_metal_v4_001_layer5();
	scroll_bits_dl_Torus_001_mesh_layer_1_vtx_0();
	scroll_bits_dl_Torus_003_mesh_layer_1_vtx_0();
	scroll_bits_dl_Torus_004_mesh_layer_1_vtx_0();
	scroll_bits_dl_Torus_005_mesh_layer_1_vtx_0();
	scroll_bits_dl_Torus_006_mesh_layer_1_vtx_0();
	scroll_bits_dl_Torus_007_mesh_layer_1_vtx_0();
	scroll_sts_mat_bits_dl_Lava_layer1_area6();
	scroll_sts_mat_bits_dl_atoll_water_layer5();
	scroll_sts_mat_bits_dl_atoll_floor_layer5();
	scroll_bits_dl_Cube_001_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_005_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_007_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_008_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_009_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_011_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_013_mesh_layer_5_vtx_0();
	scroll_sts_mat_bits_dl_f3d_material_062();
	scroll_sts_mat_bits_dl_f3d_material_015();
	scroll_sts_mat_bits_dl_f3d_material_021();
	scroll_sts_mat_bits_dl_nebula_layer1();
	scroll_sts_mat_bits_dl_nebula_not_slippery_layer1();
	scroll_sts_mat_bits_dl_slide_layer1();
	scroll_sts_mat_bits_dl_nebula_hangable_001_layer1();
	scroll_sts_mat_bits_dl_lava_layer1();
}
