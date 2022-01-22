#include "src/game/envfx_snow.h"

const GeoLayout floaty_rock_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_OPAQUE, geo_set_global_fog),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, floaty_rock_FloatyRock_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, floaty_rock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
