void scroll_sts_mat_bits_dl_laser_002() {
	Gfx *mat = segmented_to_virtual(mat_bits_dl_laser_002);
	shift_t_down(mat, 11, PACK_TILESIZE(0, 1));
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

void scroll_bits_dl_Cube_010_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_010_mesh_layer_5_vtx_0);

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

void scroll_bits_dl_Cube_022_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_022_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_023_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_023_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits_dl_Cube_024_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bits_dl_Cube_024_mesh_layer_5_vtx_0);

	deltaY = (int)(-1.0099999904632568 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bits() {
	scroll_sts_mat_bits_dl_laser_002();
	scroll_sts_mat_bits_dl_atoll_water_layer5();
	scroll_sts_mat_bits_dl_atoll_floor_layer5();
	scroll_bits_dl_Cube_001_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_005_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_007_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_008_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_009_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_010_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_011_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_013_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_022_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_023_mesh_layer_5_vtx_0();
	scroll_bits_dl_Cube_024_mesh_layer_5_vtx_0();
}
