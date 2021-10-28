void scroll_sts_mat_hmc_dl_Conveyor_Belt() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Conveyor_Belt);
	shift_t(mat, 11, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_hmc_dl_Water() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Water);
	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_s(mat, 20, PACK_TILESIZE(0, 1));
};

void scroll_hmc() {
	scroll_sts_mat_hmc_dl_Conveyor_Belt();
	scroll_sts_mat_hmc_dl_Water();
}
