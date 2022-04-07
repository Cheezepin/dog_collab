#include "src/game/envfx_snow.h"

const GeoLayout circle_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, circle_Circle_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, circle_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
