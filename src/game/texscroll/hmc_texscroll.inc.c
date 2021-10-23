#include "levels/hmc/header.h"
#include "levels/hmc/texscroll.inc.c"
#include "game/area.h"

extern Vtx hmc_dl_Coolant_mesh_layer_5_vtx_0[];

void funny_hmc_scroll(void)
{
	Vtx *vert = segmented_to_virtual(hmc_dl_Coolant_mesh_layer_5_vtx_0);
	s32 i;

	for (i = 0; i < sizeof(hmc_dl_Coolant_mesh_layer_5_vtx_0) / sizeof(Vtx); i++)
    {
        if (i < 15)
            vert[i].v.ob[1] = -9 + (sins(gAreaUpdateCounter * 500 + (i * 20000)) * 20);
        else
            vert[i].v.ob[1] = 2333 + (sins(gAreaUpdateCounter * 500 + (i * 20000)) * 20);
    }
}


void scroll_textures_hmc() {
	scroll_hmc();
	funny_hmc_scroll();
	scroll_hmc();
}
