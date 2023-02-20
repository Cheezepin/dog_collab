void scroll_gfx_cozy_pss_bg_AABG3D_mesh_layer_0() {
	Gfx *mat = segmented_to_virtual(cozy_pss_bg_AABG3D_mesh_layer_0);


	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 11, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 17, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_pss_level_geo_cozy_pss_bg() {
	scroll_gfx_cozy_pss_bg_AABG3D_mesh_layer_0();
};
