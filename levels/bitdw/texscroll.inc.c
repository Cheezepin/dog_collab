void scroll_bitdw_dl_area_2_torus_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 266;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.46000003814697266;
	float frequencyY = 0.1899999976158142;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_area_2_torus_mesh_layer_5_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

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
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_bitdw_dl_area_2_torus_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 206;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_area_2_torus_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw_dl_Cube_004_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_Cube_004_mesh_layer_5_vtx_0);

	deltaX = (int)(0.4300000071525574 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bitdw_dl_first_torus_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 443;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_first_torus_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw_dl_first_torus_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 46;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.46000003814697266;
	float frequencyY = 0.1899999976158142;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_first_torus_mesh_layer_5_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

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
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_bitdw_dl_first_torus_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 143;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_first_torus_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw_dl_first_walljumps_right_side_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_first_walljumps_right_side_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.4300000071525574 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bitdw_dl_mid_platform_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 56;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.46000003814697266;
	float frequencyY = 0.1899999976158142;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_mid_platform_mesh_layer_5_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

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
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_bitdw_dl_second_torus_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 339;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_second_torus_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw_dl_second_torus_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 8;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.46000003814697266;
	float frequencyY = 0.1899999976158142;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_second_torus_mesh_layer_5_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

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
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_bitdw_dl_second_torus_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 28;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_second_torus_001_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw_dl_Torus_023_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 768;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_Torus_023_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw_dl_Torus_023_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 64;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.46000003814697266;
	float frequencyY = 0.1899999976158142;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_Torus_023_mesh_layer_5_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

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
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_bitdw_dl_weird_lava_layer5() {
	Gfx *mat = segmented_to_virtual(mat_bitdw_dl_weird_lava_layer5);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t(mat, 13, PACK_TILESIZE(0, 2));
	shift_s(mat, 21, PACK_TILESIZE(0, 2));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_bitdw_dl_TOWER_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 373;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_TOWER_mesh_layer_5_vtx_0);

	deltaX = (int)(0.4300000071525574 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bitdw_dl_TOWER_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_TOWER_002_mesh_layer_5_vtx_0);

	deltaY = (int)(0.9400004148483276 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw_dl_walljumps_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 28;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.46000003814697266;
	float frequencyY = 0.1899999976158142;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_walljumps_mesh_layer_5_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

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
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_sts_mat_bitdw_dl_cozieswater_top_emu__layer5() {
	Gfx *mat = segmented_to_virtual(mat_bitdw_dl_cozieswater_top_emu__layer5);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s(mat, 22, PACK_TILESIZE(0, 1));
	shift_t(mat, 22, PACK_TILESIZE(0, 2));
};

void scroll_bitdw_dl_final_warp_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 630;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_final_warp_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw() {
	scroll_bitdw_dl_area_2_torus_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_area_2_torus_001_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_Cube_004_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_first_torus_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_first_torus_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_first_torus_001_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_first_walljumps_right_side_001_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_mid_platform_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_second_torus_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_second_torus_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_second_torus_001_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_Torus_023_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_Torus_023_mesh_layer_5_vtx_0();
	scroll_sts_mat_bitdw_dl_weird_lava_layer5();
	scroll_bitdw_dl_TOWER_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_TOWER_002_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_walljumps_mesh_layer_5_vtx_0();
	scroll_sts_mat_bitdw_dl_cozieswater_top_emu__layer5();
	scroll_bitdw_dl_final_warp_mesh_layer_1_vtx_0();
}
