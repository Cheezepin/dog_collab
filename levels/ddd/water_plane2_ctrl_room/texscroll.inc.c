void scroll_water_plane2_ctrl_room_water_plane2_ctrl_room_mesh_layer_7_vtx_0() {
	int i = 0;
	int count = 8;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(water_plane2_ctrl_room_water_plane2_ctrl_room_mesh_layer_7_vtx_0);

	deltaX = (int)(0.10000000149011612 * 0x20) % width;
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

void scroll_sts_mat_water_plane2_ctrl_room_foggy_wahwah_layer7() {
	Gfx *mat = segmented_to_virtual(mat_water_plane2_ctrl_room_foggy_wahwah_layer7);
	shift_s(mat, 15, PACK_TILESIZE(0, 1));
	shift_t(mat, 15, PACK_TILESIZE(0, 1));
};

void scroll_ddd_level_geo_water_plane2_ctrl_room() {
	scroll_water_plane2_ctrl_room_water_plane2_ctrl_room_mesh_layer_7_vtx_0();
	scroll_sts_mat_water_plane2_ctrl_room_foggy_wahwah_layer7();
}
