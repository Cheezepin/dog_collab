#include "src/game/envfx_snow.h"

const GeoLayout cloud_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SCALE_WITH_DL(LAYER_OPAQUE, 6554, cloud_Cloud_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cloud_CloudRain_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cloud_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cloud_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
