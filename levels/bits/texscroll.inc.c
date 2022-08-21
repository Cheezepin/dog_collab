void scroll_sts_mat_bits_dl_f3d_material_062() {
	static int intervalTex0 = 12;
	static int curInterval0 = 12;
	Gfx *mat = segmented_to_virtual(mat_bits_dl_f3d_material_062);

	if (--curInterval0 <= 0) {
		shift_t_down(mat, 18, PACK_TILESIZE(0, 64));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_bits_dl_f3d_material_015() {
	static int intervalTex0 = 45;
	static int curInterval0 = 45;
	Gfx *mat = segmented_to_virtual(mat_bits_dl_f3d_material_015);

	if (--curInterval0 <= 0) {
		shift_t(mat, 18, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_sts_mat_bits_dl_f3d_material_021() {
	static int intervalTex0 = 45;
	static int curInterval0 = 45;
	Gfx *mat = segmented_to_virtual(mat_bits_dl_f3d_material_021);

	if (--curInterval0 <= 0) {
		shift_t(mat, 11, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_bits() {
	scroll_sts_mat_bits_dl_f3d_material_062();
	scroll_sts_mat_bits_dl_f3d_material_015();
	scroll_sts_mat_bits_dl_f3d_material_021();
}
