#include "src/game/envfx_snow.h"

const GeoLayout cheeze_bombwall2_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cheeze_bombwall2_opa_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, cheeze_bombwall2_opa_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cheeze_bombwall2_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, cheeze_bombwall2_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
