void scroll_sts_mat_jrb_dl_f3d_material_065() {
	static int intervalTex0 = 12;
	static int curInterval0 = 12;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_065);

	if (--curInterval0 <= 0) {
		shift_t(mat, 18, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_jrb_dl_f3d_material_073() {
	static int intervalTex0 = 12;
	static int curInterval0 = 12;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_073);

	if (--curInterval0 <= 0) {
		shift_t(mat, 18, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_jrb_dl_f3d_material_071() {
	static int intervalTex0 = 12;
	static int curInterval0 = 12;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_071);

	if (--curInterval0 <= 0) {
		shift_t(mat, 18, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_jrb_dl_f3d_material_069() {
	static int intervalTex0 = 12;
	static int curInterval0 = 12;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_069);

	if (--curInterval0 <= 0) {
		shift_t(mat, 18, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_jrb_dl_f3d_material_067() {
	static int intervalTex0 = 12;
	static int curInterval0 = 12;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_067);

	if (--curInterval0 <= 0) {
		shift_t(mat, 18, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_jrb_dl_f3d_material_040() {
	static int intervalTex0 = 8;
	static int curInterval0 = 8;
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

void scroll_sts_mat_jrb_dl_f3d_material_062() {
	static int intervalTex0 = 12;
	static int curInterval0 = 12;
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_f3d_material_062);

	if (--curInterval0 <= 0) {
		shift_t_down(mat, 17, PACK_TILESIZE(0, 64));
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
	scroll_sts_mat_jrb_dl_f3d_material_065();
	scroll_sts_mat_jrb_dl_f3d_material_073();
	scroll_sts_mat_jrb_dl_f3d_material_071();
	scroll_sts_mat_jrb_dl_f3d_material_069();
	scroll_sts_mat_jrb_dl_f3d_material_067();
	scroll_sts_mat_jrb_dl_f3d_material_040();
	scroll_sts_mat_jrb_dl_f3d_material_031();
	scroll_sts_mat_jrb_dl_f3d_material_062();
	scroll_sts_mat_jrb_dl_f3d_material_015();
	scroll_sts_mat_jrb_dl_f3d_material_021();
}
