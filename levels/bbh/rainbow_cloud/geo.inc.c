#include "src/game/envfx_snow.h"

const GeoLayout rainbow_cloud_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, rainbow_cloud_rdl_mesh_layer_1),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rainbow_cloud_rdl_mesh_layer_5),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rainbow_cloud_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rainbow_cloud_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
