void scroll_gfx_wf_dl_ocean_mesh_layer_7() {
	Gfx *mat = segmented_to_virtual(wf_dl_ocean_mesh_layer_7);


	shift_t(mat, 16, PACK_TILESIZE(0, 3));
	shift_s(mat, 22, PACK_TILESIZE(0, 1));
	shift_t(mat, 22, PACK_TILESIZE(0, 4));

};

void scroll_gfx_wf_dl_water_mesh_layer_7() {
	Gfx *mat = segmented_to_virtual(wf_dl_water_mesh_layer_7);


	shift_t(mat, 12, PACK_TILESIZE(0, 3));
	shift_s(mat, 18, PACK_TILESIZE(0, 1));
	shift_t(mat, 18, PACK_TILESIZE(0, 4));

};

void scroll_gfx_wf_dl_Interior_Volcano_mesh_layer_1() {
	Gfx *mat = segmented_to_virtual(wf_dl_Interior_Volcano_mesh_layer_1);


	shift_t(mat, 19, PACK_TILESIZE(0, 1));
	shift_s(mat, 24, PACK_TILESIZE(0, 1));
	shift_t(mat, 24, PACK_TILESIZE(0, 2));

};

void scroll_wf() {
	scroll_gfx_wf_dl_ocean_mesh_layer_7();
	scroll_gfx_wf_dl_water_mesh_layer_7();
	scroll_gfx_wf_dl_Interior_Volcano_mesh_layer_1();
};
