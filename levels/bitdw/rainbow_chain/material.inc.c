Gfx* mat_rainbow_chain_f3d_material(Gfx* glistp) {
	gDPPipeSync(glistp++);
	gDPSetCombineLERP(glistp++, 1, TEXEL0, TEXEL1, TEXEL1, 0, 0, 0, 1, COMBINED, 0, TEXEL1, 0, 0, 0, 0, 1);
	gSPSetGeometryMode(glistp++, G_ZBUFFER | G_CULL_BACK | G_SHADING_SMOOTH);
	gSPClearGeometryMode(glistp++, G_SHADE | G_CULL_FRONT | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
	gSPSetOtherMode(glistp++, G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TL_TILE | G_TD_SHARPEN | G_TP_PERSP | G_CYC_2CYCLE | G_PM_1PRIMITIVE);
	gSPSetOtherMode(glistp++, G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_ZS_PIXEL | G_RM_PASS | G_RM_AA_ZB_OPA_SURF2);
	gSPTexture(glistp++, 65535, 65535, 0, 0, 1);
	gDPSetTextureLUT(glistp++, G_TT_NONE);
	gDPTileSync(glistp++);
	gDPSetTextureImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, segmented_to_virtual(rainbow_chain_Rainbow_small_rgba16));
	gDPSetTile(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 4, G_TX_WRAP | G_TX_NOMIRROR, 5, 0);
	gDPLoadSync(glistp++);
	gDPLoadBlock(glistp++, 7, 0, 0, 1023, 256);
	gDPPipeSync(glistp++);
	gDPSetTile(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 4, G_TX_WRAP | G_TX_NOMIRROR, 5, 0);
	gDPSetTileSize(glistp++, 0, 0, 0, 124, 124);
	gDPSetTextureLUT(glistp++, G_TT_NONE);
	gDPTileSync(glistp++);
	gDPSetTextureImage(glistp++, G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 1, segmented_to_virtual(rainbow_chain__3623064_32_grey_i8));
	gDPSetTile(glistp++, G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, 256, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0);
	gDPLoadSync(glistp++);
	gDPLoadBlock(glistp++, 6, 0, 0, 1023, 512);
	gDPPipeSync(glistp++);
	gDPSetTile(glistp++, G_IM_FMT_I, G_IM_SIZ_8b, 4, 256, 1, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0);
	gDPSetTileSize(glistp++, 1, 0, 0, 124, 252);
	return glistp;
}

Gfx* rainbow_chain_skinned_mesh(Gfx* glistp) {
	glistp = mat_rainbow_chain_f3d_material(glistp);
	gSPDisplayList(glistp++, segmented_to_virtual(rainbow_chain_skinned_mesh_tri_0));
	gDPPipeSync(glistp++);
	gSPSetGeometryMode(glistp++, G_LIGHTING);
	gSPClearGeometryMode(glistp++, G_TEXTURE_GEN);
	gDPSetCombineLERP(glistp++, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT);
	gSPTexture(glistp++, 65535, 65535, 0, 0, 0);
	return glistp;
}

