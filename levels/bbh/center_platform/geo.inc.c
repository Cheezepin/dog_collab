#include "src/game/envfx_snow.h"

const GeoLayout center_platform_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_comit_set_brightness),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, center_platform_cdl_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, center_platform_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
