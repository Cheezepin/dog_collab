#include "src/game/envfx_snow.h"

const GeoLayout cable_car_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cable_car_Cube_008_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cable_car_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
