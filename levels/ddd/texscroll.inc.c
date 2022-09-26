void scroll_ddd_dl_WaterSideDecal_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 22;
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

void scroll_sts_mat_ddd_dl_waterdecal_001_layer6() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_waterdecal_001_layer6);
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_t(mat, 21, PACK_TILESIZE(0, 4));
};

void scroll_ddd_dl_ZZSkyOcean_mesh_layer_3_vtx_1() {
	int i = 0;
	int count = 30;
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

void scroll_sts_mat_ddd_dl_ocean_001_layer3() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_ocean_001_layer3);
	shift_t_down(mat, 23, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_monitors_001_v5_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_monitors_001_v5_layer5);
	shift_s(mat, 14, PACK_TILESIZE(0, 3));
	shift_t(mat, 14, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 22, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 22, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_ddd_dl_rains_001_layer7() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_rains_001_layer7);
	shift_t(mat, 14, PACK_TILESIZE(0, 5));
	shift_s(mat, 22, PACK_TILESIZE(0, 1));
	shift_t(mat, 22, PACK_TILESIZE(0, 9));
};

void scroll_ddd_dl_AcrossTheGap_001_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 93;
	int width = 128 * 0x20;
	int height = 512 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ddd_dl_AcrossTheGap_001_mesh_layer_1_vtx_0);

	deltaX = (int)(-0.10000000149011612 * 0x20) % width;
	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_sts_mat_ddd_dl_f3dlite_material_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_f3dlite_material_002_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_goooooooop_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_goooooooop_layer1);
	shift_t_down(mat, 13, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_f3dlite_material_003_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_f3dlite_material_003_layer5);
	shift_s_down(mat, 14, PACK_TILESIZE(0, 12));
	shift_t_down(mat, 14, PACK_TILESIZE(0, 18));
	shift_s_down(mat, 22, PACK_TILESIZE(0, 13));
	shift_t_down(mat, 22, PACK_TILESIZE(0, 19));
};

void scroll_sts_mat_ddd_dl_water_material_number_4080_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_water_material_number_4080_layer5);
	shift_s_down(mat, 13, PACK_TILESIZE(0, 1));
	shift_t(mat, 13, PACK_TILESIZE(0, 1));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_waterfallin_near_the_whirlpool_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_waterfallin_near_the_whirlpool_layer5);
	shift_t(mat, 14, PACK_TILESIZE(0, 3));
	shift_t(mat, 22, PACK_TILESIZE(0, 3));
};

void scroll_sts_mat_ddd_dl_cementwhirlpool_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_cementwhirlpool_layer1);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_f3dlite_material_004_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_f3dlite_material_004_layer5);
	shift_s_down(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ddd_dl_pillarspoot_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_pillarspoot_002_layer1);
	shift_t(mat, 21, PACK_TILESIZE(0, 5));
};

void scroll_sts_mat_ddd_dl_opaque_water_001_layer3() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_opaque_water_001_layer3);
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_ddd_dl_waterfallfog_001_layer7() {
	static int intervalTex1 = 2;
	static int curInterval1 = 2;
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_waterfallfog_001_layer7);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 13, PACK_TILESIZE(0, 2));

	if (--curInterval1 <= 0) {
		shift_t(mat, 21, PACK_TILESIZE(0, 1));
		curInterval1 = intervalTex1;
	}
};

void scroll_sts_mat_ddd_dl_waterfallwaveys_001_layer6() {
	Gfx *mat = segmented_to_virtual(mat_ddd_dl_waterfallwaveys_001_layer6);
	shift_s(mat, 13, PACK_TILESIZE(0, 1));
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_s_down(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 2));
};

void scroll_ddd() {
	scroll_ddd_dl_WaterSideDecal_mesh_layer_6_vtx_0();
	scroll_sts_mat_ddd_dl_waterdecal_001_layer6();
	scroll_ddd_dl_ZZSkyOcean_mesh_layer_3_vtx_1();
	scroll_sts_mat_ddd_dl_ocean_001_layer3();
	scroll_sts_mat_ddd_dl_monitors_001_v5_layer5();
	scroll_sts_mat_ddd_dl_rains_001_layer7();
	scroll_ddd_dl_AcrossTheGap_001_mesh_layer_1_vtx_0();
	scroll_sts_mat_ddd_dl_f3dlite_material_002_layer1();
	scroll_sts_mat_ddd_dl_goooooooop_layer1();
	scroll_sts_mat_ddd_dl_f3dlite_material_003_layer5();
	scroll_sts_mat_ddd_dl_water_material_number_4080_layer5();
	scroll_sts_mat_ddd_dl_waterfallin_near_the_whirlpool_layer5();
	scroll_sts_mat_ddd_dl_cementwhirlpool_layer1();
	scroll_sts_mat_ddd_dl_f3dlite_material_004_layer5();
	scroll_sts_mat_ddd_dl_pillarspoot_002_layer1();
	scroll_sts_mat_ddd_dl_opaque_water_001_layer3();
	scroll_sts_mat_ddd_dl_waterfallfog_001_layer7();
	scroll_sts_mat_ddd_dl_waterfallwaveys_001_layer6();
}
