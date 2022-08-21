#include "src/game/envfx_snow.h"

const GeoLayout b3_balloon_platform_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, b3_balloon_platform_Bone_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, -158, -50, -138, b3_balloon_platform_Bone_001_mesh_layer_4),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_ALPHA, 162, -50, 142, b3_balloon_platform_Bone_002_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, b3_balloon_platform_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, b3_balloon_platform_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
