const Collision water_plane2_ctrl_room_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(6),
	COL_VERTEX(-167, 0, 900),
	COL_VERTEX(434, 0, 900),
	COL_VERTEX(434, 0, 0),
	COL_VERTEX(-966, 0, 0),
	COL_VERTEX(434, 0, -900),
	COL_VERTEX(-167, 0, -900),
	COL_TRI_INIT(SURFACE_NEW_WATER, 4),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(3, 2, 4),
	COL_TRI(3, 4, 5),
	COL_TRI_STOP(),
	COL_END()
};
