void scroll_sts_mat_jrb_dl_f3d_material_040() {
	static int intervalTex0 = 3;
	static int curInterval0 = 3;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_040);

	if (--curInterval0 <= 0) {
		shift_t(mat, 11, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_jrb_dl_f3d_material_031() {
	static int intervalTex0 = 15;
	static int curInterval0 = 15;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_031);

	if (--curInterval0 <= 0) {
		shift_t(mat, 17, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_jrb_dl_f3d_material_015() {
	static int intervalTex0 = 45;
	static int curInterval0 = 45;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_015);

	if (--curInterval0 <= 0) {
		shift_t(mat, 18, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_jrb_dl_f3d_material_021() {
	static int intervalTex0 = 45;
	static int curInterval0 = 45;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_021);

	if (--curInterval0 <= 0) {
		shift_t(mat, 11, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_jrb() {
	scroll_sts_mat_jrb_dl_f3d_material_040();
	scroll_sts_mat_jrb_dl_f3d_material_031();
	scroll_sts_mat_jrb_dl_f3d_material_015();
	scroll_sts_mat_jrb_dl_f3d_material_021();
}
