#include "src/game/envfx_snow.h"

const GeoLayout tube_top_geo[] = {
	GEO_CULLING_RADIUS(600),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tube_top_SemiCircleTubeTop_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tube_top_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
