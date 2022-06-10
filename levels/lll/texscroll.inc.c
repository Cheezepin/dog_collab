void scroll_lll_dl_Cloud_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 20;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(lll_dl_Cloud_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.05000000074505806 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sts_mat_lll_dl_water_001_layer5() {
	Gfx *mat = segmented_to_virtual(mat_lll_dl_water_001_layer5);
	shift_s_down(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_lll_dl_slow_mud() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	static int intervalTex1 = 5;
	static int curInterval1 = 5;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_slow_mud);

	if (--curInterval0 <= 0) {
		shift_s(mat, 11, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_lll_dl_slow_mud_002() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	static int intervalTex1 = 5;
	static int curInterval1 = 5;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_slow_mud_002);

	if (--curInterval0 <= 0) {
		shift_s(mat, 12, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_lll_dl_slow_mud_003() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	static int intervalTex1 = 5;
	static int curInterval1 = 5;
	Gfx *mat = segmented_to_virtual(mat_lll_dl_slow_mud_003);

	if (--curInterval0 <= 0) {
		shift_s(mat, 12, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}

	if (--curInterval1 <= 0) {
		shift_s(mat, -1, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_lll() {
	scroll_lll_dl_Cloud_mesh_layer_5_vtx_0();
	scroll_sts_mat_lll_dl_water_001_layer5();
	scroll_sts_mat_lll_dl_slow_mud();
	scroll_sts_mat_lll_dl_slow_mud_002();
	scroll_sts_mat_lll_dl_slow_mud_003();
}
