#include "src/game/envfx_snow.h"

const GeoLayout koopatrol_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BONE(LAYER_OPAQUE, 0, -1, 0, 0, 16384, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_SHADOW(1, 201, 100),
			GEO_BONE(LAYER_OPAQUE, 2, 49, 0, 0, 16384, 0, koopatrol_Torso_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_BONE(LAYER_OPAQUE, 0, 49, -5, 0, 0, 0, koopatrol_Head_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, koopatrol_Left_Forarm_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, -13, 29, 0, -16384, 16384, 0, koopatrol_Left_Forarm_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, koopatrol_Left_Arm_skinned_mesh_layer_1),
					GEO_BONE(LAYER_OPAQUE, 0, 20, 0, 0, 0, 0, koopatrol_Left_Arm_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_BONE(LAYER_OPAQUE, 0, 22, 0, 0, 0, 0, koopatrol_spear_mesh_layer_1),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, koopatrol_Left_Leg_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, -14, 0, 8, 0, -10887, -32768, koopatrol_Left_Leg_mesh_layer_1),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, koopatrol_Right_Forarm_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, 13, 29, 0, 0, 0, -16384, koopatrol_Right_Forarm_mesh_layer_1),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_OPAQUE, koopatrol_Right_Arm_skinned_mesh_layer_1),
					GEO_BONE(LAYER_OPAQUE, 0, 20, 0, 0, 0, 0, koopatrol_Right_Arm_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, koopatrol_Right_Leg_skinned_mesh_layer_1),
				GEO_BONE(LAYER_OPAQUE, 14, 0, 8, 0, -10887, -32768, koopatrol_Right_Leg_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, koopatrol_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
