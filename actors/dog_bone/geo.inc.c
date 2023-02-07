#include "src/game/envfx_snow.h"

const GeoLayout dog_bone_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_TRANSPARENT, 0, 0, 0, dog_bone_root_mesh_layer_1_mat_override_collected_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout dog_bone_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 128, 100),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, dog_bone_root_mesh_layer_1),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, dog_bone_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dog_bone_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, dog_bone_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
