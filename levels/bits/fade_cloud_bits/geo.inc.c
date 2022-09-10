#include "src/game/envfx_snow.h"

const GeoLayout fade_cloud_bits_switch_opt1_switch2_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, fade_cloud_bits_dl5_mesh_layer_1_mat_override_CloudGold_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fade_cloud_bits_switch_opt1_switch2_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, fade_cloud_bits_dl5_mesh_layer_1_mat_override_CloudBlue_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fade_cloud_bits_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(3, geo_switch_bparam2),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, fade_cloud_bits_dl5_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, fade_cloud_bits_switch_opt1_switch2_opt1),
				GEO_BRANCH(1, fade_cloud_bits_switch_opt1_switch2_opt2),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fade_cloud_bits_switch_opt0_switch2_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fade_cloud_bits_dl5_mesh_layer_1_mat_override_CloudGold_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fade_cloud_bits_switch_opt0_switch2_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fade_cloud_bits_dl5_mesh_layer_1_mat_override_CloudBlue_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout fade_cloud_bits_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_layer_transparency),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
					GEO_OPEN_NODE(),
						GEO_SWITCH_CASE(3, geo_switch_bparam2),
						GEO_OPEN_NODE(),
							GEO_NODE_START(),
							GEO_OPEN_NODE(),
								GEO_DISPLAY_LIST(LAYER_OPAQUE, fade_cloud_bits_dl5_mesh_layer_1),
							GEO_CLOSE_NODE(),
							GEO_BRANCH(1, fade_cloud_bits_switch_opt0_switch2_opt1),
							GEO_BRANCH(1, fade_cloud_bits_switch_opt0_switch2_opt2),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, fade_cloud_bits_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fade_cloud_bits_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, fade_cloud_bits_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
