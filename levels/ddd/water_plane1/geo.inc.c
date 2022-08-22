#include "src/game/envfx_snow.h"

const GeoLayout water_plane1_geo[] = {
	GEO_CULLING_RADIUS(20000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_plane1_water_plane1_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_plane1_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
