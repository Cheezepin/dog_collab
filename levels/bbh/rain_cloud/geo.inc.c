#include "src/game/envfx_snow.h"

const GeoLayout rain_cloud_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(1, rain_cloud_RainCloud_mesh_layer_1),
		GEO_DISPLAY_LIST(5, rain_cloud_RainCloud_mesh_layer_5),
		GEO_DISPLAY_LIST(5, rain_cloud_material_revert_render_settings),
		GEO_DISPLAY_LIST(1, rain_cloud_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
