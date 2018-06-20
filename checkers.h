
//	-- Constants

	//	Row - Groups
	const int ROW_1[9][2] = { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8} };
	const int ROW_2[9][2] = { {1,0}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {1,6}, {1,7}, {1,8} };
	const int ROW_3[9][2] = { {2,0}, {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, {2,6}, {2,7}, {2,8} };
	const int ROW_4[9][2] = { {3,0}, {3,1}, {3,2}, {3,3}, {3,4}, {3,5}, {3,6}, {3,7}, {3,8} };
	const int ROW_5[9][2] = { {4,0}, {4,1}, {4,2}, {4,3}, {4,4}, {4,5}, {4,6}, {4,7}, {4,8} };
	const int ROW_6[9][2] = { {5,0}, {5,1}, {5,2}, {5,3}, {5,4}, {5,5}, {5,6}, {5,7}, {5,8} };
	const int ROW_7[9][2] = { {6,0}, {6,1}, {6,2}, {6,3}, {6,4}, {6,5}, {6,6}, {6,7}, {6,8} };
	const int ROW_8[9][2] = { {7,0}, {7,1}, {7,2}, {7,3}, {7,4}, {7,5}, {7,6}, {7,7}, {7,8} };
	const int ROW_9[9][2] = { {8,0}, {8,1}, {8,2}, {8,3}, {8,4}, {8,5}, {8,6}, {8,7}, {8,8} };

	//	Columns - Groups
	const int COL_1[9][2] = { {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0} };
	const int COL_2[9][2] = { {0,1}, {1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1}, {7,1}, {8,1} };
	const int COL_3[9][2] = { {0,2}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}, {6,2}, {7,2}, {8,2} };
	const int COL_4[9][2] = { {0,3}, {1,3}, {2,3}, {3,3}, {4,3}, {5,3}, {6,3}, {7,3}, {8,3} };
	const int COL_5[9][2] = { {0,4}, {1,4}, {2,4}, {3,4}, {4,4}, {5,4}, {6,4}, {7,4}, {8,4} };
	const int COL_6[9][2] = { {0,5}, {1,5}, {2,5}, {3,5}, {4,5}, {5,5}, {6,5}, {7,5}, {8,5} };
	const int COL_7[9][2] = { {0,6}, {1,6}, {2,6}, {3,6}, {4,6}, {5,6}, {6,6}, {7,6}, {8,6} };
	const int COL_8[9][2] = { {0,7}, {1,7}, {2,7}, {3,7}, {4,7}, {5,7}, {6,7}, {7,7}, {8,7} };
	const int COL_9[9][2] = { {0,8}, {1,8}, {2,8}, {3,8}, {4,8}, {5,8}, {6,8}, {7,8}, {8,8} };

	//	Regions - Groups
	const int REG_A[9][2] = { {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2} };
	const int REG_B[9][2] = { {3,0}, {3,1}, {3,2}, {4,0}, {4,1}, {4,2}, {5,0}, {5,1}, {5,2} };
	const int REG_C[9][2] = { {6,0}, {6,1}, {6,2}, {7,0}, {7,1}, {7,2}, {8,0}, {8,1}, {8,2} };
	const int REG_D[9][2] = { {0,3}, {0,4}, {0,5}, {1,3}, {1,4}, {1,5}, {2,3}, {2,4}, {2,5} };
	const int REG_E[9][2] = { {3,3}, {3,4}, {3,5}, {4,3}, {4,4}, {4,5}, {5,3}, {5,4}, {5,5} };
	const int REG_F[9][2] = { {6,3}, {6,4}, {6,5}, {7,3}, {7,4}, {7,5}, {8,3}, {8,4}, {8,5} };
	const int REG_G[9][2] = { {0,6}, {0,7}, {0,8}, {1,6}, {1,7}, {1,8}, {2,6}, {2,7}, {2,8} };
	const int REG_H[9][2] = { {3,6}, {3,7}, {3,8}, {4,6}, {4,7}, {4,8}, {5,6}, {5,7}, {5,8} };
	const int REG_I[9][2] = { {6,6}, {6,7}, {6,8}, {7,6}, {7,7}, {7,8}, {8,6}, {8,7}, {8,8} };

