#include "src/game/envfx_snow.h"

const GeoLayout trapeze_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, trapeze_Cube_021_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, trapeze_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
