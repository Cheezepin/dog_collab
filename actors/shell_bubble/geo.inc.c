#include "src/game/envfx_snow.h"

const GeoLayout shell_bubble_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_BILLBOARD_WITH_PARAMS(LAYER_TRANSPARENT, 0, 0, 0),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, shell_bubble_shell_bubble_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, shell_bubble_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
