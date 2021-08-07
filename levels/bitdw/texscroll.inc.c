void scroll_bitdw_dl_final_pipe_torus_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 261;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_final_pipe_torus_mesh_layer_1_vtx_0);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

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
	int count = 494;
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
	int count = 437;
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
	int count = 365;
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
void scroll_bitdw_dl_second_torus_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 26;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_second_torus_mesh_layer_1_vtx_1);

	deltaY = (int)(1.0299999713897705 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;

}
void scroll_bitdw_dl_second_torus_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 26;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 1.0;
	float frequencyX = 1.0;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 1.0;
	float frequencyY = 1.0;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_second_torus_mesh_layer_1_vtx_2);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
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
	currentX += deltaX;
	timeX += 1;
	currentY += deltaY;
	timeY += 1;

}
void scroll_bitdw_dl_third_torus_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 725;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_third_torus_mesh_layer_1_vtx_0);

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
	scroll_bitdw_dl_final_pipe_torus_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_first_torus_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_forth_torus_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_second_torus_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_second_torus_mesh_layer_1_vtx_1();
	scroll_bitdw_dl_second_torus_mesh_layer_1_vtx_2();
	scroll_bitdw_dl_third_torus_mesh_layer_1_vtx_0();
}
