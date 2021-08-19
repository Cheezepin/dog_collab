void scroll_bitdw_dl_Cube_004_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_Cube_004_mesh_layer_5_vtx_0);

	deltaY = (int)(0.19000044465065002 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bitdw_dl_first_torus_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 415;
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
void scroll_bitdw_dl_forth_torus_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 410;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_forth_torus_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bitdw_dl_second_torus_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 332;
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
void scroll_bitdw_dl_TOWER_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 427;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_TOWER_mesh_layer_5_vtx_1);

	deltaY = (int)(0.19000044465065002 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bitdw_dl_water_bottom_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 23;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_water_bottom_mesh_layer_5_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;

}
void scroll_bitdw_dl_water_top_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 23;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_water_top_mesh_layer_1_vtx_0);

	deltaX = (int)(0.10000002384185791 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;

}
void scroll_bitdw_dl_water_top_fake_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 23;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_water_top_fake_mesh_layer_5_vtx_0);

	deltaY = (int)(0.19000044465065002 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bitdw() {
	scroll_bitdw_dl_Cube_004_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_first_torus_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_forth_torus_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_second_torus_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_TOWER_mesh_layer_5_vtx_1();
	scroll_bitdw_dl_water_bottom_mesh_layer_5_vtx_0();
	scroll_bitdw_dl_water_top_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_water_top_fake_mesh_layer_5_vtx_0();
}
