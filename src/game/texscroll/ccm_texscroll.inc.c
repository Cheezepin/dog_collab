#include "levels/ccm/header.h"
#include "levels/ccm/magma_thwomp/texscroll.inc.c"
#include "levels/ccm/texscroll.inc.c"
#include "levels/ccm/tank_base/texscroll.inc.c"
#include "levels/ccm/rmine/texscroll.inc.c"
void scroll_textures_ccm() {
	scroll_ccm_level_geo_magma_thwomp();
	scroll_ccm();
	scroll_ccm_level_geo_tank_base();
	scroll_ccm();
	scroll_ccm_level_geo_rmine();
}
