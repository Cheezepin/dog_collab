void scroll_sts_mat_ktq_ring_f3dlite_material() {
	Gfx *mat = segmented_to_virtual(mat_ktq_ring_f3dlite_material);
	shift_s(mat, 11, PACK_TILESIZE(0, 4));
	shift_t_down(mat, 11, PACK_TILESIZE(0, 8));
};

void scroll_wf_level_geo_ktq_ring() {
	scroll_sts_mat_ktq_ring_f3dlite_material();
}
