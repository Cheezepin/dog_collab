


static float TramScale = 1.0f;
void bhv_Tram2639_init(void) {
	TramScale = 1.0f;
}
void bhv_Tram2639_loop(void) {
	o->oPosX -= 70;
	o->oTimer++;
	vec3f_set(o->header.gfx.scale, TramScale, TramScale, TramScale);
	if (o->oTimer > 280) {
		TramScale -= 0.002;
	}
	if (TramScale < 0) {
		mark_obj_for_deletion(o);
	}
}
