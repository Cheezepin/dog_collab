void scroll_sts_mat_wdw_backdrop_backdrop_cloud_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wdw_backdrop_backdrop_cloud_layer1);
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_wdw_level_dl_wdw_backdrop() {
	scroll_sts_mat_wdw_backdrop_backdrop_cloud_layer1();
}
