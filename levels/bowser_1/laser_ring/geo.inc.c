#include "src/game/envfx_snow.h"

const GeoLayout laser_ring[] = {
	GEO_CULLING_RADIUS(400000),
	GEO_OPEN_NODE(),
		GEO_RENDER_RANGE(-4096, 30000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, laser_ring_Circle_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, laser_ring_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
