#define OBJECT_FIELDS_INDEX_DIRECTLY

#include "sm64.h"

#include "object_constants.h"
#include "game/object_list_processor.h"
#include "game/interaction.h"
#include "game/behavior_actions.h"
#include "game/mario_actions_cutscene.h"
#include "game/mario_misc.h"
#include "game/object_helpers.h"
#include "game/debug.h"
#include "game/obj_behaviors.h"
#include "menu/file_select.h"
#include "engine/surface_load.h"

#include "actors/common0.h"
#include "actors/common1.h"
#include "actors/group0.h"
#include "actors/group1.h"
#include "actors/group2.h"
#include "actors/group3.h"
#include "actors/group4.h"
#include "actors/group5.h"
#include "actors/group6.h"
#include "actors/group7.h"
#include "actors/group8.h"
#include "actors/group9.h"
#include "actors/group10.h"
#include "actors/group11.h"
#include "actors/group12.h"
#include "actors/group13.h"
#include "actors/group14.h"
#include "actors/group15.h"
#include "actors/group16.h"
#include "actors/group17.h"
#include "actors/group2639.h"
#include "levels/bbh/header.h"
#include "levels/castle_inside/header.h"
#include "levels/hmc/header.h"
#include "levels/ssl/header.h"
#include "levels/bob/header.h"
#include "levels/sl/header.h"
#include "levels/wdw/header.h"
#include "levels/jrb/header.h"
#include "levels/thi/header.h"
#include "levels/ttc/header.h"
#include "levels/rr/header.h"
#include "levels/castle_grounds/header.h"
#include "levels/bitdw/header.h"
#include "levels/lll/header.h"
#include "levels/sa/header.h"
#include "levels/bitfs/header.h"
#include "levels/bits/header.h"
#include "levels/ddd/header.h"
#include "levels/wf/header.h"
#include "levels/bowser_1/header.h"
#include "levels/bowser_2/header.h"
#include "levels/bowser_3/header.h"
#include "levels/ttm/header.h"
#include "levels/ccm/header.h"
#include "levels/pss/header.h"

#include "make_const_nonconst.h"
#include "behavior_data.h"

#define BC_B(a) _SHIFTL(a, 24, 8)
#define BC_BB(a, b) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8))
#define BC_BBBB(a, b, c, d) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 8, 8) | _SHIFTL(d, 0, 8))
#define BC_BBH(a, b, c) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 16, 8) | _SHIFTL(c, 0, 16))
#define BC_B0H(a, b) (_SHIFTL(a, 24, 8) | _SHIFTL(b, 0, 16))
#define BC_H(a) _SHIFTL(a, 16, 16)
#define BC_HH(a, b) (_SHIFTL(a, 16, 16) | _SHIFTL(b, 0, 16))
#define BC_W(a) ((uintptr_t)(u32)(a))
#define BC_PTR(a) ((uintptr_t)(a))

enum BehaviorCommands {
    /*0x00*/ BHV_CMD_BEGIN,
    /*0x01*/ BHV_CMD_DELAY,
    /*0x02*/ BHV_CMD_CALL,
    /*0x03*/ BHV_CMD_RETURN,
    /*0x04*/ BHV_CMD_GOTO,
    /*0x05*/ BHV_CMD_BEGIN_REPEAT,
    /*0x06*/ BHV_CMD_END_REPEAT,
    /*0x07*/ BHV_CMD_END_REPEAT_CONTINUE,
    /*0x08*/ BHV_CMD_BEGIN_LOOP,
    /*0x09*/ BHV_CMD_END_LOOP,
    /*0x0A*/ BHV_CMD_BREAK,
    /*0x0B*/ BHV_CMD_BREAK_UNUSED,
    /*0x0C*/ BHV_CMD_CALL_NATIVE,
    /*0x0D*/ BHV_CMD_ADD_FLOAT,
    /*0x0E*/ BHV_CMD_SET_FLOAT,
    /*0x0F*/ BHV_CMD_ADD_INT,
    /*0x10*/ BHV_CMD_SET_INT,
    /*0x11*/ BHV_CMD_OR_INT,
    /*0x12*/ BHV_CMD_BIT_CLEAR,
    /*0x13*/ BHV_CMD_SET_INT_RAND_RSHIFT,
    /*0x14*/ BHV_CMD_SET_RANDOM_FLOAT,
    /*0x15*/ BHV_CMD_SET_RANDOM_INT,
    /*0x16*/ BHV_CMD_ADD_RANDOM_FLOAT,
    /*0x17*/ BHV_CMD_ADD_INT_RAND_RSHIFT,
    /*0x18*/ BHV_CMD_NOP_1,
    /*0x19*/ BHV_CMD_NOP_2,
    /*0x1A*/ BHV_CMD_NOP_3,
    /*0x1B*/ BHV_CMD_SET_MODEL,
    /*0x1C*/ BHV_CMD_SPAWN_CHILD,
    /*0x1D*/ BHV_CMD_DEACTIVATE,
    /*0x1E*/ BHV_CMD_DROP_TO_FLOOR,
    /*0x1F*/ BHV_CMD_SUM_FLOAT,
    /*0x20*/ BHV_CMD_SUM_INT,
    /*0x21*/ BHV_CMD_BILLBOARD,
    /*0x22*/ BHV_CMD_HIDE,
    /*0x23*/ BHV_CMD_SET_HITBOX,
    /*0x24*/ BHV_CMD_NOP_4,
    /*0x25*/ BHV_CMD_DELAY_VAR,
    /*0x26*/ BHV_CMD_BEGIN_REPEAT_UNUSED,
    /*0x27*/ BHV_CMD_LOAD_ANIMATIONS,
    /*0x28*/ BHV_CMD_ANIMATE,
    /*0x29*/ BHV_CMD_SPAWN_CHILD_WITH_PARam,
    /*0x2A*/ BHV_CMD_LOAD_COLLISION_DATA,
    /*0x2B*/ BHV_CMD_SET_HITBOX_WITH_OFFSet,
    /*0x2C*/ BHV_CMD_SPAWN_OBJ,
    /*0x2D*/ BHV_CMD_SET_HOME,
    /*0x2E*/ BHV_CMD_SET_HURTBOX,
    /*0x2F*/ BHV_CMD_SET_INTERACT_TYPE,
    /*0x30*/ BHV_CMD_SET_OBJ_PHYSICS,
    /*0x31*/ BHV_CMD_SET_INTERACT_SUBTYPE,
    /*0x32*/ BHV_CMD_SCALE,
    /*0x33*/ BHV_CMD_PARENT_BIT_CLEAR,
    /*0x34*/ BHV_CMD_ANIMATE_TEXTURE,
    /*0x35*/ BHV_CMD_DISABLE_RENDERING,
    /*0x36*/ BHV_CMD_SET_INT_UNUSED,
    /*0x37*/ BHV_CMD_SPAWN_WATER_DROPLET,
};

// Defines the start of the behavior script as well as the object list the object belongs to.
// Has some special behavior for certain objects.
#define BEGIN(objList) \
    BC_BB(BHV_CMD_BEGIN, objList)

// Delays the behavior script for a certain number of frames.
#define DELAY(num) \
    BC_B0H(BHV_CMD_DELAY, num)

// Jumps to a new behavior command and stores the return address in the object's stack.
#define CALL(addr) \
    BC_B(BHV_CMD_CALL), \
    BC_PTR(addr)

// Jumps back to the behavior command stored in the object's stack.
#define RETURN() \
    BC_B(BHV_CMD_RETURN)

// Jumps to a new behavior script without saving anything.
#define GOTO(addr) \
    BC_B(BHV_CMD_GOTO), \
    BC_PTR(addr)

// Marks the start of a loop that will repeat a certain number of times.
#define BEGIN_REPEAT(count) \
    BC_B0H(BHV_CMD_BEGIN_REPEAT, count)

// Marks the end of a repeating loop.
#define END_REPEAT() \
    BC_B(BHV_CMD_END_REPEAT)

// Also marks the end of a repeating loop, but continues executing commands following the loop on the same frame.
#define END_REPEAT_CONTINUE() \
    BC_B(BHV_CMD_END_REPEAT_CONTINUE)

// Marks the beginning of an infinite loop.
#define BEGIN_LOOP() \
    BC_B(BHV_CMD_BEGIN_LOOP)

// Marks the end of an infinite loop.
#define END_LOOP() \
    BC_B(BHV_CMD_END_LOOP)

// Exits the behavior script.
// Often used to end behavior scripts that do not contain an infinite loop.
#define BREAK() \
    BC_B(BHV_CMD_BREAK)

// Exits the behavior script, unused.
#define BREAK_UNUSED() \
    BC_B(BHV_CMD_BREAK_UNUSED)

// Executes a native game function.
#define CALL_NATIVE(func) \
    BC_B(BHV_CMD_CALL_NATIVE), \
    BC_PTR(func)

// Adds a float to the specified field.
#define ADD_FLOAT(field, value) \
    BC_BBH(BHV_CMD_ADD_FLOAT, field, value)

// Sets the specified field to a float.
#define SET_FLOAT(field, value) \
    BC_BBH(BHV_CMD_SET_FLOAT, field, value)

// Adds an integer to the specified field.
#define ADD_INT(field, value) \
    BC_BBH(BHV_CMD_ADD_INT, field, value)

// Sets the specified field to an integer.
#define SET_INT(field, value) \
    BC_BBH(BHV_CMD_SET_INT, field, value)

// Performs a bitwise OR with the specified field and the given integer.
// Usually used to set an object's flags.
#define OR_INT(field, value) \
    BC_BBH(BHV_CMD_OR_INT, field, value)

// Performs a bit clear with the specified short. Unused in favor of the 32-bit version.
#define BIT_CLEAR(field, value) \
    BC_BBH(BHV_CMD_BIT_CLEAR, field, value)

// TODO: this one needs a better name / labelling
// Gets a random short, right shifts it the specified amount and adds min to it, then sets the specified field to that value.
#define SET_INT_RAND_RSHIFT(field, min, rshift) \
    BC_BBH(BHV_CMD_SET_INT_RAND_RSHIFT, field, min), \
    BC_H(rshift)

// Sets the specified field to a random float in the given range.
#define SET_RANDOM_FLOAT(field, min, range) \
    BC_BBH(BHV_CMD_SET_RANDOM_FLOAT, field, min), \
    BC_H(range)

// Sets the specified field to a random integer in the given range.
#define SET_RANDOM_INT(field, min, range) \
    BC_BBH(BHV_CMD_SET_RANDOM_INT, field, min), \
    BC_H(range)

// Adds a random float in the given range to the specified field.
#define ADD_RANDOM_FLOAT(field, min, range) \
    BC_BBH(BHV_CMD_ADD_RANDOM_FLOAT, field, min), \
    BC_H(range)

// TODO: better name (unused anyway)
// Gets a random short, right shifts it the specified amount and adds min to it, then adds the value to the specified field. Unused.
#define ADD_INT_RAND_RSHIFT(field, min, rshift) \
    BC_BBH(BHV_CMD_ADD_INT_RAND_RSHIFT, field, min), \
    BC_H(rshift)

// No operation. Unused.
#define CMD_NOP_1(field) \
    BC_BB(BHV_CMD_NOP_1, field)

// No operation. Unused.
#define CMD_NOP_2(field) \
    BC_BB(BHV_CMD_NOP_2, field)

// No operation. Unused.
#define CMD_NOP_3(field) \
    BC_BB(BHV_CMD_NOP_3, field)

// Sets the current model ID of the object.
#define SET_MODEL(modelID) \
    BC_B0H(BHV_CMD_SET_MODEL, modelID)

// Spawns a child object with the specified model and behavior.
#define SPAWN_CHILD(modelID, behavior) \
    BC_B(BHV_CMD_SPAWN_CHILD), \
    BC_W(modelID), \
    BC_PTR(behavior)

// Exits the behavior script and despawns the object.
// Often used to end behavior scripts that do not contain an infinite loop.
#define DEACTIVATE() \
    BC_B(BHV_CMD_DEACTIVATE)

// Finds the floor triangle directly under the object and moves the object down to it.
#define DROP_TO_FLOOR() \
    BC_B(BHV_CMD_DROP_TO_FLOOR)

// Sets the destination float field to the sum of the values of the given float fields.
#define SUM_FLOAT(fieldDst, fieldSrc1, fieldSrc2) \
    BC_BBBB(BHV_CMD_SUM_FLOAT, fieldDst, fieldSrc1, fieldSrc2)

// Sets the destination integer field to the sum of the values of the given integer fields. Unused.
#define SUM_INT(fieldDst, fieldSrc1, fieldSrc2) \
    BC_BBBB(BHV_CMD_SUM_INT, fieldDst, fieldSrc1, fieldSrc2)

// Billboards the current object, making it always face the camera.
#define BILLBOARD() \
    BC_B(BHV_CMD_BILLBOARD)

// Hides the current object.
#define HIDE() \
    BC_B(BHV_CMD_HIDE)

// Sets the size of the object's cylindrical hitbox.
#define SET_HITBOX(radius, height) \
    BC_B(BHV_CMD_SET_HITBOX), \
    BC_HH(radius, height)

// No operation. Unused.
#define CMD_NOP_4(field, value) \
    BC_BBH(BHV_CMD_NOP_4, field, value)

// Delays the behavior script for the number of frames given by the value of the specified field.
#define DELAY_VAR(field) \
    BC_BB(BHV_CMD_DELAY_VAR, field)

// Unused. Marks the start of a loop that will repeat a certain number of times.
// Uses a u8 as the argument, instead of a s16 like the other version does.
#define BEGIN_REPEAT_UNUSED(count) \
    BC_BB(BHV_CMD_BEGIN_REPEAT_UNUSED, count)

#define OR_LONG(field, value) LOAD_ANIMATIONS(field, value)

// Loads the animations for the object. <field> is always set to oAnimations.
#define LOAD_ANIMATIONS(field, anims) \
    BC_BB(BHV_CMD_LOAD_ANIMATIONS, field), \
    BC_PTR(anims)

// Begins animation and sets the object's current animation index to the specified value.
#define ANIMATE(animIndex) \
    BC_BB(BHV_CMD_ANIMATE, animIndex)

// Spawns a child object with the specified model and behavior, plus a behavior param.
#define SPAWN_CHILD_WITH_PARAM(bhvParam, modelID, behavior) \
    BC_B0H(BHV_CMD_SPAWN_CHILD_WITH_PARam, bhvParam), \
    BC_W(modelID), \
    BC_PTR(behavior)

// Loads collision data for the object.
#define LOAD_COLLISION_DATA(collisionData) \
    BC_B(BHV_CMD_LOAD_COLLISION_DATA), \
    BC_PTR(collisionData)

// Sets the size of the object's cylindrical hitbox, and applies a downwards offset.
#define SET_HITBOX_WITH_OFFSET(radius, height, downOffset) \
    BC_B(BHV_CMD_SET_HITBOX_WITH_OFFSet), \
    BC_HH(radius, height), \
    BC_H(downOffset)

// Spawns a new object with the specified model and behavior.
#define SPAWN_OBJ(modelID, behavior) \
    BC_B(BHV_CMD_SPAWN_OBJ), \
    BC_W(modelID), \
    BC_PTR(behavior)

// Sets the home position of the object to its current position.
#define SET_HOME() \
    BC_B(BHV_CMD_SET_HOME)

// Sets the size of the object's cylindrical hurtbox.
#define SET_HURTBOX(radius, height) \
    BC_B(BHV_CMD_SET_HURTBOX), \
    BC_HH(radius, height)

// Sets the object's interaction type.
#define SET_INTERACT_TYPE(type) \
    BC_B(BHV_CMD_SET_INTERACT_TYPE), \
    BC_W(type)

// Sets various parameters that the object uses for calculating physics.
#define SET_OBJ_PHYSICS(wallHitboxRadius, gravity, bounciness, dragStrength, friction, buoyancy, unused1, unused2) \
    BC_B(BHV_CMD_SET_OBJ_PHYSICS), \
    BC_HH(wallHitboxRadius, gravity), \
    BC_HH(bounciness, dragStrength), \
    BC_HH(friction, buoyancy), \
    BC_HH(unused1, unused2)

// Sets the object's interaction subtype. Unused.
#define SET_INTERACT_SUBTYPE(subtype) \
    BC_B(BHV_CMD_SET_INTERACT_SUBTYPE), \
    BC_W(subtype)

// Sets the object's size to the specified percentage.
#define SCALE(unusedField, percent) \
    BC_BBH(BHV_CMD_SCALE, unusedField, percent)

// Performs a bit clear on the object's parent's field with the specified value.
// Used for clearing active particle flags fron Mario's object.
#define PARENT_BIT_CLEAR(field, flags) \
    BC_BB(BHV_CMD_PARENT_BIT_CLEAR, field), \
    BC_W(flags)

// Animates an object using texture animation. <field> is always set to oAnimState.
#define ANIMATE_TEXTURE(field, rate) \
    BC_BBH(BHV_CMD_ANIMATE_TEXTURE, field, rate)

// Disables rendering for the object.
#define DISABLE_RENDERING() \
    BC_B(BHV_CMD_DISABLE_RENDERING)

// Unused. Sets the specified field to an integer. Wastes 4 bytes of space for no reason at all.
#define SET_INT_UNUSED(field, value) \
    BC_BB(BHV_CMD_SET_INT_UNUSED, field), \
    BC_HH(0, value)

// Spawns a water droplet with the given parameters.
#define SPAWN_WATER_DROPLET(dropletParams) \
    BC_B(BHV_CMD_SPAWN_WATER_DROPLET), \
    BC_PTR(dropletParams)


const BehaviorScript bhvFazAmbient[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR)),
    BEGIN_LOOP(),
        CALL_NATIVE(faz_ambient_loop),
    END_LOOP(),
};

const BehaviorScript bhvBossMatt[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UCODE_LARGE)),
    LOAD_COLLISION_DATA(bossmatt_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvPerservePosWarp[] = {
    BREAK(),
};

const BehaviorScript bhvBossShell[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 50),
    SET_INT(oInteractType, INTERACT_DAMAGE),
    SET_FLOAT(oDrawingDistance, 5000),
    CALL_NATIVE(koopa_boss_shell_init),
    BEGIN_LOOP(),
    SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(koopa_boss_shell_loop),
    END_LOOP(),
};

const BehaviorScript bhvKoopaBoss[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    LOAD_ANIMATIONS(oAnimations, koopa_npc_anims),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 200),
    ANIMATE(1),
    SET_FLOAT(oDrawingDistance, 5000),
    CALL_NATIVE(koopa_boss_init),
    BEGIN_LOOP(),
        CALL_NATIVE(koopa_boss_loop),
    END_LOOP(),
};

const BehaviorScript bhvKoopaBossAnchor[] = {
    BREAK(),
};

const BehaviorScript bhvDoorDog[] = {
    BEGIN(OBJ_LIST_SURFACE),
    // Door - common:
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, door_seg3_anims_030156C0),
    ANIMATE(0),
    LOAD_COLLISION_DATA(door_seg3_collision_door),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_HOME(),
    CALL_NATIVE(bhv_door_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvStarBlock[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_COLLISION_DATA(redblock_collision),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 125, /*Height*/ 200),
    SET_FLOAT(oCollisionDistance, 300),
    CALL_NATIVE(starblock_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(starblock_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvHMCDoors[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UCODE_LARGE)),
    LOAD_COLLISION_DATA(doors_collision),
    SET_FLOAT(oCollisionDistance, 6000),
    SET_FLOAT(oDrawingDistance, 6000),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvHMCElevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(hmcelevator_collision),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_FLOAT(oDrawingDistance, 1000),
    CALL_NATIVE(hmcelevator_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(hmcelevator_loop),
    END_LOOP(),
};

const BehaviorScript bhvGoombaDialog[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, goomba_seg8_anims_0801DA4C),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    ANIMATE(0),
    SET_INT(oBobombBuddyRole, 0),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 2500),
    CALL_NATIVE(bhv_bobomb_buddy_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bobomb_buddy_loop),
    END_LOOP(),
};

const BehaviorScript bhvKoopaDialog[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, koopa_npc_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    ANIMATE(0),
    SET_FLOAT(oDrawingDistance, 2500),
    SET_INT(oBobombBuddyRole, 0),
    SET_HOME(),
    CALL_NATIVE(bhv_bobomb_buddy_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bobomb_buddy_loop),
    END_LOOP(),
};

const BehaviorScript bhvGoddardHMC[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 50, /*Height*/ 40),
    ANIMATE(0),
    SET_FLOAT(oDrawingDistance, 2500),
    SET_HOME(),
    CALL_NATIVE(goddard_hmc_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(goddard_hmc_loop),
    END_LOOP(),
};

const BehaviorScript bhvStarDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    SET_INT(oInteractType, INTERACT_DOOR),
    LOAD_COLLISION_DATA(inside_castle_seg7_collision_star_door),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_STAR_DOOR),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 20000),
    CALL_NATIVE(bhv_door_init),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_star_door_loop),
        CALL_NATIVE(bhv_door_rendering_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvMrI[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SPAWN_CHILD(/*Model*/ MODEL_MR_I_IRIS, /*Behavior*/ bhvMrIIris),
    SET_MODEL(MODEL_MR_I_BODY),
    BILLBOARD(),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mr_i_body_loop),
    END_LOOP(),
};

const BehaviorScript bhvMrIIris[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mr_i_iris_loop),
    END_LOOP(),
};

const BehaviorScript bhvMrIParticle[] = {
    BEGIN(OBJ_LIST_LEVEL),
    BILLBOARD(),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX(50, 50),
    SET_INT(oDamageOrCoinValue, 1),
    SET_INT(oInteractType, INTERACT_DAMAGE),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ 0, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mr_i_particle_loop),
    END_LOOP(),
};

const BehaviorScript bhvPurpleParticle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_REPEAT(10),
        CALL_NATIVE(bhv_piranha_particle_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvGiantPole[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_POLE),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 2100),
    SET_HOME(),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_giant_pole_loop),
    END_LOOP(),
};

const BehaviorScript bhvPoleGrabbing[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oInteractType, INTERACT_POLE),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 1500),
    CALL_NATIVE(bhv_pole_init),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pole_base_loop),
    END_LOOP(),
};

const BehaviorScript bhvThiHugeIslandTop[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(thi_seg7_collision_top_trap),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_thi_huge_island_top_loop),
    END_LOOP(),
};

const BehaviorScript bhvThiTinyIslandTop[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_thi_tiny_island_top_loop),
    END_LOOP(),
};

