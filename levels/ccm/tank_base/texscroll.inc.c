#include "src/game/game_init.h"

void scroll_tank_base_Cube_038_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 48;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(tank_base_Cube_038_mesh_layer_1_vtx_1);

	deltaX = (int)(-tank_treads * 0x05) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_level_geo_tank_base() {
	scroll_tank_base_Cube_038_mesh_layer_1_vtx_1();
}
