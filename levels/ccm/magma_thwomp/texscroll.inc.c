void scroll_magma_thwomp_Cube_009_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 71;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 1.0;
	float frequencyX = 1.0;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(magma_thwomp_Cube_009_mesh_layer_1_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(0.5 * 0x20) % height;

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

}
void scroll_ccm_level_geo_magma_thwomp() {
	scroll_magma_thwomp_Cube_009_mesh_layer_1_vtx_0();
}
