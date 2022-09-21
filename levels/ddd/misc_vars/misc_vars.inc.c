#include "types.h"

f32 cozies_waterlevel0[3] = {   800.0000000000f, -9150.0000000000f, -2200.0011444092f };

f32 cozies_waterlevel1[3] = {  -200.0000000000f, -6000.0000000000f, -1900.0007629395f };

f32 cozies_waterlevel2[3] = { -3119.6420669556f, -4600.0000000000f, -4839.9833679199f };

f32 cozies_waterlevel3[3] = {    -0.0001907349f,  1353.5919189453f,    -0.0000000048f };

CozyVol cozies_area2CamVol1 = {
    {   200.0000000000f, -7369.9996948242f,   199.9991178513f },
    { 0x0000, -0x8000, 0x0000 },
    {   923.4001159668f,   944.0000534058f,   551.9999980927f },
    .param.dist = 1500,
    .type = COZY_VOL_MATCH_ROT,
    .shape = COZY_VOL_SHAPE_BOX,
};

CozyVol cozies_area2CamVol2 = {
    { -3100.0000000000f, -5340.9118652344f, -1300.0006675720f },
    { 0x0000, 0x0000, 0x0000 },
    {   225.0000000000f,  1076.2161254883f,   225.0000000000f },
    .param.dist = 1500,
    .type = COZY_VOL_MATCH_ROT,
    .shape = COZY_VOL_SHAPE_BOX,
};

CozyVol cozies_area2CamVol3 = {
    { -3100.0000000000f, -3780.0003051758f, -1300.0004768372f },
    { 0x0000, 0x2000, 0x0000 },
    {   141.7499661446f,   322.8648424149f,   141.7499661446f },
    .param.dist = 1500,
    .type = COZY_VOL_MATCH_ROT,
    .shape = COZY_VOL_SHAPE_BOX,
};

f32 coziesVol4Target[3] = { -3900.0000000000f, -4700.0000000000f, -2503.7506103516f };

CozyVol cozies_area2CamVol4 = {
    { -3500.0000000000f, -4730.0003051758f, -3150.0005722046f },
    { 0x0000, 0x0000, 0x0000 },
    {   740.9999847412f,   240.0000095367f,   640.1795864105f },
    .param.secondTarget = &coziesVol4Target,
    .type = COZY_VOL_SECOND_TARGET,
    .shape = COZY_VOL_SHAPE_BOX,
};

f32 coziesVol5Target[3] = { -3900.0000000000f, -5300.0000000000f, -1960.0006103516f };

PosFocusFov coziesVol5PosFocus = {
    { -3900.0000000000f, -4619.9996948242f, -2650.0005722046f },
    .focus = &coziesVol5Target,
    .fov = 90.0f,
};

CozyVol cozies_area2CamVol5 = {
    { -3900.0000000000f, -5000.0000000000f, -2230.0006866455f },
    { 0x0000, 0x0000, 0x0000 },
    {   259.3499898911f,   528.0000209808f,   309.8469257355f },
    .param.posFocus = &coziesVol5PosFocus,
    .type = COZY_VOL_FOCUS_POS_HINT,
    .shape = COZY_VOL_SHAPE_BOX,
};

f32 coziesVol6Focus[3] = {   700.0000000000f, -3200.0000000000f, -6300.0003814697f };

PosFocusFov coziesVol6PosFocus = {
    { -1100.0000000000f, -3900.0000000000f, -6300.0003814697f },
    .focus = &coziesVol6Focus,
    .fov = 70.0f,
};

CozyVol cozies_area2CamVol6 = {
    {  -600.0000000000f, -3207.3135375977f, -6300.0003814697f },
    { 0x0000, 0x0000, 0x0000 },
    {  1537.1780395508f,   903.8560867310f,   309.8469257355f },
    .param.spline = &ddd_area_2_spline_FunnyCameraPath,
    .type = COZY_VOL_HALLWAY_SPLINE,
    .shape = COZY_VOL_SHAPE_BOX,
};

CozyVol cozies_area2CamVol7 = {
    {  6535.9199523926f, -4900.0000000000f,  2512.2196197510f },
    { 0x0000, 0x32d8, 0x0000 },
    {  4980.4573059082f,  3416.3730621338f,   388.5479927063f },
    .param.spline = &ddd_area_2_spline_FunnyCameraPathDownTheTube,
    .type = COZY_VOL_HALLWAY_SPLINE,
    .shape = COZY_VOL_SHAPE_BOX,
};

