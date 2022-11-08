#include "src/game/envfx_snow.h"

const GeoLayout lightningbolt_sc_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightningbolt_body_mesh_layer_5_mat_override_lightning2_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lightningbolt_sc_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightningbolt_body_mesh_layer_5_mat_override_lightning3_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lightningbolt_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(3, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightningbolt_body_mesh_layer_5),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, lightningbolt_sc_opt1),
				GEO_BRANCH(1, lightningbolt_sc_opt2),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightningbolt_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