const BehaviorScript bhvCapSwitchBase[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(capswitch_collision_05003448),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCapSwitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(capswitch_collision_050033D0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cap_switch_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvKingBobomb[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, king_bobomb_seg5_anims_0500FE30),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 100),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_INT(oIntangibleTimer, 0),
    DROP_TO_FLOOR(),
    SET_HOME(),
    SPAWN_OBJ(/*Model*/ MODEL_NONE, /*Behavior*/ bhvBobombAnchorMario),
    SET_INT(oHealth, 3),
    SET_INT(oDamageOrCoinValue, 1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_king_bobomb_loop),
    END_LOOP(),
};

const BehaviorScript bhvBobombAnchorMario[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_FLOAT(oParentRelativePosX, 100),
    SET_FLOAT(oParentRelativePosZ, 150),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bobomb_anchor_mario_loop),
    END_LOOP(),
};

const BehaviorScript bhvBetaChestBottom[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    CALL_NATIVE(bhv_beta_chest_bottom_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_beta_chest_bottom_loop),
    END_LOOP(),
};

const BehaviorScript bhvBetaChestLid[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_beta_chest_lid_loop),
    END_LOOP(),
};

const BehaviorScript bhvBubbleParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    DISABLE_RENDERING(),
    SET_RANDOM_INT(oWaterObjScaleXAngle, /*Minimum*/ 2, /*Range*/ 9),
    DELAY_VAR(oWaterObjScaleXAngle),
    SPAWN_CHILD(/*Model*/ MODEL_BUBBLE, /*Behavior*/ bhvSmallWaterWave),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_BUBBLE),
    DEACTIVATE(),
};

const BehaviorScript bhvBubbleMaybe[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    CALL_NATIVE(bhv_bubble_wave_init),
    SET_RANDOM_FLOAT(oWaterObjScaleXAngle, /*Minimum*/ -75, /*Range*/ 150),
    SET_RANDOM_FLOAT(oWaterObjScaleYAngle, /*Minimum*/ -75, /*Range*/ 150),
    SET_RANDOM_FLOAT(oWaterObjScaleXAngleVel, /*Minimum*/ -75, /*Range*/ 150),
    SUM_FLOAT(/*Dest*/ oPosX, /*Value 1*/ oPosX, /*Value 2*/ oWaterObjScaleXAngle),
    SUM_FLOAT(/*Dest*/ oPosZ, /*Value 1*/ oPosZ, /*Value 2*/ oWaterObjScaleYAngle),
    SUM_FLOAT(/*Dest*/ oPosY, /*Value 1*/ oPosY, /*Value 2*/ oWaterObjScaleXAngleVel),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(60),
        ADD_INT(oAnimState, 1),
        CALL_NATIVE(bhv_bubble_maybe_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvSmallWaterWave[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    CALL_NATIVE(bhv_bubble_wave_init),
    SET_RANDOM_FLOAT(oWaterObjScaleXAngle, /*Minimum*/ -50, /*Range*/ 100),
    SET_RANDOM_FLOAT(oWaterObjScaleYAngle, /*Minimum*/ -50, /*Range*/ 100),
    SUM_FLOAT(/*Dest*/ oPosX, /*Value 1*/ oPosX, /*Value 2*/ oWaterObjScaleXAngle),
    SUM_FLOAT(/*Dest*/ oPosZ, /*Value 1*/ oPosZ, /*Value 2*/ oWaterObjScaleYAngle),
    SET_RANDOM_FLOAT(oWaterObjScaleXAngleVel, /*Minimum*/ 0, /*Range*/ 50),
    SUM_FLOAT(/*Dest*/ oPosY, /*Value 1*/ oPosY, /*Value 2*/ oWaterObjScaleXAngleVel),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    CALL(bhvSmallWaterWave398),
    BEGIN_REPEAT(60),
        CALL(bhvSmallWaterWave398),
        CALL_NATIVE(bhv_small_water_wave_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvSmallWaterWave398[] = {
    ADD_INT(oAnimState, 1),
    ADD_FLOAT(oPosY, 7),
    SET_RANDOM_FLOAT(oWaterObjScaleXAngle, /*Minimum*/ -2, /*Range*/ 5),
    SET_RANDOM_FLOAT(oWaterObjScaleYAngle, /*Minimum*/ -2, /*Range*/ 5),
    SUM_FLOAT(/*Dest*/ oPosX, /*Value 1*/ oPosX, /*Value 2*/ oWaterObjScaleXAngle),
    SUM_FLOAT(/*Dest*/ oPosZ, /*Value 1*/ oPosZ, /*Value 2*/ oWaterObjScaleYAngle),
    RETURN(),
};

const BehaviorScript bhvWaterAirBubble[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 400, /*Height*/ 150, /*Downwards offset*/ -150),
    SET_INT(oIntangibleTimer, 0),
    SET_INTERACT_TYPE(INTERACT_WATER_RING),
    SET_INT(oDamageOrCoinValue, 5),
    CALL_NATIVE(bhv_water_air_bubble_init),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_air_bubble_loop),
    END_LOOP(),
};

const BehaviorScript bhvSmallParticle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_particle_init),
    BEGIN_REPEAT(70),
        CALL_NATIVE(bhv_particle_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvPlungeBubble[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_PLUNGE_BUBBLE),
    DISABLE_RENDERING(),
    CALL_NATIVE(bhv_water_waves_init),
    DEACTIVATE(),
};

const BehaviorScript bhvSmallParticleSnow[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_particle_init),
    BEGIN_REPEAT(30),
        CALL_NATIVE(bhv_particle_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvSmallParticleBubbles[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_particle_init),
    BEGIN_REPEAT(70),
        CALL_NATIVE(bhv_small_bubbles_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvFishGroup[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fish_group_loop),
    END_LOOP(),
};

const BehaviorScript bhvCannon[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SPAWN_CHILD(/*Model*/ MODEL_CANNON_BARREL, /*Behavior*/ bhvCannonBarrel),
    SET_INT(oInteractType, INTERACT_CANNON_BASE),
    ADD_FLOAT(oPosY, -340),
    SET_HOME(),
    SET_HITBOX(/*Radius*/ 150, /*Height*/ 150),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cannon_base_loop),
    END_LOOP(),
};

const BehaviorScript bhvCannonBarrel[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cannon_barrel_loop),
    END_LOOP(),
};

const BehaviorScript bhvCannonBaseUnused[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(8),
        CALL_NATIVE(bhv_cannon_base_unused_loop),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvChuckya[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, chuckya_seg8_anims_0800C070),
    ANIMATE(CHUCKYA_ANIM_SPAWN),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_HITBOX(/*Radius*/ 150, /*Height*/ 100),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SPAWN_OBJ(/*Model*/ MODEL_NONE, /*Behavior*/ bhvChuckyaAnchorMario),
    SET_INT(oNumLootCoins, 5),
    SET_INT(oIntangibleTimer, 0),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_chuckya_loop),
    END_LOOP(),
};

const BehaviorScript bhvChuckyaAnchorMario[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_FLOAT(oParentRelativePosY, -60),
    SET_FLOAT(oParentRelativePosZ, 150),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_chuckya_anchor_mario_loop),
    END_LOOP(),
};

const BehaviorScript bhvRotatingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rotating_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTower[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_tower),
    SET_FLOAT(oCollisionDistance, 3000),
    SET_FLOAT(oDrawingDistance, 20000),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBulletBillCannon[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(wf_seg7_collision_bullet_bill_cannon),
    SET_FLOAT(oCollisionDistance, 300),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWfBreakableWallRight[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(wf_seg7_collision_breakable_wall),
    GOTO(bhvWfBreakableWallLeft + 1 + 2),
};

const BehaviorScript bhvWfBreakableWallLeft[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(wf_seg7_collision_breakable_wall_2),
    // WF breakable walls - common:
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HITBOX(/*Radius*/ 300, /*Height*/ 400),
    SET_FLOAT(oDrawingDistance, 4500),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wf_breakable_wall_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvKickableBoard[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_kickable_board),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 1200),
    SET_HURTBOX(/*Radius*/ 1, /*Height*/ 1),
    SET_FLOAT(oCollisionDistance, 1500),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_kickable_board_loop),
    END_LOOP(),
};

const BehaviorScript bhvTowerDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_tower_door),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tower_door_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvRotatingCounterClockwise[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BREAK(),
};

const BehaviorScript bhvWfRotatingWoodenPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_clocklike_rotation),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wf_rotating_wooden_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvKoopaShellUnderwater[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_LONG(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SILHOUETTE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_koopa_shell_underwater_loop),
    END_LOOP(),
};

const BehaviorScript bhvExitPodiumWarp[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_WARP),
    DROP_TO_FLOOR(),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_FLOAT(oCollisionDistance, 8000),
    LOAD_COLLISION_DATA(ttm_seg7_collision_podium_warp),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX(/*Radius*/ 50, /*Height*/ 50),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
    END_LOOP(),
};

const BehaviorScript bhvFadingWarp[] = {
    BEGIN(OBJ_LIST_LEVEL),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_FADING_WARP),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_WARP),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fading_warp_loop),
    END_LOOP(),
};

const BehaviorScript bhvWarp[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_WARP),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(OBJECT_FIELD_S32(0x1B), 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_warp_loop),
    END_LOOP(),
};

const BehaviorScript bhvWarpPipe[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_WARP),
    LOAD_COLLISION_DATA(warp_pipe_seg3_collision_03009AC8),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX(/*Radius*/ 70, /*Height*/ 50),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_warp_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWhitePuffExplosion[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_white_puff_exploding_loop),
    END_LOOP(),
};

const BehaviorScript bhvSpawnedStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oBehParams2ndByte, SPAWN_STAR_POS_CUTSCENE_BP_SPAWN_AT_HOME),
    GOTO(bhvSpawnedStarNoLevelExit + 1 + 1),
};

const BehaviorScript bhvSpawnedStarNoLevelExit[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    // Spawned star - common:
    SET_HOME(),
    CALL_NATIVE(bhv_spawned_star_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_spawned_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvMrIBlueCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    SET_INT(oInteractType, INTERACT_COIN),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oBehParams2ndByte, -1),
    SET_FLOAT(oCoinBaseYVel, 20),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_coin_init),
    SET_INT(oDamageOrCoinValue, 5),
    SET_INT(oOpacity, 255),
    SET_HITBOX(/*Radius*/ 120, /*Height*/ 64),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_coin_loop),
        ADD_INT(oBehParams2ndByte, 1),
    END_LOOP(),
};

const BehaviorScript bhvCoinInsideBoo[] = {
    BEGIN(OBJ_LIST_LEVEL),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 64),
    SET_INT(oInteractType, INTERACT_COIN),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BILLBOARD(),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_coin_inside_boo_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvCoinFormationSpawnedCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_coin_formation_spawned_coin_loop),
    END_LOOP(),
};

const BehaviorScript bhvCoinFormation[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_coin_formation_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_coin_formation_loop),
    END_LOOP(),
};

const BehaviorScript bhvOneCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    SET_INT(oBehParams2ndByte, YELLOW_COIN_BP_ONE_COIN),
    GOTO(bhvYellowCoin + 1),
};

const BehaviorScript bhvYellowCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    // Yellow coin - common:
    BILLBOARD(),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_yellow_coin_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_yellow_coin_loop),
    END_LOOP(),
};

const BehaviorScript bhvYellowCoinNoBillboard[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 64),
    SET_INT(oInteractType, INTERACT_COIN),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    SET_INT(oBehParams2ndByte, 0x69), // dont flicker and die
    CALL_NATIVE(bhv_moving_yellow_coin_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_moving_yellow_coin_loop),
        ADD_INT(oFaceAngleYaw,   0x100),
    END_LOOP(),
};

const BehaviorScript bvh20Coin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_init_room),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 80, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_20_coin_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_20_coin_loop),
        ADD_INT(oFaceAngleYaw, 0x400),
    END_LOOP(),
};

const BehaviorScript bhvTemporaryYellowCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_yellow_coin_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_temp_coin_loop),
    END_LOOP(),
};

const BehaviorScript bhvThreeCoinsSpawn[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_REPEAT(3),
        SPAWN_CHILD(/*Model*/ MODEL_YELLOW_COIN, /*Behavior*/ bhvSingleCoinGetsSpawned),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvTenCoinsSpawn[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_REPEAT(10),
        SPAWN_CHILD(/*Model*/ MODEL_YELLOW_COIN, /*Behavior*/ bhvSingleCoinGetsSpawned),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvSingleCoinGetsSpawned[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    CALL_NATIVE(bhv_coin_init),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_coin_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvCoinSparkles[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 25),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(8),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    BEGIN_REPEAT(2),
        CALL_NATIVE(bhv_coin_sparkles_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvCoinSparklesSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DISABLE_RENDERING(),
    BEGIN_REPEAT(3),
        CALL_NATIVE(bhv_golden_coin_sparkles_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvWallTinyStarParticle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SILHOUETTE)),
    BILLBOARD(),
    BEGIN_REPEAT(10),
        CALL_NATIVE(bhv_wall_tiny_star_particle_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvVertStarParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    DISABLE_RENDERING(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_V_STAR),
    CALL_NATIVE(bhv_tiny_star_particles_init),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvPoundTinyStarParticle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SILHOUETTE)),
    BILLBOARD(),
    BEGIN_REPEAT(10),
        CALL_NATIVE(bhv_pound_tiny_star_particle_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvHorStarParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    DISABLE_RENDERING(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_H_STAR),
    CALL_NATIVE(bhv_pound_tiny_star_particle_init),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvPunchTinyTriangle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_punch_tiny_triangle_loop),
    END_LOOP(),
};

const BehaviorScript bhvTriangleParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    DISABLE_RENDERING(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_TRIANGLE),
    CALL_NATIVE(bhv_punch_tiny_triangle_init),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvDoorWarp[] = {
    BEGIN(OBJ_LIST_SURFACE),
    SET_INT(oInteractType, INTERACT_WARP_DOOR),
    GOTO(bhvDoor + 1 + 1),
};

const BehaviorScript bhvDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    SET_INT(oInteractType, INTERACT_DOOR),
    // Door - common:
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, door_seg3_anims_030156C0),
    ANIMATE(DOOR_ANIM_CLOSED),
    LOAD_COLLISION_DATA(door_seg3_collision_door),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_HOME(),
    CALL_NATIVE(bhv_door_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_door_loop),
    END_LOOP(),
};

const BehaviorScript bhvGrindel[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_COLLISION_DATA(ssl_seg7_collision_grindel),
    DROP_TO_FLOOR(),
    ADD_FLOAT(oPosY, 1),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_grindel_thwomp_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvThwomp2[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(thwomp_seg5_collision_0500B92C),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    ADD_FLOAT(oPosY, 1),
    SET_HOME(),
    SCALE(/*Unused*/ 0, /*Field*/ 140),
    SET_FLOAT(oDrawingDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_grindel_thwomp_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvThwomp[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(thwomp_seg5_collision_0500B7D0),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    ADD_FLOAT(oPosY, 1),
    SCALE(/*Unused*/ 0, /*Field*/ 140),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_grindel_thwomp_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTumblingBridgePlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oCollisionDistance, 300),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tumbling_bridge_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWfTumblingBridge[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tumbling_bridge_loop),
    END_LOOP(),
};

const BehaviorScript bhvBbhTumblingBridge[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_INT(oBehParams2ndByte, TUMBLING_BRIDGE_BP_BBH),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tumbling_bridge_loop),
    END_LOOP(),
};

const BehaviorScript bhvLllTumblingBridge[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_INT(oBehParams2ndByte, TUMBLING_BRIDGE_BP_LLL),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tumbling_bridge_loop),
    END_LOOP(),
};

const BehaviorScript bhvFlame[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_HOME(),
    SCALE(/*Unused*/ 0, /*Field*/ 700),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 50, /*Height*/ 25, /*Downwards offset*/ 25),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvAnotherElavator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(hmc_seg7_collision_elevator),
    SET_HOME(),
    CALL_NATIVE(bhv_elevator_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_elevator_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvRrElevatorPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(rr_seg7_collision_elevator_platform),
    SET_HOME(),
    CALL_NATIVE(bhv_elevator_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_elevator_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvHmcElevatorPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(hmc_seg7_collision_elevator),
    SET_HOME(),
    CALL_NATIVE(bhv_elevator_init),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_elevator_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWaterMist[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_INT(oOpacity, 254),
    SET_FLOAT(oForwardVel, 20),
    SET_FLOAT(oVelY, -8),
    ADD_FLOAT(oPosY, 62),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_mist_loop),
    END_LOOP(),
};

const BehaviorScript bhvBreathParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_REPEAT(8),
        CALL_NATIVE(bhv_water_mist_spawn_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvBreakBoxTriangle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_REPEAT(18),
        CALL_NATIVE(cur_obj_rotate_face_angle_using_vel),
        CALL_NATIVE(cur_obj_move_using_fvel_and_gravity),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvWaterMist2[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_INT(oFaceAnglePitch, 0xC000),
    SCALE(/*Unused*/ 0, /*Field*/ 2100),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_mist_2_loop),
    END_LOOP(),
};

const BehaviorScript bhvMistCircParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_pound_white_puffs_init),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvDirtParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_ground_sand_init),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvSnowParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_ground_snow_init),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvBowserSnowParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_ground_bowser_snow_init),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvWind[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wind_loop),
    END_LOOP(),
};

const BehaviorScript bhvEndToad[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, toad_seg6_anims_0600FB58),
    ANIMATE(TOAD_ANIM_WEST_WAVE_THEN_TURN),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_end_toad_loop),
    END_LOOP(),
};

const BehaviorScript bhvEndPeach[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, peach_seg5_anims_0501C41C),
    ANIMATE(PEACH_ANIM_0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_end_peach_loop),
    END_LOOP(),
};

const BehaviorScript bhvUnusedParticleSpawn[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX(/*Radius*/ 40, /*Height*/ 40),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_unused_particle_spawn_loop),
    END_LOOP(),
};

const BehaviorScript bhvUkiki[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    GOTO(bhvMacroUkiki + 1),
};

const BehaviorScript bhvUkikiCageChild[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oPosX, 2560),
    SET_FLOAT(oPosY, 1457),
    SET_FLOAT(oPosZ, 1898),
    BREAK(),
};

const BehaviorScript bhvUkikiCageStar[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ukiki_cage_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvUkikiCage[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    SET_HOME(),
    LOAD_COLLISION_DATA(ttm_seg7_collision_ukiki_cage),
    SPAWN_CHILD(/*Model*/ MODEL_STAR, /*Behavior*/ bhvUkikiCageStar),
    SPAWN_CHILD(/*Model*/ MODEL_NONE, /*Behavior*/ bhvUkikiCageChild),
    SET_FLOAT(oCollisionDistance, 20000),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ukiki_cage_loop),
    END_LOOP(),
};

const BehaviorScript bhvBitfsSinkingPlatforms[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bitfs_seg7_collision_sinking_platform),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bitfs_sinking_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBitfsSinkingCagePlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bitfs_seg7_collision_sinking_cage_platform),
    SET_HOME(),
    SPAWN_CHILD(/*Model*/ MODEL_BITFS_BLUE_POLE, /*Behavior*/ bhvDddMovingPole),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bitfs_sinking_cage_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvDddMovingPole[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_POLE),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 710),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ddd_moving_pole_loop),
        CALL_NATIVE(bhv_pole_base_loop),
    END_LOOP(),
};

const BehaviorScript bhvBitfsTiltingInvertedPyramid[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bitfs_seg7_collision_inverted_pyramid),
    SET_HOME(),
    CALL_NATIVE(bhv_platform_normals_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tilting_inverted_pyramid_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSquishablePlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    LOAD_COLLISION_DATA(bitfs_seg7_collision_squishable_platform),
    SET_FLOAT(oCollisionDistance, 10000),
    CALL_NATIVE(bhv_platform_normals_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_squishable_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCutOutObject[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    DISABLE_RENDERING(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BREAK(),
};

const BehaviorScript bhvBetaMovingFlamesSpawn[] = {
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_beta_moving_flames_spawn_loop),
    END_LOOP(),
};

const BehaviorScript bhvBetaMovingFlames[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_beta_moving_flames_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvRrRotatingBridgePlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(rr_seg7_collision_rotating_platform_with_fire),
    SET_FLOAT(oCollisionDistance, 1500),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rr_rotating_bridge_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFlamethrower[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_flamethrower_loop),
    END_LOOP(),
};

const BehaviorScript bhvFlamethrowerFlame[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 50, /*Height*/ 25, /*Downwards offset*/ 25),
    BILLBOARD(),
    SET_HOME(),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_flamethrower_flame_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvBouncingFireball[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DISABLE_RENDERING(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bouncing_fireball_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvBouncingFireballFlame[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    SET_FLOAT(oGraphYOffset, 30),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 50, /*Height*/ 25, /*Downwards offset*/ 25),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bouncing_fireball_flame_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvBowserShockWave[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oOpacity, 255),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_shock_wave_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserElectricRing[] = {
    BEGIN(OBJ_LIST_SURFACE),
    //OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    OR_LONG(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    ADD_FLOAT(oPosY, 1),
    SET_INT(oOpacity, 255),
    SET_FLOAT(oCollisionDistance, 8000),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_electric_ring_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserLightning[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_LONG(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SET_INT(oOpacity, 255),
    SET_INTERACT_TYPE(INTERACT_SHOCK),
    SET_INT(oDamageOrCoinValue, 2),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_lightning_loop),
    END_LOOP(),
};

const BehaviorScript bhvStationaryLightning[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_LONG(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SET_INT(oOpacity, 255),
    SET_INTERACT_TYPE(INTERACT_SHOCK),
    SET_INT(oDamageOrCoinValue, 2),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_stationary_lightning_loop),
    END_LOOP(),
};

const BehaviorScript bhvFireParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 70),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_LOOP(),
        ADD_INT(oAnimState, 1),
        CALL_NATIVE(bhv_flame_mario_loop),
    END_LOOP(),
};

const BehaviorScript bhvBlackSmokeMario[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 50),
#ifdef BURN_SMOKE_FIX
    SET_INT(oOpacity, 255),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_black_smoke_mario_loop),
    END_LOOP(),
#else
    BEGIN_REPEAT(8),
        CALL_NATIVE(bhv_black_smoke_mario_loop),
        DELAY(1),
        CALL_NATIVE(bhv_black_smoke_mario_loop),
        DELAY(1),
        CALL_NATIVE(bhv_black_smoke_mario_loop),
    END_REPEAT(),
    DEACTIVATE(),
#endif
};

const BehaviorScript bhvBlackSmokeBowser[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 0),
    BEGIN_REPEAT(8),
        CALL_NATIVE(bhv_black_smoke_bowser_loop),
        ANIMATE_TEXTURE(oAnimState, 4),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvBlackSmokeUpward[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_REPEAT(4),
        CALL_NATIVE(bhv_black_smoke_upward_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvBetaFishSplashSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DISABLE_RENDERING(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_beta_fish_splash_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvSpindrift[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, spindrift_seg5_anims_05002D68),
    ANIMATE(SPINDRIFT_ANIM_DEFAULT),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_TWIRL_BOUNCE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_spindrift_loop),
    END_LOOP(),
};

const BehaviorScript bhvTowerPlatformGroup[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DISABLE_RENDERING(),
    ADD_FLOAT(oPosY, 300),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tower_platform_group_loop),
    END_LOOP(),
};

const BehaviorScript bhvWfSlidingTowerPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_platform),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wf_sliding_tower_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWfElevatorTowerPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_platform),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wf_elevator_tower_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWfSolidTowerPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_platform),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wf_solid_tower_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLeafParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_snow_leaf_particle_spawn_init),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvTreeSnow[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tree_snow_or_leaf_loop),
    END_LOOP(),
};

