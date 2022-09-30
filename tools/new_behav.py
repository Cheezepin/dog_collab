#!/bin/python3

B_H = "include/behavior_data.h"
B_C = "data/behavior_data.c"
b_folder = "src/game/behaviors/"
f_proto_file = "src/game/obj_behaviors.h"
f_file = "src/game/obj_behaviors.c"

def write_funcs(nm):
	with open(b_folder + "%s.inc.c" % nm, "w+") as f:
		f.write("""
void bhv_%s_init(void) {
	
}
void bhv_%s_loop(void) {
	
}
""" % (nm, nm))
	with open(f_proto_file, "a") as f:
		f.write("\n")
		f.write("void bhv_%s_init(void); void bhv_%s_loop(void);" % (nm,nm))
	with open(f_file, "a") as f:
		f.write("\n#include \"behaviors/%s.inc.c\"" % nm)

def write_behavior(nm):
	with open(B_C, "a") as f:
		f.write("\n")
		f.write("""
const BehaviorScript bhv%s[] = {
	BEGIN(OBJ_LIST_DEFAULT),
	CALL_NATIVE(bhv_%s_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_%s_loop),
	END_LOOP(),
};
""" % (nm.capitalize(), nm, nm))
	with open(B_H, "a") as f:
		f.write("\n")
		f.write("extern const BehaviorScript bhv%s[];" % nm.capitalize())

import sys
bname = sys.argv[1]

write_behavior(bname)
write_funcs(bname)