#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "stomp_smoke/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/config.h"
#include FONT_C_FILE
#endif

#include "dog/model.inc.c"

#include "rex/model.inc.c"
#include "rex/anims/data.inc.c"
#include "rex/anims/table.inc.c"
#include "galoomba/model.inc.c"
#include "galoomba/anims/data.inc.c"
#include "galoomba/anims/table.inc.c"
#include "blooper/model.inc.c"
#include "blooper/anims/data.inc.c"
#include "blooper/anims/table.inc.c"
#include "blargg/model.inc.c"
#include "blargg/anims/data.inc.c"
#include "blargg/anims/table.inc.c"
#include "buzzy_beetle/model.inc.c"
#include "buzzy_beetle/anims/data.inc.c"
#include "buzzy_beetle/anims/table.inc.c"
#include "nipper/model.inc.c"
#include "nipper/anims/data.inc.c"
#include "nipper/anims/table.inc.c"
#include "cleft/model.inc.c"
#include "cleft/anims/data.inc.c"
#include "cleft/anims/table.inc.c"
#include "motos/model.inc.c"
#include "motos/anims/anim.inc.c"
#include "strollin_stu/model.inc.c"
#include "strollin_stu/anims/data.inc.c"
#include "strollin_stu/anims/table.inc.c"
#include "laser_ring/model.inc.c"
#include "laser_ring_spawner/model.inc.c"
#include "spike/model.inc.c"
#include "spike/anims/data.inc.c"
#include "spike/anims/table.inc.c"
#include "spike_ball/model.inc.c"
#include "spike_ball/anims/data.inc.c"
#include "spike_ball/anims/table.inc.c"
#include "podoboo/model.inc.c"
#include "dog/anims/data.inc.c"
#include "dog/anims/table.inc.c"
#include "cephie/model.inc.c"
#include "cephie/anims/data.inc.c"
#include "cephie/anims/table.inc.c"
#include "koopatrol/model.inc.c"
#include "koopatrol/anims/data.inc.c"
#include "koopatrol/anims/table.inc.c"