#include "src/game/envfx_snow.h"

const GeoLayout snoulder_geo[] = {
	GEO_CULLING_RADIUS(5000),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 191, 500),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, snoulder_sm64_mesh_mesh),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, snoulder_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
