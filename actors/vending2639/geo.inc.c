#include "src/game/envfx_snow.h"

const GeoLayout vending_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, vending2639_Root_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, vending2639_Root_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, vending2639_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, vending2639_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
