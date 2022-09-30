#include "src/game/envfx_snow.h"

const GeoLayout ktq_ring_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ktq_ring_ring_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ktq_ring_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
