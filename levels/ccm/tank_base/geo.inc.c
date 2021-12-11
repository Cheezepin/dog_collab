#include "src/game/envfx_snow.h"

const GeoLayout tank_base_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tank_base_Cube_038_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, tank_base_Cube_038_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tank_base_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, tank_base_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
