#include "src/game/envfx_snow.h"

const GeoLayout cloud_rainbow_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cloud_rainbow_Rainbow_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, cloud_rainbow_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
