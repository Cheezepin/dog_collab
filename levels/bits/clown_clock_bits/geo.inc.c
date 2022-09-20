#include "src/game/envfx_snow.h"

const GeoLayout clown_clock_bits_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_clock_bits_Cube_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, clown_clock_bits_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
