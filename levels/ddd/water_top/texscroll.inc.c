void scroll_sts_mat_water_top_water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_water_top_water_layer5);
	shift_t(mat, 13, PACK_TILESIZE(0, 4));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 5));
};

void scroll_ddd_level_geo_water_top() {
	scroll_sts_mat_water_top_water_layer5();
}
