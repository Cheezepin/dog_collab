#include "game/behaviors/thecozies_helpers.h"

void bhv_initialize_adjacent_rooms(void) {
    struct Object *obj = o;
    gDoorAdjacentRooms[obj->oRoom][0] = BPARAM1;
    gDoorAdjacentRooms[obj->oRoom][1] = BPARAM2;
}