//	-- Function Prototypes
	int check_row(int **, const int[9][2]);
	int check_rows(int **);
	int check_column(int **, const int[9][2]);
	int check_columns(int **);
	int check_region(int **, const int[9][2]);
	int check_regions(int **);
	int in_array(int *, int, int);

//	-- Functions

int check_rows(int **board) {
	if (check_row(board, ROW_1)) {
		if (check_row(board, ROW_2)) {
			if (check_row(board, ROW_3)) {
				if (check_row(board, ROW_4)) {
					if (check_row(board, ROW_5)) {
						if (check_row(board, ROW_6)) {
							if (check_row(board, ROW_7)) {
								if (check_row(board, ROW_8)) {
									if (check_row(board, ROW_9)) {
										return 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int check_row(int **board, const int row[9][2]) {

	int *explored = (int *) malloc (sizeof(int) * 9);
	int exploredCount = 0;

	for (int i = 0; i < 9; i++) {
		if (
			in_array(explored, exploredCount, board[row[i][0]][row[i][1]]) == 1
			|| board[row[i][0]][row[i][1]] == 0
		) {
			free(explored);
			return 0;
		} else {
			explored[exploredCount] = board[row[i][0]][row[i][1]];
			exploredCount++;
		}
	}

	free(explored);
	return 1;
}

int check_columns(int **board) {
	if (check_row(board, COL_1)) {
		if (check_row(board, COL_2)) {
			if (check_row(board, COL_3)) {
				if (check_row(board, COL_4)) {
					if (check_row(board, COL_5)) {
						if (check_row(board, COL_6)) {
							if (check_row(board, COL_7)) {
								if (check_row(board, COL_8)) {
									if (check_row(board, COL_9)) {
										return 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int check_column(int **board, const int column[9][2]) {

	int *explored = (int *) malloc (sizeof(int) * 9);
	int exploredCount = 0;

	for (int i = 0; i < 9; i++) {
		if (
			in_array(explored, exploredCount, board[column[i][0]][column[i][1]]) == 1
			|| board[column[i][0]][column[i][1]] == 0
		) {
			free(explored);
			return 0;
		} else {
			explored[exploredCount] = board[column[i][0]][column[i][1]];
			exploredCount++;
		}
	}

	free(explored);
	return 1;
}

int check_regions(int **board) {
	if (check_row(board, REG_A)) {
		if (check_row(board, REG_B)) {
			if (check_row(board, REG_C)) {
				if (check_row(board, REG_D)) {
					if (check_row(board, REG_E)) {
						if (check_row(board, REG_F)) {
							if (check_row(board, REG_G)) {
								if (check_row(board, REG_H)) {
									if (check_row(board, REG_I)) {
										return 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int check_region(int **board, const int region[9][2]) {

	int *explored = (int *) malloc (sizeof(int) * 9);
	int exploredCount = 0;

	for (int i = 0; i < 9; i++) {
		if (
			in_array(explored, exploredCount, board[region[i][0]][region[i][1]]) == 1
			|| board[region[i][0]][region[i][1]] == 0
		) {
			free(explored);
			return 0;
		} else {
			explored[exploredCount] = board[region[i][0]][region[i][1]];
			exploredCount++;
		}
	}

	free(explored);
	return 1;

}

int in_array(int *array, int arrayLength, int value) {

	for (int i = 0; i <arrayLength; i++) {
		if (value == array[i]) return 1;
	} return 0;
}

void convert_char_to_int_board(char **board, int **new_board) {

	new_board = (int **) malloc (sizeof(int *) * 9);
	for (int a = 0; a < 9; a++) { new_board[a] = (int *) malloc (sizeof(int) * 9); }
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			new_board[i][j] = board[i][j] - '0';
		}
	}
}

int submit_solution_char(char **board) {

	int **new_board;
	convert_char_to_int_board(board, new_board);

	if ( check_rows(new_board) ) {
		if ( check_columns(new_board) ) {
			if (check_regions(new_board)) {
				return 1;
			}
		}
	}

	return 0;
}

int submit_solution(int **board) {

	if ( check_rows(board) ) {
		if ( check_columns(board) ) {
			if (check_regions(board)) {
				return 1;
			}
		}
	}

	return 0;
}