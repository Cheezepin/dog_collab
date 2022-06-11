#include "src/game/puppycam2.h"
#include "2639_defs.h"
void Cam2639_Main(struct gPuppyStruct *);
///This is the bit that defines where the angles happen. They're basically environment boxes that dictate camera behaviour.
///Permaswap is a boolean that simply determines wether or not when the camera changes at this point it stays changed. 0 means it resets when you leave, and 1 means it stays changed.
///The camera position fields accept "32767" as an ignore flag.
///The script supports anything that does not take an argument. It's reccomended to keep the scripts in puppycam_scripts.inc.c for the sake of cleanliness.
///If you do not wish to use a script in the angle, then just leave the field as 0.
struct newcam_hardpos newcam_fixedcam[] =
{

	{LEVEL_BOB, 1, 0, NC_MODE_NORMAL, 0, -534, 4075, 3328, -334, 4275, 3528, 32767, 32767, 32767, 32767, 32767, 32767},
	{LEVEL_BOB, 2, 0, NC_MODE_NORMAL, 0, -125, 958, -380, 75, 1158, -180, 32767, 32767, 32767, 32767, 32767, 32767},

};