#include "src/game/envfx_snow.h"

const GeoLayout cherry_tree_geo[] = {
	GEO_CULLING_RADIUS(500),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cherry_tree_Cherry_Tree_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, cherry_tree_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
