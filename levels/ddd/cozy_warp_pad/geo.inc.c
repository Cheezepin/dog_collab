#include "src/game/envfx_snow.h"

const GeoLayout cozy_warp_pad_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(LAYER_OPAQUE, geo_warp_pad_env_alpha),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cozy_warp_pad_WarpPad_mesh_layer_1),
		GEO_ASM(LAYER_TRANSPARENT_DECAL, geo_warp_pad_env_alpha),
		GEO_ASM(LAYER_TRANSPARENT_INTER, geo_warp_pad_env_alpha),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, cozy_warp_pad_WarpPadBeam_mesh_layer_7),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, cozy_warp_pad_WarpPadBeam_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cozy_warp_pad_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, cozy_warp_pad_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, cozy_warp_pad_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
