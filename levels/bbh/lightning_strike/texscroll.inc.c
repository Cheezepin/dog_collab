void scroll_lightning_strike_lightning_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 17;
	int width = 16 * 0x20;
	int height = 16 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(lightning_strike_lightning_mesh_layer_1_vtx_0);

	deltaY = (int)(2.109999895095825 * 0x20 * random_float() * random_sign()) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh_level_geo_lightning_strike() {
	scroll_lightning_strike_lightning_mesh_layer_1_vtx_0();
}
