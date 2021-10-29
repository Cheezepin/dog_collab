#include "src/game/envfx_snow.h"

const GeoLayout bitfs_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(4, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bitfs_dl_a_geo),
			GEO_BRANCH(1, bitfs_dl_b_geo),
			GEO_BRANCH(1, bitfs_dl_c_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bitfs_dl_a_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bitfs_dl_nocol_003_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bitfs_dl_op_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bitfs_dl_b_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bitfs_dl_nocol_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bitfs_dl_op_001_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bitfs_dl_c_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bitfs_dl_nocol_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bitfs_dl_op_002_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bitfs_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_SNOW_MOUNTAINS, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -500, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bitfs_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bitfs_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
