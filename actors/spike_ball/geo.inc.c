#include "src/game/envfx_snow.h"

const GeoLayout spike_ball_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS(LAYER_ALPHA, 0, 44, 0),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_ALPHA, 0, 0, 0, spike_ball_ball_mesh_layer_4),
				GEO_OPEN_NODE(),
					GEO_SHADOW(1, 150, 85),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 44, 0, spike_ball_spike_front_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 44, 0, spike_ball_spike_side_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spike_ball_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, spike_ball_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
