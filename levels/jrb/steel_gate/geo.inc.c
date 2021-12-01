#include "src/game/envfx_snow.h"

const GeoLayout steel_gate_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, steel_gate_Plane_255_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, steel_gate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
