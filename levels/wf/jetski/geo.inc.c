#include "src/game/envfx_snow.h"

const GeoLayout jetski_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 200, 70),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 65536),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, jetski_000_displaylist_mesh_layer_1),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, -1, 180, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, jetski_head_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1, 58, -34, 0, 176, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, jetski_tail_mesh_layer_1),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, jetski_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
