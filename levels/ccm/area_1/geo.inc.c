#include "src/game/envfx_snow.h"

const GeoLayout ccm_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 3384, 0, ccm_dl_bg_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 3384, 0, ccm_dl_bg_001_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -377, 760, 3026),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(0, 5000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_bridge_close_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -377, 760, 3026),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(5000, 15000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_bridge_far_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 63, 897, 1978),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(0, 4000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_crystal_hi_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -3082, 2128, 7925, 22, 41, -59),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(0, 4000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_crystal_hi_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -6047, 4235, 11606, 0, -76, 0),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(0, 4000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_crystal_hi_002_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 4381, 963, -8432, 0, 99, 0),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(0, 4000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_crystal_hi_003_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 63, 897, 1978),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(4000, 15000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_crystal_lo_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -3082, 2128, 7925, 22, 41, -59),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(4000, 15000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_crystal_lo_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, -6047, 4235, 11606, 0, -76, 0),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(4000, 15000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_crystal_lo_002_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 4381, 963, -8432, 0, 99, 0),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(4000, 15000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_crystal_lo_003_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -361, 318, 4586, ccm_dl_Cube_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_Cube_001_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11049, 6247, 4447, ccm_dl_Cube_012_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_Cube_012_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 3199, 396, 10011, ccm_dl_Cube_014_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Cube_014_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 4321, 396, 3986, ccm_dl_Cube_015_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Cube_015_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -1205, 396, -3107, ccm_dl_Cube_016_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Cube_016_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 10108, 396, -4737, 0, 21, 0, ccm_dl_Cube_017_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 12238, 396, -9224, 0, 38, 0, ccm_dl_Cube_018_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 472, 992, 7187, 0, 45, 0, ccm_dl_Cube_019_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1204, 992, 7409, 0, 90, 0, ccm_dl_Cube_020_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -1353, 992, 7251, 0, 134, 0, ccm_dl_Cube_021_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -2015, 992, 7409, 0, 90, 0, ccm_dl_Cube_022_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 10108, 396, -4737, 0, 21, 0, ccm_dl_Cube_023_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 12238, 396, -9224, 0, 38, 0, ccm_dl_Cube_024_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 10108, 396, -4737, 0, 21, 0, ccm_dl_Cube_025_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 12238, 396, -9224, 0, 38, 0, ccm_dl_Cube_026_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11049, 6247, 4447, ccm_dl_Cube_030_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 11049, 6247, 4447, ccm_dl_Cube_032_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4646, 891, -7544, ccm_dl_Cylinder_004_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_Cylinder_004_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2829, 11584, -10682, 0, 23, 0, ccm_dl_Cylinder_005_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 718, 312, -3567, 0, -12, 0),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(0, 5000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_hi_castle_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2120, 312, -6078, 0, -45, 0),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(0, 5000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_hi_castle_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 12733, 402, 1723, -10, -94, 0, ccm_dl_hi_castle_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 13963, 573, 476, -4, -83, 0, ccm_dl_hi_castle_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 15249, 593, 1260, 6, -114, 0, ccm_dl_hi_castle_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 13000, 727, -1265, 0, 3, 0, ccm_dl_hi_castle_005_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 13896, 727, -1287, 0, 85, 0, ccm_dl_hi_castle_006_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 7880, 1456, -11010, 0, 144, 0, ccm_dl_hi_castle_007_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 7229, 727, -11431, 0, 144, 0, ccm_dl_hi_castle_008_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 12831, 578, -2750, -4, 110, 0, ccm_dl_hi_castle_009_mesh_layer_1),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 718, 312, -3567, 0, -12, 0),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(5000, 15000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_lo_castle_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE(LAYER_OPAQUE, 2120, 312, -6078, 0, -45, 0),
		GEO_OPEN_NODE(),
			GEO_RENDER_RANGE(5000, 15000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_lo_castle_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5676, 3895, 8843, ccm_dl_object_board_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5676, 3895, 9074, ccm_dl_object_board_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -5676, 4073, 6871, ccm_dl_object_board_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5676, 4029, 7070, 14, 0, 0, ccm_dl_object_board_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5676, 3933, 7606, 14, 0, 0, ccm_dl_object_board_004_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_Plane_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -5876, 4261, 6485, 0, 0, 90, ccm_dl_Plane_001_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT_DECAL, 1165, 1542, 7424, -90, 0, 0, ccm_dl_Plane_003_mesh_layer_6),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT_DECAL, -2069, 1730, 7424, -90, 0, 0, ccm_dl_Plane_004_mesh_layer_6),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT_DECAL, 8815, 6556, 4221, -90, 0, 0, ccm_dl_Plane_005_mesh_layer_6),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT_DECAL, 5434, 6556, 4221, -90, 0, 0, ccm_dl_Plane_006_mesh_layer_6),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT_DECAL, 3295, 6556, 4221, -90, 0, 0, ccm_dl_Plane_007_mesh_layer_6),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT_DECAL, 2585, 11085, -862, -90, 0, 90, ccm_dl_Plane_008_mesh_layer_6),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_TRANSPARENT_DECAL, 2829, 11633, -8205, -90, 0, -180, ccm_dl_Plane_009_mesh_layer_6),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1486, 191, 1677, -21, -2, -23, ccm_dl_sunken_castle_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -2175, 191, 3475, -21, 92, -23, ccm_dl_sunken_castle_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4719, 191, 5704, -21, -130, -23, ccm_dl_sunken_castle_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 3011, 191, 7121, -21, 149, -23, ccm_dl_sunken_castle_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -104, 421, -537, 0, 90, 0, ccm_dl_terrain_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3610, 3649, 4161, ccm_dl_torch_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -4776, 3899, 3743, ccm_dl_torch_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -1833, 1052, 6711, ccm_dl_torch_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 958, 1052, 6705, ccm_dl_torch_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1136, 12207, -9256, ccm_dl_torch_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 3548, 12207, -8238, ccm_dl_torch_006_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4566, 12207, -10656, ccm_dl_torch_007_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 2154, 12207, -11674, ccm_dl_torch_008_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ccm_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 36000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, ccm_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, ccm_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, ccm_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, ccm_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, ccm_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};