#include "src/game/envfx_snow.h"

const GeoLayout rainbow_chain_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_RENDER_RANGE(-6000, 30000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, rainbow_chain_skinned_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rainbow_chain_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
