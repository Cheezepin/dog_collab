#include "src/game/envfx_snow.h"

const GeoLayout laser_ring_spawner_spikes_arm[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, laser_ring_spawner_switch_option_spikes_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout laser_ring_spawner_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, laser_ring_spawner_base_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_update_laser_ring_spawner_top),
			GEO_TRANSLATE_WITH_DL(LAYER_OPAQUE, 0, 0, 0, laser_ring_spawner_top_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_SWITCH_CASE(2, geo_switch_anim_state),
				GEO_OPEN_NODE(),
					GEO_NODE_START(),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
					GEO_CLOSE_NODE(),
					GEO_BRANCH(1, laser_ring_spawner_spikes_arm),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, laser_ring_spawner_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
