const Collision cloud_rainbow_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(203, 0, 0),
	COL_VERTEX(-203, 0, 0),
	COL_VERTEX(-203, 0, 10),
	COL_VERTEX(203, 0, 10),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
