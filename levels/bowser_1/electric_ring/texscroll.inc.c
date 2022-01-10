void scroll_sts_mat_electric_ring_electricity_layer5() {
	Gfx *mat = segmented_to_virtual(mat_electric_ring_electricity_layer5);
	shift_s(mat, 13, PACK_TILESIZE(0, 5));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 4));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 3));
	shift_t(mat, 21, PACK_TILESIZE(0, 8));
};

void scroll_bowser_1_level_geo_electric_ring() {
	scroll_sts_mat_electric_ring_electricity_layer5();
}
