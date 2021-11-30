#include "levels/jrb/header.h"
#include "levels/jrb/texscroll.inc.c"
#include "levels/jrb/circus_wheel/texscroll.inc.c"
#include "levels/jrb/clown_door_top/texscroll.inc.c"
void scroll_textures_jrb() {
	scroll_jrb();
	scroll_jrb();
	scroll_jrb_level_geo_circus_wheel();
	scroll_jrb_level_geo_clown_door_top();
}
