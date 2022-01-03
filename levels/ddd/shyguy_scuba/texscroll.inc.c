void scroll_sts_mat_shyguy_scuba_bubsydoodles_layer4() {
	Gfx *mat = segmented_to_virtual(mat_shyguy_scuba_bubsydoodles_layer4);
	shift_s_down(mat, 13, PACK_TILESIZE(0, 2));
	shift_t(mat, 13, PACK_TILESIZE(0, 24));
	shift_s(mat, 21, PACK_TILESIZE(0, 5));
	shift_t(mat, 21, PACK_TILESIZE(0, 19));
};

void scroll_ddd_level_geo_shyguy_scuba() {
	scroll_sts_mat_shyguy_scuba_bubsydoodles_layer4();
}
