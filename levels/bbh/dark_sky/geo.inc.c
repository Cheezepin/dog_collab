#include "src/game/envfx_snow.h"

const GeoLayout dark_sky_geo[] = {
	GEO_CULLING_RADIUS(16384),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(1, geo_comit_set_brightness),
			GEO_DISPLAY_LIST(LAYER_FORCE, dark_sky_skydl_mesh_layer_0),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_FORCE, dark_sky_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
