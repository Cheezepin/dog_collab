void scroll_sts_mat_wdw_dl_Water_001_layer5() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_wdw_dl_Water_001_layer5);

	if (--curInterval0 <= 0) {
		shift_s(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}

	if (--curInterval1 <= 0) {
		shift_t_down(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_wdw() {
	scroll_sts_mat_wdw_dl_Water_001_layer5();
}
