#include "src/game/envfx_snow.h"

const GeoLayout tram2639_geo[] = {
	GEO_CULLING_RADIUS(20000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tram2639__Streetcar_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, tram2639__Streetcar_mesh_layer_2),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tram2639_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, tram2639_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
