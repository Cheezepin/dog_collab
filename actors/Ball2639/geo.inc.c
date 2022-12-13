#include "src/game/envfx_snow.h"

const GeoLayout ball2639_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE(0x00, 0, 76, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, Ball2639__0_0_node_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, Ball2639_material_revert_render_settings),
			GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
