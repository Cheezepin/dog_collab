Lights1 lava_grate_metal_plate_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 lava_grate_grate_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx lava_grate_MetalTile_i8_aligner[] = {gsSPEndDisplayList()};
u8 lava_grate_MetalTile_i8[] = {
	0xdf, 0xdf, 0xff, 0xdf, 0xd3, 0xd3, 0xd3, 0xc0, 
	0xb9, 0xb9, 0xb9, 0xb9, 0xc5, 0xc5, 0xcc, 0xcc, 
	0xd8, 0xd8, 0xd0, 0xd0, 0xe0, 0xe0, 0xe8, 0xe8, 
	0xf7, 0xf7, 0xf7, 0xd8, 0xd0, 0xd0, 0xc0, 0xc0, 
	0xdf, 0xff, 0xc8, 0xad, 0xb0, 0xc0, 0xd3, 0xd3, 
	0xd0, 0xd0, 0xe0, 0xe0, 0xec, 0xec, 0xec, 0xec, 
	0xef, 0xef, 0xef, 0xef, 0xf0, 0xf0, 0xf0, 0xf0, 
	0xf7, 0xc4, 0xad, 0xad, 0xaa, 0xb0, 0xd0, 0xc0, 
	0xdf, 0xc8, 0xad, 0xad, 0xa2, 0xb0, 0xc0, 0xd3, 
	0xe0, 0xe0, 0xf7, 0xe0, 0xec, 0xec, 0xec, 0xec, 
	0xe0, 0xe0, 0xef, 0xe0, 0xe8, 0xf0, 0xe8, 0xe8, 
	0xd8, 0xad, 0xad, 0xc4, 0xb0, 0xaa, 0xd0, 0xd0, 
	0xdf, 0xc8, 0xad, 0xc8, 0xb0, 0xa2, 0xc0, 0xd3, 
	0xe0, 0xe0, 0xf7, 0xf7, 0xec, 0xdc, 0xec, 0xec, 
	0xe0, 0xd8, 0xe0, 0xe0, 0xe0, 0xe8, 0xf0, 0xe8, 
	0xd8, 0xad, 0xad, 0xad, 0xb0, 0xaa, 0xd0, 0xd0, 
	0xd3, 0xc0, 0xad, 0xc0, 0xad, 0xad, 0xb4, 0xd0, 
	0xd8, 0xe8, 0xe8, 0xe8, 0xe4, 0xdc, 0xe4, 0xf0, 
	0xe8, 0xe0, 0xdc, 0xdc, 0xd8, 0xe3, 0xe3, 0xe3, 
	0xe8, 0xad, 0xad, 0xad, 0xaa, 0xaa, 0xe0, 0xc8, 
	0xd3, 0xd3, 0xc0, 0xad, 0xad, 0xad, 0xc0, 0xc0, 
	0xd8, 0xdf, 0xe8, 0xe8, 0xe4, 0xe4, 0xe4, 0xe4, 
	0xe0, 0xe0, 0xdc, 0xdc, 0xd8, 0xe3, 0xe3, 0xe3, 
	0xe8, 0xd0, 0xad, 0xad, 0xaa, 0xb8, 0xe0, 0xc8, 
	0xd3, 0xef, 0xd3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
	0xd8, 0xdf, 0xe8, 0xe8, 0xe0, 0xdc, 0xf0, 0xe4, 
	0xe8, 0xe8, 0xe0, 0xdc, 0xd0, 0xd0, 0xd0, 0xd8, 
	0xe8, 0xe8, 0xd0, 0xd0, 0xc8, 0xe0, 0xe0, 0xb8, 
	0xc0, 0xef, 0xef, 0xd3, 0xc0, 0xc0, 0xc0, 0xd0, 
	0xd8, 0xd8, 0xe8, 0xd8, 0xe0, 0xe0, 0xf0, 0xf0, 
	0xe8, 0xe8, 0xe0, 0xdc, 0xd8, 0xd0, 0xcc, 0xcc, 
	0xd0, 0xd0, 0xd0, 0xd0, 0xe0, 0xe0, 0xe0, 0xb8, 
	0xd8, 0xe8, 0xe8, 0xd3, 0xd0, 0xcc, 0xcc, 0xd0, 
	0xe0, 0xe0, 0xdb, 0xe0, 0xef, 0xef, 0xef, 0xef, 
	0xf0, 0xf0, 0xe8, 0xe0, 0xd4, 0xcc, 0xcc, 0xcc, 
	0xc8, 0xd0, 0xd0, 0xd0, 0xe0, 0xe0, 0xc8, 0xc0, 
	0xcc, 0xd8, 0xe8, 0xcc, 0xcc, 0xd0, 0xd0, 0xd8, 
	0xdb, 0xdb, 0xe0, 0xe0, 0xef, 0xf4, 0xf4, 0xef, 
	0xf0, 0xe8, 0xe0, 0xe0, 0xd4, 0xcc, 0xcc, 0xcc, 
	0xd0, 0xc8, 0xc8, 0xc5, 0xe0, 0xe0, 0xc8, 0xc0, 
	0xd8, 0xd3, 0xe8, 0xcc, 0xd0, 0xd0, 0xd8, 0xe4, 
	0xe8, 0xe8, 0xe0, 0xe8, 0xef, 0xf4, 0xf3, 0xf4, 
	0xf0, 0xe8, 0xe8, 0xe8, 0xdc, 0xd4, 0xcc, 0xd4, 
	0xc8, 0xc8, 0xc5, 0xc5, 0xc8, 0xe0, 0xc8, 0xb0, 
	0xd3, 0xcc, 0xe8, 0xd8, 0xd8, 0xd8, 0xe4, 0xe4, 
	0xe8, 0xe8, 0xe8, 0xe8, 0xef, 0xf3, 0xef, 0xf3, 
	0xf0, 0xf0, 0xe8, 0xe8, 0xdc, 0xcc, 0xcc, 0xd4, 
	0xd0, 0xd0, 0xc5, 0xc5, 0xc8, 0xe0, 0xc0, 0xb0, 
	0xd3, 0xd3, 0xe0, 0xd3, 0xd3, 0xe0, 0xe0, 0xe0, 
	0xe8, 0xe8, 0xf3, 0xf3, 0xef, 0xf7, 0xef, 0xf7, 
	0xeb, 0xeb, 0xeb, 0xe0, 0xdc, 0xd4, 0xd4, 0xd4, 
	0xd4, 0xc8, 0xc8, 0xbc, 0xc5, 0xdc, 0xc5, 0xa5, 
	0xc8, 0xe0, 0xf3, 0xe0, 0xd3, 0xe0, 0xe0, 0xe0, 
	0xf3, 0xf3, 0xeb, 0xf3, 0xef, 0xf7, 0xf7, 0xf7, 
	0xeb, 0xeb, 0xeb, 0xe0, 0xd4, 0xd0, 0xd4, 0xd4, 
	0xc8, 0xd4, 0xc8, 0xc0, 0xc5, 0xdc, 0xc5, 0xa5, 
	0xc8, 0xf3, 0xf3, 0xe0, 0xd8, 0xd8, 0xe0, 0xe0, 
	0xf3, 0xf3, 0xeb, 0xf3, 0xef, 0xf7, 0xf7, 0xef, 
	0xeb, 0xe0, 0xe0, 0xe0, 0xd4, 0xd4, 0xd0, 0xd0, 
	0xc8, 0xd4, 0xc8, 0xc0, 0xc5, 0xdc, 0xb4, 0xa5, 
	0xc8, 0xf3, 0xf3, 0xe0, 0xe0, 0xd8, 0xd8, 0xd8, 
	0xeb, 0xeb, 0xeb, 0xf3, 0xef, 0xef, 0xef, 0xeb, 
	0xeb, 0xeb, 0xdb, 0xd8, 0xd4, 0xd0, 0xd0, 0xd0, 
	0xc8, 0xc8, 0xc8, 0xc0, 0xc5, 0xdc, 0xb4, 0xa5, 
	0xc8, 0xef, 0xff, 0xef, 0xf0, 0xe8, 0xe8, 0xe8, 
	0xeb, 0xf3, 0xeb, 0xf3, 0xeb, 0xeb, 0xeb, 0xe0, 
	0xd8, 0xe0, 0xd8, 0xd0, 0xd0, 0xd0, 0xd0, 0xd0, 
	0xc5, 0xc5, 0xc5, 0xbc, 0xbd, 0xcc, 0xbd, 0xad, 
	0xc8, 0xef, 0xff, 0xef, 0xfb, 0xf0, 0xfb, 0xf0, 
	0xeb, 0xeb, 0xe3, 0xeb, 0xeb, 0xeb, 0xe0, 0xdb, 
	0xe0, 0xd8, 0xd8, 0xd0, 0xd0, 0xd0, 0xd0, 0xc8, 
	0xc5, 0xbc, 0xc5, 0xbc, 0xbd, 0xcc, 0xbd, 0xb4, 
	0xc8, 0xef, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 
	0xeb, 0xeb, 0xeb, 0xe3, 0xe0, 0xe0, 0xe0, 0xd8, 
	0xd8, 0xd0, 0xd0, 0xd0, 0xc8, 0xd0, 0xc8, 0xc8, 
	0xbc, 0xbc, 0xb4, 0xbc, 0xb4, 0xcc, 0xb4, 0xad, 
	0xc8, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 
	0xf3, 0xe3, 0xe3, 0xe3, 0xdb, 0xdb, 0xd8, 0xd8, 
	0xd8, 0xd0, 0xd0, 0xd0, 0xc0, 0xc0, 0xc0, 0xc8, 
	0xbc, 0xb4, 0xb4, 0xb4, 0xad, 0xcc, 0xad, 0xad, 
	0xcc, 0xdb, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xeb, 
	0xe3, 0xe3, 0xd3, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 
	0xd3, 0xcc, 0xcc, 0xc4, 0xbc, 0xbc, 0xc0, 0xc0, 
	0xb8, 0xb8, 0xb8, 0xb8, 0xb0, 0xc0, 0xad, 0xad, 
	0xcc, 0xdb, 0xff, 0xff, 0xfb, 0xeb, 0xeb, 0xeb, 
	0xdb, 0xdb, 0xdb, 0xd3, 0xd3, 0xcc, 0xdb, 0xdb, 
	0xd3, 0xd3, 0xcc, 0xc4, 0xbc, 0xc0, 0xc0, 0xc0, 
	0xc0, 0xc8, 0xb8, 0xb8, 0xb0, 0xb4, 0xad, 0xb0, 
	0xcc, 0xdb, 0xff, 0xff, 0xeb, 0xe3, 0xe3, 0xe3, 
	0xe3, 0xd3, 0xd3, 0xdb, 0xd3, 0xd3, 0xd3, 0xd3, 
	0xd3, 0xd3, 0xcc, 0xc4, 0xc0, 0xc0, 0xc0, 0xc0, 
	0xc8, 0xc0, 0xc0, 0xb8, 0xb4, 0xb4, 0xb0, 0xb4, 
	0xdb, 0xe8, 0xff, 0xe8, 0xe3, 0xdb, 0xdb, 0xdb, 
	0xd3, 0xd3, 0xd3, 0xd3, 0xcc, 0xcc, 0xd3, 0xd3, 
	0xd3, 0xcc, 0xcc, 0xcc, 0xc0, 0xc8, 0xc8, 0xc8, 
	0xc8, 0xc0, 0xc0, 0xc8, 0xb4, 0xb4, 0xc0, 0xc0, 
	0xd0, 0xe3, 0xe3, 0xe3, 0xc8, 0xc8, 0xc8, 0xc8, 
	0xd3, 0xd3, 0xcc, 0xcc, 0xd0, 0xd8, 0xd8, 0xd0, 
	0xd0, 0xcc, 0xc4, 0xc4, 0xc4, 0xc4, 0xc4, 0xc4, 
	0xc8, 0xc8, 0xe0, 0xc8, 0xc8, 0xc8, 0xb4, 0xc8, 
	0xe3, 0xe3, 0xe3, 0xe3, 0xe0, 0xe0, 0xc8, 0xe0, 
	0xcc, 0xcc, 0xcc, 0xcc, 0xd0, 0xe0, 0xd0, 0xd0, 
	0xd0, 0xd0, 0xd0, 0xcc, 0xc4, 0xc4, 0xcc, 0xd3, 
	0xc8, 0xe0, 0xc8, 0xa5, 0xaa, 0xb4, 0xb4, 0xc8, 
	0xd0, 0xd0, 0xc0, 0xc0, 0xa5, 0xb8, 0xe0, 0xc8, 
	0xc4, 0xcc, 0xcc, 0xcc, 0xd8, 0xe0, 0xd8, 0xd0, 
	0xd0, 0xd0, 0xd0, 0xcc, 0xcc, 0xcc, 0xcc, 0xd3, 
	0xe0, 0xc8, 0xa5, 0xa5, 0x9e, 0x9e, 0xb4, 0xc8, 
	0xd0, 0xc0, 0xb4, 0xb4, 0xb8, 0xa5, 0xb8, 0xe0, 
	0xd3, 0xcc, 0xcc, 0xd3, 0xe0, 0xd8, 0xd8, 0xd8, 
	0xe0, 0xcc, 0xd0, 0xcc, 0xcc, 0xcc, 0xd3, 0xd3, 
	0xc8, 0xc8, 0xa5, 0xb8, 0xaa, 0x9e, 0xaa, 0xc8, 
	0xe8, 0xc8, 0x9e, 0xb4, 0xa5, 0xa5, 0xa5, 0xd5, 
	0xd8, 0xc8, 0xc8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 
	0xd0, 0xd0, 0xc5, 0xc5, 0xc8, 0xc0, 0xc8, 0xd8, 
	0xd0, 0xb4, 0xaa, 0xb4, 0xaa, 0x9e, 0x9e, 0xc8, 
	0xe8, 0xb4, 0x9e, 0x9e, 0xa5, 0xa5, 0xa5, 0xd5, 
	0xc8, 0xd8, 0xc8, 0xd8, 0xd8, 0xd8, 0xd8, 0xd8, 
	0xd0, 0xd0, 0xc5, 0xc5, 0xb9, 0xc8, 0xc0, 0xc8, 
	0xd0, 0xbc, 0xaa, 0xaa, 0xaa, 0x9e, 0xaa, 0xc8, 
	0xe8, 0xb4, 0x9e, 0x9e, 0xa5, 0xa5, 0xbd, 0xbd, 
	0xc8, 0xc0, 0xc8, 0xc8, 0xd8, 0xd8, 0xd8, 0xd8, 
	0xd0, 0xc5, 0xd0, 0xc0, 0xc0, 0xc8, 0xc8, 0xc8, 
	0xbc, 0xb4, 0xb4, 0xaa, 0x9e, 0xaa, 0xb4, 0xc8, 
	0xe8, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 0xb4, 
	0xc0, 0xb8, 0xb8, 0xb8, 0xb4, 0xb4, 0xb4, 0xb4, 
	0xbd, 0xbd, 0xc0, 0xbd, 0xb9, 0xb9, 0xb9, 0xc0, 
	0xd0, 0xd0, 0xd0, 0xd0, 0xc8, 0xc8, 0xc8, 0xc8, 
	
};

