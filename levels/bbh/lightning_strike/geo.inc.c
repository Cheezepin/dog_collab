#include "src/game/envfx_snow.h"

const GeoLayout lightning_strike_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lightning_strike_lightning_mesh_layer_1_mat_override_Blank_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lightning_strike_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(10, geo_update_layer_transparency),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightning_strike_mark_mesh_layer_5),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, lightning_strike_lightning_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, lightning_strike_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lightning_strike_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lightning_strike_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightning_strike_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
