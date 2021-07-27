#include "src/game/envfx_snow.h"

const GeoLayout laser_ring_geo[] = {
	GEO_CULLING_RADIUS(0x7FFF),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(5, laser_ring_Plane_mesh_layer_5),
		GEO_DISPLAY_LIST(5, laser_ring_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