Gfx lava_grate_grate_ia8_aligner[] = {gsSPEndDisplayList()};
u8 lava_grate_grate_ia8[] = {
	0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x1f, 0x4f, 
	0x6f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x2f, 0x2f, 0x4f, 0x2f, 0x1f, 0x1f, 0x1f, 
	0x4f, 0x2f, 0x2f, 0x4f, 0x2f, 0x1f, 0x1f, 0x1f, 
	0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x2f, 0x2f, 0x4f, 0x4f, 0x8f, 0x8f, 0x8f, 
	0x6f, 0x4f, 0x2f, 0x4f, 0x6f, 0x6f, 0x6f, 0x2f, 
	0x6f, 0x2f, 0x2f, 0x4f, 0x4f, 0x8f, 0x8f, 0x8f, 
	0x6f, 0x4f, 0x2f, 0x4f, 0x6f, 0x6f, 0x6f, 0x2f, 
	0x8f, 0x1f, 0x1f, 0x4f, 0x4f, 0x2f, 0x2f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x4f, 0x4f, 0x1f, 0x1f, 0x2f, 
	0x8f, 0x1f, 0x1f, 0x4f, 0x4f, 0x1f, 0x1f, 0x1f, 
	0x1f, 0x4f, 0x1f, 0x4f, 0x4f, 0x1f, 0x1f, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x8f, 0x6f, 0x5f, 0x4f, 0x2f, 0x2f, 0x2f, 
	0x7f, 0x7f, 0x7f, 0x8f, 0x6f, 0x6f, 0x6f, 0x6f, 
	0x8f, 0x8f, 0x8f, 0x8f, 0x7f, 0x2f, 0x2f, 0x2f, 
	0x7f, 0x7f, 0x7f, 0x7f, 0x8f, 0x8f, 0x8f, 0x7f, 
	0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x2f, 0x4f, 
	0x6f, 0x4f, 0x4f, 0x4f, 0x4f, 0x1f, 0x1f, 0x1f, 
	0x1f, 0x1f, 0x4f, 0x4f, 0x1f, 0x1f, 0x1f, 0x2f, 
	0x6f, 0x4f, 0x4f, 0x4f, 0x1f, 0x1f, 0x1f, 0x1f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x4f, 0x4f, 0x4f, 0x6f, 0x6f, 0x6f, 0x6f, 
	0x6f, 0x6f, 0x5f, 0x4f, 0x6f, 0x6f, 0x6f, 0x2f, 
	0x6f, 0x4f, 0x4f, 0x4f, 0x6f, 0x6f, 0x6f, 0x6f, 
	0x6f, 0x6f, 0x5f, 0x4f, 0x4f, 0x6f, 0x6f, 0x2f, 
	0x8f, 0x1f, 0x1f, 0x4f, 0x4f, 0x1f, 0x2f, 0x1f, 
	0x1f, 0x1f, 0x1f, 0x4f, 0x2f, 0x1f, 0x1f, 0x2f, 
	0x8f, 0x1f, 0x1f, 0x4f, 0x2f, 0x2f, 0x2f, 0x4f, 
	0x4f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x6f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x5f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2f, 
	0x8f, 0x8f, 0x8f, 0x6f, 0x6f, 0x2f, 0x2f, 0x2f, 
	0x7f, 0x7f, 0x7f, 0x7f, 0x6f, 0x4f, 0x4f, 0x6f, 
	0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x4f, 0x1f, 
	0x7f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x7f, 0x7f, 
	
};

