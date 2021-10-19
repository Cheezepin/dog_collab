void scroll_sts_mat_sl_dl_Water_layer5() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_dl_Water_layer5);

	if (--curInterval0 <= 0) {
		shift_t_down(mat, 14, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}

	if (--curInterval1 <= 0) {
		shift_s(mat, 22, PACK_TILESIZE(0, 1));
		shift_t(mat, 22, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_sl_dl_Logs_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_dl_Logs_layer1);

	if (--curInterval0 <= 0) {
		shift_s_down(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_sl_dl_Metal_White_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_dl_Metal_White_layer1);

	if (--curInterval0 <= 0) {
		shift_t(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_sl_dl_Planks_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_dl_Planks_layer1);

	if (--curInterval0 <= 0) {
		shift_s_down(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_sl_dl_Metal_Black_layer1() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_dl_Metal_Black_layer1);

	if (--curInterval0 <= 0) {
		shift_t(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_sl_dl_Planks_Fade_layer7() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_dl_Planks_Fade_layer7);

	if (--curInterval0 <= 0) {
		shift_s_down(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_sl_dl_Logs_Fade_layer7() {
	static int intervalTex0 = 2;
	static int curInterval0 = 2;
	Gfx *mat = segmented_to_virtual(mat_sl_dl_Logs_Fade_layer7);

	if (--curInterval0 <= 0) {
		shift_s_down(mat, 13, PACK_TILESIZE(0, 1));
		curInterval0 = intervalTex0;
	}
};

void scroll_sl() {
	scroll_sts_mat_sl_dl_Water_layer5();
	scroll_sts_mat_sl_dl_Logs_layer1();
	scroll_sts_mat_sl_dl_Metal_White_layer1();
	scroll_sts_mat_sl_dl_Planks_layer1();
	scroll_sts_mat_sl_dl_Metal_Black_layer1();
	scroll_sts_mat_sl_dl_Planks_Fade_layer7();
	scroll_sts_mat_sl_dl_Logs_Fade_layer7();
}
