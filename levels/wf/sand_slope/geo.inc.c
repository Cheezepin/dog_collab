#include "src/game/envfx_snow.h"

const GeoLayout sand_slope_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sand_slope_slope_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sand_slope_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
