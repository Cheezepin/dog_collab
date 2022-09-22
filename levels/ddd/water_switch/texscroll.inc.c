void scroll_sts_mat_water_switch_switchenvmat_layer3() {
	Gfx *mat = segmented_to_virtual(mat_water_switch_switchenvmat_layer3);
	shift_s_down(mat, 13, PACK_TILESIZE(0, 3));
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_s(mat, 21, PACK_TILESIZE(0, 4));
};

void scroll_ddd_level_geo_water_switch() {
	scroll_sts_mat_water_switch_switchenvmat_layer3();
}
