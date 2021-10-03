#include <ultra64.h>
#include "dma_textures.h"
#include "memory.h"

static float get_im_siz_mult(u32 g_img_siz) {
	switch (g_img_siz) {
		case G_IM_SIZ_4b: return 0.5f; break;
		case G_IM_SIZ_8b: return 1.0f; break;
		case G_IM_SIZ_16b: return 2.0f; break;
		case G_IM_SIZ_32b: return 4.0f; break;
	}

	return 0.0f;
}

void dmat_init(u32 **t_array, u8 *rom, u32 width, u32 height, u32 g_img_siz, u32 count) {
	for (u32 i = 0; i < count; i++) {
		t_array[i] = (u32) rom + (u32)(i * (width * height) * get_im_siz_mult(g_img_siz));
	}
}

void dmat_copy(Texture t_pointer[], u32 **t_array, u32 idx, u32 count) {
	u32 *rom = t_array[idx % count];

	dma_read(segmented_to_virtual(t_pointer), rom, rom + (u32) t_array[1] - (u32) t_array[0]);
}

