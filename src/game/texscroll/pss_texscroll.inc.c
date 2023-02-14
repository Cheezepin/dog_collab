#include "levels/pss/header.h"
#include "levels/pss/cozy_pss_bg/texscroll.inc.c"
#include "levels/pss/water_spout_pss/texscroll.inc.c"
#include "levels/pss/texscroll.inc.c"
void scroll_textures_pss() {
	scroll_pss_level_geo_cozy_pss_bg();
	scroll_pss_level_geo_water_spout_pss();
	scroll_pss();
}
