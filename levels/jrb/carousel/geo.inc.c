#include "src/game/envfx_snow.h"

const GeoLayout carousel_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, carousel_main_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_OPAQUE, 0, 175, 0, carousel_1Zgeo_mesh_layer_1),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_OPAQUE, -48, 110, 203, carousel_2Zgeo_mesh_layer_1),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_OPAQUE, -24, 107, -190, carousel_3Zgeo_mesh_layer_1),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 175, 1080, -93, 0, 0),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, carousel_horse1_mesh_layer_1),
			GEO_CLOSE_NODE(),
			GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 0, 170, -1037, 0, 90, 87),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, carousel_horse2_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, carousel_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
