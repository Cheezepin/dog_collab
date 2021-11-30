void scroll_sts_mat_circus_wheel_f3d_material_036() {
	Gfx *mat = segmented_to_virtual(mat_circus_wheel_f3d_material_036);
	shift_t_down(mat, 19, PACK_TILESIZE(0, 16));
};

void scroll_sts_mat_circus_wheel_f3d_material_035() {
	Gfx *mat = segmented_to_virtual(mat_circus_wheel_f3d_material_035);
	shift_t_down(mat, 19, PACK_TILESIZE(0, 12));
};

void scroll_sts_mat_circus_wheel_f3d_material_034() {
	static int intervalTex0 = 40;
	static int curInterval0 = 40;
	Gfx *mat = segmented_to_virtual(mat_circus_wheel_f3d_material_034);

	if (--curInterval0 <= 0) {
		shift_t_down(mat, 18, PACK_TILESIZE(0, 64));
		curInterval0 = intervalTex0;
	}
};

void scroll_jrb_level_geo_circus_wheel() {
	scroll_sts_mat_circus_wheel_f3d_material_036();
	scroll_sts_mat_circus_wheel_f3d_material_035();
	scroll_sts_mat_circus_wheel_f3d_material_034();
}
