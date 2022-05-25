#include "src/game/envfx_snow.h"

const GeoLayout lll_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_Cloud_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_court_bridge_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_court_bridge_rope_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_crate_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_cutout_bg_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_flower_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_fountain_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_fountain_water_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_Grass_Decal_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, lll_dl_Mud_Vis_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_Mud_Vis_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, lll_dl_Mud_Vis_001_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_platforms_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_platforms_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_platforms_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_pole_vis_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_Shadow_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_FORCE, lll_dl_skybox_mesh_layer_0),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, lll_dl_statue_vis_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_water_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, lll_dl_windows_doors_mesh_layer_2),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout lll_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 120000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, lll_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_FORCE, lll_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, lll_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, lll_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, lll_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lll_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, lll_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