Vtx lava_grate_Cube_004_mesh_layer_1_vtx_cull[8] = {
	{{{-300, -886, -300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-300, -886, 300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-300, 300, 300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-300, 300, -300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{300, -886, -300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{300, -886, 300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{300, 300, 300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{300, 300, -300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx lava_grate_Cube_004_mesh_layer_1_vtx_0[80] = {
	{{{-300, 259, 300},0, {398, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 300, 300},0, {594, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 300, -300},0, {594, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 259, -300},0, {398, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 259, -300},0, {398, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 300, -300},0, {594, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 300, -300},0, {594, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 259, -300},0, {398, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 259, -300},0, {398, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 300, -300},0, {594, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 300, 300},0, {594, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 259, 300},0, {398, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 259, 300},0, {398, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 300, 300},0, {594, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 300, 300},0, {594, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 259, 300},0, {398, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-240, -886, 240},0, {405, 1008},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{-240, 259, 240},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-251, 259, 300},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-251, -886, 300},0, {405, -16},{0xFF, 0x1, 0x4, 0xFF}}},
	{{{-251, -886, 300},0, {405, 1008},{0xFF, 0x1, 0x4, 0xFF}}},
	{{{-251, 259, 300},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-298, 259, 261},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-298, -886, 261},0, {405, -16},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{-298, -886, 261},0, {405, 1008},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{-298, 259, 261},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-240, 259, 240},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-240, -886, 240},0, {405, -16},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{240, -886, 240},0, {405, 1008},{0xFF, 0x2, 0x4, 0xFF}}},
	{{{240, 259, 240},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{298, 259, 219},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{298, -886, 219},0, {405, -16},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{287, -886, 280},0, {405, 1008},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{287, 259, 280},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{240, 259, 240},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{240, -886, 240},0, {405, -16},{0xFF, 0x2, 0x4, 0xFF}}},
	{{{298, -886, 219},0, {405, 1008},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{298, 259, 219},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{287, 259, 280},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{287, -886, 280},0, {405, -16},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{-298, -886, -280},0, {405, 1008},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{-298, 259, -280},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-240, 259, -300},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-240, -886, -300},0, {405, -16},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{-251, -886, -240},0, {405, 1008},{0xFC, 0x10, 0x4, 0xFF}}},
	{{{-251, 259, -240},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-298, 259, -280},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-298, -886, -280},0, {405, -16},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{-240, -886, -300},0, {405, 1008},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{-240, 259, -300},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-251, 259, -240},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{-251, -886, -240},0, {405, -16},{0xFC, 0x10, 0x4, 0xFF}}},
	{{{240, -886, -279},0, {405, 1008},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{240, 259, -279},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{298, 259, -300},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{298, -886, -300},0, {405, -16},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{287, -886, -240},0, {405, 1008},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{287, 259, -240},0, {587, 1008},{0xFA, 0xE0, 0x0, 0xFF}}},
	{{{240, 259, -279},0, {587, -16},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{240, -886, -279},0, {405, -16},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{298, -886, -300},0, {405, 1008},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{298, 259, -300},0, {587, 1008},{0xFF, 0xE3, 0x0, 0xFF}}},
	{{{287, 259, -240},0, {587, -16},{0xFA, 0xE0, 0x0, 0xFF}}},
	{{{287, -886, -240},0, {405, -16},{0xFF, 0x0, 0x4, 0xFF}}},
	{{{-240, 259, -240},0, {906, 906},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-240, 259, 240},0, {86, 906},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 259, 300},0, {-16, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 259, 300},0, {-16, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{240, 259, 240},0, {86, 86},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 259, -300},0, {1008, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{240, 259, -240},0, {906, 86},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 259, -300},0, {1008, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 300, -300},0, {1008, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 300, -300},0, {-16, -16},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-240, 300, -240},0, {86, 86},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-240, 300, 240},0, {86, 906},{0x0, 0x83, 0x5, 0xFF}}},
	{{{-300, 300, 300},0, {-16, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{240, 300, 240},0, {906, 906},{0x0, 0x83, 0x5, 0xFF}}},
	{{{300, 300, 300},0, {1008, 1008},{0x0, 0x83, 0x5, 0xFF}}},
	{{{240, 300, -240},0, {906, 86},{0x0, 0x83, 0x5, 0xFF}}},
};

