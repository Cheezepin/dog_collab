static const u16 cleft_anim_trip_values[] = {
	0x0000, 0x0000, 0x0001, 0x0004, 0x0007, 0x000B, 0x000D, 0x000F, 0x000F, 
	0x0010, 0x0011, 0x0014, 0x001A, 0x0023, 0x002B, 0x0032, 0x0035, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xFDF6, 0xF87A, 0xF074, 0xE6D1, 0xDC71, 
	0xD1EF, 0xC762, 0xBCC5, 0xB209, 0xA71C, 0x9C01, 0x916F, 0x887D, 0x824F, 
	0x7FFF, 0x0000, 0x0000, 0x0000, 0xFDCC, 0xF881, 0xF228, 0xECDD, 0xEAAA, 
	0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 
	0xFFFF, 0x0000, 0x0000, 0xFDCC, 0xF881, 0xF228, 0xECDD, 0xEAAA, 0x0000, 
	0x0000, 
};

static const u16 cleft_anim_trip_indices[] = {
	0x0001, 0x0000, 0x0010, 0x0001, 0x0001, 0x0011, 0x0001, 0x0012, 0x0001, 
	0x0013, 0x0001, 0x0014, 0x0010, 0x0015, 0x0001, 0x0025, 0x0001, 0x0026, 
	0x0006, 0x0027, 0x0006, 0x002D, 0x0005, 0x0033, 0x0006, 0x0038, 0x0001, 
	0x003E, 0x0001, 0x003F, 
};

static const struct Animation cleft_anim_trip[] = {
	1,
	0,
	0,
	0,
	15,
	ANIMINDEX_NUMPARTS(cleft_anim_trip_indices),
	cleft_anim_trip_values,
	cleft_anim_trip_indices,
	0,
};

