const Collision sandpile_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(13),
	COL_VERTEX(0, 0, -227),
	COL_VERTEX(0, 37, -165),
	COL_VERTEX(143, 37, -83),
	COL_VERTEX(196, 0, -113),
	COL_VERTEX(196, 0, 113),
	COL_VERTEX(143, 37, 83),
	COL_VERTEX(0, 37, 165),
	COL_VERTEX(0, 0, 227),
	COL_VERTEX(-196, 0, 113),
	COL_VERTEX(-143, 37, 83),
	COL_VERTEX(-143, 37, -83),
	COL_VERTEX(-196, 0, -113),
	COL_VERTEX(0, 88, 0),
	COL_TRI_INIT(SURFACE_DEFAULT, 18),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(8, 9, 10),
	COL_TRI(8, 10, 11),
	COL_TRI(3, 2, 5),
	COL_TRI(3, 5, 4),
	COL_TRI(7, 6, 9),
	COL_TRI(7, 9, 8),
	COL_TRI(11, 10, 1),
	COL_TRI(11, 1, 0),
	COL_TRI(2, 12, 5),
	COL_TRI(6, 12, 9),
	COL_TRI(10, 12, 1),
	COL_TRI(1, 12, 2),
	COL_TRI(5, 12, 6),
	COL_TRI(9, 12, 10),
	COL_TRI_STOP(),
	COL_END()
};