#include "src/game/envfx_snow.h"

const GeoLayout flippy_bitch_pss_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flippy_bitch_pss_FlippyBitchFlipper_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, flippy_bitch_pss_FlippyBitchFlipper_mesh_layer_4),
		GEO_ASM(LAYER_OPAQUE, geo_flippy_bitch_static_rot),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 0, 0, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, flippy_bitch_pss_FlippyBitchFlipperStatic_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flippy_bitch_pss_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, flippy_bitch_pss_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
