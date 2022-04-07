#include "src/game/envfx_snow.h"

const GeoLayout lightning_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightning_Plane_mesh_layer_5),
		GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 0, 101, 0, lightning_Plane_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightning_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
