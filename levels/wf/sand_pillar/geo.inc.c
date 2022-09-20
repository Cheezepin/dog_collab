#include "src/game/envfx_snow.h"

const GeoLayout sand_pillar_geo[] = {
	GEO_CULLING_RADIUS(32700),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sand_pillar_pillar_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sand_pillar_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
