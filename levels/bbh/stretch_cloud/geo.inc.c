#include "src/game/envfx_snow.h"

const GeoLayout stretch_cloud_switch_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, stretch_cloud_stretchface_mesh_layer_4_mat_override_StretchFace2_0),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout stretch_cloud_geo[] = {
	GEO_CULLING_RADIUS(4096),
	GEO_OPEN_NODE(),
		GEO_NODE_START(),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, stretch_cloud_stretchdl_mesh_layer_1),
			GEO_SWITCH_CASE(2, geo_switch_anim_state),
			GEO_OPEN_NODE(),
				GEO_NODE_START(),
				GEO_OPEN_NODE(),
					GEO_DISPLAY_LIST(LAYER_ALPHA, stretch_cloud_stretchface_mesh_layer_4),
				GEO_CLOSE_NODE(),
				GEO_BRANCH(1, stretch_cloud_switch_opt1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, stretch_cloud_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, stretch_cloud_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
