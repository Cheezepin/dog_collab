#ifndef PSS_HEADER_H
#define PSS_HEADER_H

#include "types.h"

// geo
extern const GeoLayout pss_geo_000100[];

// leveldata
extern const Gfx pss_seg7_dl_0700A7C0[];
extern const Gfx pss_seg7_dl_0700AFA8[];
extern const Gfx pss_seg7_dl_0700B3F0[];
extern const Gfx pss_seg7_dl_0700D338[];
extern const Gfx pss_seg7_dl_0700DAD8[];
extern const Gfx pss_seg7_dl_0700E2B0[];
extern const Gfx pss_seg7_dl_0700E3E8[];
extern const Collision pss_seg7_collision[];
extern const MacroObject pss_seg7_macro_objs[];

// script
extern const LevelScript level_pss_entry[];


#include "levels/pss/header.inc.h"

#include "levels/pss/warpbox_pss/geo_header.h"

#include "levels/pss/clown_door_bottom_pss/geo_header.h"
#include "levels/pss/clown_door_bottom_pss/collision_header.h"
#include "levels/pss/clown_door_top_pss/geo_header.h"
#include "levels/pss/clown_door_top_pss/collision_header.h"
#include "levels/pss/carousel_pss/geo_header.h"
#include "levels/pss/carousel_pss/collision_header.h"
#include "levels/pss/carousel_pss/anim_header.h"
#include "levels/pss/balloon_platform_pss/geo_header.h"
#include "levels/pss/balloon_platform_pss/collision_header.h"
#include "levels/pss/pinwheel_pss/geo_header.h"
#include "levels/pss/circus_balloon_pss/geo_header.h"
#include "levels/pss/circus_balloon_pss/collision_header.h"
#include "levels/pss/trapeze_pss/geo_header.h"
#include "levels/pss/clown_clock_pss/geo_header.h"
#include "levels/pss/clown_clock_pss/collision_header.h"

extern const GeoLayout bits_octagonal_platform_geo[];
extern const Gfx bits_octagonal_dl_070135A0[];
extern const Collision bits_octagonal_collision_0701AA84[];

#endif
