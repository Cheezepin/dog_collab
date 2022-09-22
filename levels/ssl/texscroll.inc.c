void scroll_ssl_dl_Beam_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 256 * 0x20;
	int height = 8 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Beam_mesh_layer_5_vtx_0);

	deltaX = (int)(6.279999732971191 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_Beam2_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 256 * 0x20;
	int height = 8 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Beam2_mesh_layer_5_vtx_0);

	deltaX = (int)(6.279999732971191 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_Beam2_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 256 * 0x20;
	int height = 8 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Beam2_001_mesh_layer_5_vtx_0);

	deltaX = (int)(6.279999732971191 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl_dl_Plane_002_mesh_layer_0_vtx_0() {
	int i = 0;
	int count = 157;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Plane_002_mesh_layer_0_vtx_0);

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

void scroll_ssl_dl_Cylinder_014_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 41;
	int width = 256 * 0x20;
	int height = 8 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ssl_dl_Cylinder_014_mesh_layer_5_vtx_0);

	deltaX = (int)(3.159998893737793 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ssl() {
	scroll_ssl_dl_Beam_mesh_layer_5_vtx_0();
	scroll_ssl_dl_Beam2_mesh_layer_5_vtx_0();
	scroll_ssl_dl_Beam2_001_mesh_layer_5_vtx_0();
	scroll_ssl_dl_Plane_002_mesh_layer_0_vtx_0();
	scroll_ssl_dl_Cylinder_014_mesh_layer_5_vtx_0();
}
