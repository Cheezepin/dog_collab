#include "src/game/envfx_snow.h"

const GeoLayout dog_bone_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 128, 100),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, dog_bone_bone_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dog_bone_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
