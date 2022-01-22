void scroll_lightning_Plane_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(lightning_Plane_mesh_layer_5_vtx_0);

	deltaY = (int)(1.420000433921814 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_lightning_electricity_layer5() {
	Gfx *mat = segmented_to_virtual(mat_lightning_electricity_layer5);
	shift_t_down(mat, 13, PACK_TILESIZE(0, 4));
	shift_t(mat, 21, PACK_TILESIZE(0, 8));
};

void scroll_bowser_1_level_geo_lightning() {
	scroll_lightning_Plane_mesh_layer_5_vtx_0();
	scroll_sts_mat_lightning_electricity_layer5();
}
