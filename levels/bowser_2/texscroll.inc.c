void scroll_sts_mat_bowser_2_dl_snow() {
	Gfx *mat = segmented_to_virtual(mat_bowser_2_dl_snow);
	shift_s_down(mat, 18, PACK_TILESIZE(0, 40));
};

void scroll_sts_mat_bowser_2_dl_trees() {
	Gfx *mat = segmented_to_virtual(mat_bowser_2_dl_trees);
	shift_s_down(mat, 11, PACK_TILESIZE(0, 20));
};

void scroll_bowser_2() {
	scroll_sts_mat_bowser_2_dl_snow();
	scroll_sts_mat_bowser_2_dl_trees();
}
