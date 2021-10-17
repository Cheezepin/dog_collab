void scroll_ddd_dl_WaterSideDecal_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 22;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_WaterSideDecal_mesh_layer_6_vtx_0);

	deltaY = (int)(0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_ddd_dl_waterdecal_layer6() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_waterdecal_layer6);
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_t(mat, 21, PACK_TILESIZE(0, 4));
};

void scroll_sts_mat_ddd_dl_rains_layer7() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_rains_layer7);
	shift_t(mat, 15, PACK_TILESIZE(0, 5));
	shift_t(mat, 23, PACK_TILESIZE(0, 9));
};

void scroll_ddd() {
	scroll_ddd_dl_WaterSideDecal_mesh_layer_6_vtx_0();
	scroll_sts_mat_ddd_dl_waterdecal_layer6();
	scroll_sts_mat_ddd_dl_rains_layer7();
}
