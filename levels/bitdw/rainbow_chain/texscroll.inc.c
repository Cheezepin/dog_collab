void scroll_sts_mat_rainbow_chain_f3d_material_layer1() {
	Gfx *mat = segmented_to_virtual(mat_rainbow_chain_f3d_material_layer1);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
};

void scroll_bitdw_level_geo_rainbow_chain() {
	scroll_sts_mat_rainbow_chain_f3d_material_layer1();
}
