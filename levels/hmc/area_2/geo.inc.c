#include "src/game/envfx_snow.h"

const GeoLayout hmc_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(8, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, hmc_dl_Area_2_Room_1_geo),
			GEO_BRANCH(1, hmc_dl_Area_2_Room_2_geo),
			GEO_BRANCH(1, hmc_dl_Area_2_Room_3_geo),
			GEO_BRANCH(1, hmc_dl_Area_2_Room_4_geo),
			GEO_BRANCH(1, hmc_dl_Area_2_Room_5_geo),
			GEO_BRANCH(1, hmc_dl_Area_2_Room_6_geo),
			GEO_BRANCH(1, hmc_dl_Dangling_Chain_geo),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 901, 4945, -3788, hmc_dl_Cube_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 850, 4560, -1697, hmc_dl_Doorways_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_Area_2_Room_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2916, 4378, -974, 0, 12, 0, hmc_dl_Block_Prop_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 850, 4560, -1697, hmc_dl_Lobby_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_dl_Lobby_mesh_layer_2),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -1087, 4329, -692, 0, -6, 0, hmc_dl_Lobby_Crates_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 908, 7519, -203, hmc_dl_Lobby_006_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -728, 4251, -469, 0, 72, 0, hmc_dl_Plane_003_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_Area_2_Room_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -4188, 7000, -57, 0, 0, -90, hmc_dl_Chains_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3513, 5104, -1734, hmc_dl_Lobby_002_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Lobby_002_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -5670, 4251, -106, hmc_dl_Plane_004_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -3653, 4857, -597, 0, 9, 0, hmc_dl_Shipping_Containers_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -3633, 4416, -3338, 0, 90, 0, hmc_dl_Shipping_Crate_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -4436, 4567, -1744, 0, 21, 0, hmc_dl_Warehouse_Crates_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_Area_2_Room_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 139, 5622, -5988, 0, 0, -90, hmc_dl_Chains_002_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 901, 4464, -6421, hmc_dl_Coolant_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 184, 6461, -7406, 0, 90, -90, hmc_dl_Coolant_Pipes_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1935, 6461, -6570, 0, 90, -90, hmc_dl_Coolant_Pipes_001_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 184, 6461, -7406, 0, 90, -90, hmc_dl_Coolant_Pipes_003_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 829, 8916, -5469, hmc_dl_Cube_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_Cube_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 854, 8396, -7068, 0, 12, 0, hmc_dl_Cube_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 265, 4632, -5259, 0, -43, 0, hmc_dl_Engine_Room_Crates_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 850, 4560, -1697, hmc_dl_Generator_Climb_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Generator_Climb_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 838, 4587, -4879, hmc_dl_Generator_Room_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_Generator_Room_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 838, 4587, -4879, hmc_dl_Generator_Room_001_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 1315, 8353, -7023, 0, 30, 0, hmc_dl_Plane_002_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -349, 6461, -7406, 0, 90, -90, hmc_dl_Power_Cables_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_Area_2_Room_4_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -3360, 4390, -6702, hmc_dl_Assembly_Room_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -761, 4297, -4664, 0, -15, -90, hmc_dl_Block_Prop_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -927, 4311, -7477, 0, 90, -90, hmc_dl_Coolant_Pipes_002_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -6959, 3675, -7914, hmc_dl_Cube_004_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Cube_004_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -2991, 4094, -8104, hmc_dl_Cylinder_001_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_Cylinder_001_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -8199, 3825, -6393, 0, -90, 0, hmc_dl_Generator_Climb_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -5607, 3825, -7555, 0, -180, 0, hmc_dl_Lobby_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_Area_2_Room_5_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5588, 6014, -9570, hmc_dl_Block_Prop_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 5941, 5429, -7575, hmc_dl_Broken_Glass_mesh_layer_6),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 9731, 6234, -8468, 0, -2, 0, hmc_dl_Cube_006_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 3459, 3291, -10554, 0, 0, -90, hmc_dl_Dangling_Chain_001_mesh_layer_4),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 4775, 5057, -8230, hmc_dl_Generator_Climb_002_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 5652, 5497, -10410, 0, -180, 0, hmc_dl_Lobby_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, -859, 6464, -8525, hmc_dl_Lobby_005_mesh_layer_4),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, 5571, 4251, -7769, 0, 73, 0, hmc_dl_Plane_006_mesh_layer_4),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_Plane_006_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 5941, 5428, -7575, hmc_dl_Unpacking_Room_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_Unpacking_Room_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_Unpacking_Room_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 4366, 4457, -4035, hmc_dl_Unpacking_Room_001_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_ALPHA, 5941, 5428, -7575, hmc_dl_Unpacking_Room_003_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_Area_2_Room_6_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1142, 5506, -6063, hmc_dl_Assembly_Room_001_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1142, 5506, -6063, hmc_dl_Assembly_Room_004_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 765, 4501, -9265, hmc_dl_Cube_003_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_dl_Dangling_Chain_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_ALPHA, -7523, 6831, -3386, 0, 0, -90, hmc_dl_Dangling_Chain_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout hmc_area_2[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, -13138, 0, -1000, -13138, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, hmc_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, hmc_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, hmc_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
