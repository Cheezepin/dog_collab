#include "src/game/envfx_snow.h"

const GeoLayout electric_ring_geo[] = {
	GEO_CULLING_RADIUS(400000),
	GEO_OPEN_NODE(),
		GEO_RENDER_RANGE(-6000, 10000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_ring_skinned_001_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, electric_ring_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
