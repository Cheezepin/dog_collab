#include "src/game/envfx_snow.h"

const GeoLayout water_spout_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, -50, 0),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 49152),
			GEO_OPEN_NODE(),
				GEO_RENDER_RANGE(0, 5000),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_spout_b_inner_water_spout_mesh_layer_7),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_spout_top_water_spout_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_spout_b_inner_water_spout_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_spout_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
