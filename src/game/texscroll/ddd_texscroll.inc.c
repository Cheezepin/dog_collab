#include "levels/ddd/header.h"
#include "levels/ddd/texscroll.inc.c"
#include "levels/ddd/water_top/texscroll.inc.c"
#include "levels/ddd/water_spout/texscroll.inc.c"
#include "levels/ddd/cloud/texscroll.inc.c"
#include "levels/ddd/shyguy_scuba/texscroll.inc.c"
#include "levels/ddd/water_switch/texscroll.inc.c"
#include "levels/ddd/water_plane1/texscroll.inc.c"
#include "levels/ddd/water_plane2_ctrl_room/texscroll.inc.c"
#include "levels/ddd/water_plane3_purp_room/texscroll.inc.c"
#include "levels/ddd/water_plane4_whirlpool/texscroll.inc.c"
void scroll_textures_ddd() {
		scroll_ddd();
	scroll_ddd_level_geo_water_top();
	scroll_ddd_level_geo_water_spout();
	scroll_ddd_level_geo_cloud();
	scroll_ddd_level_geo_shyguy_scuba();
	scroll_ddd_level_geo_water_switch();
	scroll_ddd_level_geo_water_plane1();
	scroll_ddd_level_geo_water_plane2_ctrl_room();
	scroll_ddd_level_geo_water_plane3_purp_room();
	scroll_ddd_level_geo_water_plane4_whirlpool();
}
