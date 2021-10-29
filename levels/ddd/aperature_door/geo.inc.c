#include "src/game/envfx_snow.h"

const GeoLayout aperature_door_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -331, 1, 456, aperature_door_Gear1_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 331, 1, 456, aperature_door_Gear2_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 536, 1, -174, aperature_door_Gear3_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 1, -564, aperature_door_Gear4_mesh_layer_1),
			GEO_ANIMATED_PART(LAYER_OPAQUE, -536, 1, -174, aperature_door_Gear5_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, aperature_door_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
