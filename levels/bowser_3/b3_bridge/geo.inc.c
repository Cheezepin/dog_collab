#include "src/game/envfx_snow.h"

const GeoLayout b3_bridge_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, b3_bridge_bridge_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, b3_bridge_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
