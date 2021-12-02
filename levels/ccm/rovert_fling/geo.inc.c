#include "src/game/envfx_snow.h"

const GeoLayout rovert_fling_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rovert_fling_Cube_033_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rovert_fling_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
