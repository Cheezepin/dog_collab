#include "src/game/envfx_snow.h"

const GeoLayout ball2639_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 128, 160),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, Ball2639_Icosphere_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, Ball2639_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
