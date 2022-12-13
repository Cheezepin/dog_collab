#include "src/game/envfx_snow.h"

const GeoLayout couch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0, geo2639_ModulatePrim),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, couch_Cube_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, couch_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
