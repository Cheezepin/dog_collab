#include "src/game/envfx_snow.h"

const GeoLayout bits_area_4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(3, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bits_dl_nocol_007_geo),
			GEO_BRANCH(1, bits_dl_op_004_geo),
		GEO_CLOSE_NODE(),
		GEO_BRANCH(1, cozy_bits_bg_geo),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bits_dl_nocol_007_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bits_dl_nocol_007_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bits_dl_nocol_007_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bits_dl_nocol_007_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bits_dl_op_004_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bits_dl_op_004_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bits_area_4[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, -150000, 0, -100, -150000, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bits_area_4_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bits_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bits_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, bits_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
