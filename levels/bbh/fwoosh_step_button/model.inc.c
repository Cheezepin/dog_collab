Lights1 fwoosh_step_button_Metal_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 fwoosh_step_button_MetalDecal_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx fwoosh_step_button_i8_metal_pattern2_i8_aligner[] = {gsSPEndDisplayList()};
u8 fwoosh_step_button_i8_metal_pattern2_i8[] = {
	0x6b, 0x6a, 0x57, 0x6f, 0x77, 0x78, 0x65, 0x63, 
	0x81, 0x7e, 0x80, 0x6f, 0x69, 0x69, 0x6a, 0x56, 
	0x94, 0x71, 0x31, 0x49, 0x7f, 0x7d, 0x73, 0x4d, 
	0x31, 0x51, 0x72, 0x4f, 0x4b, 0x61, 0x50, 0x4f, 
	0x51, 0x54, 0x54, 0x50, 0x52, 0x7f, 0x63, 0x20, 
	0x5f, 0x77, 0x76, 0x66, 0x3c, 0x2c, 0x71, 0x96, 
	0x75, 0x85, 0x84, 0x84, 0x81, 0x74, 0x6d, 0x5e, 
	0x62, 0x73, 0x7a, 0x79, 0x7c, 0x7d, 0x67, 0x7c, 
	0x6a, 0x3f, 0x40, 0x3f, 0x33, 0x51, 0x7b, 0x62, 
	0x3e, 0x43, 0x43, 0x39, 0x35, 0x35, 0x36, 0x39, 
	0x3d, 0x3b, 0x36, 0x56, 0x98, 0x6b, 0x61, 0x5d, 
	0x2f, 0x4f, 0x5e, 0x45, 0x47, 0x56, 0x47, 0x41, 
	0x30, 0x42, 0x48, 0x48, 0x4c, 0x73, 0x5d, 0x23, 
	0x5d, 0x66, 0x6a, 0x74, 0x45, 0x36, 0x38, 0x3b, 
	0x38, 0x3c, 0x3c, 0x3c, 0x3b, 0x38, 0x38, 0x33, 
	0x54, 0x6a, 0x4f, 0x40, 0x3e, 0x3d, 0x38, 0x7b, 
	0x69, 0x3f, 0x55, 0x51, 0x41, 0x42, 0x6d, 0x62, 
	0x3b, 0x40, 0x3e, 0x31, 0x2e, 0x2e, 0x2e, 0x31, 
	0x35, 0x33, 0x35, 0x46, 0x7b, 0x74, 0x75, 0x5d, 
	0x34, 0x52, 0x6b, 0x51, 0x4f, 0x5d, 0x53, 0x54, 
	0x4f, 0x51, 0x52, 0x50, 0x52, 0x73, 0x5f, 0x21, 
	0x76, 0x77, 0x67, 0x73, 0x43, 0x32, 0x32, 0x31, 
	0x32, 0x36, 0x36, 0x36, 0x32, 0x3b, 0x4b, 0x3d, 
	0x53, 0x69, 0x4c, 0x4c, 0x4f, 0x50, 0x38, 0x7b, 
	0x7f, 0x3e, 0x59, 0x6a, 0x55, 0x3f, 0x6b, 0x62, 
	0x3b, 0x38, 0x69, 0x7c, 0x7c, 0x7b, 0x7a, 0x89, 
	0x6a, 0x86, 0x6f, 0x8c, 0x70, 0x7e, 0x89, 0x5b, 
	0x3a, 0x55, 0x6e, 0x53, 0x53, 0x60, 0x59, 0x5a, 
	0x57, 0x56, 0x56, 0x54, 0x55, 0x73, 0x5e, 0x24, 
	0x75, 0x7f, 0x6a, 0x6e, 0x6d, 0x6d, 0x6c, 0x6b, 
	0x6b, 0x63, 0x64, 0x68, 0x7c, 0x63, 0x47, 0x3e, 
	0x52, 0x68, 0x4c, 0x4b, 0x64, 0x54, 0x38, 0x7b, 
	0x81, 0x38, 0x55, 0x55, 0x42, 0x4c, 0x6f, 0x51, 
	0x42, 0x3c, 0x74, 0x84, 0x70, 0x7f, 0x81, 0x79, 
	0x8e, 0x77, 0x75, 0x72, 0x5d, 0x74, 0x72, 0x51, 
	0x30, 0x5a, 0x5c, 0x44, 0x42, 0x49, 0x3d, 0x3a, 
	0x32, 0x39, 0x3f, 0x3c, 0x41, 0x5b, 0x53, 0x26, 
	0x5f, 0x66, 0x5d, 0x61, 0x61, 0x79, 0x68, 0x78, 
	0x7a, 0x70, 0x5e, 0x73, 0x75, 0x67, 0x41, 0x45, 
	0x52, 0x78, 0x54, 0x49, 0x54, 0x52, 0x35, 0x80, 
	0x6b, 0x30, 0x3b, 0x3a, 0x2c, 0x3f, 0x69, 0x61, 
	0x40, 0x3c, 0x75, 0x84, 0x6f, 0x6e, 0x6d, 0x75, 
	0x91, 0x5c, 0x75, 0x6f, 0x6b, 0x78, 0x84, 0x59, 
	0x2e, 0x4a, 0x56, 0x42, 0x3b, 0x39, 0x32, 0x2f, 
	0x27, 0x2e, 0x35, 0x33, 0x3a, 0x4e, 0x45, 0x30, 
	0x50, 0x65, 0x5d, 0x69, 0x70, 0x77, 0x76, 0x66, 
	0x66, 0x72, 0x6f, 0x73, 0x71, 0x57, 0x42, 0x43, 
	0x64, 0x73, 0x48, 0x32, 0x36, 0x38, 0x2d, 0x81, 
	0x69, 0x7a, 0x60, 0x4f, 0x57, 0x5e, 0x72, 0x62, 
	0x41, 0x40, 0x65, 0x6d, 0x69, 0x6a, 0x69, 0x74, 
	0x7b, 0x5b, 0x73, 0x64, 0x7f, 0x59, 0x70, 0x5e, 
	0x2a, 0x5e, 0x6d, 0x59, 0x55, 0x5a, 0x5a, 0x59, 
	0x51, 0x52, 0x54, 0x4f, 0x4e, 0x5e, 0x58, 0x35, 
	0x5c, 0x6a, 0x69, 0x6f, 0x64, 0x76, 0x76, 0x61, 
	0x61, 0x60, 0x60, 0x6f, 0x5d, 0x56, 0x43, 0x43, 
	0x66, 0x6f, 0x5c, 0x71, 0x65, 0x61, 0x5f, 0x6c, 
	0x68, 0x72, 0x69, 0x50, 0x50, 0x66, 0x77, 0x63, 
	0x3f, 0x41, 0x5e, 0x77, 0x6e, 0x5b, 0x4b, 0x4b, 
	0x4c, 0x46, 0x4f, 0x49, 0x52, 0x44, 0x52, 0x48, 
	0x2e, 0x57, 0x6b, 0x5b, 0x57, 0x5d, 0x5d, 0x5b, 
	0x5c, 0x5b, 0x51, 0x4e, 0x55, 0x65, 0x58, 0x34, 
	0x56, 0x58, 0x4a, 0x4b, 0x44, 0x4e, 0x4c, 0x43, 
	0x43, 0x3f, 0x6c, 0x6f, 0x6d, 0x62, 0x41, 0x4a, 
	0x6a, 0x7d, 0x79, 0x7f, 0x6e, 0x69, 0x80, 0x69, 
	0x7a, 0x43, 0x46, 0x40, 0x43, 0x49, 0x50, 0x50, 
	0x50, 0x3f, 0x6c, 0x76, 0x62, 0x5b, 0x3f, 0x3b, 
	0x38, 0x3d, 0x3c, 0x39, 0x35, 0x36, 0x42, 0x3c, 
	0x27, 0x53, 0x67, 0x5e, 0x58, 0x55, 0x59, 0x5a, 
	0x5c, 0x5a, 0x4e, 0x4d, 0x57, 0x65, 0x58, 0x2c, 
	0x45, 0x49, 0x3a, 0x34, 0x38, 0x3c, 0x3c, 0x39, 
	0x3b, 0x3d, 0x68, 0x69, 0x6c, 0x5a, 0x40, 0x4f, 
	0x51, 0x52, 0x53, 0x53, 0x52, 0x43, 0x4d, 0x5e, 
	0x65, 0x34, 0x38, 0x3b, 0x41, 0x3f, 0x3d, 0x4c, 
	0x4d, 0x34, 0x6f, 0x71, 0x67, 0x68, 0x3f, 0x3b, 
	0x60, 0x54, 0x60, 0x51, 0x45, 0x56, 0x66, 0x53, 
	0x48, 0x5d, 0x69, 0x5a, 0x5a, 0x5a, 0x5c, 0x5b, 
	0x5e, 0x5d, 0x4f, 0x4b, 0x4f, 0x5f, 0x5e, 0x4b, 
	0x58, 0x5c, 0x55, 0x65, 0x5e, 0x56, 0x54, 0x58, 
	0x3b, 0x40, 0x72, 0x5e, 0x55, 0x57, 0x41, 0x51, 
	0x47, 0x3e, 0x3f, 0x3d, 0x46, 0x44, 0x2e, 0x5b, 
	0x59, 0x37, 0x39, 0x32, 0x39, 0x38, 0x38, 0x3e, 
	0x3b, 0x29, 0x70, 0x70, 0x6a, 0x6c, 0x40, 0x3a, 
	0x68, 0x57, 0x66, 0x59, 0x54, 0x5c, 0x72, 0x65, 
	0x4b, 0x5c, 0x68, 0x56, 0x55, 0x4b, 0x48, 0x46, 
	0x48, 0x40, 0x40, 0x55, 0x49, 0x59, 0x59, 0x48, 
	0x5f, 0x69, 0x55, 0x61, 0x64, 0x68, 0x67, 0x5b, 
	0x3b, 0x41, 0x75, 0x5d, 0x60, 0x62, 0x31, 0x3d, 
	0x3b, 0x3b, 0x3d, 0x3b, 0x42, 0x4a, 0x34, 0x59, 
	0x58, 0x38, 0x42, 0x70, 0x76, 0x73, 0x73, 0x6b, 
	0x5b, 0x59, 0x68, 0x6c, 0x6b, 0x6a, 0x3d, 0x39, 
	0x57, 0x59, 0x45, 0x41, 0x46, 0x4d, 0x64, 0x59, 
	0x3e, 0x50, 0x5b, 0x58, 0x55, 0x3d, 0x43, 0x3c, 
	0x2e, 0x2e, 0x39, 0x5a, 0x52, 0x53, 0x4b, 0x36, 
	0x4a, 0x5c, 0x44, 0x3e, 0x45, 0x48, 0x64, 0x63, 
	0x38, 0x3f, 0x77, 0x5e, 0x65, 0x71, 0x65, 0x65, 
	0x6d, 0x66, 0x5d, 0x60, 0x65, 0x42, 0x30, 0x6b, 
	0x69, 0x32, 0x42, 0x78, 0x76, 0x71, 0x6a, 0x6a, 
	0x63, 0x67, 0x6b, 0x67, 0x65, 0x62, 0x49, 0x46, 
	0x6f, 0x6d, 0x40, 0x4f, 0x53, 0x53, 0x5a, 0x50, 
	0x39, 0x4d, 0x56, 0x59, 0x5f, 0x40, 0x3b, 0x56, 
	0x48, 0x31, 0x3b, 0x55, 0x4d, 0x54, 0x47, 0x30, 
	0x46, 0x54, 0x51, 0x54, 0x49, 0x3c, 0x5e, 0x6b, 
	0x41, 0x46, 0x69, 0x61, 0x66, 0x71, 0x66, 0x65, 
	0x6f, 0x6d, 0x68, 0x6b, 0x72, 0x3e, 0x30, 0x62, 
	0x71, 0x2f, 0x40, 0x71, 0x64, 0x58, 0x55, 0x5d, 
	0x5e, 0x62, 0x65, 0x5c, 0x58, 0x5e, 0x4f, 0x4e, 
	0x74, 0x6f, 0x57, 0x5e, 0x5d, 0x5a, 0x5b, 0x52, 
	0x3b, 0x56, 0x5e, 0x59, 0x63, 0x41, 0x33, 0x61, 
	0x63, 0x2e, 0x3b, 0x62, 0x5b, 0x61, 0x51, 0x31, 
	0x4e, 0x59, 0x59, 0x64, 0x5a, 0x4c, 0x5c, 0x6c, 
	0x47, 0x4b, 0x5e, 0x61, 0x5c, 0x64, 0x61, 0x63, 
	0x5c, 0x63, 0x68, 0x69, 0x71, 0x3f, 0x30, 0x66, 
	0x72, 0x2f, 0x40, 0x72, 0x67, 0x5f, 0x63, 0x65, 
	0x69, 0x66, 0x62, 0x58, 0x53, 0x5e, 0x50, 0x4e, 
	0x5e, 0x5d, 0x4d, 0x50, 0x54, 0x5e, 0x5e, 0x53, 
	0x44, 0x5d, 0x5f, 0x60, 0x64, 0x3f, 0x32, 0x5f, 
	0x69, 0x2e, 0x3c, 0x6b, 0x67, 0x65, 0x59, 0x42, 
	0x55, 0x56, 0x52, 0x52, 0x4b, 0x41, 0x52, 0x60, 
	0x48, 0x4b, 0x5f, 0x59, 0x58, 0x6a, 0x64, 0x64, 
	0x61, 0x5f, 0x66, 0x64, 0x67, 0x3d, 0x2f, 0x70, 
	0x66, 0x30, 0x40, 0x72, 0x69, 0x67, 0x63, 0x58, 
	0x5d, 0x59, 0x56, 0x4e, 0x4a, 0x4d, 0x4d, 0x54, 
	0x4d, 0x4f, 0x32, 0x3b, 0x43, 0x52, 0x51, 0x49, 
	0x3c, 0x55, 0x5d, 0x62, 0x64, 0x40, 0x36, 0x5d, 
	0x68, 0x2d, 0x3c, 0x69, 0x65, 0x64, 0x56, 0x3c, 
	0x48, 0x3f, 0x3d, 0x34, 0x33, 0x2e, 0x4b, 0x4a, 
	0x4a, 0x4b, 0x4c, 0x47, 0x4d, 0x5f, 0x53, 0x4f, 
	0x54, 0x56, 0x5d, 0x5c, 0x5c, 0x3b, 0x2f, 0x6f, 
	0x57, 0x32, 0x3f, 0x6e, 0x65, 0x69, 0x58, 0x44, 
	0x47, 0x42, 0x40, 0x40, 0x41, 0x36, 0x48, 0x4d, 
	0x53, 0x51, 0x4b, 0x5a, 0x55, 0x64, 0x60, 0x62, 
	0x62, 0x61, 0x69, 0x6b, 0x64, 0x41, 0x37, 0x6a, 
	0x68, 0x2d, 0x3c, 0x6a, 0x65, 0x63, 0x5b, 0x54, 
	0x62, 0x5c, 0x55, 0x53, 0x50, 0x4e, 0x50, 0x4a, 
	0x46, 0x47, 0x30, 0x39, 0x39, 0x3f, 0x41, 0x44, 
	0x3e, 0x50, 0x5a, 0x5c, 0x62, 0x3f, 0x35, 0x68, 
	0x61, 0x31, 0x3f, 0x6b, 0x69, 0x6a, 0x53, 0x46, 
	0x53, 0x58, 0x55, 0x52, 0x52, 0x46, 0x5f, 0x5e, 
	0x50, 0x51, 0x63, 0x6c, 0x5f, 0x70, 0x6d, 0x72, 
	0x77, 0x71, 0x6c, 0x75, 0x66, 0x40, 0x37, 0x6a, 
	0x68, 0x2d, 0x3a, 0x63, 0x65, 0x62, 0x64, 0x6a, 
	0x70, 0x69, 0x64, 0x65, 0x66, 0x5c, 0x4b, 0x4a, 
	0x5c, 0x56, 0x41, 0x4a, 0x4d, 0x55, 0x56, 0x53, 
	0x42, 0x51, 0x5d, 0x5d, 0x63, 0x44, 0x38, 0x6b, 
	0x6e, 0x30, 0x3f, 0x6c, 0x68, 0x67, 0x58, 0x3a, 
	0x52, 0x60, 0x60, 0x5d, 0x5b, 0x51, 0x70, 0x70, 
	0x4f, 0x51, 0x6e, 0x6b, 0x5d, 0x6d, 0x6d, 0x65, 
	0x6b, 0x72, 0x69, 0x69, 0x6b, 0x42, 0x37, 0x66, 
	0x68, 0x2d, 0x39, 0x60, 0x66, 0x62, 0x64, 0x69, 
	0x64, 0x69, 0x70, 0x67, 0x60, 0x4d, 0x49, 0x49, 
	0x6d, 0x61, 0x4e, 0x57, 0x59, 0x5d, 0x5f, 0x54, 
	0x39, 0x57, 0x60, 0x64, 0x64, 0x42, 0x41, 0x78, 
	0x60, 0x31, 0x3f, 0x69, 0x59, 0x61, 0x5e, 0x31, 
	0x4c, 0x5d, 0x55, 0x50, 0x50, 0x44, 0x65, 0x61, 
	0x47, 0x4c, 0x74, 0x6e, 0x61, 0x65, 0x6b, 0x64, 
	0x69, 0x6c, 0x78, 0x74, 0x76, 0x49, 0x33, 0x73, 
	0x6c, 0x2d, 0x3c, 0x6f, 0x67, 0x65, 0x63, 0x64, 
	0x63, 0x6d, 0x74, 0x67, 0x56, 0x4e, 0x44, 0x42, 
	0x5a, 0x59, 0x42, 0x4a, 0x4a, 0x51, 0x5b, 0x4f, 
	0x2f, 0x55, 0x5b, 0x65, 0x64, 0x41, 0x4e, 0x6b, 
	0x3a, 0x31, 0x3e, 0x68, 0x5c, 0x62, 0x5d, 0x37, 
	0x51, 0x60, 0x47, 0x3f, 0x49, 0x43, 0x54, 0x61, 
	0x39, 0x42, 0x6c, 0x6a, 0x6b, 0x5b, 0x5c, 0x62, 
	0x62, 0x55, 0x6b, 0x79, 0x6a, 0x4c, 0x2e, 0x6f, 
	0x6a, 0x31, 0x43, 0x67, 0x5e, 0x5d, 0x59, 0x58, 
	0x5a, 0x54, 0x63, 0x5c, 0x62, 0x5e, 0x3e, 0x38, 
	0x55, 0x54, 0x49, 0x48, 0x3d, 0x4a, 0x5e, 0x52, 
	0x38, 0x52, 0x5f, 0x5c, 0x63, 0x40, 0x46, 0x43, 
	0x49, 0x4a, 0x50, 0x66, 0x5f, 0x69, 0x60, 0x48, 
	0x5e, 0x68, 0x54, 0x56, 0x5e, 0x5e, 0x5c, 0x72, 
	0x39, 0x3c, 0x5b, 0x5c, 0x6b, 0x57, 0x40, 0x4c, 
	0x4a, 0x41, 0x3e, 0x3c, 0x42, 0x47, 0x2e, 0x70, 
	0x61, 0x33, 0x4b, 0x45, 0x46, 0x45, 0x45, 0x4c, 
	0x47, 0x34, 0x6a, 0x5f, 0x62, 0x6a, 0x40, 0x39, 
	0x61, 0x61, 0x63, 0x67, 0x5e, 0x63, 0x70, 0x64, 
	0x4b, 0x66, 0x6f, 0x64, 0x63, 0x51, 0x4c, 0x4c, 
	0x68, 0x66, 0x65, 0x61, 0x5f, 0x6a, 0x5f, 0x47, 
	0x5c, 0x61, 0x52, 0x54, 0x55, 0x5b, 0x5c, 0x6a, 
	0x3b, 0x3e, 0x60, 0x63, 0x73, 0x5a, 0x48, 0x55, 
	0x4a, 0x41, 0x43, 0x44, 0x41, 0x41, 0x2b, 0x6a, 
	0x6d, 0x2d, 0x43, 0x42, 0x42, 0x42, 0x43, 0x4c, 
	0x51, 0x3f, 0x69, 0x69, 0x5a, 0x5b, 0x3e, 0x39, 
	0x5a, 0x5a, 0x5d, 0x63, 0x5f, 0x5d, 0x6d, 0x60, 
	0x49, 0x62, 0x66, 0x5e, 0x5a, 0x64, 0x66, 0x68, 
	0x55, 0x54, 0x55, 0x55, 0x5d, 0x69, 0x5b, 0x2e, 
	0x42, 0x47, 0x3a, 0x34, 0x32, 0x44, 0x43, 0x3b, 
	0x43, 0x42, 0x69, 0x6b, 0x78, 0x61, 0x45, 0x4f, 
	0x57, 0x54, 0x50, 0x4b, 0x43, 0x40, 0x41, 0x55, 
	0x5b, 0x49, 0x3f, 0x44, 0x4e, 0x44, 0x4d, 0x56, 
	0x50, 0x41, 0x6c, 0x74, 0x66, 0x6e, 0x47, 0x40, 
	0x3a, 0x3c, 0x3d, 0x31, 0x33, 0x37, 0x48, 0x44, 
	0x2e, 0x54, 0x64, 0x57, 0x63, 0x5c, 0x57, 0x58, 
	0x59, 0x58, 0x57, 0x55, 0x56, 0x6e, 0x5c, 0x33, 
	0x4a, 0x54, 0x48, 0x45, 0x45, 0x54, 0x55, 0x52, 
	0x51, 0x5a, 0x66, 0x61, 0x62, 0x5d, 0x42, 0x3c, 
	0x70, 0x7c, 0x72, 0x5c, 0x61, 0x6e, 0x6a, 0x5a, 
	0x69, 0x79, 0x6a, 0x6d, 0x80, 0x69, 0x79, 0x6c, 
	0x4a, 0x45, 0x76, 0x64, 0x66, 0x81, 0x52, 0x47, 
	0x50, 0x50, 0x50, 0x47, 0x4a, 0x4c, 0x59, 0x51, 
	0x39, 0x52, 0x60, 0x5d, 0x62, 0x67, 0x59, 0x5a, 
	0x58, 0x57, 0x56, 0x53, 0x51, 0x6b, 0x5f, 0x33, 
	0x5a, 0x73, 0x68, 0x65, 0x62, 0x74, 0x74, 0x76, 
	0x76, 0x89, 0x60, 0x62, 0x6b, 0x70, 0x3d, 0x40, 
	0x60, 0x70, 0x6b, 0x56, 0x48, 0x73, 0x61, 0x79, 
	0x7a, 0x5e, 0x72, 0x63, 0x74, 0x69, 0x7f, 0x67, 
	0x3e, 0x3e, 0x61, 0x71, 0x71, 0x6a, 0x72, 0x67, 
	0x79, 0x78, 0x76, 0x6e, 0x6e, 0x71, 0x7b, 0x5d, 
	0x30, 0x5b, 0x66, 0x55, 0x5c, 0x5f, 0x53, 0x53, 
	0x31, 0x35, 0x38, 0x3a, 0x3a, 0x54, 0x60, 0x2c, 
	0x64, 0x84, 0x6d, 0x69, 0x53, 0x70, 0x63, 0x6f, 
	0x74, 0x5f, 0x62, 0x62, 0x6a, 0x70, 0x3d, 0x3b, 
	0x74, 0x80, 0x4a, 0x37, 0x3e, 0x36, 0x34, 0x67, 
	0x79, 0x33, 0x3a, 0x3a, 0x36, 0x4a, 0x69, 0x57, 
	0x4e, 0x48, 0x62, 0x7f, 0x83, 0x6d, 0x83, 0x75, 
	0x76, 0x74, 0x72, 0x5c, 0x5f, 0x67, 0x78, 0x59, 
	0x2e, 0x46, 0x56, 0x42, 0x45, 0x3d, 0x39, 0x37, 
	0x3a, 0x3d, 0x40, 0x41, 0x45, 0x5e, 0x52, 0x2e, 
	0x69, 0x75, 0x66, 0x68, 0x6e, 0x74, 0x75, 0x4b, 
	0x74, 0x63, 0x62, 0x60, 0x6a, 0x6e, 0x3c, 0x3c, 
	0x72, 0x7f, 0x49, 0x4c, 0x53, 0x41, 0x36, 0x7a, 
	0x78, 0x3a, 0x51, 0x53, 0x4c, 0x4e, 0x6d, 0x57, 
	0x4d, 0x45, 0x78, 0x76, 0x6a, 0x6f, 0x82, 0x67, 
	0x76, 0x65, 0x63, 0x66, 0x74, 0x6b, 0x66, 0x57, 
	0x2b, 0x53, 0x62, 0x49, 0x44, 0x45, 0x42, 0x40, 
	0x5e, 0x5b, 0x5b, 0x58, 0x5c, 0x7b, 0x6f, 0x2b, 
	0x6b, 0x77, 0x6c, 0x5c, 0x7d, 0x68, 0x65, 0x52, 
	0x66, 0x63, 0x61, 0x4f, 0x66, 0x5c, 0x40, 0x42, 
	0x66, 0x75, 0x46, 0x47, 0x4e, 0x4e, 0x32, 0x6a, 
	0x72, 0x45, 0x4b, 0x5c, 0x45, 0x60, 0x7b, 0x51, 
	0x42, 0x4d, 0x6f, 0x83, 0x6d, 0x81, 0x68, 0x8c, 
	0x70, 0x8a, 0x6e, 0x72, 0x6d, 0x63, 0x70, 0x56, 
	0x3b, 0x69, 0x79, 0x5d, 0x5f, 0x63, 0x60, 0x64, 
	0x60, 0x5c, 0x5b, 0x57, 0x5a, 0x77, 0x5c, 0x2f, 
	0x6b, 0x79, 0x6f, 0x73, 0x4d, 0x3e, 0x3d, 0x3d, 
	0x3a, 0x37, 0x37, 0x39, 0x37, 0x38, 0x38, 0x34, 
	0x54, 0x6a, 0x47, 0x45, 0x4e, 0x36, 0x2d, 0x83, 
	0x5c, 0x31, 0x48, 0x47, 0x40, 0x51, 0x86, 0x65, 
	0x40, 0x51, 0x3e, 0x33, 0x36, 0x34, 0x36, 0x36, 
	0x39, 0x38, 0x3a, 0x45, 0x77, 0x73, 0x72, 0x58, 
	0x38, 0x67, 0x7a, 0x5a, 0x58, 0x5c, 0x58, 0x5a, 
	0x42, 0x46, 0x4b, 0x49, 0x4e, 0x72, 0x55, 0x2a, 
	0x54, 0x69, 0x83, 0x69, 0x46, 0x3f, 0x41, 0x40, 
	0x3f, 0x3b, 0x3c, 0x3b, 0x3c, 0x3d, 0x3d, 0x38, 
	0x56, 0x6c, 0x4b, 0x35, 0x37, 0x36, 0x33, 0x69, 
	0x5e, 0x34, 0x36, 0x35, 0x2c, 0x57, 0x7b, 0x52, 
	0x39, 0x3c, 0x3b, 0x3d, 0x3d, 0x3b, 0x3d, 0x3d, 
	0x3e, 0x3f, 0x3c, 0x47, 0x78, 0x73, 0x6e, 0x52, 
	0x2e, 0x62, 0x76, 0x51, 0x4e, 0x50, 0x47, 0x45, 
	0x61, 0x58, 0x58, 0x53, 0x56, 0x7e, 0x5c, 0x2a, 
	0x59, 0x70, 0x85, 0x6a, 0x45, 0x35, 0x82, 0x87, 
	0x86, 0x69, 0x7d, 0x6a, 0x82, 0x88, 0x88, 0x7c, 
	0x66, 0x78, 0x82, 0x81, 0x85, 0x6d, 0x68, 0x84, 
	0x74, 0x74, 0x74, 0x71, 0x6c, 0x84, 0x76, 0x71, 
	0x83, 0x83, 0x6e, 0x82, 0x8b, 0x70, 0x88, 0x5b, 
	0x78, 0x74, 0x35, 0x47, 0x76, 0x68, 0x75, 0x55, 
	0x2f, 0x68, 0x81, 0x58, 0x56, 0x5b, 0x53, 0x56, 
	0x54, 0x54, 0x54, 0x50, 0x52, 0x7f, 0x63, 0x20, 
	0x5f, 0x77, 0x76, 0x66, 0x3c, 0x2c, 0x71, 0x96, 
	0x75, 0x85, 0x84, 0x84, 0x81, 0x74, 0x6d, 0x5e, 
	0x62, 0x73, 0x7a, 0x79, 0x7c, 0x7d, 0x67, 0x7c, 
	0x6b, 0x6a, 0x57, 0x6f, 0x77, 0x78, 0x65, 0x63, 
	0x81, 0x7e, 0x80, 0x6f, 0x69, 0x69, 0x6a, 0x56, 
	0x94, 0x71, 0x31, 0x49, 0x7f, 0x7d, 0x73, 0x4d, 
	0x31, 0x51, 0x72, 0x4f, 0x4b, 0x61, 0x50, 0x4f, 
	0x30, 0x42, 0x48, 0x48, 0x4c, 0x73, 0x5d, 0x23, 
	0x5d, 0x66, 0x6a, 0x74, 0x45, 0x36, 0x38, 0x3b, 
	0x38, 0x3c, 0x3c, 0x3c, 0x3b, 0x38, 0x38, 0x33, 
	0x54, 0x6a, 0x4f, 0x40, 0x3e, 0x3d, 0x38, 0x7b, 
	0x6a, 0x3f, 0x40, 0x3f, 0x33, 0x51, 0x7b, 0x62, 
	0x3e, 0x43, 0x43, 0x39, 0x35, 0x35, 0x36, 0x39, 
	0x3d, 0x3b, 0x36, 0x56, 0x98, 0x6b, 0x61, 0x5d, 
	0x2f, 0x4f, 0x5e, 0x45, 0x47, 0x56, 0x47, 0x41, 
	0x4f, 0x51, 0x52, 0x50, 0x52, 0x73, 0x5f, 0x21, 
	0x76, 0x77, 0x67, 0x73, 0x43, 0x32, 0x32, 0x31, 
	0x32, 0x36, 0x36, 0x36, 0x32, 0x3b, 0x4b, 0x3d, 
	0x53, 0x69, 0x4c, 0x4c, 0x4f, 0x50, 0x38, 0x7b, 
	0x69, 0x3f, 0x55, 0x51, 0x41, 0x42, 0x6d, 0x62, 
	0x3b, 0x40, 0x3e, 0x31, 0x2e, 0x2e, 0x2e, 0x31, 
	0x35, 0x33, 0x35, 0x46, 0x7b, 0x74, 0x75, 0x5d, 
	0x34, 0x52, 0x6b, 0x51, 0x4f, 0x5d, 0x53, 0x54, 
	0x57, 0x56, 0x56, 0x54, 0x55, 0x73, 0x5e, 0x24, 
	0x75, 0x7f, 0x6a, 0x6e, 0x6d, 0x6d, 0x6c, 0x6b, 
	0x6b, 0x63, 0x64, 0x68, 0x7c, 0x63, 0x47, 0x3e, 
	0x52, 0x68, 0x4c, 0x4b, 0x64, 0x54, 0x38, 0x7b, 
	0x7f, 0x3e, 0x59, 0x6a, 0x55, 0x3f, 0x6b, 0x62, 
	0x3b, 0x38, 0x69, 0x7c, 0x7c, 0x7b, 0x7a, 0x89, 
	0x6a, 0x86, 0x6f, 0x8c, 0x70, 0x7e, 0x89, 0x5b, 
	0x3a, 0x55, 0x6e, 0x53, 0x53, 0x60, 0x59, 0x5a, 
	0x32, 0x39, 0x3f, 0x3c, 0x41, 0x5b, 0x53, 0x26, 
	0x5f, 0x66, 0x5d, 0x61, 0x61, 0x79, 0x68, 0x78, 
	0x7a, 0x70, 0x5e, 0x73, 0x75, 0x67, 0x41, 0x45, 
	0x52, 0x78, 0x54, 0x49, 0x54, 0x52, 0x35, 0x80, 
	0x81, 0x38, 0x55, 0x55, 0x42, 0x4c, 0x6f, 0x51, 
	0x42, 0x3c, 0x74, 0x84, 0x70, 0x7f, 0x81, 0x79, 
	0x8e, 0x77, 0x75, 0x72, 0x5d, 0x74, 0x72, 0x51, 
	0x30, 0x5a, 0x5c, 0x44, 0x42, 0x49, 0x3d, 0x3a, 
	0x27, 0x2e, 0x35, 0x33, 0x3a, 0x4e, 0x45, 0x30, 
	0x50, 0x65, 0x5d, 0x69, 0x70, 0x77, 0x76, 0x66, 
	0x66, 0x72, 0x6f, 0x73, 0x71, 0x57, 0x42, 0x43, 
	0x64, 0x73, 0x48, 0x32, 0x36, 0x38, 0x2d, 0x81, 
	0x6b, 0x30, 0x3b, 0x3a, 0x2c, 0x3f, 0x69, 0x61, 
	0x40, 0x3c, 0x75, 0x84, 0x6f, 0x6e, 0x6d, 0x75, 
	0x91, 0x5c, 0x75, 0x6f, 0x6b, 0x78, 0x84, 0x59, 
	0x2e, 0x4a, 0x56, 0x42, 0x3b, 0x39, 0x32, 0x2f, 
	0x51, 0x52, 0x54, 0x4f, 0x4e, 0x5e, 0x58, 0x35, 
	0x5c, 0x6a, 0x69, 0x6f, 0x64, 0x76, 0x76, 0x61, 
	0x61, 0x60, 0x60, 0x6f, 0x5d, 0x56, 0x43, 0x43, 
	0x66, 0x6f, 0x5c, 0x71, 0x65, 0x61, 0x5f, 0x6c, 
	0x69, 0x7a, 0x60, 0x4f, 0x57, 0x5e, 0x72, 0x62, 
	0x41, 0x40, 0x65, 0x6d, 0x69, 0x6a, 0x69, 0x74, 
	0x7b, 0x5b, 0x73, 0x64, 0x7f, 0x59, 0x70, 0x5e, 
	0x2a, 0x5e, 0x6d, 0x59, 0x55, 0x5a, 0x5a, 0x59, 
	0x5c, 0x5b, 0x51, 0x4e, 0x55, 0x65, 0x58, 0x34, 
	0x56, 0x58, 0x4a, 0x4b, 0x44, 0x4e, 0x4c, 0x43, 
	0x43, 0x3f, 0x6c, 0x6f, 0x6d, 0x62, 0x41, 0x4a, 
	0x6a, 0x7d, 0x79, 0x7f, 0x6e, 0x69, 0x80, 0x69, 
	0x68, 0x72, 0x69, 0x50, 0x50, 0x66, 0x77, 0x63, 
	0x3f, 0x41, 0x5e, 0x77, 0x6e, 0x5b, 0x4b, 0x4b, 
	0x4c, 0x46, 0x4f, 0x49, 0x52, 0x44, 0x52, 0x48, 
	0x2e, 0x57, 0x6b, 0x5b, 0x57, 0x5d, 0x5d, 0x5b, 
	0x5c, 0x5a, 0x4e, 0x4d, 0x57, 0x65, 0x58, 0x2c, 
	0x45, 0x49, 0x3a, 0x34, 0x38, 0x3c, 0x3c, 0x39, 
	0x3b, 0x3d, 0x68, 0x69, 0x6c, 0x5a, 0x40, 0x4f, 
	0x51, 0x52, 0x53, 0x53, 0x52, 0x43, 0x4d, 0x5e, 
	0x7a, 0x43, 0x46, 0x40, 0x43, 0x49, 0x50, 0x50, 
	0x50, 0x3f, 0x6c, 0x76, 0x62, 0x5b, 0x3f, 0x3b, 
	0x38, 0x3d, 0x3c, 0x39, 0x35, 0x36, 0x42, 0x3c, 
	0x27, 0x53, 0x67, 0x5e, 0x58, 0x55, 0x59, 0x5a, 
	0x5e, 0x5d, 0x4f, 0x4b, 0x4f, 0x5f, 0x5e, 0x4b, 
	0x58, 0x5c, 0x55, 0x65, 0x5e, 0x56, 0x54, 0x58, 
	0x3b, 0x40, 0x72, 0x5e, 0x55, 0x57, 0x41, 0x51, 
	0x47, 0x3e, 0x3f, 0x3d, 0x46, 0x44, 0x2e, 0x5b, 
	0x65, 0x34, 0x38, 0x3b, 0x41, 0x3f, 0x3d, 0x4c, 
	0x4d, 0x34, 0x6f, 0x71, 0x67, 0x68, 0x3f, 0x3b, 
	0x60, 0x54, 0x60, 0x51, 0x45, 0x56, 0x66, 0x53, 
	0x48, 0x5d, 0x69, 0x5a, 0x5a, 0x5a, 0x5c, 0x5b, 
	0x48, 0x40, 0x40, 0x55, 0x49, 0x59, 0x59, 0x48, 
	0x5f, 0x69, 0x55, 0x61, 0x64, 0x68, 0x67, 0x5b, 
	0x3b, 0x41, 0x75, 0x5d, 0x60, 0x62, 0x31, 0x3d, 
	0x3b, 0x3b, 0x3d, 0x3b, 0x42, 0x4a, 0x34, 0x59, 
	0x59, 0x37, 0x39, 0x32, 0x39, 0x38, 0x38, 0x3e, 
	0x3b, 0x29, 0x70, 0x70, 0x6a, 0x6c, 0x40, 0x3a, 
	0x68, 0x57, 0x66, 0x59, 0x54, 0x5c, 0x72, 0x65, 
	0x4b, 0x5c, 0x68, 0x56, 0x55, 0x4b, 0x48, 0x46, 
	0x2e, 0x2e, 0x39, 0x5a, 0x52, 0x53, 0x4b, 0x36, 
	0x4a, 0x5c, 0x44, 0x3e, 0x45, 0x48, 0x64, 0x63, 
	0x38, 0x3f, 0x77, 0x5e, 0x65, 0x71, 0x65, 0x65, 
	0x6d, 0x66, 0x5d, 0x60, 0x65, 0x42, 0x30, 0x6b, 
	0x58, 0x38, 0x42, 0x70, 0x76, 0x73, 0x73, 0x6b, 
	0x5b, 0x59, 0x68, 0x6c, 0x6b, 0x6a, 0x3d, 0x39, 
	0x57, 0x59, 0x45, 0x41, 0x46, 0x4d, 0x64, 0x59, 
	0x3e, 0x50, 0x5b, 0x58, 0x55, 0x3d, 0x43, 0x3c, 
	0x48, 0x31, 0x3b, 0x55, 0x4d, 0x54, 0x47, 0x30, 
	0x46, 0x54, 0x51, 0x54, 0x49, 0x3c, 0x5e, 0x6b, 
	0x41, 0x46, 0x69, 0x61, 0x66, 0x71, 0x66, 0x65, 
	0x6f, 0x6d, 0x68, 0x6b, 0x72, 0x3e, 0x30, 0x62, 
	0x69, 0x32, 0x42, 0x78, 0x76, 0x71, 0x6a, 0x6a, 
	0x63, 0x67, 0x6b, 0x67, 0x65, 0x62, 0x49, 0x46, 
	0x6f, 0x6d, 0x40, 0x4f, 0x53, 0x53, 0x5a, 0x50, 
	0x39, 0x4d, 0x56, 0x59, 0x5f, 0x40, 0x3b, 0x56, 
	0x63, 0x2e, 0x3b, 0x62, 0x5b, 0x61, 0x51, 0x31, 
	0x4e, 0x59, 0x59, 0x64, 0x5a, 0x4c, 0x5c, 0x6c, 
	0x47, 0x4b, 0x5e, 0x61, 0x5c, 0x64, 0x61, 0x63, 
	0x5c, 0x63, 0x68, 0x69, 0x71, 0x3f, 0x30, 0x66, 
	0x71, 0x2f, 0x40, 0x71, 0x64, 0x58, 0x55, 0x5d, 
	0x5e, 0x62, 0x65, 0x5c, 0x58, 0x5e, 0x4f, 0x4e, 
	0x74, 0x6f, 0x57, 0x5e, 0x5d, 0x5a, 0x5b, 0x52, 
	0x3b, 0x56, 0x5e, 0x59, 0x63, 0x41, 0x33, 0x61, 
	0x69, 0x2e, 0x3c, 0x6b, 0x67, 0x65, 0x59, 0x42, 
	0x55, 0x56, 0x52, 0x52, 0x4b, 0x41, 0x52, 0x60, 
	0x48, 0x4b, 0x5f, 0x59, 0x58, 0x6a, 0x64, 0x64, 
	0x61, 0x5f, 0x66, 0x64, 0x67, 0x3d, 0x2f, 0x70, 
	0x72, 0x2f, 0x40, 0x72, 0x67, 0x5f, 0x63, 0x65, 
	0x69, 0x66, 0x62, 0x58, 0x53, 0x5e, 0x50, 0x4e, 
	0x5e, 0x5d, 0x4d, 0x50, 0x54, 0x5e, 0x5e, 0x53, 
	0x44, 0x5d, 0x5f, 0x60, 0x64, 0x3f, 0x32, 0x5f, 
	0x68, 0x2d, 0x3c, 0x69, 0x65, 0x64, 0x56, 0x3c, 
	0x48, 0x3f, 0x3d, 0x34, 0x33, 0x2e, 0x4b, 0x4a, 
	0x4a, 0x4b, 0x4c, 0x47, 0x4d, 0x5f, 0x53, 0x4f, 
	0x54, 0x56, 0x5d, 0x5c, 0x5c, 0x3b, 0x2f, 0x6f, 
	0x66, 0x30, 0x40, 0x72, 0x69, 0x67, 0x63, 0x58, 
	0x5d, 0x59, 0x56, 0x4e, 0x4a, 0x4d, 0x4d, 0x54, 
	0x4d, 0x4f, 0x32, 0x3b, 0x43, 0x52, 0x51, 0x49, 
	0x3c, 0x55, 0x5d, 0x62, 0x64, 0x40, 0x36, 0x5d, 
	0x68, 0x2d, 0x3c, 0x6a, 0x65, 0x63, 0x5b, 0x54, 
	0x62, 0x5c, 0x55, 0x53, 0x50, 0x4e, 0x50, 0x4a, 
	0x46, 0x47, 0x30, 0x39, 0x39, 0x3f, 0x41, 0x44, 
	0x3e, 0x50, 0x5a, 0x5c, 0x62, 0x3f, 0x35, 0x68, 
	0x57, 0x32, 0x3f, 0x6e, 0x65, 0x69, 0x58, 0x44, 
	0x47, 0x42, 0x40, 0x40, 0x41, 0x36, 0x48, 0x4d, 
	0x53, 0x51, 0x4b, 0x5a, 0x55, 0x64, 0x60, 0x62, 
	0x62, 0x61, 0x69, 0x6b, 0x64, 0x41, 0x37, 0x6a, 
	0x68, 0x2d, 0x3a, 0x63, 0x65, 0x62, 0x64, 0x6a, 
	0x70, 0x69, 0x64, 0x65, 0x66, 0x5c, 0x4b, 0x4a, 
	0x5c, 0x56, 0x41, 0x4a, 0x4d, 0x55, 0x56, 0x53, 
	0x42, 0x51, 0x5d, 0x5d, 0x63, 0x44, 0x38, 0x6b, 
	0x61, 0x31, 0x3f, 0x6b, 0x69, 0x6a, 0x53, 0x46, 
	0x53, 0x58, 0x55, 0x52, 0x52, 0x46, 0x5f, 0x5e, 
	0x50, 0x51, 0x63, 0x6c, 0x5f, 0x70, 0x6d, 0x72, 
	0x77, 0x71, 0x6c, 0x75, 0x66, 0x40, 0x37, 0x6a, 
	0x68, 0x2d, 0x39, 0x60, 0x66, 0x62, 0x64, 0x69, 
	0x64, 0x69, 0x70, 0x67, 0x60, 0x4d, 0x49, 0x49, 
	0x6d, 0x61, 0x4e, 0x57, 0x59, 0x5d, 0x5f, 0x54, 
	0x39, 0x57, 0x60, 0x64, 0x64, 0x42, 0x41, 0x78, 
	0x6e, 0x30, 0x3f, 0x6c, 0x68, 0x67, 0x58, 0x3a, 
	0x52, 0x60, 0x60, 0x5d, 0x5b, 0x51, 0x70, 0x70, 
	0x4f, 0x51, 0x6e, 0x6b, 0x5d, 0x6d, 0x6d, 0x65, 
	0x6b, 0x72, 0x69, 0x69, 0x6b, 0x42, 0x37, 0x66, 
	0x6c, 0x2d, 0x3c, 0x6f, 0x67, 0x65, 0x63, 0x64, 
	0x63, 0x6d, 0x74, 0x67, 0x56, 0x4e, 0x44, 0x42, 
	0x5a, 0x59, 0x42, 0x4a, 0x4a, 0x51, 0x5b, 0x4f, 
	0x2f, 0x55, 0x5b, 0x65, 0x64, 0x41, 0x4e, 0x6b, 
	0x60, 0x31, 0x3f, 0x69, 0x59, 0x61, 0x5e, 0x31, 
	0x4c, 0x5d, 0x55, 0x50, 0x50, 0x44, 0x65, 0x61, 
	0x47, 0x4c, 0x74, 0x6e, 0x61, 0x65, 0x6b, 0x64, 
	0x69, 0x6c, 0x78, 0x74, 0x76, 0x49, 0x33, 0x73, 
	0x6a, 0x31, 0x43, 0x67, 0x5e, 0x5d, 0x59, 0x58, 
	0x5a, 0x54, 0x63, 0x5c, 0x62, 0x5e, 0x3e, 0x38, 
	0x55, 0x54, 0x49, 0x48, 0x3d, 0x4a, 0x5e, 0x52, 
	0x38, 0x52, 0x5f, 0x5c, 0x63, 0x40, 0x46, 0x43, 
	0x3a, 0x31, 0x3e, 0x68, 0x5c, 0x62, 0x5d, 0x37, 
	0x51, 0x60, 0x47, 0x3f, 0x49, 0x43, 0x54, 0x61, 
	0x39, 0x42, 0x6c, 0x6a, 0x6b, 0x5b, 0x5c, 0x62, 
	0x62, 0x55, 0x6b, 0x79, 0x6a, 0x4c, 0x2e, 0x6f, 
	0x61, 0x33, 0x4b, 0x45, 0x46, 0x45, 0x45, 0x4c, 
	0x47, 0x34, 0x6a, 0x5f, 0x62, 0x6a, 0x40, 0x39, 
	0x61, 0x61, 0x63, 0x67, 0x5e, 0x63, 0x70, 0x64, 
	0x4b, 0x66, 0x6f, 0x64, 0x63, 0x51, 0x4c, 0x4c, 
	0x49, 0x4a, 0x50, 0x66, 0x5f, 0x69, 0x60, 0x48, 
	0x5e, 0x68, 0x54, 0x56, 0x5e, 0x5e, 0x5c, 0x72, 
	0x39, 0x3c, 0x5b, 0x5c, 0x6b, 0x57, 0x40, 0x4c, 
	0x4a, 0x41, 0x3e, 0x3c, 0x42, 0x47, 0x2e, 0x70, 
	0x6d, 0x2d, 0x43, 0x42, 0x42, 0x42, 0x43, 0x4c, 
	0x51, 0x3f, 0x69, 0x69, 0x5a, 0x5b, 0x3e, 0x39, 
	0x5a, 0x5a, 0x5d, 0x63, 0x5f, 0x5d, 0x6d, 0x60, 
	0x49, 0x62, 0x66, 0x5e, 0x5a, 0x64, 0x66, 0x68, 
	0x68, 0x66, 0x65, 0x61, 0x5f, 0x6a, 0x5f, 0x47, 
	0x5c, 0x61, 0x52, 0x54, 0x55, 0x5b, 0x5c, 0x6a, 
	0x3b, 0x3e, 0x60, 0x63, 0x73, 0x5a, 0x48, 0x55, 
	0x4a, 0x41, 0x43, 0x44, 0x41, 0x41, 0x2b, 0x6a, 
	0x5b, 0x49, 0x3f, 0x44, 0x4e, 0x44, 0x4d, 0x56, 
	0x50, 0x41, 0x6c, 0x74, 0x66, 0x6e, 0x47, 0x40, 
	0x3a, 0x3c, 0x3d, 0x31, 0x33, 0x37, 0x48, 0x44, 
	0x2e, 0x54, 0x64, 0x57, 0x63, 0x5c, 0x57, 0x58, 
	0x55, 0x54, 0x55, 0x55, 0x5d, 0x69, 0x5b, 0x2e, 
	0x42, 0x47, 0x3a, 0x34, 0x32, 0x44, 0x43, 0x3b, 
	0x43, 0x42, 0x69, 0x6b, 0x78, 0x61, 0x45, 0x4f, 
	0x57, 0x54, 0x50, 0x4b, 0x43, 0x40, 0x41, 0x55, 
	0x69, 0x79, 0x6a, 0x6d, 0x80, 0x69, 0x79, 0x6c, 
	0x4a, 0x45, 0x76, 0x64, 0x66, 0x81, 0x52, 0x47, 
	0x50, 0x50, 0x50, 0x47, 0x4a, 0x4c, 0x59, 0x51, 
	0x39, 0x52, 0x60, 0x5d, 0x62, 0x67, 0x59, 0x5a, 
	0x59, 0x58, 0x57, 0x55, 0x56, 0x6e, 0x5c, 0x33, 
	0x4a, 0x54, 0x48, 0x45, 0x45, 0x54, 0x55, 0x52, 
	0x51, 0x5a, 0x66, 0x61, 0x62, 0x5d, 0x42, 0x3c, 
	0x70, 0x7c, 0x72, 0x5c, 0x61, 0x6e, 0x6a, 0x5a, 
	0x7a, 0x5e, 0x72, 0x63, 0x74, 0x69, 0x7f, 0x67, 
	0x3e, 0x3e, 0x61, 0x71, 0x71, 0x6a, 0x72, 0x67, 
	0x79, 0x78, 0x76, 0x6e, 0x6e, 0x71, 0x7b, 0x5d, 
	0x30, 0x5b, 0x66, 0x55, 0x5c, 0x5f, 0x53, 0x53, 
	0x58, 0x57, 0x56, 0x53, 0x51, 0x6b, 0x5f, 0x33, 
	0x5a, 0x73, 0x68, 0x65, 0x62, 0x74, 0x74, 0x76, 
	0x76, 0x89, 0x60, 0x62, 0x6b, 0x70, 0x3d, 0x40, 
	0x60, 0x70, 0x6b, 0x56, 0x48, 0x73, 0x61, 0x79, 
	0x79, 0x33, 0x3a, 0x3a, 0x36, 0x4a, 0x69, 0x57, 
	0x4e, 0x48, 0x62, 0x7f, 0x83, 0x6d, 0x83, 0x75, 
	0x76, 0x74, 0x72, 0x5c, 0x5f, 0x67, 0x78, 0x59, 
	0x2e, 0x46, 0x56, 0x42, 0x45, 0x3d, 0x39, 0x37, 
	0x31, 0x35, 0x38, 0x3a, 0x3a, 0x54, 0x60, 0x2c, 
	0x64, 0x84, 0x6d, 0x69, 0x53, 0x70, 0x63, 0x6f, 
	0x74, 0x5f, 0x62, 0x62, 0x6a, 0x70, 0x3d, 0x3b, 
	0x74, 0x80, 0x4a, 0x37, 0x3e, 0x36, 0x34, 0x67, 
	0x78, 0x3a, 0x51, 0x53, 0x4c, 0x4e, 0x6d, 0x57, 
	0x4d, 0x45, 0x78, 0x76, 0x6a, 0x6f, 0x82, 0x67, 
	0x76, 0x65, 0x63, 0x66, 0x74, 0x6b, 0x66, 0x57, 
	0x2b, 0x53, 0x62, 0x49, 0x44, 0x45, 0x42, 0x40, 
	0x3a, 0x3d, 0x40, 0x41, 0x45, 0x5e, 0x52, 0x2e, 
	0x69, 0x75, 0x66, 0x68, 0x6e, 0x74, 0x75, 0x4b, 
	0x74, 0x63, 0x62, 0x60, 0x6a, 0x6e, 0x3c, 0x3c, 
	0x72, 0x7f, 0x49, 0x4c, 0x53, 0x41, 0x36, 0x7a, 
	0x72, 0x45, 0x4b, 0x5c, 0x45, 0x60, 0x7b, 0x51, 
	0x42, 0x4d, 0x6f, 0x83, 0x6d, 0x81, 0x68, 0x8c, 
	0x70, 0x8a, 0x6e, 0x72, 0x6d, 0x63, 0x70, 0x56, 
	0x3b, 0x69, 0x79, 0x5d, 0x5f, 0x63, 0x60, 0x64, 
	0x5e, 0x5b, 0x5b, 0x58, 0x5c, 0x7b, 0x6f, 0x2b, 
	0x6b, 0x77, 0x6c, 0x5c, 0x7d, 0x68, 0x65, 0x52, 
	0x66, 0x63, 0x61, 0x4f, 0x66, 0x5c, 0x40, 0x42, 
	0x66, 0x75, 0x46, 0x47, 0x4e, 0x4e, 0x32, 0x6a, 
	0x5c, 0x31, 0x48, 0x47, 0x40, 0x51, 0x86, 0x65, 
	0x40, 0x51, 0x3e, 0x33, 0x36, 0x34, 0x36, 0x36, 
	0x39, 0x38, 0x3a, 0x45, 0x77, 0x73, 0x72, 0x58, 
	0x38, 0x67, 0x7a, 0x5a, 0x58, 0x5c, 0x58, 0x5a, 
	0x60, 0x5c, 0x5b, 0x57, 0x5a, 0x77, 0x5c, 0x2f, 
	0x6b, 0x79, 0x6f, 0x73, 0x4d, 0x3e, 0x3d, 0x3d, 
	0x3a, 0x37, 0x37, 0x39, 0x37, 0x38, 0x38, 0x34, 
	0x54, 0x6a, 0x47, 0x45, 0x4e, 0x36, 0x2d, 0x83, 
	0x5e, 0x34, 0x36, 0x35, 0x2c, 0x57, 0x7b, 0x52, 
	0x39, 0x3c, 0x3b, 0x3d, 0x3d, 0x3b, 0x3d, 0x3d, 
	0x3e, 0x3f, 0x3c, 0x47, 0x78, 0x73, 0x6e, 0x52, 
	0x2e, 0x62, 0x76, 0x51, 0x4e, 0x50, 0x47, 0x45, 
	0x42, 0x46, 0x4b, 0x49, 0x4e, 0x72, 0x55, 0x2a, 
	0x54, 0x69, 0x83, 0x69, 0x46, 0x3f, 0x41, 0x40, 
	0x3f, 0x3b, 0x3c, 0x3b, 0x3c, 0x3d, 0x3d, 0x38, 
	0x56, 0x6c, 0x4b, 0x35, 0x37, 0x36, 0x33, 0x69, 
	0x74, 0x74, 0x74, 0x71, 0x6c, 0x84, 0x76, 0x71, 
	0x83, 0x83, 0x6e, 0x82, 0x8b, 0x70, 0x88, 0x5b, 
	0x78, 0x74, 0x35, 0x47, 0x76, 0x68, 0x75, 0x55, 
	0x2f, 0x68, 0x81, 0x58, 0x56, 0x5b, 0x53, 0x56, 
	0x61, 0x58, 0x58, 0x53, 0x56, 0x7e, 0x5c, 0x2a, 
	0x59, 0x70, 0x85, 0x6a, 0x45, 0x35, 0x82, 0x87, 
	0x86, 0x69, 0x7d, 0x6a, 0x82, 0x88, 0x88, 0x7c, 
	0x66, 0x78, 0x82, 0x81, 0x85, 0x6d, 0x68, 0x84, 
	
};

