#ifndef DDD_HEADER_H
#define DDD_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

// geo
// extern const GeoLayout ddd_geo_000450[];
// extern const GeoLayout ddd_geo_000478[];
// extern const GeoLayout ddd_geo_0004A0[];
// extern const GeoLayout ddd_geo_0004C0[];
// extern const GeoLayout ddd_geo_000570[];

// // leveldata
// extern const Gfx ddd_seg7_dl_07004D48[];
// extern const Gfx ddd_seg7_dl_070057E8[];
// extern const Gfx ddd_seg7_dl_07005C40[];
// extern const Gfx ddd_seg7_dl_07005F78[];
// extern const Gfx ddd_seg7_dl_07007408[];
// extern const Gfx ddd_seg7_dl_07007CB8[];
// extern const Gfx ddd_seg7_dl_07008C48[];
// extern const Gfx ddd_seg7_dl_07008F80[];
// extern const Gfx ddd_seg7_dl_07009030[];
// extern const Gfx ddd_seg7_dl_07009120[];
// extern const Gfx ddd_seg7_dl_07009208[];
// extern const Gfx ddd_seg7_dl_0700AF10[];
// extern const Gfx ddd_seg7_dl_0700B068[];
// extern const Gfx ddd_seg7_dl_0700BAE0[];
// extern const Gfx ddd_seg7_dl_0700CE48[];
// extern const Gfx ddd_seg7_dl_0700D2A0[];
// extern const Collision ddd_seg7_area_1_collision[];
// extern const Collision ddd_seg7_area_2_collision[];
// extern const MacroObject ddd_seg7_area_1_macro_objs[];
// extern const MacroObject ddd_seg7_area_2_macro_objs[];
// extern const Collision ddd_seg7_collision_submarine[];
// extern const Collision ddd_seg7_collision_bowser_sub_door[];
// extern const struct MovtexQuadCollection ddd_movtex_area1_water[];
// extern const struct MovtexQuadCollection ddd_movtex_area2_water[];
#include "levels/ddd/frames/frames.h"


// script
extern const LevelScript level_ddd_entry[];


#include "levels/ddd/header.inc.h"

#include "levels/ddd/cloud/geo_header.h"

#include "levels/ddd/cloud/collision_header.h"

#include "levels/ddd/water_top/collision_header.h"

#include "levels/ddd/water_top/geo_header.h"

#include "levels/ddd/water_spout/geo_header.h"

#include "levels/ddd/water_spout/collision_header.h"

#include "levels/ddd/aperature_door/geo_header.h"

#include "levels/ddd/aperature_door/collision_header.h"

#include "levels/ddd/aperature_door/anim_header.h"

#include "levels/ddd/floaty_rock/geo_header.h"

#include "levels/ddd/floaty_rock/collision_header.h"

#include "levels/ddd/shyguy_scuba/geo_header.h"

#include "levels/ddd/water_switch/collision_header.h"

#include "levels/ddd/water_switch/geo_header.h"

#include "levels/ddd/flippy_bitch/geo_header.h"

#include "levels/ddd/flippy_bitch/collision_header.h"

#include "levels/ddd/water_plane1/collision_header.h"

#include "levels/ddd/water_plane1/geo_header.h"

#include "levels/ddd/water_plane2_ctrl_room/geo_header.h"

#include "levels/ddd/water_plane2_ctrl_room/collision_header.h"

#include "levels/ddd/water_plane3_purp_room/collision_header.h"

#include "levels/ddd/water_plane3_purp_room/geo_header.h"

#include "levels/ddd/tube_top/geo_header.h"

#include "levels/ddd/tube_top/collision_header.h"

#include "levels/ddd/water_plane4_whirlpool/collision_header.h"

#include "levels/ddd/water_plane4_whirlpool/geo_header.h"

#include "levels/ddd/misc_vars/misc_vars.h"
#include "levels/ddd/the_20_coin/geo_header.h"

#include "levels/ddd/cozy_warp_pad/geo_header.h"

#include "levels/ddd/cozy_warp_pad/collision_header.h"

#endif
