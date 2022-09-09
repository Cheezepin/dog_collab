#include "src/game/envfx_snow.h"

const GeoLayout water_plane4_whirlpool_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, water_plane4_whirlpool_water_plane4_whirlpool_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, water_plane4_whirlpool_material_revert_render_settings),
		GEO_ASM(LAYER_TRANSPARENT, geo_set_global_fog),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
