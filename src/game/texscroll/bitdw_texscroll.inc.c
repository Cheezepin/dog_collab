#include "levels/bitdw/header.h"
#include "levels/bitdw/texscroll.inc.c"
#include "levels/bitdw/rainbow_chain/texscroll.inc.c"
#include "levels/bitdw/sphere/texscroll.inc.c"
void scroll_textures_bitdw() {
	scroll_bitdw();
	scroll_bitdw_level_geo_rainbow_chain();
	scroll_bitdw_level_geo_sphere();
}
