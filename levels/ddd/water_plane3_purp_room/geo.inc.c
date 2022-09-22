#include "src/game/envfx_snow.h"

const GeoLayout water_plane3_purp_room_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_plane3_purp_room_water_plane3_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_plane3_purp_room_material_revert_render_settings),
		GEO_ASM(LAYER_TRANSPARENT_INTER, geo_set_global_fog),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
