void scroll_sts_mat_bitfs_dl_laser() {
	Gfx *mat = segmented_to_virtual(mat_bitfs_dl_laser);
	shift_t_down(mat, 11, PACK_TILESIZE(0, 1));
};

void scroll_bitfs() {
	scroll_sts_mat_bitfs_dl_laser();
}
