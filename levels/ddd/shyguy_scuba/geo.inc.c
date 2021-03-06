#include "src/game/envfx_snow.h"

const GeoLayout shyguy_scuba_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SCALE(LAYER_OPAQUE, 1311),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, shyguy_scuba_root_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1132, 1540, -554, -176, 7, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, shyguy_scuba_foot_l_skinned_mesh_layer_1),
						GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 1061, 0, 0, 91, -86),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, shyguy_scuba_foot_l_mesh_layer_1),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -1132, 1540, -554, -176, -6, 0),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_OPAQUE, shyguy_scuba_foot_r_skinned_mesh_layer_1),
						GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 1061, 0, 0, -91, 86),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, shyguy_scuba_foot_r_mesh_layer_1),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, shyguy_scuba_topbod_skinned_mesh_layer_1),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 2500, 0, shyguy_scuba_topbod_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, shyguy_scuba_topbod_mesh_layer_5),
					GEO_DISPLAY_LIST(LAYER_ALPHA, shyguy_scuba_topbod_mesh_layer_4),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 1996, 1542, 355, -56, -58, -58),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, shyguy_scuba_arm_l_mesh_layer_1),
					GEO_CLOSE_NODE(),
					GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -2184, 1542, 355, -56, 58, 58),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, shyguy_scuba_arm_r_mesh_layer_1),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, shyguy_scuba_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, shyguy_scuba_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, shyguy_scuba_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
