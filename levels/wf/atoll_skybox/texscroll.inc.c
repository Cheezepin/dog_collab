void scroll_sts_mat_atoll_skybox_atoll_water_layer1() {
	Gfx *mat = segmented_to_virtual(mat_atoll_skybox_atoll_water_layer1);
	shift_t(mat, 15, PACK_TILESIZE(0, 3));
	shift_s(mat, 23, PACK_TILESIZE(0, 1));
	shift_t(mat, 23, PACK_TILESIZE(0, 4));
};

void scroll_wf_level_dl_atoll_skybox() {
	scroll_sts_mat_atoll_skybox_atoll_water_layer1();
}
