#include "src/game/envfx_snow.h"

const GeoLayout cheezebombwall_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cheezebombwall_bomb1_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, cheezebombwall_bomb1_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cheezebombwall_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, cheezebombwall_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
