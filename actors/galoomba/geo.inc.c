#include "src/game/envfx_snow.h"

const GeoLayout galoomba_000_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 48, 0, 0, galoomba_000_offset_002_mesh_mat_override_blink_black_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout galoomba_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 150, 100),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 24576),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
					GEO_OPEN_NODE(),
						GEO_SWITCH_CASE(2, geo_switch_anim_state),
						GEO_OPEN_NODE(),
							GEO_NODE_START(),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 48, 0, 0, galoomba_000_offset_002_mesh),
							GEO_CLOSE_NODE(),
							GEO_BRANCH(1, galoomba_000_switch_opt1),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, -60, -16, 45, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, galoomba_000_offset_003_mesh),
						GEO_CLOSE_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, -60, -16, -45, NULL),
						GEO_OPEN_NODE(),
							GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, galoomba_000_offset_004_mesh),
						GEO_CLOSE_NODE(),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, galoomba_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};