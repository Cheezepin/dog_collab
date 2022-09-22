#include "src/game/envfx_snow.h"

const GeoLayout the_20_coin_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, the_20_coin_The20Coin_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, the_20_coin_The20Coin_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, the_20_coin_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, the_20_coin_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
