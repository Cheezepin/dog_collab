void scroll_sts_mat_cozy_pss_bg_cozyskybox_layer0() {
	Gfx *mat = segmented_to_virtual(mat_cozy_pss_bg_cozyskybox_layer0);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_pss_level_geo_cozy_pss_bg() {
	scroll_sts_mat_cozy_pss_bg_cozyskybox_layer0();
}
