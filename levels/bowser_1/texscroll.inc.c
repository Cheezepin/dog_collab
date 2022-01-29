void scroll_sts_mat_bowser_1_dl_f3d_material_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bowser_1_dl_f3d_material_layer1);
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_bowser_1_dl_cozieswater_top_emu__layer5() {
	Gfx *mat = segmented_to_virtual(mat_bowser_1_dl_cozieswater_top_emu__layer5);
	shift_t(mat, -1, PACK_TILESIZE(0, 1));
	shift_s(mat, -1, PACK_TILESIZE(0, 1));
};

void scroll_bowser_1() {
	scroll_sts_mat_bowser_1_dl_f3d_material_layer1();
	scroll_sts_mat_bowser_1_dl_cozieswater_top_emu__layer5();
}
