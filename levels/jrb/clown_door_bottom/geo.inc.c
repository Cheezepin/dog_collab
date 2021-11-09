#include "src/game/envfx_snow.h"

const GeoLayout clown_door_bottom_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_door_bottom_Cube_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_door_bottom_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
