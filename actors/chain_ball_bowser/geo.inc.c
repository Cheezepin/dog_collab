#include "src/game/envfx_snow.h"

const GeoLayout metallic_ball_bowser_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x96, 60),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, chain_ball_bowser_Plane_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, chain_ball_bowser_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
