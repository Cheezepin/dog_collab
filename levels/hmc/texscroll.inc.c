void scroll_hmc_dl_Lobby_002_mesh_layer_1_vtx_6() {
	int i = 0;
	int count = 30;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Lobby_002_mesh_layer_1_vtx_6);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_hmc_dl_Water() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_Water);
	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 12, PACK_TILESIZE(0, 1));
	shift_s(mat, 20, PACK_TILESIZE(0, 1));
};

void scroll_hmc_dl_Lobby_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 134;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Lobby_003_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_hmc_dl_Lobby_004_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 46;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_Lobby_004_mesh_layer_1_vtx_0);

	deltaY = (int)(0.10000000149011612 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_hmc() {
	scroll_hmc_dl_Lobby_002_mesh_layer_1_vtx_6();
	scroll_sts_mat_hmc_dl_Water();
	scroll_hmc_dl_Lobby_003_mesh_layer_1_vtx_0();
	scroll_hmc_dl_Lobby_004_mesh_layer_1_vtx_0();
}
