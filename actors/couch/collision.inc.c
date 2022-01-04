const Collision couch_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(64),
	COL_VERTEX(-106, 0, -241),
	COL_VERTEX(-106, 200, -241),
	COL_VERTEX(-106, 200, -311),
	COL_VERTEX(-106, 0, -311),
	COL_VERTEX(94, 0, -241),
	COL_VERTEX(94, 0, -311),
	COL_VERTEX(94, 170, -311),
	COL_VERTEX(94, 170, -241),
	COL_VERTEX(94, 62, -241),
	COL_VERTEX(-106, 0, 326),
	COL_VERTEX(94, 0, 326),
	COL_VERTEX(94, 170, 326),
	COL_VERTEX(90, 185, 326),
	COL_VERTEX(79, 196, 326),
	COL_VERTEX(64, 200, 326),
	COL_VERTEX(-106, 200, 326),
	COL_VERTEX(64, 200, -241),
	COL_VERTEX(64, 200, -311),
	COL_VERTEX(-51, 200, -241),
	COL_VERTEX(-106, 0, 255),
	COL_VERTEX(94, 0, 255),
	COL_VERTEX(94, 62, 255),
	COL_VERTEX(94, 170, 255),
	COL_VERTEX(79, 196, -311),
	COL_VERTEX(90, 185, -311),
	COL_VERTEX(94, 0, -170),
	COL_VERTEX(-106, 0, -170),
	COL_VERTEX(94, 0, -99),
	COL_VERTEX(-106, 0, -99),
	COL_VERTEX(94, 0, -28),
	COL_VERTEX(-106, 0, -28),
	COL_VERTEX(94, 0, 42),
	COL_VERTEX(-106, 0, 42),
	COL_VERTEX(94, 0, 113),
	COL_VERTEX(-106, 0, 113),
	COL_VERTEX(94, 0, 184),
	COL_VERTEX(-106, 0, 184),
	COL_VERTEX(-51, 62, -241),
	COL_VERTEX(90, 185, -241),
	COL_VERTEX(79, 196, -241),
	COL_VERTEX(94, 62, -170),
	COL_VERTEX(94, 62, -99),
	COL_VERTEX(94, 62, -28),
	COL_VERTEX(94, 62, 42),
	COL_VERTEX(94, 62, 113),
	COL_VERTEX(94, 62, 184),
	COL_VERTEX(-106, 200, 255),
	COL_VERTEX(-106, 200, 184),
	COL_VERTEX(-106, 200, 113),
	COL_VERTEX(-106, 200, 42),
	COL_VERTEX(-106, 200, -28),
	COL_VERTEX(-106, 200, -99),
	COL_VERTEX(-106, 200, -170),
	COL_VERTEX(-51, 200, 113),
	COL_VERTEX(-51, 200, 42),
	COL_VERTEX(-51, 200, -99),
	COL_VERTEX(-51, 200, -170),
	COL_VERTEX(-51, 200, 184),
	COL_VERTEX(-51, 200, -28),
	COL_VERTEX(-51, 200, 255),
	COL_VERTEX(-51, 62, 255),
	COL_VERTEX(64, 200, 255),
	COL_VERTEX(79, 196, 255),
	COL_VERTEX(90, 185, 255),
	COL_TRI_INIT(SURFACE_DEFAULT, 120),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(6, 7, 8),
	COL_TRI(6, 8, 4),
	COL_TRI(9, 10, 11),
	COL_TRI(11, 12, 13),
	COL_TRI(13, 14, 15),
	COL_TRI(15, 9, 11),
	COL_TRI(11, 13, 15),
	COL_TRI(16, 17, 2),
	COL_TRI(2, 1, 18),
	COL_TRI(2, 18, 16),
	COL_TRI(19, 20, 10),
	COL_TRI(19, 10, 9),
	COL_TRI(10, 20, 21),
	COL_TRI(21, 22, 11),
	COL_TRI(21, 11, 10),
	COL_TRI(5, 3, 2),
	COL_TRI(2, 17, 23),
	COL_TRI(23, 24, 6),
	COL_TRI(6, 5, 2),
	COL_TRI(2, 23, 6),
	COL_TRI(3, 5, 4),
	COL_TRI(3, 4, 0),
	COL_TRI(0, 4, 25),
	COL_TRI(0, 25, 26),
	COL_TRI(26, 25, 27),
	COL_TRI(26, 27, 28),
	COL_TRI(28, 27, 29),
	COL_TRI(28, 29, 30),
	COL_TRI(30, 29, 31),
	COL_TRI(30, 31, 32),
	COL_TRI(32, 31, 33),
	COL_TRI(32, 33, 34),
	COL_TRI(34, 33, 35),
	COL_TRI(34, 35, 36),
	COL_TRI(36, 35, 20),
	COL_TRI(36, 20, 19),
	COL_TRI(16, 18, 37),
	COL_TRI(37, 8, 7),
	COL_TRI(7, 38, 39),
	COL_TRI(39, 16, 37),
	COL_TRI(37, 7, 39),
	COL_TRI(4, 8, 40),
	COL_TRI(4, 40, 25),
	COL_TRI(25, 40, 41),
	COL_TRI(25, 41, 27),
	COL_TRI(27, 41, 42),
	COL_TRI(27, 42, 29),
	COL_TRI(29, 42, 43),
	COL_TRI(29, 43, 31),
	COL_TRI(31, 43, 44),
	COL_TRI(31, 44, 33),
	COL_TRI(33, 44, 45),
	COL_TRI(33, 45, 35),
	COL_TRI(35, 45, 21),
	COL_TRI(35, 21, 20),
	COL_TRI(9, 15, 46),
	COL_TRI(9, 46, 19),
	COL_TRI(19, 46, 47),
	COL_TRI(19, 47, 36),
	COL_TRI(36, 47, 48),
	COL_TRI(36, 48, 34),
	COL_TRI(34, 48, 49),
	COL_TRI(34, 49, 32),
	COL_TRI(32, 49, 50),
	COL_TRI(32, 50, 30),
	COL_TRI(30, 50, 51),
	COL_TRI(30, 51, 28),
	COL_TRI(28, 51, 52),
	COL_TRI(28, 52, 26),
	COL_TRI(26, 52, 1),
	COL_TRI(26, 1, 0),
	COL_TRI(53, 54, 49),
	COL_TRI(53, 49, 48),
	COL_TRI(55, 56, 52),
	COL_TRI(55, 52, 51),
	COL_TRI(57, 53, 48),
	COL_TRI(57, 48, 47),
	COL_TRI(58, 55, 51),
	COL_TRI(58, 51, 50),
	COL_TRI(59, 57, 47),
	COL_TRI(59, 47, 46),
	COL_TRI(54, 58, 50),
	COL_TRI(54, 50, 49),
	COL_TRI(56, 18, 1),
	COL_TRI(56, 1, 52),
	COL_TRI(57, 59, 60),
	COL_TRI(60, 37, 18),
	COL_TRI(60, 18, 56),
	COL_TRI(53, 57, 60),
	COL_TRI(54, 53, 60),
	COL_TRI(60, 56, 54),
	COL_TRI(21, 60, 59),
	COL_TRI(59, 61, 62),
	COL_TRI(62, 63, 22),
	COL_TRI(22, 21, 59),
	COL_TRI(59, 62, 22),
	COL_TRI(37, 60, 21),
	COL_TRI(37, 21, 45),
	COL_TRI(40, 8, 37),
	COL_TRI(41, 40, 37),
	COL_TRI(37, 45, 43),
	COL_TRI(43, 41, 37),
	COL_TRI(61, 14, 13),
	COL_TRI(61, 13, 62),
	COL_TRI(62, 13, 12),
	COL_TRI(62, 12, 63),
	COL_TRI(63, 12, 11),
	COL_TRI(63, 11, 22),
	COL_TRI(17, 16, 39),
	COL_TRI(17, 39, 23),
	COL_TRI(23, 39, 38),
	COL_TRI(23, 38, 24),
	COL_TRI(24, 38, 7),
	COL_TRI(24, 7, 6),
	COL_TRI(14, 61, 59),
	COL_TRI(59, 46, 15),
	COL_TRI(59, 15, 14),
	COL_TRI_STOP(),
	COL_END()
};
