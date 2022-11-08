#include "src/game/envfx_snow.h"

const GeoLayout water_switch_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, water_switch_AAAWaterSwitchContainer_mesh_layer_3),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, water_switch_AAAWaterSwitchContainer_mesh_layer_1),
		GEO_ASM(LAYER_TRANSPARENT_INTER, geo_water_switch_activation),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_ASM(LAYER_OPAQUE_INTER, geo_water_switch_activation_anim),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, water_switch_WaterSwitch_mesh_layer_3),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_switch_WaterSwitch_mesh_layer_7),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, water_switch_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, mat_revert_water_switch_switchenvmat_layer3),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, water_switch_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_INTER, water_switch_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
