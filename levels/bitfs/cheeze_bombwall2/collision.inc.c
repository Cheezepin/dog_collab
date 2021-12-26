const Collision cheeze_bombwall2_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(484, 1250, -96),
	COL_VERTEX(484, 0, -96),
	COL_VERTEX(-484, 0, 96),
	COL_VERTEX(-484, 1250, 96),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