const BehaviorScript bhvTreeLeaf[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tree_snow_or_leaf_loop),
    END_LOOP(),
};

const BehaviorScript bhvAnotherTiltingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    CALL_NATIVE(bhv_platform_normals_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tilting_inverted_pyramid_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSquarishPathMoving[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bitdw_seg7_collision_moving_pyramid),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_squarish_path_moving_loop),
    END_LOOP(),
};

const BehaviorScript bhvPiranhaPlantBubble[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_piranha_plant_bubble_loop),
    END_LOOP(),
};

const BehaviorScript bhvPiranhaPlantWakingBubbles[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    BILLBOARD(),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_REPEAT(10),
        CALL_NATIVE(bhv_piranha_plant_waking_bubbles_loop),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvFloorSwitchAnimatesObject[] = {
    BEGIN(OBJ_LIST_SURFACE),
    SET_INT(oBehParams2ndByte, PURPLE_SWITCH_BP_ANIMATES),
    GOTO(bhvFloorSwitchHardcodedModel + 1),
};

const BehaviorScript bhvFloorSwitchGrills[] = {
    BEGIN(OBJ_LIST_SURFACE),
    GOTO(bhvFloorSwitchHardcodedModel + 1),
};

const BehaviorScript bhvFloorSwitchHardcodedModel[] = {
    BEGIN(OBJ_LIST_SURFACE),
    // Floor switch - common:
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(purple_switch_seg8_collision_0800C7A8),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_purple_switch_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFloorSwitchHiddenObjects[] = {
    BEGIN(OBJ_LIST_SURFACE),
    SET_INT(oBehParams2ndByte, PURPLE_SWITCH_BP_REVEAL_HIDDEN),
    GOTO(bhvFloorSwitchHardcodedModel + 1),
};

const BehaviorScript bhvSaveSwitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    // Floor switch - common:
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(purple_switch_seg8_collision_0800C7A8),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_purple_switch_loop),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_save_switch_loop),
    END_LOOP(),
};

const BehaviorScript bhvHiddenObject[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(breakable_box_seg8_collision),
    SET_FLOAT(oCollisionDistance, 300),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hidden_object_loop),
    END_LOOP(),
};

const BehaviorScript bhvBreakableBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    LOAD_COLLISION_DATA(breakable_box_seg8_collision),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_FLOAT(oDrawingDistance, 0x4000),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_breakable_box_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
    BREAK(),
};

const BehaviorScript bhvPushableMetalBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(metal_box_seg8_collision_08024C28),
    SET_FLOAT(oCollisionDistance, 500),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pushable_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvHeaveHo[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, heave_ho_seg5_anims_0501534C),
    ANIMATE(HEAVE_HO_ANIM_MOVING),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 200, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 600, /*Unused*/ 0, 0),
    SPAWN_OBJ(/*Model*/ MODEL_NONE, /*Behavior*/ bhvHeaveHoThrowMario),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_INT(oInteractionSubtype, (INT_SUBTYPE_NOT_GRABBABLE | INT_SUBTYPE_GRABS_MARIO)),
    SET_HITBOX(/*Radius*/ 120, /*Height*/ 100),
    SET_HOME(),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_heave_ho_loop),
    END_LOOP(),
};

const BehaviorScript bhvHeaveHoThrowMario[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_heave_ho_throw_mario_loop),
    END_LOOP(),
};

const BehaviorScript bhvCcmTouchedStarSpawn[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HITBOX(/*Radius*/ 500, /*Height*/ 500),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ccm_touched_star_spawn_loop),
    END_LOOP(),
};

const BehaviorScript bhvUnusedPoundablePlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_unused_poundable_platform),
    END_LOOP(),
};

const BehaviorScript bhvBetaTrampolineTop[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(springboard_collision_05001A28),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_beta_trampoline_top_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBetaTrampolineSpring[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_beta_trampoline_spring_loop),
    END_LOOP(),
};

const BehaviorScript bhvJumpingBox[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO  | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 600, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_jumping_box_loop),
    END_LOOP(),
};

const BehaviorScript bhvBooCage[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oGraphYOffset, 10),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_boo_cage_loop),
    END_LOOP(),
};

const BehaviorScript bhvStub[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    DISABLE_RENDERING(),
    BREAK(),
};

const BehaviorScript bhvIgloo[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_IGLOO_BARRIER),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 200),
    SET_INT(oIntangibleTimer, 0),
    SET_HOME(),
    BEGIN_LOOP(),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
    END_LOOP(),
};

const BehaviorScript bhvBowserKey[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_key_loop),
    END_LOOP(),
};

const BehaviorScript bhvGrandStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_STAR_OR_KEY),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_GRAND_STAR),
    SET_HITBOX(/*Radius*/ 160, /*Height*/ 100),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_grand_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvBetaBooKey[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 32, /*Height*/ 64),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_beta_boo_key_loop),
    END_LOOP(),
};

const BehaviorScript bhvAlphaBooKey[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 32, /*Height*/ 64),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_alpha_boo_key_loop),
    END_LOOP(),
};

const BehaviorScript bhvBulletBill[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 50, /*Height*/ 50, /*Downwards offset*/ 50),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_INT(oDamageOrCoinValue, 3),
    SCALE(/*Unused*/ 0, /*Field*/ 40),
    SET_INT(oIntangibleTimer, 0),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ 0, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_bullet_bill_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bullet_bill_loop),
    END_LOOP(),
};

const BehaviorScript bhvWhitePuffSmoke[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    ADD_FLOAT(oPosY, -100),
    CALL_NATIVE(bhv_white_puff_smoke_init),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(10),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvBowserTailAnchor[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 100, /*Height*/ 50, /*Downwards offset*/ -50),
    SET_INT(oIntangibleTimer, 0),
    DISABLE_RENDERING(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_tail_anchor_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowser[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_HITBOX(/*Radius*/ 400, /*Height*/ 400),
    DROP_TO_FLOOR(),
    SET_HOME(),
    LOAD_ANIMATIONS(oAnimations, bowser_seg6_anims_06057690),
    SPAWN_CHILD(/*Model*/ MODEL_NONE, /*Behavior*/ bhvBowserBodyAnchor),
    SPAWN_CHILD(/*Model*/ MODEL_BOWSER_BOMB_CHILD_OBJ, /*Behavior*/ bhvBowserFlameSpawn),
    SPAWN_OBJ(/*Model*/ MODEL_NONE, /*Behavior*/ bhvBowserTailAnchor),
    // Beta leftover that spawn 50 coins when Bowser is defeated
    SET_INT(oNumLootCoins, 50),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    CALL_NATIVE(bhv_bowser_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserSnow[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_DAMAGE),
    SET_HITBOX(/*Radius*/ 400, /*Height*/ 400),
    SET_HOME(),
    LOAD_ANIMATIONS(oAnimations, bowser_seg6_anims_06057690),
    ANIMATE(27),
    SET_INT(oOpacity, 255),
    CALL_NATIVE(bhv_snow_bowser_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_snow_bowser_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserBodyAnchor[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 300),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_BIG_KNOCKBACK),
    DISABLE_RENDERING(),
    SET_INT(oDamageOrCoinValue, 2),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_body_anchor_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserFlameSpawn[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_MODEL(MODEL_NONE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_flame_spawn_loop),
    END_LOOP(),
};

const BehaviorScript bhvTiltingBowserLavaPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    LOAD_COLLISION_DATA(bowser_2_seg7_collision_tilting_platform),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_FLOAT(oCollisionDistance, 20000),
    SET_INT(oFaceAngleYaw, 0x0),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(cur_obj_rotate_face_angle_using_vel),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFallingBowserPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_FLOAT(oCollisionDistance, 20000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_falling_bowser_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBlueBowserFlame[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_blue_bowser_flame_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_blue_bowser_flame_loop),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvFlameFloatingLanding[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_flame_floating_landing_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_flame_floating_landing_loop),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvBlueFlamesGroup[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_blue_flames_group_loop),
    END_LOOP(),
};

const BehaviorScript bhvFlameBouncing[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    BILLBOARD(),
    CALL_NATIVE(bhv_flame_bouncing_init),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_flame_bouncing_loop),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvFlameMovingForwardGrowing[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    BILLBOARD(),
    CALL_NATIVE(bhv_flame_moving_forward_growing_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_flame_moving_forward_growing_loop),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvFlameBowser[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    BILLBOARD(),
    CALL_NATIVE(bhv_flame_bowser_init),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_flame_bowser_loop),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvFlameLargeBurningOut[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    BILLBOARD(),
    CALL_NATIVE(bhv_flame_large_burning_out_init),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_flame_bowser_loop),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvBlueFish[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    LOAD_ANIMATIONS(oAnimations, blue_fish_seg3_anims_0301C2B0),
    ANIMATE(FISH_ANIM_DEFAULT),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_blue_fish_movement_loop),
    END_LOOP(),
};

const BehaviorScript bhvTankFishGroup[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tank_fish_group_loop),
    END_LOOP(),
};

const BehaviorScript bhvCheckerboardElevatorGroup[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_checkerboard_elevator_group_init),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvCheckerboardPlatformSub[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(checkerboard_platform_seg8_collision_platform),
    CALL_NATIVE(bhv_checkerboard_platform_init),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_checkerboard_platform_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserKeyUnlockDoor[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    LOAD_ANIMATIONS(oAnimations, bowser_key_seg3_anims_list),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_key_unlock_door_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserKeyCourseExit[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    LOAD_ANIMATIONS(oAnimations, bowser_key_seg3_anims_list),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_key_course_exit_loop),
    END_LOOP(),
};

const BehaviorScript bhvInvisibleObjectsUnderBridge[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    CALL_NATIVE(bhv_invisible_objects_under_bridge_init),
    BREAK(),
};

const BehaviorScript bhvWaterLevelPillar[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(inside_castle_seg7_collision_water_level_pillar),
    CALL_NATIVE(bhv_water_level_pillar_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_level_pillar_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvDddWarp[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oCollisionDistance, 30000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ddd_warp_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvMoatGrills[] = {
    BEGIN(OBJ_LIST_SURFACE),
#ifdef UNLOCK_ALL
    DEACTIVATE(),
#else
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(castle_grounds_seg7_collision_moat_grills),
    SET_FLOAT(oCollisionDistance, 30000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_moat_grills_loop),
    END_LOOP(),
#endif
};

const BehaviorScript bhvClockMinuteHand[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    SET_INT(oAngleVelRoll, -0x180),
    GOTO(bhvClockHourHand + 1 + 1),
};

const BehaviorScript bhvClockHourHand[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    SET_INT(oAngleVelRoll, -0x20),
    // Clock hand - common:
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rotating_clock_arm_loop),
    END_LOOP(),
};

const BehaviorScript bhvMacroUkiki[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    // Ukiki - common:
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_HOLDABLE_NPC),
    SET_HITBOX(/*Radius*/ 40, /*Height*/ 40),
    SET_INT(oIntangibleTimer, 0),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, ukiki_seg5_anims_05015784),
    ANIMATE(UKIKI_ANIM_RUN),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    CALL_NATIVE(bhv_ukiki_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ukiki_loop),
    END_LOOP(),
};

const BehaviorScript bhvLllRotatingHexagonalPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    LOAD_COLLISION_DATA(lll_seg7_collision_hexagonal_platform),
    SET_HOME(),
    BEGIN_LOOP(),
        SET_INT(oAngleVelYaw,  0x100),
        ADD_INT(oMoveAngleYaw, 0x100),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLllSinkingRockBlock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_floating_block),
    ADD_FLOAT(oPosY, -50),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_sinking_rock_block_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLllMovingOctagonalMeshPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    ADD_FLOAT(oPosY, -50),
    LOAD_COLLISION_DATA(lll_seg7_collision_octagonal_moving_platform),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_moving_octagonal_mesh_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSnowBall[] = {
    BREAK(),
};

const BehaviorScript bhvLllRotatingBlockWithFireBars[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_rotating_fire_bars),
    SET_FLOAT(oCollisionDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_rotating_block_fire_bars_loop),
    END_LOOP(),
};

const BehaviorScript bhvLllRotatingHexFlame[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 50, /*Height*/ 100, /*Downwards offset*/ 50),
    SET_INT(oIntangibleTimer, 0),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_rotating_hex_flame_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvLllWoodPiece[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_wood_piece),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_wood_piece_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLllFloatingWoodBridge[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_MODEL(MODEL_NONE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_floating_wood_bridge_loop),
    END_LOOP(),
};

const BehaviorScript bhvVolcanoFlames[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    BEGIN_LOOP(),
        ADD_INT(oAnimState, 1),
        CALL_NATIVE(bhv_volcano_flames_loop),
    END_LOOP(),
};

const BehaviorScript bhvLllRotatingHexagonalRing[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_rotating_platform),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_rotating_hexagonal_ring_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLllSinkingRectangularPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_slow_tilting_platform),
    SET_FLOAT(oCollisionDistance, 2000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_sinking_rectangular_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLllSinkingSquarePlatforms[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_sinking_pyramids),
    ADD_FLOAT(oPosY, 5),
    SET_FLOAT(oCollisionDistance, 2000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_sinking_square_platforms_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLllTiltingInvertedPyramid[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_inverted_pyramid),
    ADD_FLOAT(oPosY, 5),
    SET_HOME(),
    CALL_NATIVE(bhv_platform_normals_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tilting_inverted_pyramid_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvKoopaShell[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SILHOUETTE)), //! Silhouette doesn't show up in-game, due to combiner modes.
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_koopa_shell_loop),
    END_LOOP(),
};

const BehaviorScript bhvKoopaShellFlame[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_koopa_shell_flame_loop),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvToxBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_COLLISION_DATA(ssl_seg7_collision_tox_box),
    ADD_FLOAT(oPosY, 256),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tox_box_loop),
    END_LOOP(),
};

const BehaviorScript bhvPiranhaPlant[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, piranha_plant_seg6_anims_0601C31C),
    ANIMATE(PIRANHA_PLANT_ANIM_BITE),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 200),
    SET_HURTBOX(/*Radius*/ 50, /*Height*/ 200),
    SET_INT(oIntangibleTimer,   0),
    SET_INT(oDamageOrCoinValue, 3),
    SET_INT(oNumLootCoins,      5),
    SPAWN_CHILD(/*Model*/ MODEL_BUBBLE, /*Behavior*/ bhvPiranhaPlantBubble),
    SET_FLOAT(oDrawingDistance, 2000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_piranha_plant_loop),
    END_LOOP(),
};

const BehaviorScript bhvLllBowserPuzzlePiece[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    LOAD_COLLISION_DATA(lll_seg7_collision_puzzle_piece),
    SET_HOME(),
    SET_FLOAT(oCollisionDistance, 3000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_bowser_puzzle_piece_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLllBowserPuzzle[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    DISABLE_RENDERING(),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_bowser_puzzle_loop),
    END_LOOP(),
};

const BehaviorScript bhvTuxiesMother[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, penguin_seg5_anims_05008B74),
    ANIMATE(PENGUIN_ANIM_IDLE),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    SET_HOME(),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*/ 200, /*Height*/ 300),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tuxies_mother_loop),
    END_LOOP(),
};

const BehaviorScript bhvPenguinBaby[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    BREAK(),
};

const BehaviorScript bhvSmallPenguinReturned[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    BREAK(),
};

const BehaviorScript bhvSmallPenguin[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, penguin_seg5_anims_05008B74),
    ANIMATE(PENGUIN_ANIM_WALK),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_HOLDABLE_NPC),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX(/*Radius*/ 40, /*Height*/ 40),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_small_penguin_loop),
    END_LOOP(),
};

const BehaviorScript bhvManyBlueFishSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    SET_INT(oBehParams2ndByte, FISH_SPAWNER_BP_MANY_BLUE),
    GOTO(bhvFishSpawner + 1),
};

const BehaviorScript bhvFewBlueFishSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    SET_INT(oBehParams2ndByte, FISH_SPAWNER_BP_FEW_BLUE),
    GOTO(bhvFishSpawner + 1),
};

const BehaviorScript bhvFishSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    // Fish Spawner - common:
    DISABLE_RENDERING(),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fish_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvFish[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fish_loop),
    END_LOOP(),
};

const BehaviorScript bhvWdwExpressElevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wdw_seg7_collision_express_elevator_platform),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wdw_express_elevator_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWdwExpressElevatorPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wdw_seg7_collision_express_elevator_platform),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBubSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    SET_INT(oCheepCheepSpawnerSpawnAmount, 1),
    DISABLE_RENDERING(),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bub_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvBub[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, bub_seg6_anims_06012354),
    ANIMATE(BUB_ANIM_SWIM),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 20, /*Height*/ 10, /*Downwards offset*/ 10),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_INT(oDamageOrCoinValue, 1),
    SET_HOME(),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bub_loop),
    END_LOOP(),
};

const BehaviorScript bhvExclamationBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(exclamation_box_outline_seg8_collision_08025F78),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oCollisionDistance, 300),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_exclamation_box_loop),
    END_LOOP(),
};

const BehaviorScript bhvRotatingExclamationMark[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SCALE(/*Unused*/ 0, /*Field*/ 200),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rotating_exclamation_mark_loop),
        ADD_INT(oMoveAngleYaw, 0x800),
    END_LOOP(),
};

const BehaviorScript bhvSoundSpawner[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DELAY(3),
    CALL_NATIVE(bhv_sound_spawner_init),
    DELAY(30),
    DEACTIVATE(),
};

const BehaviorScript bhvRockSolid[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(jrb_seg7_collision_rock_solid),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBowserSubDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    // LOAD_COLLISION_DATA(ddd_seg7_collision_bowser_sub_door),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_FLOAT(oCollisionDistance, 20000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowsers_sub_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBowsersSub[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_FLOAT(oCollisionDistance, 20000),
    // LOAD_COLLISION_DATA(ddd_seg7_collision_submarine),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowsers_sub_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSushiShark[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, sushi_seg5_anims_0500AE54),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 100, /*Height*/ 50, /*Downwards offset*/ 50),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_INT(oDamageOrCoinValue, 3),
    SET_HOME(),
    ANIMATE(SUSHI_ANIM_SWIM),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sushi_shark_loop),
    END_LOOP(),
};

const BehaviorScript bhvJrbSlidingBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(jrb_seg7_collision_floating_box),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_jrb_sliding_box_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvShipPart3[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ship_part_3_loop),
    END_LOOP(),
};

const BehaviorScript bhvInSunkenShip3[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(jrb_seg7_collision_in_sunken_ship_3),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ship_part_3_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSunkenShipPart[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SCALE(/*Unused*/ 0, /*Field*/ 50),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sunken_ship_part_loop),
    END_LOOP(),
};

const BehaviorScript bhvSunkenShipSetRotation[] = {
    SET_INT(oFaceAnglePitch, 0xE958),
    SET_INT(oFaceAngleYaw, 0xEE6C),
    SET_INT(oFaceAngleRoll, 0x0C80),
    RETURN(),
};

const BehaviorScript bhvSunkenShipPart2[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_FLOAT(oDrawingDistance, 6000),
    SET_HOME(),
    CALL(bhvSunkenShipSetRotation),
    BREAK(),
};

const BehaviorScript bhvInSunkenShip[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(jrb_seg7_collision_in_sunken_ship),
    GOTO(bhvInSunkenShip2 + 1 + 2),
};

const BehaviorScript bhvInSunkenShip2[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(jrb_seg7_collision_in_sunken_ship_2),
    // Sunken ship - common:
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 4000),
    CALL(bhvSunkenShipSetRotation),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvMistParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_DUST),
    DISABLE_RENDERING(),
    SPAWN_CHILD(/*Model*/ MODEL_MIST, /*Behavior*/ bhvWhitePuff1),
    SPAWN_CHILD(/*Model*/ MODEL_SMOKE, /*Behavior*/ bhvWhitePuff2),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvWhitePuff1[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_DUST),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_white_puff_1_loop),
    END_LOOP(),
};

const BehaviorScript bhvWhitePuff2[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(7),
        CALL_NATIVE(bhv_white_puff_2_loop),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvWhitePuffSmoke2[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(7),
        CALL_NATIVE(bhv_white_puff_2_loop),
        CALL_NATIVE(cur_obj_move_using_fvel_and_gravity),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvPurpleSwitchHiddenBoxes[] = {
    BEGIN(OBJ_LIST_SURFACE),
    SET_INT(oBehParams2ndByte, PURPLE_SWITCH_BP_REVEAL_HIDDEN),
    GOTO(bhvFloorSwitchHardcodedModel + 1),
};

const BehaviorScript bhvBlueCoinSwitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(blue_coin_switch_seg8_collision_08000E98),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_blue_coin_switch_loop),
    END_LOOP(),
};

const BehaviorScript bhvHiddenBlueCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    SET_INT(oInteractType, INTERACT_COIN),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 64),
    SET_INT(oDamageOrCoinValue, 5),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oBehParams2ndByte, -1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hidden_blue_coin_loop),
        ADD_INT(oBehParams2ndByte, 1),
    END_LOOP(),
};

const BehaviorScript bhvOpenableCageDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_openable_cage_door_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvOpenableGrill[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_openable_grill_loop),
    END_LOOP(),
};

const BehaviorScript bhvWaterLevelDiamond[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 70, /*Height*/ 30),
    SET_FLOAT(oCollisionDistance, 200),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_level_diamond_loop),
    END_LOOP(),
};

const BehaviorScript bhvInitializeChangingWaterLevel[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_init_changing_water_level_loop),
    END_LOOP(),
};

const BehaviorScript bhvTweesterSandParticle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tweester_sand_particle_loop),
    END_LOOP(),
};

const BehaviorScript bhvTweester[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    DROP_TO_FLOOR(),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tweester_loop),
    END_LOOP(),
};

const BehaviorScript bhvMerryGoRoundBooManager[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_merry_go_round_boo_manager_loop),
    END_LOOP(),
};

const BehaviorScript bhvAnimatedTexture[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -70, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_animated_texture_loop),
        ADD_INT(oAnimState, 1),
        ANIMATE_TEXTURE(oAnimState, 2),
    END_LOOP(),
};

