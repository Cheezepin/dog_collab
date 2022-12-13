#include "src/game/envfx_snow.h"

const GeoLayout elevator_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, elevator__THE_actual_elevator_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, elevator__THE_actual_elevator_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, elevator_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, elevator_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
