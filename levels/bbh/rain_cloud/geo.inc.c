#include "src/game/envfx_snow.h"

const GeoLayout rain_cloud_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rain_cloud_rainface_mesh_layer_5_mat_override_CryEyes3_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout rain_cloud_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, rain_cloud_rainbody_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rain_cloud_raintear_mesh_layer_5),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rain_cloud_rainface_mesh_layer_5),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, rain_cloud_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rain_cloud_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rain_cloud_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
