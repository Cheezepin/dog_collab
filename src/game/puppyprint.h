#ifndef PUPPYPRINT_H
#define PUPPYPRINT_H


//This is how many indexes of timers are saved at once. higher creates a smoother average, but naturally uses more RAM. 15's fine.
#define NUM_PERF_ITERATIONS 15

extern Texture small_font[];
extern u8 perfIteration;

//General
extern OSTime cpuTime;
extern OSTime rspTime;
extern OSTime rdpTime;
extern OSTime ramTime;
extern OSTime loadTime;
extern OSTime rspDelta;

//CPU
extern OSTime collisionTime[NUM_PERF_ITERATIONS+1];
extern OSTime behaviourTime[NUM_PERF_ITERATIONS+1];
extern OSTime scriptTime[NUM_PERF_ITERATIONS+1];
extern OSTime graphTime[NUM_PERF_ITERATIONS+1];
extern OSTime audioTime[NUM_PERF_ITERATIONS+1];
//RSP
extern OSTime rspGenTime[NUM_PERF_ITERATIONS+1];
//RDP
extern OSTime bufferTime[NUM_PERF_ITERATIONS+1];
extern OSTime tmemTime[NUM_PERF_ITERATIONS+1];
extern OSTime busTime[NUM_PERF_ITERATIONS+1];

extern void profiler_update(OSTime *time, OSTime time2);
extern void puppyprint_profiler_process(void);
extern void puppyprint_render_profiler(void);

extern void prepare_blank_box(void);
extern void finish_blank_box(void);
extern void render_blank_box(s16 x1, s16 y1, s16 x2, s16 y2, u8 r, u8 g, u8 b, u8 a);
extern void print_small_text(s32 x, s32 y, u8 *str, s32 align, s32 amount);
extern void render_multi_image(Texture *image, s32 x, s32 y, s32 width, s32 height, s32 scaleX, s32 scaleY, s32 mode);
extern s32 get_text_height(u8 *str);
extern s32 get_text_width(u8 *str);
extern void prepare_blank_box(void);
extern void finish_blank_box(void);
extern void render_blank_box(s16 x1, s16 y1, s16 x2, s16 y2, u8 r, u8 g, u8 b, u8 a);

#endif // PUPPYPRINT_H