const BehaviorScript bhvBooInCastle[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_FLOAT(oGraphYOffset, 60),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_boo_in_castle_loop),
    END_LOOP(),
};

const BehaviorScript bhvBooWithCage[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_INT(oDamageOrCoinValue, 3),
    SET_HURTBOX(/*Radius*/ 80, /*Height*/ 120),
    SET_HITBOX(/*Radius*/ 180, /*Height*/ 140),
    SET_FLOAT(oGraphYOffset, 60),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_boo_with_cage_init),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_boo_with_cage_loop),
    END_LOOP(),
};

const BehaviorScript bhvBalconyBigBoo[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    SET_INT(oBehParams2ndByte, BIG_BOO_BP_BALCONY),
    SET_INT(oBigBooNumMinionBoosKilled, 10),
    GOTO(bhvGhostHuntBigBoo + 1),
};

const BehaviorScript bhvMerryGoRoundBigBoo[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    SET_INT(oBehParams2ndByte, BIG_BOO_BP_MERRY_GO_ROUND),
    // Set number of minion boos killed to 10, which is greater than 5 so that the boo always loads without needing to kill any boos.
    SET_INT(oBigBooNumMinionBoosKilled, 10),
    GOTO(bhvGhostHuntBigBoo + 1),
};

const BehaviorScript bhvGhostHuntBigBoo[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    // Big boo - common:
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_boo_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_big_boo_loop),
    END_LOOP(),
};

const BehaviorScript bhvCourtyardBooTriplet[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    DISABLE_RENDERING(),
    CALL_NATIVE(bhv_courtyard_boo_triplet_init),
    DEACTIVATE(),
};

const BehaviorScript bhvBoo[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    SET_INT(oBehParams2ndByte, BOO_BP_NORMAL),
    GOTO(bhvGhostHuntBoo + 1),
};

const BehaviorScript bhvMerryGoRoundBoo[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    SET_INT(oBehParams2ndByte, BOO_BP_MERRY_GO_ROUND),
    GOTO(bhvGhostHuntBoo + 1),
};

const BehaviorScript bhvGhostHuntBoo[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    // Boo - common:
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oIntangibleTimer, 0),
    SET_HOME(),
    SET_INT(oDamageOrCoinValue, 2),
    SET_HITBOX(/*Radius*/ 140, /*Height*/ 80),
    SET_HURTBOX(/*Radius*/ 40, /*Height*/ 60),
    SET_FLOAT(oGraphYOffset, 30),
    CALL_NATIVE(bhv_init_room),
    SPAWN_CHILD(/*Model*/ MODEL_YELLOW_COIN, /*Behavior*/ bhvCoinInsideBoo),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_boo_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_boo_loop),
    END_LOOP(),
};

const BehaviorScript bhvHiddenStaircaseStep[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bbh_seg7_collision_staircase_step),
    SET_INT(oRoom, 1),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBooStaircase[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(bbh_seg7_collision_staircase_step),
    SET_INT(oRoom, 1),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_boo_staircase),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBbhTiltingTrapPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bbh_seg7_collision_tilt_floor_platform),
    SET_HOME(),
    SET_INT(oRoom, 2),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bbh_tilting_trap_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvHauntedBookshelf[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bbh_seg7_collision_haunted_bookshelf),
    SET_HOME(),
    SET_INT(oRoom, 6),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_haunted_bookshelf_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvMeshElevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(bbh_seg7_collision_mesh_elevator),
    SET_HOME(),
    SET_INT(oRoom, 12),
    SET_INT(oBehParams2ndByte, ELEVATOR_BP_BBH_MESH),
    CALL_NATIVE(bhv_elevator_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_elevator_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvMerryGoRound[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bbh_seg7_collision_merry_go_round),
    SET_FLOAT(oCollisionDistance, 2000),
    SET_INT(oRoom, 10),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_merry_go_round_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvPlaysMusicTrackWhenTouched[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_play_music_track_when_touched_loop),
    END_LOOP(),
};

const BehaviorScript bhvBetaBowserAnchor[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_HOME(),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 300),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        ADD_INT(oAnimState, 1),
        CALL_NATIVE(bhv_beta_bowser_anchor_loop),
    END_LOOP(),
};

const BehaviorScript bhvStaticCheckeredPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(checkerboard_platform_seg8_collision_platform),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_static_checkered_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvUnusedFakeStar[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        ADD_INT(oFaceAnglePitch, 0x100),
        ADD_INT(oFaceAngleYaw,   0x100),
    END_LOOP(),
};

const BehaviorScript bhvStaticObject[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BREAK(),
};

void jewel_2639loop();
const BehaviorScript bhv2639Jewel[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags,
        (
            OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
          | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO
          | OBJ_FLAG_COMPUTE_DIST_TO_MARIO
          | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW
          | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
        )
    ),
    BEGIN_LOOP(),
        CALL_NATIVE(jewel_2639loop),
    END_LOOP(),
};

const BehaviorScript bhvCastleFloorTrap[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    DISABLE_RENDERING(),
    CALL_NATIVE(bhv_castle_floor_trap_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_castle_floor_trap_loop),
    END_LOOP(),
};

const BehaviorScript bhvFloorTrapInCastle[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(inside_castle_seg7_collision_floor_trap),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_floor_trap_in_castle_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTree[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    BILLBOARD(),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_OPACITY_FROM_CAMERA_DIST)),
    SET_INT(oInteractType, INTERACT_POLE),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 500),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pole_base_loop),
    END_LOOP(),
};

const BehaviorScript bhvPalmTree[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    LOAD_ANIMATIONS(oAnimations, wf_palm_tree_anims),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_OPACITY_FROM_CAMERA_DIST)),
    ANIMATE(0),
    SET_INT(oInteractType, INTERACT_POLE),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 1018),
    SET_INT(oIntangibleTimer, 0),
    SET_FLOAT(oDrawingDistance, 0x7fff),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pole_base_loop),
    END_LOOP(),
};

const BehaviorScript bhvPalmTreeBits[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    LOAD_ANIMATIONS(oAnimations, wf_palm_tree_bits_anims),
    GOTO(bhvPalmTree + 1 + 2),
};

const BehaviorScript bhvSparkle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(9),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvSparkleSpawn[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sparkle_spawn_loop),
    END_LOOP(),
};

const BehaviorScript bhvSparkleParticleSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_SPARKLES),
    BEGIN(OBJ_LIST_UNIMPORTANT),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oGraphYOffset, 25),
    SET_RANDOM_FLOAT(oMarioParticleFlags, /*Minimum*/ -50, /*Range*/ 100),
    SUM_FLOAT(/*Dest*/ oPosX, /*Value 1*/ oPosX, /*Value 2*/ oMarioParticleFlags),
    SET_RANDOM_FLOAT(oMarioParticleFlags, /*Minimum*/ -50, /*Range*/ 100),
    SUM_FLOAT(/*Dest*/ oPosZ, /*Value 1*/ oPosZ, /*Value 2*/ oMarioParticleFlags),
    SET_RANDOM_FLOAT(oMarioParticleFlags, /*Minimum*/ -50, /*Range*/ 100),
    SUM_FLOAT(/*Dest*/ oPosY, /*Value 1*/ oPosY, /*Value 2*/ oMarioParticleFlags),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(12),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

const BehaviorScript bhvScuttlebug[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, scuttlebug_seg6_anims_06015064),
    ANIMATE(SCUTTLEBUG_ANIM_JUMP),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 80, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_scuttlebug_loop),
    END_LOOP(),
};

const BehaviorScript bhvScuttlebugSpawn[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_scuttlebug_spawn_loop),
    END_LOOP(),
};

const BehaviorScript bhvWhompKingBoss[] = {
    BEGIN(OBJ_LIST_SURFACE),
    SET_INT(oBehParams2ndByte, WHOMP_BP_KING),
    SET_INT(oHealth, 3),
    GOTO(bhvSmallWhomp + 1 + 1),
};

const BehaviorScript bhvSmallWhomp[] = {
    BEGIN(OBJ_LIST_SURFACE),
    SET_INT(oNumLootCoins, 5),
    // Whomp - common:
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, whomp_seg6_anims_06020A04),
    LOAD_COLLISION_DATA(whomp_seg6_collision_06020A0C),
    ANIMATE(WHOMP_ANIM_WALK),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_whomp_loop),
    END_LOOP(),
};

// The large splash Mario makes when he jumps into a pool of water.
const BehaviorScript bhvWaterSplash[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(3),
        ADD_INT(oAnimState, 1),
        CALL_NATIVE(bhv_water_splash_spawn_droplets),
        DELAY(1),
        CALL_NATIVE(bhv_water_splash_spawn_droplets),
    END_REPEAT(),
    BEGIN_REPEAT(5),
        ADD_INT(oAnimState, 1),
        DELAY(1),
    END_REPEAT(),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_WATER_SPLASH),
    DEACTIVATE(),
};

// Droplets of water that spawn as a result of various water splashes.
const BehaviorScript bhvWaterDroplet[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_droplet_loop),
    END_LOOP(),
};

// Small splashes that are seen when a water droplet lands back into the water.
const BehaviorScript bhvWaterDropletSplash[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oFaceAnglePitch, 0),
    SET_INT(oFaceAngleYaw, 0),
    SET_INT(oFaceAngleRoll, 0),
    CALL_NATIVE(bhv_water_droplet_splash_init),
    ADD_FLOAT(oPosY, 5),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(6),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

// The splash created when an air bubble hits the surface of the water.
const BehaviorScript bhvBubbleSplash[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oFaceAnglePitch, 0),
    SET_INT(oFaceAngleYaw, 0),
    SET_INT(oFaceAngleRoll, 0),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    CALL_NATIVE(bhv_bubble_splash_init),
    BEGIN_REPEAT(6),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

// The water wave surrounding Mario when he is idle in a pool of water.
const BehaviorScript bhvIdleWaterWave[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oFaceAnglePitch, 0),
    SET_INT(oFaceAngleYaw, 0),
    SET_INT(oFaceAngleRoll, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_idle_water_wave_loop),
        ADD_INT(oAnimState, 1),
        BEGIN_REPEAT(6),
            CALL_NATIVE(bhv_idle_water_wave_loop),
        END_REPEAT(),
        CALL_NATIVE(bhv_idle_water_wave_loop),
    END_LOOP(),
};

// Water splashes similar to the splashes created by water droplets, but are created by other objects.
const BehaviorScript bhvObjectWaterSplash[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oFaceAnglePitch, 0),
    SET_INT(oFaceAngleYaw, 0),
    SET_INT(oFaceAngleRoll, 0),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(6),
        ADD_INT(oAnimState, 1),
    END_REPEAT(),
    DEACTIVATE(),
};

// Waves that are generated when running in shallow water.
const BehaviorScript bhvShallowWaterWave[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DISABLE_RENDERING(),
    BEGIN_REPEAT(5),
        SPAWN_WATER_DROPLET(&gShallowWaterWaveDropletParams),
    END_REPEAT_CONTINUE(),
    DELAY(1),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_SHALLOW_WATER_WAVE),
    DEACTIVATE(),
};

// A small water splash that occurs when jumping in and out of shallow water.
// Unlike the larger water splash it has no visible model of its own.
// It has a 1 in 256 chance of spawning the fish particle easter egg.
const BehaviorScript bhvShallowWaterSplash[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DISABLE_RENDERING(),
    BEGIN_REPEAT(18),
        SPAWN_WATER_DROPLET(&gShallowWaterSplashDropletParams),
    END_REPEAT_CONTINUE(),
    CALL_NATIVE(bhv_shallow_water_splash_init),
    DELAY(1),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_SHALLOW_WATER_SPLASH),
    DEACTIVATE(),
};

// Waves created by other objects along the water's surface, specifically the koopa shell and Sushi.
const BehaviorScript bhvObjectWaveTrail[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    GOTO(bhvWaveTrail + 1 + 1 + 2), // Wave trail - common
};

// The waves created by Mario while he is swimming.
const BehaviorScript bhvWaveTrail[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    PARENT_BIT_CLEAR(oActiveParticleFlags, ACTIVE_PARTICLE_WAVE_TRAIL),
    // Wave trail - common:
    SET_INT(oFaceAnglePitch, 0),
    SET_INT(oFaceAngleYaw, 0),
    SET_INT(oFaceAngleRoll, 0),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_REPEAT(8),
        ADD_INT(oAnimState, 1),
        CALL_NATIVE(bhv_wave_trail_shrink),
        DELAY(1),
        CALL_NATIVE(bhv_wave_trail_shrink),
    END_REPEAT(),
    DEACTIVATE(),
};

// Tiny wind particles that provide aesthetics to the strong winds generated by the Snowman and Fwoosh.
// As they are unimportant objects, they don't have collision with Mario.
const BehaviorScript bhvTinyStrongWindParticle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_strong_wind_particle_loop),
    END_LOOP(),
};

// Strong wind particles generated by the Snowman and Fwoosh that blow Mario back and knock his cap off.
const BehaviorScript bhvStrongWindParticle[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_strong_wind_particle_loop),
    END_LOOP(),
};

const BehaviorScript bhvWeakWindParticle[] = {
    BEGIN(OBJ_LIST_POLELIKE), //?
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_weak_wind_particle_loop),
    END_LOOP(),
};

const BehaviorScript bhvPinwheelWindParticle[] = {
    BEGIN(OBJ_LIST_POLELIKE), //?
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pinwheel_wind_particle_loop),
    END_LOOP(),
};

// The handler for the strong wind blown by the Snowman in SL. Triggers dialog and then aims towards Mario.
const BehaviorScript bhvSLSnowmanWind[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sl_snowman_wind_loop),
    END_LOOP(),
};

// The penguin that walks erratically along the ice bridge in front of the Snowman in SL.
// Blocks strong wind particles, allowing Mario to walk behind it.
const BehaviorScript bhvSLWalkingPenguin[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(penguin_seg5_collision_05008B88),
    LOAD_ANIMATIONS(oAnimations, penguin_seg5_anims_05008B74),
    ANIMATE(PENGUIN_ANIM_WALK),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 600),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sl_walking_penguin_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvYellowBall[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BREAK(),
};

UNUSED static const u64 behavior_data_unused_0 = 0;
const BehaviorScript bhvMario[] = {
    BEGIN(OBJ_LIST_PLAYER),
    SET_INT(oIntangibleTimer, 0),
    OR_LONG(oFlags, (OBJ_FLAG_PLAYER | OBJ_FLAG_SILHOUETTE)),
    OR_INT(oUnk94, 0x0001),
    SET_HITBOX(/*Radius*/ 37, /*Height*/ 160),
    BEGIN_LOOP(),
        CALL_NATIVE(run_2639_sound),
        CALL_NATIVE(bhv_mario_update),
    END_LOOP(),
};

const BehaviorScript bhvToadMessage[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, toad_seg6_anims_0600FB58),
    ANIMATE(TOAD_ANIM_WEST_WAVING_BOTH_ARMS),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_toad_message_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_toad_message_loop),
    END_LOOP(),
};

void bhv_angry_toad_message_loop();
void bhv_angry_toad_message_init();
const BehaviorScript bhvAngryToadMessage[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, toad_seg6_anims_0600FB58),
    ANIMATE(TOAD_ANIM_WEST_WAVING_BOTH_ARMS),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_angry_toad_message_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_angry_toad_message_loop),
    END_LOOP(),
};

const BehaviorScript bhvUnlockDoorStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_unlock_door_star_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_unlock_door_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvInstantActiveWarp[] = {
    BREAK(),
};

const BehaviorScript bhvAirborneWarp[] = {
    BREAK(),
};

const BehaviorScript bhvHardAirKnockBackWarp[] = {
    BREAK(),
};

const BehaviorScript bhvSpinAirborneCircleWarp[] = {
    BREAK(),
};

const BehaviorScript bhvDeathWarp[] = {
    BREAK(),
};

const BehaviorScript bhvSpinAirborneWarp[] = {
    BREAK(),
};

const BehaviorScript bhvFlyingWarp[] = {
    BREAK(),
};

const BehaviorScript bhvPaintingStarCollectWarp[] = {
    BREAK(),
};

const BehaviorScript bhvPaintingDeathWarp[] = {
    BREAK(),
};

const BehaviorScript bhvAirborneDeathWarp[] = {
    BREAK(),
};

const BehaviorScript bhvAirborneStarCollectWarp[] = {
    BREAK(),
};

const BehaviorScript bhvLaunchStarCollectWarp[] = {
    BREAK(),
};

const BehaviorScript bhvLaunchDeathWarp[] = {
    BREAK(),
};

const BehaviorScript bhvSwimmingWarp[] = {
    BREAK(),
};

UNUSED static const u64 behavior_data_unused_1 = 0;
const BehaviorScript bhvRandomAnimatedTexture[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oGraphYOffset, -16),
    BILLBOARD(),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_LOOP(),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvYellowBackgroundInMenu[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(beh_yellow_background_menu_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(beh_yellow_background_menu_loop),
    END_LOOP(),
};

const BehaviorScript bhvMenuButton[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_menu_button_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_menu_button_loop),
    END_LOOP(),
};

const BehaviorScript bhvMenuButtonManager[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_SET_THROW_MATRIX_FROM_TRANSFORM | OBJ_FLAG_UPDATE_TRANSFORM_FOR_THROW_MATRIX | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_menu_button_manager_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_menu_button_manager_loop),
    END_LOOP(),
};

const BehaviorScript bhvActSelectorStarType[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_act_selector_star_type_loop),
    END_LOOP(),
};

const BehaviorScript bhvActSelector[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_act_selector_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_act_selector_loop),
    END_LOOP(),
};

const BehaviorScript bhvMovingYellowCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 64),
    SET_INT(oInteractType, INTERACT_COIN),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    CALL_NATIVE(bhv_moving_yellow_coin_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_moving_yellow_coin_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvBlueCoinMotos[] = {
    BEGIN(OBJ_LIST_LEVEL),
    CALL_NATIVE(bhv_moving_blue_coin_init),
    SET_INT(oOpacity, 255),
    GOTO(bhvMovingYellowCoin),
};

const BehaviorScript bhvMovingBlueCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oBehParams2ndByte, -1),
    CALL_NATIVE(bhv_moving_blue_coin_init),
    SET_INT(oOpacity, 255),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_moving_blue_coin_loop),
        ADD_INT(oBehParams2ndByte, 1),
    END_LOOP(),
};

const BehaviorScript bhvBlueCoinSliding[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oBehParams2ndByte, -1),
    CALL_NATIVE(bhv_blue_coin_sliding_jumping_init),
    SET_INT(oOpacity, 255),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_blue_coin_sliding_loop),
        ADD_INT(oBehParams2ndByte, 1),
    END_LOOP(),
};

const BehaviorScript bhvBlueCoinJumping[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oBehParams2ndByte, -1),
    CALL_NATIVE(bhv_blue_coin_sliding_jumping_init),
    SET_INT(oOpacity, 255),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_blue_coin_jumping_loop),
        ADD_INT(oBehParams2ndByte, 1),
    END_LOOP(),
};

const BehaviorScript bhvSeaweed[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, seaweed_seg6_anims_0600A4D4),
    ANIMATE(SEAWEED_ANIM_WAVE),
    CALL_NATIVE(bhv_seaweed_init),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvSeaweedBundle[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DROP_TO_FLOOR(),
    CALL_NATIVE(bhv_seaweed_bundle_init),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvBobomb[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, bobomb_seg8_anims_0802396C),
    DROP_TO_FLOOR(),
    ANIMATE(BOBOMB_ANIM_WALKING),
    SET_INT(oIntangibleTimer, 0),
    SET_HOME(),
    CALL_NATIVE(bhv_bobomb_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bobomb_loop),
    END_LOOP(),
};

const BehaviorScript bhvBobombFuseSmoke[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    CALL_NATIVE(bhv_bobomb_fuse_smoke_init),
    DELAY(1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dust_smoke_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvBobombBuddy[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oBobombBuddyRole, 0),
    LOAD_ANIMATIONS(oAnimations, bobomb_seg8_anims_0802396C),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    ANIMATE(BOBOMB_ANIM_WALKING),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 2500),
    CALL_NATIVE(bhv_bobomb_buddy_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bobomb_buddy_loop),
    END_LOOP(),
};

const BehaviorScript bhvBobombBuddyOpensCannon[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oBobombBuddyRole, 1),
    GOTO(bhvBobombBuddy + 1 + 2),
};

const BehaviorScript bhvCannonClosed[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(cannon_lid_seg8_collision_08004950),
    SET_HOME(),
    CALL_NATIVE(bhv_cannon_closed_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cannon_closed_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWhirlpool[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_whirlpool_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_whirlpool_loop),
    END_LOOP(),
};

const BehaviorScript bhvJetStream[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_jet_stream_loop),
    END_LOOP(),
};

const BehaviorScript bhvMessagePanel[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wooden_signpost_seg3_collision_0302DD80),
    SET_FLOAT(oCollisionDistance, 150),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_SIGN),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 150, /*Height*/ 80),
    SET_INT(oWoodenPostTotalMarioAngle, 0),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(load_object_collision_model),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
    END_LOOP(),
};

const BehaviorScript bhvSignOnWall[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_SIGN),
    SET_HITBOX(/*Radius*/ 150, /*Height*/ 80),
    SET_INT(oWoodenPostTotalMarioAngle, 0),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
    END_LOOP(),
};

const BehaviorScript bhvHomingAmp[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dAmpAnimsList),
    ANIMATE(AMP_ANIM_DEFAULT),
    SET_FLOAT(oGraphYOffset, 40),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_homing_amp_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_homing_amp_loop),
    END_LOOP(),
};

const BehaviorScript bhvCirclingAmp[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dAmpAnimsList),
    ANIMATE(AMP_ANIM_DEFAULT),
    SET_FLOAT(oGraphYOffset, 40),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_circling_amp_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_circling_amp_loop),
    END_LOOP(),
};

const BehaviorScript bhvButterfly[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, butterfly_seg3_anims_030056B0),
    DROP_TO_FLOOR(),
    SET_FLOAT(oGraphYOffset, 5),
    CALL_NATIVE(bhv_butterfly_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_butterfly_loop),
    END_LOOP(),
};

const BehaviorScript bhvHoot[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, hoot_seg5_anims_05005768),
    SET_INT(oInteractType, INTERACT_HOOT),
    SET_HITBOX(/*Radius*/ 75, /*Height*/ 75),
    CALL_NATIVE(bhv_hoot_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hoot_loop),
    END_LOOP(),
};

const BehaviorScript bhvBetaHoldableObject[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 40, /*Height*/ 50),
    CALL_NATIVE(bhv_beta_holdable_object_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_beta_holdable_object_loop),
    END_LOOP(),
};

const BehaviorScript bhvCarrySomethingHeld[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BREAK(),
};

const BehaviorScript bhvCarrySomethingDropped[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BREAK(),
};

