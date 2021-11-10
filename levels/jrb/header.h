#ifndef JRB_HEADER_H
#define JRB_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

// geo
extern const GeoLayout jrb_geo_000900[];
extern const GeoLayout jrb_geo_000918[];
extern const GeoLayout jrb_geo_000930[];
extern const GeoLayout jrb_geo_000948[];
extern const GeoLayout jrb_geo_000960[];
extern const GeoLayout jrb_geo_000978[];
extern const GeoLayout jrb_geo_000990[];
extern const GeoLayout jrb_geo_0009B0[];
extern const GeoLayout jrb_geo_0009C8[];
extern const GeoLayout jrb_geo_0009E8[];
extern const GeoLayout jrb_geo_000A00[];
extern const GeoLayout jrb_geo_000A18[];
extern const GeoLayout jrb_geo_000AFC[];

// leveldata
extern const Gfx jrb_seg7_dl_07002FD0[];
extern const Gfx jrb_seg7_dl_07004940[];
extern const Gfx jrb_seg7_dl_07004C78[];
extern const Gfx jrb_seg7_dl_070058C8[];
extern const Gfx jrb_seg7_dl_070069B0[];
extern const Gfx jrb_seg7_dl_07007570[];
extern const Gfx jrb_seg7_dl_07007718[];
extern const Gfx jrb_seg7_dl_07007AC8[];
extern const Gfx jrb_seg7_dl_07007DC8[];
extern const Gfx jrb_seg7_dl_070080F8[];
extern const Gfx jrb_seg7_dl_07008FD8[];
extern const Gfx jrb_seg7_dl_070090B0[];
extern const Gfx jrb_seg7_dl_07009A58[];
extern const Gfx jrb_seg7_dl_07009B30[];
extern const Gfx jrb_seg7_dl_0700A608[];
extern const Gfx jrb_seg7_dl_0700AC68[];
extern const Gfx jrb_seg7_dl_0700AE48[];
extern const Gfx jrb_seg7_dl_0700AFB0[];
extern const Collision jrb_seg7_area_1_collision[];
extern const MacroObject jrb_seg7_area_1_macro_objs[];
extern const Collision jrb_seg7_collision_rock_solid[];
extern const Collision jrb_seg7_collision_floating_platform[];
extern const Collision jrb_seg7_collision_floating_box[];
extern const Collision jrb_seg7_collision_in_sunken_ship_3[];
extern const Collision jrb_seg7_collision_in_sunken_ship[];
extern const Collision jrb_seg7_collision_0700CEF0[];
extern const Collision jrb_seg7_collision_in_sunken_ship_2[];
extern const Collision jrb_seg7_collision_pillar_base[];
extern const Collision jrb_seg7_collision_0700D1DC[];
extern const Trajectory jrb_seg7_trajectory_unagi_1[];
extern const Trajectory jrb_seg7_trajectory_unagi_2[];
extern const struct MovtexQuadCollection jrb_movtex_water[];
extern const struct MovtexQuadCollection jrb_movtex_intial_mist[];
extern const Gfx jrb_seg7_dl_0700EF00[];
extern const Gfx jrb_seg7_dl_0700FE48[];
extern const Gfx jrb_seg7_dl_07010548[];
extern const Collision jrb_seg7_area_2_collision[];
extern const MacroObject jrb_seg7_area_2_macro_objs[];
extern const struct MovtexQuadCollection jrb_movtex_sinked_boat_water[];

// script
extern const LevelScript level_jrb_entry[];

#include "levels/jrb/header.inc.h"

#include "carousel/geo_header.h"

#include "carousel/collision_header.h"


#include "carousel/anim_header.h"
#include "circus_pole/geo_header.h"

#include "clown_clock/geo_header.h"

#include "clown_clock/collision_header.h"

#include "clown_door_top/geo_header.h"

#include "clown_door_bottom/geo_header.h"

#include "clown_door_top/collision_header.h"

#include "clown_door_bottom/collision_header.h"

#include "circus_wheel/geo_header.h"

#include "cable_car/geo_header.h"

#include "cable_car/collision_header.h"

#include "circus_balloon/collision_header.h"

#include "circus_balloon/geo_header.h"

#include "pinwheel/geo_header.h"

#include "trapeze/geo_header.h"

#include "balloon_platform/geo_header.h"

#include "balloon_platform/collision_header.h"

#include "clown_boss/geo_header.h"


#include "clown_boss/anim_header.h"
#include "boss_curtains/geo_header.h"

#include "boss_curtains/collision_header.h"

#include "steel_gate/geo_header.h"

#include "steel_gate/collision_header.h"

#include "sad_carousel/geo_header.h"

#include "sad_pinwheel/geo_header.h"

#include "sad_clown_clock/geo_header.h"

#include "power_switch/geo_header.h"

#include "kid_toad/geo_header.h"


#include "kid_toad/anim_header.h"

#include "clown_toad/anim_header.h"
#include "clown_toad/geo_header.h"

#include "levels/jrb/circus_wheel/geo_header.h"

#include "levels/jrb/cable_car/geo_header.h"

#include "levels/jrb/clown_door_top/geo_header.h"

#include "levels/jrb/clown_clock/geo_header.h"

#include "levels/jrb/sad_clown_clock/geo_header.h"

#include "levels/jrb/circus_cannon/geo_header.h"

#include "levels/jrb/balloon_platform/collision_header.h"

#include "levels/jrb/thwomp_clock/collision_header.h"

#endif
