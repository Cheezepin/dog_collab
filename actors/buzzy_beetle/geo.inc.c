#include "src/game/envfx_snow.h"

const GeoLayout buzzy_beetle_Shell[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, buzzy_beetle_Switch_Option_Shell_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout buzzy_beetle_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_SHADOW(1, 150, 100),
			GEO_OPEN_NODE(),
				GEO_SCALE(LAYER_OPAQUE, 32768),
				GEO_OPEN_NODE(),
					GEO_SWITCH_CASE(2, geo_switch_anim_state),
					GEO_OPEN_NODE(),
						GEO_NODE_START(),
						GEO_OPEN_NODE(),
							GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 45, -17, 90, 0, 0),
							GEO_OPEN_NODE(),
								GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, buzzy_beetle_body_mesh),
								GEO_OPEN_NODE(),
									GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 94, 0, buzzy_beetle_head_mesh),
									GEO_OPEN_NODE(),
										GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 34, 0, -90, 0, 0),
										GEO_OPEN_NODE(),
											GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, buzzy_beetle_eyes_mesh),
										GEO_CLOSE_NODE(),
									GEO_CLOSE_NODE(),
									GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 57, -35, 4, 90, 0, 0),
									GEO_OPEN_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, buzzy_beetle_legLback_mesh),
									GEO_CLOSE_NODE(),
									GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 57, 55, 4, 90, 0, 0),
									GEO_OPEN_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, buzzy_beetle_legLfront_mesh),
									GEO_CLOSE_NODE(),
									GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -60, -35, 4, 90, 0, 0),
									GEO_OPEN_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, buzzy_beetle_legRback_mesh),
									GEO_CLOSE_NODE(),
									GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -60, 55, 4, 90, 0, 0),
									GEO_OPEN_NODE(),
										GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, buzzy_beetle_legRfront_mesh),
									GEO_CLOSE_NODE(),
								GEO_CLOSE_NODE(),
							GEO_CLOSE_NODE(),
						GEO_CLOSE_NODE(),
						GEO_BRANCH(1, buzzy_beetle_Shell),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, buzzy_beetle_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, buzzy_beetle_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
