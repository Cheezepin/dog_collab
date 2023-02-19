void scroll_gfx_cozy_bits_bg_AABG3D_mesh_layer_0() {
	Gfx *mat = segmented_to_virtual(cozy_bits_bg_AABG3D_mesh_layer_0);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 18, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 18, PACK_TILESIZE(0, 1));

};

void scroll_bits_level_geo_cozy_bits_bg() {
	scroll_gfx_cozy_bits_bg_AABG3D_mesh_layer_0();
};
