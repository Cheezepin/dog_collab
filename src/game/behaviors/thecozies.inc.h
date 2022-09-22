#pragma once

void set_water_top_force(struct MarioState *m);
void water_top_loop(void);
void water_spout_init(void);
void water_spout_loop(void);
void rain_cloud_init(void);
void rain_cloud_loop(void);
Gfx *geo_set_rain_cloud_prim(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx);
Gfx *geo_set_rain_cloud_wind_vis(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx);
void vertical_instant_warp_loop(void);
void aperature_door_loop(void);
void floaty_rock_init(void);
void floaty_rock_loop(void);
void bubble_shell_loop(void);

// water switch funcs
void water_switch_init(void);
void water_switch_loop(void);
void water_switch_water_init(void);
void water_switch_water_loop(void);
Gfx *geo_water_switch_activation(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx);
Gfx *geo_water_switch_activation_anim(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx);

// flippy bitch funcs
void flippy_bitch_init(void);
void flippy_bitch_loop(void);
Gfx *geo_flippy_bitch_static_rot(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx);

// static water
void static_water_obj_init(void);

// adjacent room initializer
void bhv_initialize_adjacent_rooms(void);

// spinny cloud spawner
void spinny_cloud_spawner_init(void);
void spinny_cloud_spawner_loop(void);

// dddddooooggggggggg
void bhv_cozies_dog_init(void);
void bhv_cozies_dog_loop(void);

// misc
Gfx *geo_reflect_light_panel(s32 callContext, struct GraphNode *node, UNUSED Mat4 mtx);
