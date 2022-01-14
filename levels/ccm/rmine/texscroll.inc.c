void scroll_rmine_Cylinder_006_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 25;
	int width = 4 * 0x20;
	int height = 4 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(rmine_Cylinder_006_mesh_layer_1_vtx_1);

	deltaX = (int)(0.05000000074505806 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_level_geo_rmine() {
	scroll_rmine_Cylinder_006_mesh_layer_1_vtx_1();
}
