void scroll_sts_mat_cozy_warp_pad_warppad_top_layer1() {
	Gfx *mat = segmented_to_virtual(mat_cozy_warp_pad_warppad_top_layer1);
	shift_s_down(mat, 13, PACK_TILESIZE(0, 2));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_cozy_warp_pad_warppad_enveloper_layer7() {
	Gfx *mat = segmented_to_virtual(mat_cozy_warp_pad_warppad_enveloper_layer7);
	shift_s(mat, 15, PACK_TILESIZE(0, 9));
	shift_s(mat, 23, PACK_TILESIZE(0, 7));
};

void scroll_ddd_level_geo_cozy_warp_pad() {
	scroll_sts_mat_cozy_warp_pad_warppad_top_layer1();
	scroll_sts_mat_cozy_warp_pad_warppad_enveloper_layer7();
}
