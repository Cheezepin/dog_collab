#include "src/game/envfx_snow.h"

const GeoLayout rcsign_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, rcsign_x_mesh_layer_6_mat_override__3_checkmark_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout rcsign_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rcsign_root_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, rcsign_root_mesh_layer_6),
		GEO_SWITCH_CASE(0, geo_switch_is_red_coin_collected),
		GEO_OPEN_NODE(),
			GEO_NODE_START(),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, rcsign_x_mesh_layer_6),
			GEO_CLOSE_NODE(),
			GEO_BRANCH(1, rcsign_switch_opt1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rcsign_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, rcsign_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
