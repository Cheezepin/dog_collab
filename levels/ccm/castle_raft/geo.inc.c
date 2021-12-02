#include "src/game/envfx_snow.h"

const GeoLayout castle_raft_geo[] = {
	GEO_CULLING_RADIUS(9999),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_raft_Cylinder_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_raft_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
