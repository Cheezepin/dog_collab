void scroll_sts_mat_cloud_rains_002_layer5() {
	Gfx *mat = segmented_to_virtual(mat_cloud_rains_002_layer5);
	shift_t(mat, 16, PACK_TILESIZE(0, 17));
	shift_t(mat, 24, PACK_TILESIZE(0, 24));
};

void scroll_sts_mat_cloud_windydoodle_001_layer5() {
	Gfx *mat = segmented_to_virtual(mat_cloud_windydoodle_001_layer5);
	shift_s(mat, 13, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 21, PACK_TILESIZE(0, 2));
};

void scroll_ddd_level_geo_cloud() {
	scroll_sts_mat_cloud_rains_002_layer5();
	scroll_sts_mat_cloud_windydoodle_001_layer5();
}
