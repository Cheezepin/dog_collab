
void bhv_2639PC2_TargetObj_init(void) {
	
}
void bhv_2639PC2_TargetObj_loop(void) {
	switch (gCurrAreaIndex) {
		case 1:
			outside_music();
			break;
		case 2:
			introcutscene_music();
			break;
	}
}