Vtx fwoosh_step_button_StepButton_mesh_layer_1_vtx_cull[8] = {
	{{{-200, 0, 200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-200, 20, 200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-200, 20, -200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-200, 0, -200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{200, 0, 200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{200, 20, 200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{200, 20, -200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{200, 0, -200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx fwoosh_step_button_StepButton_mesh_layer_1_vtx_0[12] = {
	{{{150, 0, -150},0, {1776, 10},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, 0, -150},0, {240, 10},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, 20, -150},0, {240, 240},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{150, 20, -150},0, {1776, 240},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, 20, 150},0, {240, 1776},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, 0, -150},0, {10, 240},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, 0, 150},0, {10, 1776},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{150, 20, 150},0, {1776, 1776},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-150, 0, 150},0, {240, 2006},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{150, 0, 150},0, {1776, 2006},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{150, 0, 150},0, {2006, 1776},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{150, 0, -150},0, {2006, 240},{0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx fwoosh_step_button_StepButton_mesh_layer_1_tri_0[] = {
	gsSPVertex(fwoosh_step_button_StepButton_mesh_layer_1_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 3, 2, 0, 5, 4, 2, 0),
	gsSP2Triangles(5, 6, 4, 0, 4, 7, 3, 0),
	gsSP2Triangles(8, 7, 4, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 3, 7, 0, 10, 11, 3, 0),
	gsSPEndDisplayList(),
};

Vtx fwoosh_step_button_StepButton_mesh_layer_2_vtx_cull[8] = {
	{{{-200, 0, 200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-200, 20, 200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-200, 20, -200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{-200, 0, -200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{200, 0, 200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{200, 20, 200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{200, 20, -200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
	{{{200, 0, -200},0, {-16, -16},{0x0, 0x0, 0x0, 0x0}}},
};

Vtx fwoosh_step_button_StepButton_mesh_layer_2_vtx_0[8] = {
	{{{-150, 0, 150},0, {240, 1776},{0xC3, 0xC3, 0xC3, 0xFF}}},
	{{{-150, 0, -150},0, {240, 240},{0xC3, 0xC3, 0xC3, 0xFF}}},
	{{{-200, 0, -200},0, {-16, -16},{0xC3, 0xC3, 0xC3, 0xFF}}},
	{{{200, 0, -200},0, {2032, -16},{0xC3, 0xC3, 0xC3, 0xFF}}},
	{{{150, 0, -150},0, {1776, 240},{0xC3, 0xC3, 0xC3, 0xFF}}},
	{{{200, 0, 200},0, {2032, 2032},{0xC3, 0xC3, 0xC3, 0xFF}}},
	{{{150, 0, 150},0, {1776, 1776},{0xC3, 0xC3, 0xC3, 0xFF}}},
	{{{-200, 0, 200},0, {-16, 2032},{0xC3, 0xC3, 0xC3, 0xFF}}},
};

Gfx fwoosh_step_button_StepButton_mesh_layer_2_tri_0[] = {
	gsSPVertex(fwoosh_step_button_StepButton_mesh_layer_2_vtx_0 + 0, 8, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 6, 7, 5, 0),
	gsSP2Triangles(6, 0, 7, 0, 0, 2, 7, 0),
	gsSPEndDisplayList(),
};


Gfx mat_fwoosh_step_button_Metal_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 1, fwoosh_step_button_i8_metal_pattern2_i8),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPSetLights1(fwoosh_step_button_Metal_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_fwoosh_step_button_Metal_001[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx mat_fwoosh_step_button_MetalDecal[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 1, fwoosh_step_button_i8_metal_pattern2_i8),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPSetLights1(fwoosh_step_button_MetalDecal_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_fwoosh_step_button_MetalDecal[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPEndDisplayList(),
};

Gfx fwoosh_step_button_StepButton_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(fwoosh_step_button_StepButton_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_fwoosh_step_button_Metal_001),
	gsSPDisplayList(fwoosh_step_button_StepButton_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_fwoosh_step_button_Metal_001),
	gsSPEndDisplayList(),
};

Gfx fwoosh_step_button_StepButton_mesh_layer_2[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(fwoosh_step_button_StepButton_mesh_layer_2_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_fwoosh_step_button_MetalDecal),
	gsSPDisplayList(fwoosh_step_button_StepButton_mesh_layer_2_tri_0),
	gsSPDisplayList(mat_revert_fwoosh_step_button_MetalDecal),
	gsSPEndDisplayList(),
};

Gfx fwoosh_step_button_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

