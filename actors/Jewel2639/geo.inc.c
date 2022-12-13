#include "src/game/envfx_snow.h"

const GeoLayout jewelwhatever_geo[] = {
	GEO_NODE_START(),
	GEO_SCALE(LAYER_OPAQUE, 16384),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, Jewel2639_Cone_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, Jewel2639_material_revert_render_settings),
		GEO_CLOSE_NODE(),
	GEO_END(),
};
