#include "src/game/envfx_snow.h"

const GeoLayout water_plane2_ctrl_room_geo[] = {
	GEO_CULLING_RADIUS(1200),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_plane2_ctrl_room_water_plane2_ctrl_room_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_plane2_ctrl_room_material_revert_render_settings),
		GEO_ASM(LAYER_TRANSPARENT_INTER, geo_set_global_fog),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
