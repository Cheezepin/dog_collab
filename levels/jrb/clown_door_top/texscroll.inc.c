void scroll_sts_mat_clown_door_top_f3d_material_031() {
	static int intervalTex0 = 15;
	static int curInterval0 = 15;
	Gfx *mat = segmented_to_virtual(mat_clown_door_top_f3d_material_031);

	if (--curInterval0 <= 0) {
		shift_t(mat, 17, PACK_TILESIZE(0, 128));
		curInterval0 = intervalTex0;
	}
};

void scroll_jrb_level_geo_clown_door_top() {
	scroll_sts_mat_clown_door_top_f3d_material_031();
}
