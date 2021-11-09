#include "src/game/envfx_snow.h"

const GeoLayout circus_pole_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_OPAQUE, 0, 0, 0, circus_pole_Bone_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, circus_pole_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
