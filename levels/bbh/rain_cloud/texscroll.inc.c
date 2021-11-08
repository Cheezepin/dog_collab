void scroll_rain_cloud_raintear_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 2 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 0.15000000596046448;
	float frequencyX = 0.699999988079071;
	float offsetX = 0.0;
	Vtx *vertices = segmented_to_virtual(rain_cloud_raintear_mesh_layer_5_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;	timeX += 1;
}

void scroll_bbh_level_geo_rain_cloud() {
	scroll_rain_cloud_raintear_mesh_layer_5_vtx_0();
}
