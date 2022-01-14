void scroll_ddd_dl_WaterSideDecal_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 22;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_WaterSideDecal_mesh_layer_6_vtx_0);

	deltaY = (int)(0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_ddd_dl_waterdecal_layer6() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_waterdecal_layer6);
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_t(mat, 21, PACK_TILESIZE(0, 4));
};

void scroll_ddd_dl_ZZSkyOcean_mesh_layer_3_vtx_1() {
	int i = 0;
	int count = 30;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_ZZSkyOcean_mesh_layer_3_vtx_1);

	deltaY = (int)(-0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_ddd_dl_ocean_layer3() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_ocean_layer3);
	shift_t_down(mat, 25, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_monitors_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_monitors_layer5);
	shift_s(mat, 14, PACK_TILESIZE(0, 3));
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 22, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 22, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_ddd_dl_pillarspoot_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_pillarspoot_layer1);
	shift_t(mat, 22, PACK_TILESIZE(0, 5));
};

void scroll_sts_mat_ddd_dl_opaque_water_layer3() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_opaque_water_layer3);
	shift_t(mat, 15, PACK_TILESIZE(0, 3));
	shift_s(mat, 23, PACK_TILESIZE(0, 1));
	shift_t(mat, 23, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_ddd_dl_waterfallfog_layer7() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_waterfallfog_layer7);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 2));

	if (--curInterval1 <= 0) {
		shift_t(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_ddd_dl_waterfallwaveys_layer6() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_waterfallwaveys_layer6);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 2));
};

void scroll_ddd() {
	scroll_ddd_dl_WaterSideDecal_mesh_layer_6_vtx_0();
	scroll_sts_mat_ddd_dl_waterdecal_layer6();
	scroll_ddd_dl_ZZSkyOcean_mesh_layer_3_vtx_1();
	scroll_sts_mat_ddd_dl_ocean_layer3();
	scroll_sts_mat_ddd_dl_monitors_layer5();
	scroll_sts_mat_ddd_dl_pillarspoot_layer1();
	scroll_sts_mat_ddd_dl_opaque_water_layer3();
	scroll_sts_mat_ddd_dl_waterfallfog_layer7();
	scroll_sts_mat_ddd_dl_waterfallwaveys_layer6();
}