const BehaviorScript bhvCarrySomethingThrown[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BREAK(),
};

const BehaviorScript bhvObjectBubble[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_Y_WITH_TERMINAL_VEL | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    CALL_NATIVE(bhv_object_bubble_init),
    SET_RANDOM_FLOAT(oVelY, /*Minimum*/ 3, /*Range*/ 6),
    SET_INT_RAND_RSHIFT(oMoveAngleYaw, /*Minimum*/ 0, /*Right shift*/ 0),
    DELAY(1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_object_bubble_loop),
    END_LOOP(),
};

const BehaviorScript bhvObjectWaterWave[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oFaceAnglePitch, 0),
    SET_INT(oFaceAngleYaw, 0),
    SET_INT(oFaceAngleRoll, 0),
    CALL_NATIVE(bhv_object_water_wave_init),
    DELAY(6),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_object_water_wave_loop),
        ADD_INT(oAnimState, 1),
    BEGIN_REPEAT(6),
        CALL_NATIVE(bhv_object_water_wave_loop),
    END_REPEAT(),
    END_LOOP(),
};

const BehaviorScript bhvExplosion[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_INTERACT_TYPE(INTERACT_DAMAGE),
    SET_INT(oDamageOrCoinValue, 2),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 150, /*Height*/ 150, /*Downwards offset*/ 50),
    SET_INT(oAnimState, -1),
    CALL_NATIVE(bhv_explosion_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_explosion_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvVisualExplosion[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_INT(oAnimState, -1),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 150, /*Height*/ 150, /*Downwards offset*/ 150),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    CALL_NATIVE(bhv_explosion_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_explosion_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvBobombBullyDeathSmoke[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_Y_WITH_TERMINAL_VEL | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    CALL_NATIVE(bhv_bobomb_bully_death_smoke_init),
    DELAY(1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dust_smoke_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvSmoke[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_Y_WITH_TERMINAL_VEL | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    DELAY(1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dust_smoke_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvBobombExplosionBubble[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_bobomb_explosion_bubble_init),
    ADD_RANDOM_FLOAT(oPosX, /*Minimum*/ -50, /*Range*/ 100),
    ADD_RANDOM_FLOAT(oPosY, /*Minimum*/ -50, /*Range*/ 100),
    ADD_RANDOM_FLOAT(oPosZ, /*Minimum*/ -50, /*Range*/ 100),
    CALL(bhvBobombExplosionBubble3600),
    DELAY(1),
    BEGIN_LOOP(),
        CALL(bhvBobombExplosionBubble3600),
        CALL_NATIVE(bhv_bobomb_explosion_bubble_loop),
    END_LOOP(),
};

const BehaviorScript bhvBobombExplosionBubble3600[] = {
    ADD_RANDOM_FLOAT(oPosX, /*Minimum*/ -2, /*Range*/ 4),
    ADD_RANDOM_FLOAT(oPosZ, /*Minimum*/ -2, /*Range*/ 4),
    RETURN(),
};

const BehaviorScript bhvRespawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_respawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvSmallBully[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, bully_seg5_anims_0500470C),
    DROP_TO_FLOOR(),
    SET_HOME(),
    CALL_NATIVE(bhv_small_bully_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bully_loop),
    END_LOOP(),
};

const BehaviorScript bhvBigBully[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, bully_seg5_anims_0500470C),
    DROP_TO_FLOOR(),
    SET_HOME(),
    CALL_NATIVE(bhv_big_bully_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bully_loop),
    END_LOOP(),
};

const BehaviorScript bhvBigBullyWithMinions[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, bully_seg5_anims_0500470C),
    SET_HOME(),
    CALL_NATIVE(bhv_big_bully_init),
    CALL_NATIVE(bhv_big_bully_with_minions_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_big_bully_with_minions_loop),
    END_LOOP(),
};

const BehaviorScript bhvSmallChillBully[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, chilly_chief_seg6_anims_06003994),
    DROP_TO_FLOOR(),
    SET_HOME(),
    SET_INT(oBullySubtype, 0x0010),
    CALL_NATIVE(bhv_small_bully_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bully_loop),
    END_LOOP(),
};

const BehaviorScript bhvBigChillBully[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, chilly_chief_seg6_anims_06003994),
    DROP_TO_FLOOR(),
    SET_HOME(),
    SET_INT(oBullySubtype, 0x0010),
    CALL_NATIVE(bhv_big_bully_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bully_loop),
    END_LOOP(),
};

const BehaviorScript bhvMotosHand[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_motos_hand_loop),
    END_LOOP(),
};

const BehaviorScript bhvMotos[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, motos_anime),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 100),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SPAWN_OBJ(/*Model*/ MODEL_NONE, /*Behavior*/ bhvMotosHand),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_motos_loop),
    END_LOOP(),
};

const BehaviorScript bhvJetStreamRingSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    HIDE(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_jet_stream_ring_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvJetStreamWaterRing[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, water_ring_seg6_anims_06013F7C),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 75, /*Height*/ 20, /*Downwards offset*/ 20),
    SET_INTERACT_TYPE(INTERACT_WATER_RING),
    SET_INT(oDamageOrCoinValue, 2),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_jet_stream_water_ring_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_jet_stream_water_ring_loop),
    END_LOOP(),
};

const BehaviorScript bhvMantaRayWaterRing[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, water_ring_seg6_anims_06013F7C),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 75, /*Height*/ 20, /*Downwards offset*/ 20),
    SET_INTERACT_TYPE(INTERACT_WATER_RING),
    SET_INT(oDamageOrCoinValue, 2),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_manta_ray_water_ring_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_manta_ray_water_ring_loop),
    END_LOOP(),
};

const BehaviorScript bhvMantaRayRingManager[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvBowserBomb[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 40, /*Height*/ 40, /*Downwards offset*/ 40),
    DELAY(1),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bowser_bomb_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserBombExplosion[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, -288),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_bomb_explosion_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserBombSmoke[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, -288),
    SET_INT(oOpacity, 255),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_bomb_smoke_loop),
    END_LOOP(),
};

const BehaviorScript bhvCelebrationStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_celebration_star_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_celebration_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvCelebrationStarSparkle[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oGraphYOffset, 25),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_LOOP(),
        ADD_INT(oAnimState, 1),
        CALL_NATIVE(bhv_celebration_star_sparkle_loop),
    END_LOOP(),
};

const BehaviorScript bhvStarKeyCollectionPuffSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BILLBOARD(),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_star_key_collection_puff_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvLllDrawbridgeSpawner[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    HIDE(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_drawbridge_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvLllDrawbridge[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_drawbridge),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lll_drawbridge_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSmallBomp[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_small_bomp),
    CALL_NATIVE(bhv_small_bomp_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_small_bomp_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLargeBomp[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_large_bomp),
    CALL_NATIVE(bhv_large_bomp_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_large_bomp_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWfSlidingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wf_seg7_collision_sliding_brick_platform),
    CALL_NATIVE(bhv_wf_sliding_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wf_sliding_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvMoneybag[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, moneybag_seg6_anims_06005E5C),
    DROP_TO_FLOOR(),
    SET_HOME(),
    SET_INT(oIntangibleTimer, -1),
    CALL_NATIVE(bhv_moneybag_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_moneybag_loop),
    END_LOOP(),
};

const BehaviorScript bhvMoneybagHidden[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oGraphYOffset, 27),
    BILLBOARD(),
    SET_HITBOX(/*Radius*/ 110, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    BEGIN_LOOP(),
        ADD_INT(oAnimState, 1),
        CALL_NATIVE(bhv_moneybag_hidden_loop),
    END_LOOP(),
};

const BehaviorScript bhvPitBowlingBall[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 130),
    CALL_NATIVE(bhv_bob_pit_bowling_ball_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bob_pit_bowling_ball_loop),
    END_LOOP(),
};

const BehaviorScript bhvFreeBowlingBall[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 130),
    CALL_NATIVE(bhv_free_bowling_ball_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_free_bowling_ball_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowlingBall[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 130),
    CALL_NATIVE(bhv_bowling_ball_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowling_ball_loop),
    END_LOOP(),
};

const BehaviorScript bhvClownBowlingBall[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_FLOAT(oGraphYOffset, 130),
    CALL_NATIVE(bhv_clown_bowling_ball_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_clown_bowling_ball_roll_loop),
    END_LOOP(),
};


const BehaviorScript bhvTtmBowlingBallSpawner[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oBBallSpawnerPeriodMinus1, 63),
    CALL_NATIVE(bhv_generic_bowling_ball_spawner_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_generic_bowling_ball_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvBobBowlingBallSpawner[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oBBallSpawnerPeriodMinus1, 127),
    CALL_NATIVE(bhv_generic_bowling_ball_spawner_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_generic_bowling_ball_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvThiBowlingBallSpawner[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_thi_bowling_ball_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvRrCruiserWing[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_rr_cruiser_wing_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rr_cruiser_wing_loop),
    END_LOOP(),
};

const BehaviorScript bhvSpindel[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_COLLISION_DATA(ssl_seg7_collision_spindel),
    CALL_NATIVE(bhv_spindel_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_spindel_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSslMovingPyramidWall[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_COLLISION_DATA(ssl_seg7_collision_0702808C),
    CALL_NATIVE(bhv_ssl_moving_pyramid_wall_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ssl_moving_pyramid_wall_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvPyramidElevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_COLLISION_DATA(ssl_seg7_collision_pyramid_elevator),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_FLOAT(oCollisionDistance, 20000),
    CALL_NATIVE(bhv_pyramid_elevator_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pyramid_elevator_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvPyramidElevatorTrajectoryMarkerBall[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pyramid_elevator_trajectory_marker_ball_loop),
    END_LOOP(),
};

const BehaviorScript bhvPyramidTop[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    //LOAD_COLLISION_DATA(ssl_seg7_collision_pyramid_top),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_FLOAT(oCollisionDistance, 20000),
    CALL_NATIVE(bhv_pyramid_top_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pyramid_top_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvPyramidTopFragment[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_pyramid_top_fragment_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pyramid_top_fragment_loop),
    END_LOOP(),
};

const BehaviorScript bhvPyramidPillarTouchDetector[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 50, /*Height*/ 50),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pyramid_pillar_touch_detector_loop),
    END_LOOP(),
};

const BehaviorScript bhvWaterfallSoundLoop[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_waterfall_sound_loop),
    END_LOOP(),
};

const BehaviorScript bhvVolcanoSoundLoop[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_volcano_sound_loop),
    END_LOOP(),
};

const BehaviorScript bhvCastleFlagWaving[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, castle_grounds_seg7_anims_flags),
    ANIMATE(CASTLE_FLAG_ANIM_WAVE),
    CALL_NATIVE(bhv_castle_flag_init),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvBirdsSoundLoop[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_birds_sound_loop),
    END_LOOP(),
};

const BehaviorScript bhvAmbientSounds[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    CALL_NATIVE(bhv_ambient_sounds_init),
    BEGIN_LOOP(),
    END_LOOP(),
};

const BehaviorScript bhvSandSoundLoop[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sand_sound_loop),
    END_LOOP(),
};

const BehaviorScript bhvHiddenAt120Stars[] = {
    BEGIN(OBJ_LIST_SURFACE),
#ifdef UNLOCK_ALL
    DEACTIVATE(),
#else
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(castle_grounds_seg7_collision_cannon_grill),
    SET_FLOAT(oCollisionDistance, 4000),
    CALL_NATIVE(bhv_castle_cannon_grate_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
#endif
};

const BehaviorScript bhvSnowmansBottom[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_snowmans_bottom_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_snowmans_bottom_loop),
    END_LOOP(),
};

const BehaviorScript bhvSnowmansHead[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_FLOAT(oGraphYOffset, 110),
    CALL_NATIVE(bhv_snowmans_head_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_snowmans_head_loop),
    END_LOOP(),
};

const BehaviorScript bhvSnowmansBodyCheckpoint[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_snowmans_body_checkpoint_loop),
    END_LOOP(),
};

const BehaviorScript bhvBigSnowmanWhole[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oGraphYOffset, 180),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*/ 210, /*Height*/ 550),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
    END_LOOP(),
};

const BehaviorScript bhvBigBoulder[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oGraphYOffset, 180),
    CALL_NATIVE(bhv_big_boulder_init),
    SET_FLOAT(oDrawingDistance, 20000),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_big_boulder_loop),
    END_LOOP(),
};

const BehaviorScript bhvBigBoulderGenerator[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_big_boulder_generator_loop),
    END_LOOP(),
};

const BehaviorScript bhvWingCap[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SILHOUETTE)),
    CALL_NATIVE(bhv_wing_cap_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wing_vanish_cap_loop),
    END_LOOP(),
};

const BehaviorScript bhvMetalCap[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SILHOUETTE)),
    CALL_NATIVE(bhv_metal_cap_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_metal_cap_loop),
    END_LOOP(),
};

const BehaviorScript bhvNormalCap[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SILHOUETTE)),
    CALL_NATIVE(bhv_normal_cap_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_normal_cap_loop),
    END_LOOP(),
};

const BehaviorScript bhvVanishCap[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SILHOUETTE)),
    CALL_NATIVE(bhv_vanish_cap_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wing_vanish_cap_loop),
    END_LOOP(),
};

const BehaviorScript bhvStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_collect_star_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_collect_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvStarSpawnCoordinates[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_collect_star_init),
    CALL_NATIVE(bhv_star_spawn_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_star_spawn_loop),
    END_LOOP(),
};

const BehaviorScript bhvHiddenRedCoinStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_hidden_red_coin_star_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hidden_red_coin_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvRedCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_INT(oIntangibleTimer, 0),
    SET_INT(oAnimState, OBJ_ANIM_STATE_INIT_ANIM),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_red_coin_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_red_coin_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvBowserCourseRedCoinStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_course_red_coin_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvDogBone[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_red_coin_init),
    CALL_NATIVE(bhv_dog_bone_init),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dog_bone_loop),
    END_LOOP(),
};

const BehaviorScript bhvFinalBowserCourseDogBoneStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_final_bowser_course_dog_bone_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvHiddenStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_hidden_star_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hidden_star_loop),
    END_LOOP(),
};

const BehaviorScript bhvHiddenStarTrigger[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hidden_star_trigger_loop),
    END_LOOP(),
};

const BehaviorScript bhvTtmRollingLog[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(ttm_seg7_collision_pitoune_2),
    SET_HOME(),
    SET_FLOAT(oCollisionDistance, 2000),
    CALL_NATIVE(bhv_ttm_rolling_log_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rolling_log_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLllVolcanoFallingTrap[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_falling_wall),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_volcano_trap_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLllRollingLog[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(lll_seg7_collision_pitoune),
    SET_HOME(),
    SET_FLOAT(oCollisionDistance, 2000),
    CALL_NATIVE(bhv_lll_rolling_log_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rolling_log_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhv1upWalking[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 30, /*Height*/ 30, /*Downwards offset*/ 0),
    SET_FLOAT(oGraphYOffset, 30),
    CALL_NATIVE(bhv_1up_common_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_1up_walking_loop),
    END_LOOP(),
};

const BehaviorScript bhv1upRunningAway[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 30, /*Height*/ 30, /*Downwards offset*/ 0),
    SET_FLOAT(oGraphYOffset, 30),
    CALL_NATIVE(bhv_1up_common_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_1up_running_away_loop),
    END_LOOP(),
};

const BehaviorScript bhv1upSliding[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 30, /*Height*/ 30, /*Downwards offset*/ 0),
    SET_FLOAT(oGraphYOffset, 30),
    CALL_NATIVE(bhv_1up_common_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_1up_sliding_loop),
    END_LOOP(),
};

const BehaviorScript bhv1Up[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 30, /*Height*/ 30, /*Downwards offset*/ 0),
    SET_FLOAT(oGraphYOffset, 30),
    CALL_NATIVE(bhv_1up_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_1up_loop),
    END_LOOP(),
};

const BehaviorScript bhv1upJumpOnApproach[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 30, /*Height*/ 30, /*Downwards offset*/ 0),
    SET_FLOAT(oGraphYOffset, 30),
    CALL_NATIVE(bhv_1up_common_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_1up_jump_on_approach_loop),
    END_LOOP(),
};

const BehaviorScript bhvHidden1up[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 30, /*Height*/ 30, /*Downwards offset*/ 0),
    SET_FLOAT(oGraphYOffset, 30),
    CALL_NATIVE(bhv_1up_common_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_1up_hidden_loop),
    END_LOOP(),
};

const BehaviorScript bhvHidden1upTrigger[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_1up_hidden_trigger_loop),
    END_LOOP(),
};

const BehaviorScript bhvHidden1upInPole[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 30, /*Height*/ 30, /*Downwards offset*/ 0),
    SET_FLOAT(oGraphYOffset, 30),
    CALL_NATIVE(bhv_1up_common_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_1up_hidden_in_pole_loop),
    END_LOOP(),
};

const BehaviorScript bhvHidden1upInPoleTrigger[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_1up_hidden_in_pole_trigger_loop),
    END_LOOP(),
};

const BehaviorScript bhvHidden1upInPoleSpawner[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_1up_hidden_in_pole_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvControllablePlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_THROW_MATRIX_FROM_TRANSFORM | OBJ_FLAG_UPDATE_TRANSFORM_FOR_THROW_MATRIX | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(hmc_seg7_collision_controllable_platform),
    SET_HOME(),
    CALL_NATIVE(bhv_controllable_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_controllable_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvControllablePlatformSub[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(hmc_seg7_collision_controllable_platform_sub),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_controllable_platform_sub_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBreakableBoxSmall[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_HOME(),
    CALL_NATIVE(bhv_breakable_box_small_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_breakable_box_small_loop),
    END_LOOP(),
};

const BehaviorScript bhvSlidingSnowMound[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sliding_snow_mound_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSnowMoundSpawn[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_snow_mound_spawn_loop),
    END_LOOP(),
};

const BehaviorScript bhvWdwSquareFloatingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wdw_seg7_collision_square_floating_platform),
    SET_FLOAT(oFloatingPlatformHeightOffset, 64),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_floating_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWdwSquareFloatingPlatform2[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wdw_seg7_collision_square_floating_platform2),
    SET_FLOAT(oFloatingPlatformHeightOffset, 64),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_floating_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWdwRectangularFloatingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(wdw_seg7_collision_rect_floating_platform),
    SET_FLOAT(oFloatingPlatformHeightOffset, 64),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_floating_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvJrbFloatingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(jrb_seg7_collision_floating_platform),
    SET_FLOAT(oFloatingPlatformHeightOffset, 64),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_floating_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvArrowLift[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(wdw_seg7_collision_arrow_lift),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_arrow_lift_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvOrangeNumber[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_HOME(),
    CALL_NATIVE(bhv_orange_number_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_orange_number_loop),
    END_LOOP(),
};

const BehaviorScript bhvMantaRay[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, manta_seg5_anims_05008EB4),
    ANIMATE(MANTA_ANIM_SWIM),
    CALL_NATIVE(bhv_manta_ray_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_manta_ray_loop),
    END_LOOP(),
};

const BehaviorScript bhvFallingPillar[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    CALL_NATIVE(bhv_falling_pillar_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_falling_pillar_loop),
    END_LOOP(),
};

const BehaviorScript bhvFallingPillarHitbox[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_falling_pillar_hitbox_loop),
    END_LOOP(),
};

const BehaviorScript bhvPillarBase[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(jrb_seg7_collision_pillar_base),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvJrbFloatingBox[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(jrb_seg7_collision_floating_box),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_jrb_floating_box_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvDecorativePendulum[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_decorative_pendulum_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_decorative_pendulum_loop),
    END_LOOP(),
};

const BehaviorScript bhvTreasureChestsShip[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DROP_TO_FLOOR(),
    CALL_NATIVE(bhv_treasure_chest_ship_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_treasure_chest_ship_loop),
    END_LOOP(),
};

const BehaviorScript bhvTreasureChestsJrb[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DROP_TO_FLOOR(),
    CALL_NATIVE(bhv_treasure_chest_jrb_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_treasure_chest_jrb_loop),
    END_LOOP(),
};

const BehaviorScript bhvTreasureChests[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DROP_TO_FLOOR(),
    CALL_NATIVE(bhv_treasure_chest_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_treasure_chest_loop),
    END_LOOP(),
};

const BehaviorScript bhvTreasureChestBottom[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DROP_TO_FLOOR(),
    CALL_NATIVE(bhv_treasure_chest_bottom_init),
    SET_INT(oIntangibleTimer, -1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_treasure_chest_bottom_loop),
    END_LOOP(),
};

const BehaviorScript bhvTreasureChestTop[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_treasure_chest_top_loop),
    END_LOOP(),
};

const BehaviorScript bhvMips[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, wf_mips_seg6_anims_06015634),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 50, /*Height*/ 75),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_mips_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mips_loop),
    END_LOOP(),
};

const BehaviorScript bhvYoshi[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, yoshi_seg5_anims_05024100),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 160, /*Height*/ 150),
    ANIMATE(YOSHI_ANIM_IDLE),
    SET_HOME(),
    CALL_NATIVE(bhv_yoshi_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_yoshi_loop),
    END_LOOP(),
};

const BehaviorScript bhvKoopa[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, koopa_seg6_anims_06011364),
    ANIMATE(KOOPA_ANIM_WALK),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 50, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 150),
    SET_FLOAT(oKoopaAgility, 1),
    CALL_NATIVE(bhv_koopa_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_koopa_update),
    END_LOOP(),
};

const BehaviorScript bhvKoopaRaceEndpoint[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SPAWN_CHILD_WITH_PARAM(/*Bhv param*/ 0, /*Model*/ MODEL_KOOPA_FLAG, /*Behavior*/ bhvKoopaFlag),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_koopa_race_endpoint_update),
    END_LOOP(),
};

const BehaviorScript bhvKoopaFlag[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    SET_INTERACT_TYPE(INTERACT_POLE),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 700),
    SET_INT(oIntangibleTimer, 0),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, koopa_flag_seg6_anims_06001028),
    ANIMATE(KOOPA_FLAG_ANIM_WAVE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pole_base_loop),
    END_LOOP(),
};

const BehaviorScript bhvPokey[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 60, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pokey_update),
    END_LOOP(),
};

const BehaviorScript bhvPokeyBodyPart[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 60, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BILLBOARD(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pokey_body_part_update),
    END_LOOP(),
};

const BehaviorScript bhvSwoop[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, swoop_seg6_anims_060070D0),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 50, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_init_room),
    SCALE(/*Unused*/ 0, /*Field*/ 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_swoop_update),
    END_LOOP(),
};

const BehaviorScript bhvFlyGuy[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, flyguy_seg8_anims_08011A64),
    ANIMATE(FLY_GUY_ANIM_FLYING),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 50, /*Gravity*/ 0, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 1000, /*Buoyancy*/ 600, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_init_room),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_TWIRL_BOUNCE),
    SET_FLOAT(oGraphYOffset, 30),
    SCALE(/*Unused*/ 0, /*Field*/ 150),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fly_guy_update),
    END_LOOP(),
};

