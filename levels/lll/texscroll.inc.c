void scroll_lll_dl_ZZ2_Cloud_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 14;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(lll_dl_ZZ2_Cloud_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.05000000074505806 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_gfx_lll_dl_fountain_water_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(lll_dl_fountain_water_mesh_layer_5);


	shift_s_down(mat, 16, PACK_TILESIZE(0, 1));
	shift_s(mat, 22, PACK_TILESIZE(0, 1));

};

void scroll_gfx_lll_dl_Y1_grass_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(lll_dl_Y1_grass_mesh_layer_1);
	static int intervalTex0 = 2;
	static int curInterval0 = 2;

	if (--curInterval0 <= 0) {
		shift_s(mat, 167, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}

};

void scroll_gfx_lll_dl_Y4_water_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(lll_dl_Y4_water_mesh_layer_5);


	shift_s_down(mat, 12, PACK_TILESIZE(0, 1));
	shift_s(mat, 18, PACK_TILESIZE(0, 1));

};

void scroll_gfx_lll_dl_ZZ2_Cloud_mesh_layer_5() {
	Gfx *mat = segmented_to_virtual(lll_dl_ZZ2_Cloud_mesh_layer_5);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 18, PACK_TILESIZE(0, 1));

};

void scroll_lll() {
	scroll_lll_dl_ZZ2_Cloud_mesh_layer_5_vtx_0();
	scroll_gfx_lll_dl_fountain_water_mesh_layer_5();
	scroll_gfx_lll_dl_Y1_grass_mesh_layer_1();
	scroll_gfx_lll_dl_Y4_water_mesh_layer_5();
	scroll_gfx_lll_dl_ZZ2_Cloud_mesh_layer_5();
};
