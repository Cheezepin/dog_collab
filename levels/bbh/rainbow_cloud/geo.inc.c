#include "src/game/envfx_snow.h"

const GeoLayout rainbow_cloud_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, rainbow_cloud_rdl_mesh_layer_1_mat_override_CloudFace_001_0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rainbow_cloud_rdl_mesh_layer_5_mat_override_CloudFace_001_0),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout rainbow_cloud_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, rainbow_cloud_rdl_mesh_layer_1),
					GEO_OPEN_NODE(),
						GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rainbow_cloud_rdl_mesh_layer_5),
					GEO_CLOSE_NODE(),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, rainbow_cloud_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rainbow_cloud_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rainbow_cloud_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
