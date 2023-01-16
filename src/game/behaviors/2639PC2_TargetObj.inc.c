
void bhv_2639PC2_TargetObj_init(void) {
	
}
#include "audio/external.h"
#include "audio/load.h"

void bhv_2639PC2_TargetObj_loop(void) {
	if(gCurrLevelNum == LEVEL_BOB && gCurrCreditsEntry == NULL) {
		if (gIsConsole == 1) {
			console_music();
		} else {
			switch (gCurrAreaIndex) {
				case 0:
					challenge_music();
					break;
				case 1:
					outside_music();
					break;
				case 2: // lobby
					introcutscene_music();
					break;
				case 3: // peachs new room
					Floor2Music();
					break;
				case 4: // Soda Party
					Floor2Music();
					break;
				case 5: // Flood!
					Floor5Music();
					break;
				case 7: // Basement Sports Complex
					Floor7Music();
					break;
				case 6: // Penthouse Panic!
					Floor2Music();
					break;
			}
		}
	}
}
