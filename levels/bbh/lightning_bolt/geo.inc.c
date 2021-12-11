#include "src/game/envfx_snow.h"

const GeoLayout lightning_bolt_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 0, 0, 0, lightning_bolt_bb_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, lightning_bolt_bolt_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lightning_bolt_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightning_bolt_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
