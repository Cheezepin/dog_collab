#include "src/game/envfx_snow.h"

const GeoLayout floor_door_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, floor_door_FloorDoor_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, floor_door_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
