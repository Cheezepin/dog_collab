void scroll_sts_mat_cloud_rains_layer5() {
	Gfx *mat = segmented_to_virtual(mat_cloud_rains_layer5);
	shift_t(mat, 16, PACK_TILESIZE(0, 17));
	shift_t(mat, 24, PACK_TILESIZE(0, 24));
};

void scroll_ddd_level_geo_cloud() {
	scroll_sts_mat_cloud_rains_layer5();
}
