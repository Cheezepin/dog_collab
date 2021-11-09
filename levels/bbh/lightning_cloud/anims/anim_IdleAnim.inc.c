static const s16 lightning_cloud_anim_IdleAnim_values[] = {
	0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 
};

static const u16 lightning_cloud_anim_IdleAnim_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001, 
	0x0004, 0x0001, 0x0005, 
};

static const struct Animation lightning_cloud_anim_IdleAnim = {
	1,
	0,
	0,
	1,
	1,
	ANIMINDEX_NUMPARTS(lightning_cloud_anim_IdleAnim_indices),
	lightning_cloud_anim_IdleAnim_values,
	lightning_cloud_anim_IdleAnim_indices,
	0,
};

