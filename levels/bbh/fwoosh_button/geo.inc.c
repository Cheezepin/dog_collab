#include "src/game/envfx_snow.h"

const GeoLayout fwoosh_button_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ASM(0, geo_comit_set_brightness),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, fwoosh_button_buttondl_mesh_layer_2),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, fwoosh_button_buttondl_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fwoosh_button_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, fwoosh_button_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
