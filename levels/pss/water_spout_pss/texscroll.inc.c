void scroll_sts_mat_water_spout_pss_cozieswater_layer7() {
	Gfx *mat = segmented_to_virtual(mat_water_spout_pss_cozieswater_layer7);
	shift_t_down(mat, 13, PACK_TILESIZE(0, 2));
	shift_s(mat, 21, PACK_TILESIZE(0, 4));
	shift_t_down(mat, 21, PACK_TILESIZE(0, 16));
};

void scroll_pss_level_geo_water_spout_pss() {
	scroll_sts_mat_water_spout_pss_cozieswater_layer7();
}
