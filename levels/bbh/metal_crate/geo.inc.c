#include "src/game/envfx_snow.h"

const GeoLayout metal_crate_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, metal_crate_Crate_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, metal_crate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