const BehaviorScript bhvGoomba[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, goomba_seg8_anims_0801DA4C),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_goomba_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_goomba_update),
    END_LOOP(),
};

const BehaviorScript bhvGoombaTripletSpawner[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_goomba_triplet_spawner_update),
    END_LOOP(),
};

#ifdef FLOOMBAS
const BehaviorScript bhvFloomba[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    SET_INT(oIsFloomba, TRUE),
    GOTO(bhvGoomba + 1),
};

#ifdef INTRO_FLOOMBAS
const BehaviorScript bhvFloombaStartup[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    LOAD_ANIMATIONS(oAnimations, goomba_seg8_anims_0801DA4C),
    SET_INT(oIsFloomba, TRUE),
    SET_INT(oAction, FLOOMBA_ACT_STARTUP),
    OR_INT(oFlags, OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    CALL_NATIVE(bhv_goomba_init),
    SET_FLOAT(oDrawingDistance, 30000),
    SET_INT(oIntangibleTimer, -1),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ 0, /*Bounciness*/ 0, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_goomba_update),
    END_LOOP(),
};

#define DOG_ANIM_BARK 7
const BehaviorScript bhvDogStartup[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    OR_INT(oFlags, OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    ANIMATE(DOG_ANIM_BARK),
    CALL_NATIVE(bhv_intro_object_init),
    SET_FLOAT(oDrawingDistance, 30000),
    SET_INT(oIntangibleTimer, -1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_intro_object_loop),
    END_LOOP(),
};
#endif

const BehaviorScript bhvFloombaTripletSpawner[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    SET_INT(oIsFloomba, TRUE),
    GOTO(bhvGoombaTripletSpawner + 1),
};
#endif

const BehaviorScript bhvChainChomp[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    // Yoshi Milkman: Commented this part out for my level
    // DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, chain_chomp_seg6_anims_06025178),
    ANIMATE(CHAIN_CHOMP_ANIM_CHOMPING),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    HIDE(),
    SET_HOME(),
    SET_FLOAT(oGraphYOffset, 240),
    SCALE(/*Unused*/ 0, /*Field*/ 200),
    // Yoshi Milkman: Commented this part out for my level
    // SPAWN_CHILD_WITH_PARAM(/*Bhv param*/ 0, /*Model*/ MODEL_WOODEN_POST, /*Behavior*/ bhvWoodenPost),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_chain_chomp_update),
    END_LOOP(),
};

const BehaviorScript bhvChainChompChainPart[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_FLOAT(oGraphYOffset, 40),
    SCALE(/*Unused*/ 0, /*Field*/ 200),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_chain_chomp_chain_part_update),
    END_LOOP(),
};

const BehaviorScript bhvWoodenPost[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(poundable_pole_collision_wooden_post),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_INT(oNumLootCoins, 5),
    DROP_TO_FLOOR(),
    SET_HOME(),
    SCALE(/*Unused*/ 0, /*Field*/ 50),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wooden_post_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvChainChompGate[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(bob_seg7_collision_chain_chomp_gate),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_chain_chomp_gate_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_chain_chomp_gate_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWigglerHead[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, wiggler_seg5_anims_0500EC8C),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 60, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    HIDE(),
    SCALE(/*Unused*/ 0, /*Field*/ 400),
    SET_FLOAT(oWigglerFallThroughFloorsHeight, 5000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wiggler_update),
    END_LOOP(),
};

const BehaviorScript bhvWigglerBody[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, wiggler_seg5_anims_0500C874),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 400),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wiggler_body_part_update),
    END_LOOP(),
};

const BehaviorScript bhvEnemyLakitu[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, lakitu_enemy_seg5_anims_050144D4),
    ANIMATE(ENEMY_LAKITU_ANIM_SPAWN),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_enemy_lakitu_update),
    END_LOOP(),
};

const BehaviorScript bhvCameraLakitu[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, lakitu_seg6_anims_060058F8),
    ANIMATE(CAMERA_LAKITU_ANIM_DEFAULT),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_camera_lakitu_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_camera_lakitu_update),
    END_LOOP(),
};

const BehaviorScript bhvCloud[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_HOME(),
    SET_INT(oOpacity, 240),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cloud_update),
    END_LOOP(),
};

const BehaviorScript bhvCloudPart[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oOpacity, 240),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cloud_part_update),
    END_LOOP(),
};

const BehaviorScript bhvSpiny[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, spiny_seg5_anims_05016EAC),
    ANIMATE(SPINY_ANIM_DEFAULT),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_spiny_update),
    END_LOOP(),
};

const BehaviorScript bhvMontyMole[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, monty_mole_seg5_anims_05007248),
    ANIMATE(MONTY_MOLE_ANIM_BEGIN_JUMP_INTO_HOLE),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    HIDE(),
    SET_INT(oIntangibleTimer, -1),
    SET_FLOAT(oGraphYOffset, -60),
    SCALE(/*Unused*/ 0, /*Field*/ 150),
    DELAY(1),
    CALL_NATIVE(bhv_monty_mole_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_monty_mole_update),
    END_LOOP(),
};

const BehaviorScript bhvMontyMoleHole[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SCALE(/*Unused*/ 0, /*Field*/ 150),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_monty_mole_hole_update),
    END_LOOP(),
};

const BehaviorScript bhvMontyMoleRock[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_FLOAT(oGraphYOffset, 10),
    SCALE(/*Unused*/ 0, /*Field*/ 200),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_monty_mole_rock_update),
    END_LOOP(),
};

const BehaviorScript bhvPlatformOnTrack[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 50, /*Gravity*/ -100, /*Bounciness*/ -50, /*Drag strength*/ 100, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_platform_on_track_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_platform_on_track_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTrackBall[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    CALL_NATIVE(bhv_init_room),
    SCALE(/*Unused*/ 0, /*Field*/ 15),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_track_ball_update),
    END_LOOP(),
};

const BehaviorScript bhvSeesawPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_seesaw_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_seesaw_platform_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFerrisWheelAxle[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    ADD_INT(oMoveAngleYaw, 0x4000),
    CALL_NATIVE(bhv_ferris_wheel_axle_init),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleRoll, 400),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFerrisWheelPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ferris_wheel_platform_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWaterBombSpawner[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_bomb_spawner_update),
    END_LOOP(),
};

const BehaviorScript bhvWaterBomb[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 120, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_bomb_update),
    END_LOOP(),
};

const BehaviorScript bhvWaterBombShadow[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SCALE(/*Unused*/ 0, /*Field*/ 150),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_bomb_shadow_update),
    END_LOOP(),
};

const BehaviorScript bhvTTCRotatingSolid[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_FLOAT(oCollisionDistance, 450),
    CALL_NATIVE(bhv_ttc_rotating_solid_init),
    SET_INT(oTTCRotatingSolidNumTurns, 1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ttc_rotating_solid_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTTCPendulum[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(ttc_seg7_collision_clock_pendulum),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oCollisionDistance, 1500),
    CALL_NATIVE(bhv_ttc_pendulum_init),
    SET_FLOAT(oTTCPendulumAccelDir, 1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ttc_pendulum_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTTCTreadmill[] = {
    BEGIN(OBJ_LIST_SURFACE),
#ifdef PLATFORM_DISPLACEMENT_2
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_VELOCITY_PLATFORM)),
#else
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
#endif
    SET_FLOAT(oCollisionDistance, 750),
    CALL_NATIVE(bhv_ttc_treadmill_init),
    DELAY(1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ttc_treadmill_update),
        CALL_NATIVE(cur_obj_compute_vel_xz),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTTCMovingBar[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(ttc_seg7_collision_sliding_surface),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_FLOAT(oCollisionDistance, 550),
    CALL_NATIVE(bhv_ttc_moving_bar_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ttc_moving_bar_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTTCCog[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oCollisionDistance, 400),
    CALL_NATIVE(bhv_ttc_cog_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ttc_cog_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTTCPitBlock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_FLOAT(oCollisionDistance, 350),
    CALL_NATIVE(bhv_ttc_pit_block_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ttc_pit_block_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTTCElevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(ttc_seg7_collision_clock_platform),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_FLOAT(oCollisionDistance, 400),
    CALL_NATIVE(bhv_ttc_elevator_init),
    SET_FLOAT(oTTCElevatorDir, 1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ttc_elevator_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTTC2DRotator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(ttc_seg7_collision_clock_main_rotation),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oCollisionDistance, 1800),
    CALL_NATIVE(bhv_ttc_2d_rotator_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ttc_2d_rotator_update),
    END_LOOP(),
};

const BehaviorScript bhvTTCSpinner[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(ttc_seg7_collision_rotating_clock_platform2),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oCollisionDistance, 450),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ttc_spinner_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvMrBlizzard[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, snowman_seg5_anims_0500D118),
    ANIMATE(MR_BLIZZARD_ANIM_SPAWN_SNOWBALL),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_mr_blizzard_init),
    SET_FLOAT(oMrBlizzardScale, 1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mr_blizzard_update),
    END_LOOP(),
};

const BehaviorScript bhvMrBlizzardSnowball[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -300, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 200),
    ADD_INT(oMoveAngleYaw, -0x5B58),
    SET_FLOAT(oForwardVel, 5),
    SET_FLOAT(oVelY, -1),
    SET_FLOAT(oGraphYOffset, 10),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mr_blizzard_snowball),
    END_LOOP(),
};

const BehaviorScript bhvSlidingPlatform2[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    CALL_NATIVE(bhv_sliding_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sliding_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvOctagonalPlatformRotating[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_rotating_octagonal_plat_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rotating_octagonal_plat_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvAnimatesOnFloorSwitchPress[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_FLOAT(oCollisionDistance, 8000),
    CALL_NATIVE(bhv_animates_on_floor_switch_press_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_animates_on_floor_switch_press_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvActivatedBackAndForthPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    CALL_NATIVE(bhv_activated_back_and_forth_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_activated_back_and_forth_platform_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvRecoveryHeart[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_recovery_heart_loop),
    END_LOOP(),
};

const BehaviorScript bhvWaterBombCannon[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_water_bomb_cannon_loop),
    END_LOOP(),
};

const BehaviorScript bhvCannonBarrelBubbles[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bubble_cannon_barrel_loop),
    END_LOOP(),
};

const BehaviorScript bhvUnagi[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, unagi_seg5_anims_05012824),
    ANIMATE(UNAGI_ANIM_IDLE_2),
    SET_HOME(),
    SCALE(/*Unused*/ 0, /*Field*/ 300),
    SET_FLOAT(oDrawingDistance, 6000),
    CALL_NATIVE(bhv_unagi_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_unagi_loop),
    END_LOOP(),
};

const BehaviorScript bhvUnagiSubobject[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_unagi_subobject_loop),
    END_LOOP(),
};

const BehaviorScript bhvDorrie[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(dorrie_seg6_collision_0600F644),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dorrie_seg6_anims_0600F638),
    SET_HOME(),
    SET_FLOAT(oCollisionDistance, 30000),
    ADD_FLOAT(oPosX, 2000),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dorrie_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvHauntedChair[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, chair_seg5_anims_05005784),
    ANIMATE(HAUNTED_CHAIR_ANIM_DEFAULT),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_haunted_chair_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_haunted_chair_loop),
    END_LOOP(),
};

const BehaviorScript bhvMadPiano[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, mad_piano_seg5_anims_05009B14),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    ADD_INT(oMoveAngleYaw, 0x4000),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mad_piano_update),
    END_LOOP(),
};

const BehaviorScript bhvFlyingBookend[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, bookend_seg5_anims_05002540),
    ANIMATE(FLYING_BOOKEND_ANIM_SPAWN),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 60, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_INT(oMoveFlags, OBJ_MOVE_NONE),
    SCALE(/*Unused*/ 0, /*Field*/ 70),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_flying_bookend_loop),
    END_LOOP(),
};

const BehaviorScript bhvBookendSpawn[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bookend_spawn_loop),
    END_LOOP(),
};

const BehaviorScript bhvHauntedBookshelfManager[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_haunted_bookshelf_manager_loop),
    END_LOOP(),
};

const BehaviorScript bhvBookSwitch[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_FLOAT(oGraphYOffset, 30),
    ADD_INT(oMoveAngleYaw, 0x4000),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_book_switch_loop),
    END_LOOP(),
};

const BehaviorScript bhvFirePiranhaPlant[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, piranha_plant_seg6_anims_0601C31C),
    ANIMATE(FIRE_PIRANHA_PLANT_ANIM_SHRINK),
    SET_HOME(),
    HIDE(),
    CALL_NATIVE(bhv_fire_piranha_plant_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fire_piranha_plant_update),
    END_LOOP(),
};

const BehaviorScript bhvMovingFlame[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_moving_flame_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvMovingFlameEmber[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ 200, /*Bounciness*/ 0, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_moving_flame_particle_loop),
        ADD_INT(oAnimState, 1),
    END_LOOP(),
};

const BehaviorScript bhvFireSpitter[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SCALE(/*Unused*/ 0, /*Field*/ 40),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fire_spitter_update),
    END_LOOP(),
};

const BehaviorScript bhvSnufit[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        SET_INT(oSnufitRecoil, 0),
        CALL_NATIVE(bhv_snufit_loop),
    END_LOOP(),
};

const BehaviorScript bhvSnufitBalls[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 10, /*Gravity*/ 0, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_init_room),
    SET_FLOAT(oGraphYOffset, 10),
    SCALE(/*Unused*/ 0, /*Field*/ 10),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_snufit_balls_loop),
    END_LOOP(),
};

const BehaviorScript bhvHorizontalGrindel[] = {
    BEGIN(OBJ_LIST_SURFACE),
    //LOAD_COLLISION_DATA(ssl_seg7_collision_grindel),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DROP_TO_FLOOR(),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 90),
    CALL_NATIVE(bhv_horizontal_grindel_init),
    BEGIN_LOOP(),
        CALL_NATIVE(cur_obj_update_floor_and_walls),
        CALL_NATIVE(bhv_horizontal_grindel_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvEyerokBoss[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_eyerok_boss_loop),
    END_LOOP(),
};

const BehaviorScript bhvEyerokHand[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, eyerok_seg5_anims_050116E4),
    ANIMATE(EYEROK_HAND_ANIM_SLEEPING),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 150, /*Gravity*/ 0, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    SET_INT(oAnimState, EYEROK_HAND_ANIM_STATE_EYE_CLOSED),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_eyerok_hand_loop),
    END_LOOP(),
};

const BehaviorScript bhvKlepto[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, klepto_seg5_anims_05008CFC),
    ANIMATE(KLEPTO_ANIM_DIVE_0),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 100, /*Gravity*/ 0, /*Bounciness*/ -20, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    CALL_NATIVE(bhv_klepto_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_klepto_update),
    END_LOOP(),
};

const BehaviorScript bhvBird[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, birds_seg5_anims_050009E8),
    ANIMATE(BIRD_ANIM_FLY),
    HIDE(),
    SCALE(/*Unused*/ 0, /*Field*/ 70),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bird_update),
    END_LOOP(),
};

const BehaviorScript bhvRacingPenguin[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, penguin_seg5_anims_05008B74),
    ANIMATE(PENGUIN_ANIM_IDLE),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 300, /*Gravity*/ -800, /*Bounciness*/ -5, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 400),
    CALL_NATIVE(bhv_racing_penguin_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_racing_penguin_update),
    END_LOOP(),
};

const BehaviorScript bhvPenguinRaceFinishLine[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_penguin_race_finish_line_update),
    END_LOOP(),
};

const BehaviorScript bhvPenguinRaceShortcutCheck[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_penguin_race_shortcut_check_update),
    END_LOOP(),
};

const BehaviorScript bhvCoffinSpawner[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_coffin_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvCoffin[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(bbh_seg7_collision_coffin),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_coffin_loop),
    END_LOOP(),
};

const BehaviorScript bhvClamShell[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, clam_shell_seg5_anims_05001744),
    SET_FLOAT(oGraphYOffset, 10),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_clam_loop),
    END_LOOP(),
};

const BehaviorScript bhvSkeeter[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, skeeter_seg6_anims_06007DE0),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 180, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 1200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_skeeter_update),
    END_LOOP(),
};

const BehaviorScript bhvSkeeterWave[] = {
    BEGIN(OBJ_LIST_UNIMPORTANT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_skeeter_wave_update),
    END_LOOP(),
};

const BehaviorScript bhvSwingPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(rr_seg7_collision_pendulum),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oCollisionDistance, 2000),
    CALL_NATIVE(bhv_swing_platform_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_swing_platform_update),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvDonutPlatformSpawner[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_donut_platform_spawner_update),
    END_LOOP(),
};

const BehaviorScript bhvDonutPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(rr_seg7_collision_donut_platform),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_donut_platform_update),
    END_LOOP(),
};

const BehaviorScript bhvDDDPole[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    SET_INTERACT_TYPE(INTERACT_POLE),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 800),
    SET_INT(oIntangibleTimer, 0),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HOME(),
    CALL_NATIVE(bhv_ddd_pole_init),
    SET_FLOAT(oDDDPoleVel, 10),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ddd_pole_update),
        CALL_NATIVE(bhv_pole_base_loop),
    END_LOOP(),
};

const BehaviorScript bhvRedCoinStarMarker[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    DROP_TO_FLOOR(),
    SCALE(/*Unused*/ 0, /*Field*/ 150),
    SET_INT(oFaceAnglePitch, 0x4000),
    ADD_FLOAT(oPosY, 60),
    CALL_NATIVE(bhv_red_coin_star_marker_init),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleYaw, 0x100),
    END_LOOP(),
};

const BehaviorScript bhvRedCoinStarMarkerNoDrop[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SCALE(/*Unused*/ 0, /*Field*/ 150),
    SET_INT(oFaceAnglePitch, 0x4000),
    ADD_FLOAT(oPosY, -200),
    CALL_NATIVE(bhv_red_coin_star_marker_init),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleYaw, 0x100),
    END_LOOP(),
};

const BehaviorScript bhvTripletButterfly[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, butterfly_seg3_anims_030056B0),
    ANIMATE(BUTTERFLY_ANIM_FLYING),
    HIDE(),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ 0, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_FLOAT(oTripletButterflyScale, 1),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_triplet_butterfly_update),
    END_LOOP(),
};

const BehaviorScript bhvBubba[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 200, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 50),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bubba_loop),
    END_LOOP(),
};

const BehaviorScript bhvBeginningLakitu[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, lakitu_seg6_anims_060058F8),
    ANIMATE(INTRO_LAKITU_ANIM_DEFAULT),
    SET_INT(oOpacity, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_intro_lakitu_loop),
    END_LOOP(),
};

const BehaviorScript bhvBeginningPeach[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, peach_seg5_anims_0501C41C),
    ANIMATE(PEACH_ANIM_0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_intro_peach_loop),
    END_LOOP(),
};

const BehaviorScript bhvEndBirds1[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, birds_seg5_anims_050009E8),
    ANIMATE(END_BIRDS_ANIM_FLY),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_end_birds_1_loop),
    END_LOOP(),
};

const BehaviorScript bhvEndBirds2[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, birds_seg5_anims_050009E8),
    ANIMATE(END_BIRDS_ANIM_FLY),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_end_birds_2_loop),
    END_LOOP(),
};

const BehaviorScript bhvIntroScene[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_intro_scene_loop),
    END_LOOP(),
};

const BehaviorScript bhvRex[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, rex_anims),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_rex_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rex_update),
    END_LOOP(),
};

const BehaviorScript bhvGaloomba[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, galoomba_anims),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_galoomba_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_galoomba_update),
    END_LOOP(),
};

const BehaviorScript bhvBlooper[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    LOAD_ANIMATIONS(oAnimations, blooper_anims),
    ANIMATE(0),
    CALL_NATIVE(bhv_blooper_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_blooper_update),
    END_LOOP(),
};

const BehaviorScript bhvBlargg[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    LOAD_ANIMATIONS(oAnimations, blargg_anims),
    ANIMATE(0),
    CALL_NATIVE(bhv_blargg_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_blargg_update),
    END_LOOP(),
};

const BehaviorScript bhvBuzzyBeetle[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    SET_INT(oIntangibleTimer, 0),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, buzzy_beetle_anims),
    ANIMATE(1),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_buzzy_beetle_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_buzzy_beetle_update),
    END_LOOP(),
};

const BehaviorScript bhvNipper[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 80, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),SET_HOME(),
    DROP_TO_FLOOR(),
    SCALE(/*Unused*/ 0, /*Field*/ 25),
    LOAD_ANIMATIONS(oAnimations, nipper_anims),
    ANIMATE(0),
    CALL_NATIVE(bhv_nipper_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_nipper_update),
    END_LOOP(),
};

const BehaviorScript bhvCleft[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, cleft_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_cleft_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cleft_update),
    END_LOOP(),
};

const BehaviorScript bhvStrollinStu[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, strollin_stu_anims),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_strollin_stu_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_strollin_stu_update),
    END_LOOP(),
};

const BehaviorScript bhvLaserRingSpawner[] = {
    BEGIN(OBJ_LIST_SURFACE),
    SET_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SCALE(0, 200),
    CALL_NATIVE(bhv_laser_ring_spawner_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_laser_ring_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvLaserRing[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    SET_INTERACT_TYPE(INTERACT_SHOCK),
    SET_INT(oDamageOrCoinValue, 2),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_laser_ring_init),
    SET_FLOAT(oDrawingDistance, 8000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_laser_ring_loop),
    END_LOOP(),
};

const BehaviorScript bhvSpike[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, spike_anims),
    CALL_NATIVE(bhv_spike_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_spike_update),
    END_LOOP(),
};

const BehaviorScript bhvSpikeBall[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, spike_ball_anims),
    SET_HOME(),
    CALL_NATIVE(bhv_spike_ball_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_spike_ball_loop),
    END_LOOP(),
};

const BehaviorScript bhvPodoboo[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    SET_HOME(),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 80, /*Height*/ 50, /*Downwards offset*/ 25),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        SET_INT(oInteractStatus, 0),
        CALL_NATIVE(bhv_podoboo_loop),
    END_LOOP(),
};

const BehaviorScript bhvDogNPC[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*/ 50, /*Height*/ 30),
    ANIMATE(0),
    SCALE(0, 50),
    SET_INT(oBobombBuddyRole, 0),
    SET_HOME(),
    CALL_NATIVE(bhv_bobomb_buddy_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bobomb_buddy_loop),
    END_LOOP(),
};

//START ROVERT BEHAVIOR

const BehaviorScript bhvDirtPile[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(dirt_patch_collision),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sand_pile),
    END_LOOP(),
};

