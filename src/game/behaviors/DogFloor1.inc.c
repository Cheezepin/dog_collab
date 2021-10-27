#define DOG_ANIM_IDLE 0
#define DOG_ANIM_DIG  1
#define DOG_ANIM_RUN  2
#define DOG_ANIM_WALK 3

#define o2639CurSecrets OBJECT_FIELD_S32(0x1B)
#define o2639DogBitten OBJECT_FIELD_S32(0x1C)
#define o2639SecretActivated OBJECT_FIELD_S32(0x1C)
#define ABS(x) ((x) < 0 ? -(x) : (x))

struct Object *find_unpushed_couch(const BehaviorScript *behavior, f32 *dist) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    f32 minDist = 0x20000;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && obj != o
                && obj->o2639SecretActivated == 0
                ) {
                f32 objDist = dist_between_objects(o, obj);
                if (objDist < minDist) {
                    closestObj = obj;
                    minDist = objDist;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }

    *dist = minDist;
    return closestObj;
}

void bhv_DogFloor1_init(void) {
    o->o2639CurSecrets = 0;
    o->o2639DogBitten = 0;
}

int yeteye =0;
void bhv_DogFloor1_loop(void) {
    f32 dist;
    struct Object *star = cur_obj_nearest_object_with_behavior(bhv2639a2hiddenstar);
    struct Object *deliciousCouch;

    if (o->o2639DogBitten == 1) { // back to neutral after evil is done
        o->o2639DogBitten = 0;
        o->oAction = 0;
    }

    if (o->oDistanceToMario < 100) { // mario can calm the dog
        o->oAction = 0;
    }

    switch (o->oAction) {
        case 0:
            dog_FollowMario();
            if (star != NULL) {
                if (star->oHiddenStarTriggerCounter > o->o2639CurSecrets) {
                    o->o2639CurSecrets = star->oHiddenStarTriggerCounter;
                    o->oTimer = 0;
                    if (o->o2639CurSecrets != 5) {
                        o->oAction++;
                    }
                }
            }
            break;
        case 1:
            o->oForwardVel = 0.0f;
            cur_obj_init_animation(DOG_ANIM_RUN);
            play_sound(SOUND_ACTION_METAL_STEP, gGlobalSoundSource);
            deliciousCouch = find_unpushed_couch(bhvA2pushablecouch, &dist);
            if (deliciousCouch != NULL) {
                obj_turn_toward_object(o, deliciousCouch, 16, 0x800);
                if (o->oTimer > 60) {
                    o->oAction++;
                }
            }
            break;
        case 2:
            o->oForwardVel = 25.0f;
            deliciousCouch = find_unpushed_couch(bhvA2pushablecouch, &dist);
            if (deliciousCouch != NULL) {
                obj_turn_toward_object(o, deliciousCouch, 16, 0x800);
            } else {
                o->oAction = 0;
            }
            break;

    }
}

#undef o2639CurSecrets
#undef o2639SecretActivated
