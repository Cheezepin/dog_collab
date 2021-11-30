#include "src/game/envfx_snow.h"

const GeoLayout circus_wheel_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, circus_wheel_Cube_007_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, circus_wheel_Cube_007_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, circus_wheel_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, circus_wheel_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
