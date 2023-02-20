#include "src/game/envfx_snow.h"

const GeoLayout bits_area_6_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BRANCH(1, cozy_bits_bg_geo),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bits_dl_Cube_012_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bits_dl_Cube_012_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 8681, -620, 1893, -90, 0, 0, bits_dl_Plane_006_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bits_area_6[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, -250000, 0, -100, -250000, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bits_area_6_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bits_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, bits_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
