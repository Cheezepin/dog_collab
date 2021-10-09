#include "types.h"
#include "include/segment_symbols.h"
#include "memory.h"
#include "engine/math_util.h"
#include "src/engine/behavior_script.h"
//#include "tile_scroll.h"
#include "texscroll.h"
#include "src/game/tile_scroll.h"

#ifdef TARGET_N64
#define SCROLL_CONDITION(condition) condition
#else
#define SCROLL_CONDITION(condition) 1
#endif


#include "src/game/texscroll/ccm_texscroll.inc.c"
#include "src/game/texscroll/bitdw_texscroll.inc.c"
#include "src/game/texscroll/sl_texscroll.inc.c"
#include "src/game/texscroll/ddd_texscroll.inc.c"

void scroll_textures() {
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ccm_segment_7SegmentRomStart)) {
		scroll_textures_ccm();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_sl_segment_7SegmentRomStart)) {
		scroll_textures_sl();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ddd_segment_7SegmentRomStart)) {
		scroll_textures_ddd();
	}
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bitdw_segment_7SegmentRomStart)) {
		scroll_textures_bitdw();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bitdw_segment_7SegmentRomStart)) {
		scroll_textures_bitdw();
	}

}
