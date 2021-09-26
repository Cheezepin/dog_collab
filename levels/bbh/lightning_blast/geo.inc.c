#include "src/game/envfx_snow.h"

const GeoLayout lightning_blast_geo[] = {
	GEO_CULLING_RADIUS(8192),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightning_blast_Blast_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, lightning_blast_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
