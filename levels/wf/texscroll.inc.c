void scroll_sts_mat_wf_dl_atoll_water_layer7() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_atoll_water_layer7);
	shift_t(mat, 15, PACK_TILESIZE(0, 3));
	shift_s(mat, 23, PACK_TILESIZE(0, 1));
	shift_t(mat, 23, PACK_TILESIZE(0, 4));
};

void scroll_wf() {
	scroll_sts_mat_wf_dl_atoll_water_layer7();
}
