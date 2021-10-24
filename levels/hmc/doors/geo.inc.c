#include "src/game/envfx_snow.h"

const GeoLayout doors_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
        GEO_CULLING_RADIUS(20000),
        GEO_OPEN_NODE(),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, doors_Cube_008_mesh_layer_1),
            GEO_DISPLAY_LIST(LAYER_ALPHA, doors_Cube_008_mesh_layer_4),
            GEO_DISPLAY_LIST(LAYER_OPAQUE, doors_material_revert_render_settings),
            GEO_DISPLAY_LIST(LAYER_ALPHA, doors_material_revert_render_settings),
        GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