const BehaviorScript bhvCherryTree[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(cherry_tree_collision),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cherry_tree_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTreeNut[] = {
	BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    //SET_INT(oInteractionSubtype, INT_SUBTYPE),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 80),
    SET_HOME(),
    //SET_INT(oIntangibleTimer, 0),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
	CALL_NATIVE(bhv_tree_nut_init),
    BEGIN_LOOP(),
		CALL_NATIVE(bhv_tree_nut_loop),
	END_LOOP(),
};

const BehaviorScript bhvDogForSC[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    ANIMATE(2),
    BEGIN_LOOP(),
    CALL_NATIVE(bhv_goddard_clown_fight_init),
    END_LOOP(),
};

const BehaviorScript bhvCarousel[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_ANIMATIONS(oAnimations, carousel_anims),
    LOAD_COLLISION_DATA(carousel_collision),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_carousel_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_carousel_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCarouselBits[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_ANIMATIONS(oAnimations, carousel_bits_anims),
    LOAD_COLLISION_DATA(carousel_bits_collision),
    GOTO(bhvCarousel + 1 + 2 + 2),
};

const BehaviorScript bhvPowerSwitch[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_power_switch_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_power_switch_loop),
    END_LOOP(),
};

const BehaviorScript bhvCircusCannon[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_circus_cannon_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_circus_cannon_loop),
    END_LOOP(),
};

const BehaviorScript bhvMagmaThwomp[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(magma_thwomp_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    DROP_TO_FLOOR(),
    ADD_FLOAT(oPosY, 1),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_Magma_Thwomp),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvClownClock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(clown_clock_collision),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_clown_clock_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_clown_clock_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvClownClockBits[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(clown_clock_bits_collision),
    GOTO(bhvClownClock + 1 + 2),
};

const BehaviorScript bhvClownDoorSpawner[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    SET_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    CALL_NATIVE(bhv_clown_door_spawner_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_clown_door_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvClownDoorSegmentTop[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(clown_door_top_collision),
    SET_INT(oInteractType, INTERACT_DOOR),
    SET_FLOAT(oDrawingDistance, 10000),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_clown_door_segment_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvClownDoorSegmentTopBits[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(clown_door_top_bits_collision),
    GOTO(bhvClownDoorSegmentTop + 1 + 2),
};

const BehaviorScript bhvClownDoorSegmentBottom[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(clown_door_bottom_collision),
    SET_INT(oInteractType, INTERACT_DOOR),
    SET_FLOAT(oDrawingDistance, 10000),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_clown_door_segment_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvClownDoorSegmentBottomBits[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(clown_door_bottom_bits_collision),
    GOTO(bhvClownDoorSegmentBottom + 1 + 2),
};

const BehaviorScript bhvCircusWheel[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
    ADD_INT(oMoveAngleYaw, 0x4000),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_circus_wheel_init),
    BEGIN_LOOP(),
        ADD_INT(oFaceAngleRoll, 50),
        CALL_NATIVE(bhv_circus_wheel_loop),
    END_LOOP(),
};

const BehaviorScript bhvCircusWheelPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
    LOAD_COLLISION_DATA(cable_car_collision),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_circus_wheel_platform_update),
    END_LOOP(),
};

const BehaviorScript bhvPinwheel[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_pinwheel_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pinwheel_loop),
    END_LOOP(),
};

const BehaviorScript bhvCircusBalloon[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(circus_balloon_collision),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_balloon_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_balloon_loop),
    END_LOOP(),
};

const BehaviorScript bhvCircusBalloonCol[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(circus_balloon_collision),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST),
    SET_FLOAT(oCollisionDistance, 1500),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCircusBalloonBits[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(circus_balloon_bits_collision),
    GOTO(bhvCircusBalloon + 1 + 2),
};

const BehaviorScript bhvCircusBalloonColBits[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(circus_balloon_bits_collision),
    GOTO(bhvCircusBalloonCol + 1 + 2),
};

const BehaviorScript bhvWheelWind[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wheel_wind_loop),
    END_LOOP(),
};

const BehaviorScript bhvTrapeze[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_trapeze_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_trapeze_loop),
    END_LOOP(),
};

const BehaviorScript bhvTrapezeHitbox[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_trapeze_hitbox_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_trapeze_hitbox_loop),
    END_LOOP(),
};

const BehaviorScript bhvCircusPole[] = {
    BEGIN(OBJ_LIST_POLELIKE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oInteractType, INTERACT_POLE),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 1500),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_pole_init),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_pole_base_loop),
        
    END_LOOP(),
};

const BehaviorScript bhvBalloonPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(balloon_platform_collision),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_balloon_platform_loop),
    END_LOOP(),
};

const BehaviorScript bhvBalloonPlatformBits[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(balloon_platform_bits_collision),
    GOTO(bhvBalloonPlatform + 1 + 2),
};

const BehaviorScript bhvSteelGate[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
    LOAD_COLLISION_DATA(steel_gate_collision),
    SET_FLOAT(oDrawingDistance, 15500),
    CALL_NATIVE(bhv_steel_gate_init),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvClownBoss[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, clown_boss_anims),
    //SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ 5.5, /*Bounciness*/ 1, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    ANIMATE(0),
    SET_HOME(),
    DROP_TO_FLOOR(),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_clown_boss_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_clown_boss_loop),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvBossCurtains[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    OR_LONG(oFlags, OBJ_FLAG_UCODE_LARGE),
    LOAD_COLLISION_DATA(boss_curtains_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_boss_curtains_loop),
    END_LOOP(),
};

const BehaviorScript bhvGoddardClownFight[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_goddard_clown_fight_loop),
    END_LOOP(),
};

const BehaviorScript bhvClownToad[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, clown_toad_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    ANIMATE(0),
    SET_INT(oBobombBuddyRole, 0),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 10500),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_bobomb_buddy_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bobomb_buddy_loop),
        CALL_NATIVE(bhv_clown_toad_loop),
    END_LOOP(),
};

const BehaviorScript bhvKidToad[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, kid_toad_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    SET_INT(oBobombBuddyRole, 0),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 10500),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_kid_toad_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        //CALL_NATIVE(bhv_bobomb_buddy_loop),
    END_LOOP(),
};

const BehaviorScript bhvSwingBoard[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(swing_board_collision),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_swing_Board),
    END_LOOP(),
};

const BehaviorScript bhvPropaneThrower[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
    SET_INTERACT_TYPE(INTERACT_IGLOO_BARRIER),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 200),
    SET_INT(oIntangibleTimer, 0),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    BEGIN_LOOP(),
        SET_INT(oInteractStatus, 0),
        CALL_NATIVE(bhv_Propane_Shooter),
    END_LOOP(),
};

const BehaviorScript bhvPropane[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_HOME(),
    SCALE(/*Unused*/ 0, /*Field*/ 700),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 50, /*Height*/ 25, /*Downwards offset*/ 25),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        SET_INT(oInteractStatus, 0),
        ANIMATE_TEXTURE(oAnimState, 2),
        CALL_NATIVE(bhv_Propane_Flame),
    END_LOOP(),
};

const BehaviorScript bhvLavaGrate[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(lava_grate_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 1000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lava_grate_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCastleRaft[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(castle_raft_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 12000),
    SET_FLOAT(oCollisionDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_castle_raft),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvAshpile[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(ashpile_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 500),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ash_pile),
    END_LOOP(),
};

const BehaviorScript bhvAshpileBits[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(ashpile_bits_collision),
    GOTO(bhvAshpile + 1 + 2),
};

const BehaviorScript bhvAshpileEmu[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(ashpile_collision_emu),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 500),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_ash_pile),
    END_LOOP(),
};

const BehaviorScript bhvDogRovert[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_INTERACT_TYPE(INTERACT_IGLOO_BARRIER),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    ANIMATE(1),
    SET_HOME(),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
    END_LOOP(),
};

const BehaviorScript bhvRovertElevator[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(rovert_elevator_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 12000),
    SET_FLOAT(oCollisionDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rovert_elevator),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvRovertFling[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(rovert_fling_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 600),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rovert_fling),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvToadCage[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(toad_cage_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 600),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_toad_cage),
    END_LOOP(),
};

const BehaviorScript bhvRovertToad[] = {

    BEGIN(OBJ_LIST_LEVEL),
    SET_INT(oOpacity, 255),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, toad_seg6_anims_0600FB58),
    ANIMATE(6),
    SET_INTERACT_TYPE(INTERACT_IGLOO_BARRIER),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rovert_toad),
        SET_INT(oIntangibleTimer, 0),
    END_LOOP(),
};

const BehaviorScript bhvTankBase[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(tank_base_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 4000),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tank_base),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTankHead[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(tank_head_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_tank_head),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTankPropane[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SCALE(/*Unused*/ 0, /*Field*/ 700),
    SET_INTERACT_TYPE(INTERACT_FLAME),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 50, /*Height*/ 25, /*Downwards offset*/ 25),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        SET_INT(oInteractStatus, 0),
        ANIMATE_TEXTURE(oAnimState, 2),
        CALL_NATIVE(bhv_Tank_Propane_Flame),
    END_LOOP(),
};

const BehaviorScript bhv_rmine[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 110, /*Height*/ 40, /*Downwards offset*/ 0),
    DELAY(1),
    SET_FLOAT(oDrawingDistance, 2000),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bowser_bomb_loop),
    END_LOOP(),
};

const BehaviorScript bhvStaticMotos[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, motos_anime),
    SET_INT(oInteractType, INTERACT_IGLOO_BARRIER),
    SCALE(/*Unused*/ 0, /*Field*/ 200),
    ANIMATE(8),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_Launcher_Motos),
    END_LOOP(),
};

const BehaviorScript bhvMissile[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 80, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_missile_loop),
    END_LOOP(),
};

//END ROVERT BEHAVIOR

const BehaviorScript bhvBounceCloud[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(bounce_cloud_collision),
    SET_FLOAT(oDrawingDistance, 0x3000),
    SET_HOME(),
    CALL_NATIVE(bhv_bounce_cloud_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_bounce_cloud_loop),
    END_LOOP(),
};


const BehaviorScript bhvStretchCloud[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(stretch_cloud_collision),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_FLOAT(oCollisionDistance, 0x600),
    CALL_NATIVE(bhv_stretch_cloud_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_stretch_cloud_loop),
    END_LOOP(),
};

const BehaviorScript bhvRainbowCloud[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, rainbow_cloud_anims),
    ANIMATE(1),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_HOME(),
    //CALL_NATIVE(bhv_rainbow_cloud_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rainbow_cloud_loop),
    END_LOOP(),
};

const BehaviorScript bhvRainbowCloudSpawner[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_rainbow_cloud_spawner_loop),
    END_LOOP(),
};


const BehaviorScript bhvCloudRainbow[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(cloud_rainbow_collision),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_FLOAT(oCollisionDistance, 0x1400),
    SET_HOME(),
    //CALL_NATIVE(bhv_cloud_rainbow_init),
    BEGIN_LOOP(),
        // CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_cloud_rainbow_loop),
    END_LOOP(),
};

const BehaviorScript bhvCRainCloud[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(rain_cloud_collision),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_HOME(),
    //CALL_NATIVE(bhv_rain_cloud_init),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_rain_cloud_loop),
    END_LOOP(),
};



const BehaviorScript bhvFadeCloud[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(fade_cloud_collision),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_FLOAT(oCollisionDistance, 0x600),
    SET_HOME(),
    SET_INT(oOpacity, 255),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_fade_cloud_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fade_cloud_loop),
    END_LOOP(),
};

const BehaviorScript bhvFadeCloudBits[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(fade_cloud_bits_collision),
    GOTO(bhvFadeCloud + 1 + 2),
};


const BehaviorScript bhvBodyLakitu[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    LOAD_ANIMATIONS(oAnimations, body_lakitu_anims),
    SET_FLOAT(oDrawingDistance, 0x5000),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NPC),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 110, /*Height*/ 60),
    ANIMATE(1),
    SET_HOME(),
    SCALE(0, 150),
    CALL_NATIVE(bhv_body_lakitu_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_body_lakitu_loop),
    END_LOOP(),
};

const BehaviorScript bhvMinigameFwoosh[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BILLBOARD(),
    SET_HOME(),
    SET_INT(oOpacity, 240),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mg_fwoosh_update),
    END_LOOP(),
};


const BehaviorScript bhvFwooshButton[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(fwoosh_step_button_collision),
    SET_FLOAT(oDrawingDistance, 0x4000),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fwoosh_button_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};


const BehaviorScript bhvMetalCrate[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(metal_crate_collision),
    SET_FLOAT(oDrawingDistance, 0x7FFF),
    SET_FLOAT(oCollisionDistance, 0x7FFF),
    SET_HOME(),
    CALL_NATIVE(bhv_metal_crate_init),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_metal_crate_loop),
    END_LOOP(),
};


const BehaviorScript bhvFwooshMGHandler[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    CALL_NATIVE(bhv_fwooshmg_handler_init),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fwooshmg_handler_update),
    END_LOOP(),
};


const BehaviorScript bhvFwooshMGGoomba[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, goomba_seg8_anims_0801DA4C),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 40, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    CALL_NATIVE(bhv_goomba_init),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fwooshmg_goomba_update),
    END_LOOP(),
};

const BehaviorScript bhvFwooshMGKoopa[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, koopa_seg6_anims_06011364),
    ANIMATE(9),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 50, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 160),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fwooshmg_koopa_update),
    END_LOOP(),
};


const BehaviorScript bhvFwooshMGStar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_fwooshmg_star_loop),
    END_LOOP(),
};


const BehaviorScript bhvMistTrigger[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 100),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_mist_trigger_loop),
    END_LOOP(),
};

const BehaviorScript bhvLightningCloud[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, lightning_cloud_anims),
    ANIMATE(2),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_HOME(),
    CALL_NATIVE(bhv_rainbow_cloud_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lightning_cloud_loop),
    END_LOOP(),
};

const BehaviorScript bhvLightningBolt[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_HOME(),
    CALL_NATIVE(bhv_lightning_bolt_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lightning_bolt_loop),
    END_LOOP(),
};


const BehaviorScript bhvFloorDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(floor_door_collision),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_FLOAT(oCollisionDistance, 0x500),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_floor_door_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFloorDoorButton[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(fwoosh_button_collision),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_FLOAT(oCollisionDistance, 0x500),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_floor_door_button_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvLightningStrike[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_INT(oIntangibleTimer, 0),
    SET_HOME(),
    CALL_NATIVE(bhv_lightning_strike_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lightning_strike_loop),
    END_LOOP(),
};

const BehaviorScript bhvLightningBlast[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lightning_blast_loop),
    END_LOOP(),
};


const BehaviorScript bhvCenterPlatform[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_COLLISION_DATA(center_platform_collision),
    SET_FLOAT(oDrawingDistance, 0x7FFF),
    SET_FLOAT(oCollisionDistance, 0x4000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_center_platform_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

//START EMU BEHAVIOR
const BehaviorScript bhvRotatingTorus[] = {
   BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    ADD_FLOAT(oPosY, 1),
    LOAD_COLLISION_DATA(rainbow_chain_collision),
    SET_FLOAT(oCollisionDistance, 8000),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_HOME(),
    BEGIN_LOOP(),
        ADD_INT(oFaceAnglePitch, -150),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSphere[] = {
     BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    ADD_FLOAT(oPosY, 1),
    LOAD_COLLISION_DATA(sphere_collision),
    SET_FLOAT(oCollisionDistance, 8000),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_emu_sphere),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvPaletteSwap[] = {
    BEGIN_LOOP(),
    CALL_NATIVE(palette_swap),
    END_LOOP(),
};

const BehaviorScript bhvGoddardCage[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oIntangibleTimer, 0),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 40, /*Height*/ 40, /*Downwards offset*/ 40),
    SPAWN_CHILD(/*Model*/ MODEL_NONE, /*Behavior*/ bhvGoddardCageCOL),
    SPAWN_CHILD(/*Model*/ MODEL_DOG, /*Behavior*/ bhvDogEmu),
    DELAY(1),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_goddard_cage_loop),
    END_LOOP(),
};

const BehaviorScript bhvGoddardCageCOL[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(cage_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_goddard_cageCOL_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvDogEmu[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    ANIMATE(0),
    ADD_INT(oMoveAngleYaw, 0x8000),
    CALL_NATIVE(bhv_idle_dog_init),
    SCALE(/*Unused*/ 0, /*Field*/ 50),
    SET_HOME(),
    BEGIN_LOOP(),
    CALL_NATIVE(cur_obj_rotate_face_angle_using_vel),
        CALL_NATIVE(bhv_idle_dog_loop),
    END_LOOP(),
};

const BehaviorScript bhvAttackableAmp[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dAmpAnimsList),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 100),
    ANIMATE(0),
    SET_FLOAT(oGraphYOffset, 40),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_attackable_amp_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_attackable_amp_loop),
    END_LOOP(),
};

const BehaviorScript bhvEmuBomb[] = {
    BEGIN(OBJ_LIST_DESTRUCTIVE),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    SET_INT(oIntangibleTimer, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 50),
    SET_HOME(),
    CALL_NATIVE(bhv_emu_bomb_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_emu_bomb_loop),
    END_LOOP(),
};
// END EMU BEHAVIOR

// axo start
const BehaviorScript bhvCephie[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, cephie_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*/ 80, /*Height*/ 100),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_cephie_init),
    SET_HOME(),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_cephie_loop),
    END_LOOP(),
};
// axo end

const BehaviorScript bhvLightningButton[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_COLLISION_DATA(fwoosh_button_collision),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_FLOAT(oCollisionDistance, 0x500),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_lightning_button_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvBonusLightningCloud[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, lightning_cloud_anims),
    ANIMATE(2),
    SET_FLOAT(oDrawingDistance, 0x4000),
    //SET_HOME(),
    CALL_NATIVE(bhv_bonus_lightning_cloud_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bonus_lightning_cloud_loop),
    END_LOOP(),
};


const BehaviorScript bhvComitCoin[] = {
    BEGIN(OBJ_LIST_LEVEL),
    BILLBOARD(),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    CALL_NATIVE(bhv_comit_coin_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_yellow_coin_loop),
        ADD_FLOAT(oPosY, 8),
    END_LOOP(),
};


const BehaviorScript bhvDarkSky[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SET_FLOAT(oDrawingDistance, 0x7FFF),
    SET_INT(oOpacity, 0x58),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_dark_sky_loop),
    END_LOOP(),
};

const BehaviorScript bhvHiddenBounceCloud[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_hidden_cloud_loop),
    END_LOOP(),
};


const BehaviorScript bhvGuideLakitu[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    LOAD_ANIMATIONS(oAnimations, body_lakitu_anims),
    SET_FLOAT(oDrawingDistance, 0x5000),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NPC),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 150, /*Height*/ 60),
    ANIMATE(1),
    SET_HOME(),
    SCALE(0, 220),
    CALL_NATIVE(bhv_guide_lakitu_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_guide_lakitu_loop),
    END_LOOP(),
};

const BehaviorScript bhvGateLakitu[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    LOAD_ANIMATIONS(oAnimations, body_lakitu_anims),
    SET_FLOAT(oDrawingDistance, 0x5000),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NPC),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 90, /*Height*/ 60),
    ANIMATE(1),
    SET_HOME(),
    SCALE(0, 150),
    CALL_NATIVE(bhv_body_lakitu_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_gate_lakitu_loop),
    END_LOOP(),
};

const BehaviorScript bhvEntranceGate[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    LOAD_COLLISION_DATA(entrance_gate_collision),
    SET_FLOAT(oDrawingDistance, 0x4000),
    SET_FLOAT(oCollisionDistance, 0x500),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_entrance_gate_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSpectatorLakitu[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ACTIVE_FROM_AFAR)),
    LOAD_ANIMATIONS(oAnimations, body_lakitu_anims),
    SET_FLOAT(oDrawingDistance, 0x5000),
    DROP_TO_FLOOR(),
    ANIMATE(1),
    SET_HOME(),
    SCALE(0, 500),
    CALL_NATIVE(bhv_spectator_lakitu_init),
    BREAK(),
};

const BehaviorScript bhvComitDog[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    ANIMATE(0),
    SCALE(0, 50),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 100, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    //SET_INT(oBobombBuddyRole, 0),
    SET_HOME(),
    //CALL_NATIVE(bhv_bobomb_buddy_init),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_NPC),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_comit_dog_loop),
    END_LOOP(),
};

// thecozies bhvs start

#define BASE_DRAW_DIST 5000

