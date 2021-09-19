void bhv_emu_electric_spinner(void) {
    long a;
    a = o->oBehParams;
    if (a >= 0x10000000) {
        o->oFaceAngleRoll -= (a-0x10000000); 
    }
    else {
        o->oFaceAngleRoll += a;
     }
}
static struct ObjectHitbox sShockHitbox = {
    /* interactType:      */ INTERACT_SHOCK,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 300,
    /* height:            */ 140,
    /* hurtboxRadius:     */ 180,
    /* hurtboxHeight:     */ 100,
};
u8 timer;
static void should_despawn(void) {
if (gMarioState == INTERACT_SHOCK){
     mark_obj_for_deletion(o);
     print_fps(1,1);
     o->oAction = 2;
    }
       else if (gMarioState == ACT_BACKWARD_AIR_KB) {
        print_fps(89,89);
        obj_set_pos(o, gMarioObject->oPosX, gMarioObject->oPosY, gMarioObject->oPosZ);
        o->oAction = 2;
    }
    else { o->oAction = 1; }
    
}
static void despawn(void) {
//if (timer >= 2){
    mark_obj_for_deletion(o);
    //print_fps(89,89);
    if (gMarioState == ACT_BACKWARD_AIR_KB) {
        print_fps(89,89);
        obj_set_pos(o, gMarioObject->oPosX, gMarioObject->oPosY, gMarioObject->oPosZ);
        o->oAction = 1;
    }
    //o->oAction = 1;
    else {
        o->oAction = 1;
    }
}

static void (*sShockActions[])(void) = {
    should_despawn,
    despawn,
};

void bhv_shock_texture_loop(void) {
    obj_set_hitbox(o, &sShockHitbox);
    cur_obj_call_action_function(sShockActions);
    
}

void bhv_emu_simple_spinner(void){
    long a;
    a = o->oBehParams;
    if (a >= 0x10000000) {
        o->oFaceAngleYaw -= (a-0x10000000); 
    }
    else {
        o->oFaceAngleYaw += a;
    }
}

void bhv_emu_sphere(void){
   long a;
    a = o->oBehParams;
    if (a >= 0x10000000) {
        o->oFaceAnglePitch -= (a-0x10000000); 
    }
    else {
        o->oFaceAnglePitch += a;
    }
}