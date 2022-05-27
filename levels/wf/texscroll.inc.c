#include "engine/math_util.h"

void scroll_sts_mat_wf_dl_atoll_water_layer7() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_atoll_water_layer7);
	shift_t(mat, 13, PACK_TILESIZE(0, 3));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 4));
};

int i;
int time;
void scroll_wf() {
	Vtx *vertices = segmented_to_virtual(wf_dl_Water_mesh_layer_7_vtx_0);
	for (i = 1; i <= 154; i++) {
    	vertices[i].n.ob[1] = 50*((sins(4*(time-vertices[i].n.ob[2]))) - (sins(4*(time-vertices[i].n.ob[0]))))+575;
		time++;
  	}
	scroll_sts_mat_wf_dl_atoll_water_layer7();
}