const BehaviorScript bhvRainCloud[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(cloud_collision),
    SET_HOME(),
    CALL_NATIVE(rain_cloud_init),
    CALL_NATIVE(load_object_collision_model),
    SET_FLOAT(oDrawingDistance, BASE_DRAW_DIST),
    SET_FLOAT(oCollisionDistance, 1200),
    BEGIN_LOOP(),
        ADD_INT(oMoveAngleYaw, 0x10),
        CALL_NATIVE(rain_cloud_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSpinnyCloudSpawner[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    OR_LONG(oFlags, (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(spinny_cloud_spawner_init),
    BEGIN_LOOP(),
        CALL_NATIVE(spinny_cloud_spawner_loop),
    END_LOOP(),
};

const BehaviorScript bhvWaterTop[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(water_top_collision),
    SET_FLOAT(oCollisionDistance, 30000),
    SET_FLOAT(oDrawingDistance, 1000000),
    BEGIN_LOOP(),
        CALL_NATIVE(water_top_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCoziesAmbientSound[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_LONG(oFlags, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(cozies_ambient_sound_loop),
    END_LOOP(),
};

const BehaviorScript bhvWaterSpout[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(water_spout_collision),
    SET_FLOAT(oCollisionDistance, 4000),
    SET_FLOAT(oDrawingDistance, BASE_DRAW_DIST),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(water_spout_init),
    BEGIN_LOOP(),
        CALL_NATIVE(water_spout_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWaterSpoutPSS[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(water_spout_pss_collision),
    SET_FLOAT(oCollisionDistance, 4000),
    SET_FLOAT(oDrawingDistance, BASE_DRAW_DIST),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(water_spout_init),
    BEGIN_LOOP(),
        CALL_NATIVE(water_spout_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvVerticalInstantWarp[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(vertical_instant_warp_loop),
    END_LOOP(),
};

const BehaviorScript bhvAperatureDoor[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, aperature_door_anims),
    ANIMATE(0),
    LOAD_COLLISION_DATA(aperature_door_collision),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_FLOAT(oDrawingDistance, 30000),
    CALL_NATIVE(bhv_init_room),
    BEGIN_LOOP(),
        CALL_NATIVE(aperature_door_loop),
    END_LOOP(),
};

const BehaviorScript bhvFloatyRock[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(floaty_rock_collision),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_FLOAT(oDrawingDistance, 30000),
    CALL_NATIVE(floaty_rock_init),
    BEGIN_LOOP(),
        CALL_NATIVE(floaty_rock_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvTubeTop[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(tube_top_collision),
    SET_FLOAT(oCollisionDistance, 1000),
    SET_FLOAT(oDrawingDistance, BASE_DRAW_DIST),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(floaty_rock_init),
    BEGIN_LOOP(),
        CALL_NATIVE(floaty_rock_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCozyWarpPad[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(cozy_warp_pad_collision),
    SET_FLOAT(oDrawingDistance, BASE_DRAW_DIST),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_cozy_warp_pad_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_cozy_warp_pad_loop),
    END_LOOP(),
};

const BehaviorScript bhvShyguyScuba[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    // LOAD_ANIMATIONS(oAnimations, shyguy_scuba_anims),
    // ANIMATE(0),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 200, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 0, /*Unused*/ 0, 0),
    BEGIN_LOOP(),
        // CALL_NATIVE(bhv_shyguy_scuba_loop),
    END_LOOP(),
};

const BehaviorScript bhvBubbleShell[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_SILHOUETTE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bubble_shell_loop),
    END_LOOP(),
};

const BehaviorScript bhvWaterSwitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(water_switch_collision),
    SET_FLOAT(oCollisionDistance, 2000),
    SET_FLOAT(oDrawingDistance, 10000),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(water_switch_init),
    BEGIN_LOOP(),
        CALL_NATIVE(water_switch_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWaterSwitchWater1[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(water_plane1_collision),
    SET_FLOAT(oCollisionDistance, 20000),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(water_switch_water_init),
    BEGIN_LOOP(),
        CALL_NATIVE(water_switch_water_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWaterSwitchWater3[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(water_plane3_purp_room_collision),
    SET_FLOAT(oCollisionDistance, 30000),
    SET_FLOAT(oDrawingDistance, 30000),
    SET_HOME(),
    CALL_NATIVE(water_switch_water_init),
    BEGIN_LOOP(),
        CALL_NATIVE(water_switch_water_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvWaterPlane4Whirlpool[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(water_plane4_whirlpool_collision),
    SET_FLOAT(oCollisionDistance, 8000),
    SET_FLOAT(oDrawingDistance, 8000),
    SET_HOME(),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(water_switch_water_init),
    BEGIN_LOOP(),
        CALL_NATIVE(water_switch_water_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCoziesStaticWater[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oCollisionDistance, 8000),
    SET_FLOAT(oDrawingDistance, BASE_DRAW_DIST),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(static_water_obj_init),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFlippyBitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(flippy_bitch_collision),
    SET_FLOAT(oCollisionDistance, 2000),
    SET_FLOAT(oDrawingDistance, BASE_DRAW_DIST),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(flippy_bitch_init),
    BEGIN_LOOP(),
        CALL_NATIVE(flippy_bitch_loop),
        // CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFlippyBitchPSS[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(flippy_bitch_pss_collision),
    SET_FLOAT(oCollisionDistance, 2000),
    SET_FLOAT(oDrawingDistance, BASE_DRAW_DIST),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(flippy_bitch_init),
    BEGIN_LOOP(),
        CALL_NATIVE(flippy_bitch_loop),
        // CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvAdjacentRoomInitializer[] = {
    BEGIN(OBJ_LIST_SPAWNER),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_initialize_adjacent_rooms),
    DEACTIVATE()
};

const BehaviorScript bhvCoziesDog[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_INTERACT_TYPE(INTERACT_BOUNCE_TOP),
    SET_HITBOX(/*Radius*/ 50, /*Height*/ 60),
    ANIMATE(0),
    SCALE(0, 50),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_cozies_dog_init),
    SET_HOME(),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
        CALL_NATIVE(bhv_cozies_dog_loop),
    END_LOOP(),
};

// thecozies bhvs end

//cheeze bhvs start

const BehaviorScript bhvCheezePlat[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(cheezeplat_collision),
    SET_FLOAT(oCollisionDistance, 10000),
    SET_FLOAT(oDrawingDistance, 10000),
    SET_HOME(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cheezeplat_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvCheezeBombWall[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SET_FLOAT(oCollisionDistance, 10000),
    SET_FLOAT(oDrawingDistance, 10000),
    SET_HITBOX(/*Radius*/ 250, /*Height*/ 800),
    SET_INT(oIntangibleTimer, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cheezebombwall_loop),
    END_LOOP(),
};

const BehaviorScript bhvCheezeDog[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO |OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_INTERACT_TYPE(INTERACT_BOUNCE_TOP),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    ANIMATE(0),
    SET_HOME(),
    SCALE(0, 50),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
        CALL_NATIVE(bhv_cheezedog_loop),
    END_LOOP(),
};

const BehaviorScript bhvCheezeSkiDog[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_HOLDABLE)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    ANIMATE(0),
    SET_HOME(),
    SCALE(0, 50),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cheezeskidog_loop),
    END_LOOP(),
};

const BehaviorScript bhvB3Dog[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 50, /*Height*/ 40),
    ANIMATE(0),
    SCALE(0, 50),
    SET_HOME(),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_b3_dog_loop),
    END_LOOP(),
};

const BehaviorScript bhvDogLaser[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_dog_laser_loop),
    END_LOOP(),
};

const BehaviorScript bhvB3Bridge[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    LOAD_COLLISION_DATA(b3_bridge_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_b3_bridge_loop),
    END_LOOP(),
};

const BehaviorScript bhvLaserGlow[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    BILLBOARD(),
    DELAY(1),
    DEACTIVATE(),
};

const BehaviorScript bhvKoopatrol[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, koopatrol_anims),
    ANIMATE(0),
    SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 50, /*Gravity*/ -400, /*Bounciness*/ 0, /*Drag strength*/ 0, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SCALE(/*Unused*/ 0, /*Field*/ 150),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_FLOAT(oKoopaAgility, 1),
    CALL_NATIVE(bhv_init_room),
    CALL_NATIVE(bhv_koopatrol_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_koopatrol_loop),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvWindSoundLoop[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_wind_sound_loop),
    END_LOOP(),
};

const BehaviorScript bhvPeachCutscene[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oOpacity, 255),
    LOAD_ANIMATIONS(oAnimations, peach_seg5_anims_0501C41C),
    ANIMATE(9),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_peach_cutscene_loop),
    END_LOOP(),
};

const BehaviorScript bhvDogCutscene[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO |OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    ANIMATE(2),
    SET_HOME(),
    SCALE(0, 50),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cutscenedog_loop),
    END_LOOP(),
};

const BehaviorScript bhvBowserCutscene[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    SET_HOME(),
    SET_INT(oOpacity, 255),
    LOAD_ANIMATIONS(oAnimations, bowser_seg6_anims_06057690),
    ANIMATE(BOWSER_ANIM_RUN_SLIP),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_bowser_cutscene_loop),
    END_LOOP(),
};

const BehaviorScript bhvDoorCutscene[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_door_cutscene_loop),
    END_LOOP(),
};

const BehaviorScript bhvGlobe[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 50),
    SET_HOME(),
    CALL_NATIVE(bhv_bobomb_buddy_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bobomb_buddy_loop),
    END_LOOP(),
};

const BehaviorScript bhvSpiresDog[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO |OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    //SET_INTERACT_TYPE(INTERACT_BOUNCE_TOP),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 60),
    ANIMATE(0),
    SET_HOME(),
    SCALE(0, 60),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, 0),
        CALL_NATIVE(bhv_spiresdog_loop),
    END_LOOP(),
};

const BehaviorScript bhvChainChompBowser[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_ACTIVE_FROM_AFAR | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    // Yoshi Milkman: Commented this part out for my level
    // DROP_TO_FLOOR(),
    LOAD_ANIMATIONS(oAnimations, chain_chomp_bowser_anims),
    ANIMATE(CHAIN_CHOMP_ANIM_CHOMPING),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    HIDE(),
    SET_HOME(),
    SET_FLOAT(oGraphYOffset, 240),
    SCALE(/*Unused*/ 0, /*Field*/ 200),
    // Yoshi Milkman: Commented this part out for my level
    // SPAWN_CHILD_WITH_PARAM(/*Bhv param*/ 0, /*Model*/ MODEL_WOODEN_POST, /*Behavior*/ bhvWoodenPost),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_chain_chomp_bowser_update),
        SET_INT(oInteractStatus, 0),
    END_LOOP(),
};

const BehaviorScript bhvChainChompChainPartBowser[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BILLBOARD(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 0, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_FLOAT(oGraphYOffset, 40),
    SCALE(/*Unused*/ 0, /*Field*/ 200),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_chain_chomp_chain_part_update),
    END_LOOP(),
};

const BehaviorScript bhvNothing[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BREAK(),
};

const BehaviorScript bhvCheezeLightning[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    CALL_NATIVE(bhv_cheeze_lightning_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_cheeze_lightning_loop),
    END_LOOP(),
};

const BehaviorScript bhvPeachEnding[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_INT(oOpacity, 0),
    SET_FLOAT(oPosX, 0),
    SET_FLOAT(oPosY, 1000),
    SET_FLOAT(oPosZ, 0),
    SET_HOME(),
    LOAD_ANIMATIONS(oAnimations, peach_seg5_anims_0501C41C),
    ANIMATE(PEACH_ANIM_DESCEND_FROM_WINDOW),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_peach_ending_loop),
    END_LOOP(),
};

const BehaviorScript bhvRedCoinSign[] = {
    BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_FLOAT(oDrawingDistance, 16000),
    SET_FLOAT(oCollisionDistance, 16000),
    LOAD_COLLISION_DATA(rcsign_collision),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvFlipSwitch[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(flipswitch_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE)),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 12000),
    SET_FLOAT(oCollisionDistance, 4000),
    BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
        CALL_NATIVE(bhv_flipswitch_loop),
    END_LOOP(),
};

const BehaviorScript bhvJetskiBits[] = {
    BEGIN(OBJ_LIST_LEVEL),
    LOAD_ANIMATIONS(oAnimations, jetski_bits_anims),
    GOTO(bhvJetski + 1 + 2),
};

//cheeze bhvs end

// someone2638 scripts

const BehaviorScript bhvDoginlobby[] = {
	BEGIN(OBJ_LIST_DEFAULT),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
    SET_FLOAT(oGravity, 3.0f),
    SCALE(0, 50),
	CALL_NATIVE(bhv_DogInLobby_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_DogInLobby_loop),
	END_LOOP(),
};


const BehaviorScript bhvDogoutsidehotel[] = {
	BEGIN(OBJ_LIST_DEFAULT),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_FLOAT(oGravity, 3.0f),
    SCALE(0, 50),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
	CALL_NATIVE(bhv_DogOutsideHotel_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_DogOutsideHotel_loop),
	END_LOOP(),
};


const BehaviorScript bhvDogfloor1[] = {
	BEGIN(OBJ_LIST_DEFAULT),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_FLOAT(oGravity, 3.0f),
    SCALE(0, 50),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
	CALL_NATIVE(bhv_DogFloor1_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_DogFloor1_loop),
	END_LOOP(),
};


const BehaviorScript bhvDogfloor2[] = {
	BEGIN(OBJ_LIST_DEFAULT),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_FLOAT(oGravity, 3.0f),
    SCALE(0, 50),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
	CALL_NATIVE(bhv_DogFloor2_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_DogFloor2_loop),
	END_LOOP(),
};


const BehaviorScript bhvDogfloor3[] = {
	BEGIN(OBJ_LIST_DEFAULT),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_FLOAT(oGravity, 3.0f),
    SCALE(0, 50),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
	CALL_NATIVE(bhv_DogFloor3_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_DogFloor3_loop),
	END_LOOP(),
};


const BehaviorScript bhvDogfloor4[] = {
	BEGIN(OBJ_LIST_DEFAULT),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_FLOAT(oGravity, 3.0f),
    SCALE(0, 50),
    SET_HOME(),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
	CALL_NATIVE(bhv_DogFloor4_init),
    SET_FLOAT(oDrawingDistance, 20000),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_DogFloor4_loop),
	END_LOOP(),
};


const BehaviorScript bhvDogbalcony[] = {
	BEGIN(OBJ_LIST_DEFAULT),
    LOAD_ANIMATIONS(oAnimations, dog_anims),
    SET_FLOAT(oGravity, 3.0f),
    SCALE(0, 50),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO)),
	CALL_NATIVE(bhv_DogBalcony_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_DogBalcony_loop),
	END_LOOP(),
};


const BehaviorScript bhv2639cane[] = {
	BEGIN(OBJ_LIST_GENACTOR),
	CALL_NATIVE(bhv_2639cane_init),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639cane_loop),
	END_LOOP(),
};


const BehaviorScript bhv2639glasses[] = {
	BEGIN(OBJ_LIST_GENACTOR),
	CALL_NATIVE(bhv_2639glasses_init),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639glasses_loop),
	END_LOOP(),
};


const BehaviorScript bhvA2pushablecouch[] = {
	BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(couch_collision),
    SET_FLOAT(oCollisionDistance, 20000),
    SET_FLOAT(oDrawingDistance, 20000),
    OR_LONG(oFlags, (OBJ_FLAG_UCODE_LARGE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL)),
	CALL_NATIVE(bhv_A2PushableCouch_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_A2PushableCouch_loop),
        CALL_NATIVE(load_object_collision_model),
        SET_INT(oInteractStatus, 0),
	END_LOOP(),
};


const BehaviorScript bhv2639a2hiddenstar[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, (OBJ_FLAG_PERSISTENT_RESPAWN | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
	CALL_NATIVE(bhv_2639A2HiddenStar_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639A2HiddenStar_loop),
	END_LOOP(),
};


const BehaviorScript bhv2639elevator[] = {
	BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE| OBJ_FLAG_COMPUTE_DIST_TO_MARIO)),
    LOAD_COLLISION_DATA(elevator_collision),
	CALL_NATIVE(bhv_2639Elevator_init),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_HOME(),
	BEGIN_LOOP(),
        CALL_NATIVE(load_object_collision_model),
		CALL_NATIVE(bhv_2639Elevator_loop),
	END_LOOP(),
};


const BehaviorScript bhv2639soda[] = {
	BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_HOLDABLE_NPC),
    SET_HITBOX(/*Radius*/ 100, /*Height*/ 50),
    SET_INT(oIntangibleTimer, 0),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    SET_HOME(),
	CALL_NATIVE(bhv_2639Soda_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639Soda_loop),
	END_LOOP(),
};

const BehaviorScript bhvBowserSnowball[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 20000),
    SCALE(0, 0),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_bowser_snowball_loop),
    END_LOOP(),
};

// Koopa Atoll Objects
const BehaviorScript bhvKokoTripletSpawner[] = {
    BEGIN(OBJ_LIST_PUSHABLE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    DROP_TO_FLOOR(),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_koko_triplet_spawner_update),
    END_LOOP(),
};

const BehaviorScript bhvWarpBox[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oDrawingDistance, 20000),
    SET_FLOAT(oWarpBoxInnerScale, 0),
    SET_HITBOX(/*Radius*/ 50, /*Height*/ 100),
    SCALE(0, 50),
    SET_HOME(),
    CALL_NATIVE(bhv_warp_box_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_warp_box_loop),
    END_LOOP(),
};

const BehaviorScript bhvSpecialWarpBox[] = {
    BEGIN(OBJ_LIST_GENACTOR),
    CALL_NATIVE(bhv_special_warp_box_init),
    GOTO(bhvWarpBox + 1),
};

const BehaviorScript bhvEntranceturnstile[] = {
	BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_COLLISION_DATA(turnstile_collision),
    SET_FLOAT(oDrawingDistance, 20000),
	CALL_NATIVE(bhv_EntranceTurnStile_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_EntranceTurnStile_loop),
        CALL_NATIVE(load_object_collision_model),
	END_LOOP(),
};


const BehaviorScript bhv2639pc2_targetobj[] = {
	BEGIN(OBJ_LIST_DEFAULT),
	CALL_NATIVE(bhv_2639PC2_TargetObj_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639PC2_TargetObj_loop),
	END_LOOP(),
};

const BehaviorScript bhv2639_DRM[] = {
    BEGIN(OBJ_LIST_DEFAULT),
    BREAK(),
};

extern const struct Animation *const peach2639_anims[];
const BehaviorScript bhv2639peachNPC[] = {
	BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    LOAD_ANIMATIONS(oAnimations, peach2639_anims),
    ANIMATE(PEACH_ANIM_DIALOG_1_PART_1),
    SET_INT(oOpacity, 255),
    SET_FLOAT(oCollisionDistance, 150),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_SIGN),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 150, /*Height*/ 300),
    SET_INT(oWoodenPostTotalMarioAngle, 0),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
    END_LOOP(),
};


const BehaviorScript bhv2639TrophyCase[] = {
	BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_FLOAT(oCollisionDistance, 400),
    SET_INTERACT_TYPE(INTERACT_TEXT),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_SIGN),
    DROP_TO_FLOOR(),
    SET_HITBOX(/*Radius*/ 400, /*Height*/ 300),
    SET_INT(oWoodenPostTotalMarioAngle, 0),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
    END_LOOP(),
};

extern const struct Animation *const vending2639_anims[];
const BehaviorScript bhv2639Vending[] = {
	BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    LOAD_ANIMATIONS(oAnimations, vending2639_anims),
    ANIMATE(0),
    LOAD_COLLISION_DATA(vending_collision),
	CALL_NATIVE(bhv_2639Vending_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639Vending_loop),
        CALL_NATIVE(load_object_collision_model),
	END_LOOP(),
};


const BehaviorScript bhv2639A4DrainScrew[] = {
	BEGIN(OBJ_LIST_SURFACE),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
	CALL_NATIVE(bhv_2639A4DrainScrew_init),
    SET_HOME(),
    LOAD_COLLISION_DATA(Screw2639_collision),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639A4DrainScrew_loop),
	END_LOOP(),
};


const BehaviorScript bhv2639SoccerBall[] = {
	BEGIN(OBJ_LIST_GENACTOR),
        OR_INT(oFlags, OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
        SET_HOME(),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 100, /*Gravity*/ -400, /*Bounciness*/ 20, /*Drag strength*/ 0, /*Friction*/ 1, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
	CALL_NATIVE(bhv_2639SoccerBall_init),
    SET_FLOAT(oDrawingDistance, 20000),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639SoccerBall_loop),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
	END_LOOP(),
};


const BehaviorScript bhv2639BallEater[] = {
	BEGIN(OBJ_LIST_DEFAULT),
	CALL_NATIVE(bhv_2639BallEater_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639BallEater_loop),
	END_LOOP(),
};


const BehaviorScript bhv2639FinalPresent[] = {
	BEGIN(OBJ_LIST_GENACTOR),
    OR_INT(oFlags, (OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)),
    SET_INT(oInteractType, INTERACT_GRABBABLE),
    SET_INT(oInteractionSubtype, INT_SUBTYPE_HOLDABLE_NPC),
    SET_HITBOX(/*Radius*/ 200, /*Height*/ 200),
    SET_HOME(),
    SET_INT(oIntangibleTimer, 0),
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 0, /*Friction*/ 0, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
	CALL_NATIVE(bhv_2639FinalPresent_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639FinalPresent_loop),
        SET_INT(oInteractStatus, INT_STATUS_NONE),
	END_LOOP(),
};



const BehaviorScript bhv2639PresentEater[] = {
	BEGIN(OBJ_LIST_DEFAULT),
	CALL_NATIVE(bhv_2639PresentEater_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639PresentEater_loop),
	END_LOOP(),
};

const BehaviorScript bhvJetski[] = {
    BEGIN(OBJ_LIST_LEVEL),
    LOAD_ANIMATIONS(oAnimations, jetski_anims),
    OR_LONG(oFlags, (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SILHOUETTE)), //! Silhouette doesn't show up in-game, due to combiner modes.
    SET_OBJ_PHYSICS(/*Wall hitbox radius*/ 30, /*Gravity*/ -400, /*Bounciness*/ -50, /*Drag strength*/ 1000, /*Friction*/ 1000, /*Buoyancy*/ 200, /*Unused*/ 0, 0),
    ANIMATE(0),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_koopa_shell_loop),
    END_LOOP(),
};

const BehaviorScript bhvSandPile[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(sandpile_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE)),
    SCALE(/*Unused*/ 0, /*Field*/ 100),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 4000),
    SET_FLOAT(oCollisionDistance, 500),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sand_pile),
    END_LOOP(),
};

const BehaviorScript bhvSandPillar[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(sand_pillar_collision),
    OR_LONG(oFlags, (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_DONT_CALC_COLL_DIST)),
    SET_HOME(),
    SET_FLOAT(oDrawingDistance, 32000),
    SET_FLOAT(oCollisionDistance, 32000),
    CALL_NATIVE(bhv_sand_pillar_init),
    BEGIN_LOOP(),
        CALL_NATIVE(bhv_sand_pillar_loop),
        CALL_NATIVE(load_object_collision_model),
    END_LOOP(),
};

const BehaviorScript bhvSandSlope[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(sand_slope_collision),
    GOTO(bhvSandPillar + 1 + 2),
};

const BehaviorScript bhvSandCastle[] = {
    BEGIN(OBJ_LIST_SURFACE),
    LOAD_COLLISION_DATA(sandcastle_collision),
    GOTO(bhvSandPillar + 1 + 2),
};

const BehaviorScript bhvKTQRing[] = {
    BEGIN(OBJ_LIST_LEVEL),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    SET_HITBOX_WITH_OFFSET(/*Radius*/ 200, /*Height*/ 800, /*Downwards offset*/ 0),
    SET_INTERACT_TYPE(INTERACT_WATER_RING),
    SET_INT(oDamageOrCoinValue, 2),
    SET_INT(oIntangibleTimer, 0),
    CALL_NATIVE(bhv_ktq_ring_init),
    BEGIN_LOOP(),
        SET_INT(oIntangibleTimer, 0),
        CALL_NATIVE(bhv_ktq_ring_loop),
    END_LOOP(),
};


const BehaviorScript bhv2639ElevatorKey[] = {
	BEGIN(OBJ_LIST_DEFAULT),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO),
	CALL_NATIVE(bhv_2639ElevatorKey_init),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_2639ElevatorKey_loop),
        ADD_INT(oFaceAngleYaw, 1),
	END_LOOP(),
};

const BehaviorScript bhvTram2639[] = {
	BEGIN(OBJ_LIST_SURFACE),
    OR_LONG(oFlags, OBJ_FLAG_DONT_CALC_COLL_DIST | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_UCODE_LARGE),
	CALL_NATIVE(bhv_Tram2639_init),
    SET_FLOAT(oCollisionDistance, 10000),
    SET_FLOAT(oDrawingDistance, 10000),
    LOAD_COLLISION_DATA(tram2639_collision),
	BEGIN_LOOP(),
		CALL_NATIVE(bhv_Tram2639_loop),
        CALL_NATIVE(load_object_collision_model),
	END_LOOP(),
};