Gfx lava_grate_Cube_004_mesh_layer_1_tri_0[] = {
	gsSPVertex(lava_grate_Cube_004_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPVertex(lava_grate_Cube_004_mesh_layer_1_vtx_0 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPVertex(lava_grate_Cube_004_mesh_layer_1_vtx_0 + 64, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 6, 7, 5, 0),
	gsSP2Triangles(6, 0, 7, 0, 0, 2, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
	gsSP2Triangles(9, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(12, 14, 13, 0, 14, 15, 13, 0),
	gsSP2Triangles(14, 8, 15, 0, 8, 10, 15, 0),
	gsSPEndDisplayList(),
};

Vtx lava_grate_Cube_004_mesh_layer_4_vtx_cull[8] = {
	{{{-300, -886, -300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-300, -886, 300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-300, 300, 300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-300, 300, -300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{300, -886, -300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{300, -886, 300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{300, 300, 300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{300, 300, -300},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx lava_grate_Cube_004_mesh_layer_4_vtx_0[8] = {
	{{{-240, 259, -240},0, {-952, 496},{0x0, 0x81, 0x0, 0xFF}}},
	{{{240, 259, -240},0, {496, 1944},{0x0, 0x81, 0x0, 0xFF}}},
	{{{240, 259, 240},0, {1944, 496},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-240, 259, 240},0, {496, -952},{0x0, 0x81, 0x0, 0xFF}}},
	{{{240, 300, -240},0, {-952, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-240, 300, -240},0, {496, 1944},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-240, 300, 240},0, {1944, 496},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{240, 300, 240},0, {496, -952},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx lava_grate_Cube_004_mesh_layer_4_tri_0[] = {
	gsSPVertex(lava_grate_Cube_004_mesh_layer_4_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSPEndDisplayList(),
};


Gfx mat_lava_grate_metal_plate[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, TEXEL0, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b, 32, lava_grate_MetalTile_i8),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(lava_grate_metal_plate_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_lava_grate_metal_plate[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx mat_lava_grate_grate[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b, 32, lava_grate_grate_ia8),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(lava_grate_grate_lights),
	gsSPEndDisplayList(),
};

Gfx lava_grate_Cube_004_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(lava_grate_Cube_004_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_lava_grate_metal_plate),
	gsSPDisplayList(lava_grate_Cube_004_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_lava_grate_metal_plate),
	gsSPEndDisplayList(),
};

Gfx lava_grate_Cube_004_mesh_layer_4[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(lava_grate_Cube_004_mesh_layer_4_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_lava_grate_grate),
	gsSPDisplayList(lava_grate_Cube_004_mesh_layer_4_tri_0),
	gsSPEndDisplayList(),
};

Gfx lava_grate_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