CozyVol cozies_area2CamVol8 = {
    {  4400.0000000000f,  5199.9996185303f,  4385.5415344238f },
    { 0x0000, 0x0000, 0x0000 },
    {  3984.3658447266f,  1366.5491104126f,   815.9507751465f },
    .param.spline = &ddd_area_2_spline_FunnyCameraPathToTheWhirlpool,
    .type = COZY_VOL_HALLWAY_SPLINE,
    .shape = COZY_VOL_SHAPE_BOX,
};

CozyVol cozies_area2CamVol9 = {
    {     0.0000000000f,  5599.9996185303f,  2700.0007629395f },
    { 0x0000, 0x0000, 0x0000 },
    {   996.0912704468f,  1300.0668525696f,   884.6211433411f },
    .param.spline = &ddd_area_2_spline_FunnyCameraPathToTheWhirlpoolTWO,
    .type = COZY_VOL_HALLWAY_SPLINE,
    .shape = COZY_VOL_SHAPE_BOX,
};

CozyVol cozies_area2CamVol10 = {
    {     0.0000000000f,  5299.9996185303f,  4200.0007629395f },
    { 0x0000, 0x0000, 0x0000 },
    {   996.0912704468f,  1477.3486137390f,   707.6969146729f },
    .param.dist = 500,
    .type = COZY_VOL_MATCH_ROT,
    .shape = COZY_VOL_SHAPE_BOX,
};

f32 coziesVol11Target[3] = {     0.0003814697f, -1000.0015258789f,    -0.0010781599f };

CozyVol cozies_area2CamVol11 = {
    {     0.0003957190f, -1740.0016784668f,    -0.0010781599f },
    { 0x0000, 0x0000, 0x0000 },
    {  2080.0001144409f,   700.0000000000f,  2080.0001144409f },
    .param.secondTarget = &coziesVol11Target,
    .type = COZY_VOL_SECOND_TARGET_FULL,
    .shape = COZY_VOL_SHAPE_CYL,
};

CozyVol cozies_area2CamVol12 = {
    {     0.0003957190f,  4899.9984741211f,    -0.0010781599f },
    { 0x0000, 0x0000, 0x0000 },
    {   645.6322193146f,  6059.7198486328f,   645.6322193146f },
    .param.spline = &ddd_area_2_spline_FunnyCameraPathToTheTop,
    .type = COZY_VOL_HALLWAY_SPLINE,
    .shape = COZY_VOL_SHAPE_CYL,
};

f32 CamAct1Focus[3] = {  1300.0000000000f, -9000.0015258789f, -2000.0000000000f };

PosFocusFov CamAct1Pos = {
    {  -100.0000000000f, -9300.0015258789f, -4300.0000000000f },
    .focus = &CamAct1Focus,
    .fov = FOV_24MM,
};

f32 CamAct2Focus[3] = {  1400.0000000000f, -8400.0015258789f, -2200.0000000000f };

PosFocusFov CamAct2Pos = {
    {   400.0000000000f, -8700.0015258789f,  -300.0000000000f },
    .focus = &CamAct2Focus,
    .fov = FOV_24MM,
};

f32 CamAct3Focus[3] = { -5700.0000000000f, -3900.0015258789f, -1100.0000000000f };

PosFocusFov CamAct3Pos = {
    { -2000.0000000000f, -4050.0015258789f, -1900.0000000000f },
    .focus = &CamAct3Focus,
    .fov = FOV_75MM,
};

f32 CamAct4Focus[3] = {  4108.5796356201f,  -502.5939941406f, -6185.4450225830f };

PosFocusFov CamAct4Pos = {
    {  3379.9999237061f,  -900.0015258789f, -7019.9996948242f },
    .focus = &CamAct4Focus,
    .fov = FOV_24MM,
};

f32 CamAct5Focus[3] = {  7500.0000000000f,  2876.6632080078f, -1296.5400695801f };

PosFocusFov CamAct5Pos = {
    {  7500.0000000000f,  2789.9986267090f, -2839.9999618530f },
    .focus = &CamAct5Focus,
    .fov = FOV_18MM,
};

f32 CamAct6Focus[3] = {  -101.1964440346f,  3399.9984741211f, -1299.3271827698f };

PosFocusFov CamAct6Pos = {
    {   700.0000000000f,  4670.0298309326f, -2600.0000000000f },
    .focus = &CamAct6Focus,
    .fov = FOV_12MM,
};

