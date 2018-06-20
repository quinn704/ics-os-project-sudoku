
//	-- Constants
#define BOARD_SIZE 9
const int EASY_BOARD[81] = {1,2,3,4,5,6,7,8,9,4,5,6,7,8,9,1,2,3,7,8,9,1,2,3,4,5,6,2,3,4,5,6,7,8,9,1,5,6,7,8,9,1,2,3,4,8,9,1,2,3,4,5,6,7,3,4,5,6,7,8,9,1,2,6,7,8,9,1,2,3,4,5,9,1,2,3,4,5,6,7,0};
const int AVERAGE_BOARD[81] = {0,0,0,6,7,8,0,5,0,0,0,0,0,0,1,0,0,7,8,0,0,3,9,4,0,2,0,0,0,0,0,4,7,2,0,9,0,0,0,0,0,0,3,1,0,9,0,1,0,3,6,0,0,5,0,1,0,2,0,9,7,0,0,7,0,3,4,0,0,0,0,0,0,0,9,0,0,0,0,8,1};
const int DIFFICULT_BOARD[81] = {0,0,0,4,0,0,8,9,0,0,0,5,0,0,8,0,7,0,9,4,0,3,0,0,0,2,0,0,0,0,0,0,0,0,8,2,0,0,0,2,0,0,0,0,0,5,3,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,5,4,0,6,0,0,0,1,8,1,9,0,0,5,0,0,0};
const int INSANE_BOARD[81] = {8,0,0,0,0,0,0,7,0,0,6,0,0,0,0,5,0,1,0,0,0,3,1,9,6,0,0,0,0,0,0,0,0,0,0,4,0,9,8,0,0,1,0,0,0,4,0,0,2,9,5,0,0,0,0,0,1,6,0,8,0,5,0,0,3,2,0,0,0,0,8,0,6,0,9,0,0,3,0,0,0};

//	-- Imports
#include "design.h"

//	-- Functions

/*************************************************************************
* This functions serves as the add / rename function to modify the board *
*************************************************************************/
void add_number(int **board, int **validityBoard) {

	int row, col, value;
	printf("Specify row: "); scanf("%d", &row); row--;
	printf("Specify column: "); scanf("%d", &col); col--;
	printf("Specify value: "); scanf("%d", &value);
	if (validityBoard[row][col] == 0) board[row][col] = value;
}

/***************************************
* This function initializes the board. *
***************************************/
void create_board(int ***board, int difficultyLevel) {

	*board = (int **) malloc(sizeof(int *) * BOARD_SIZE);
	for (int i = 0; i < BOARD_SIZE; i++) {
		(*board)[i] = (int *) malloc (sizeof(int) * BOARD_SIZE);
	}
}

/***************************************
* This function initializes the board. *
***************************************/
void create_validity_board(int **board, int ***valids) {

	*valids = (int **) malloc(sizeof(int *) * BOARD_SIZE);
	for (int i = 0; i < BOARD_SIZE; i++) {
		(*valids)[i] = (int *) malloc (sizeof(int) * BOARD_SIZE);
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == 0) (*valids)[i][j] = 0;
			else (*valids)[i][j] = 1;
		}
	}
}

/*******************************************************************
* This functions serves as the delete function to modify the board *
*******************************************************************/
void delete_number(int **board, int **validityBoard) {

	int row, col, value;
	printf("Specify row: "); scanf("%d", &row);
	printf("Specify column: "); scanf("%d", &col);

	row--; col--;
	if (validityBoard[row][col] == 0) board[row][col] = 0;
}

/*******************************************************
* This function calls the print function of the board. *
*******************************************************/
void display_board(int **board) {
	print_board(board);
}

/*************************************************
* This function duplicates the board src to dest *
*************************************************/
void duplicate_array(const int src[81], int **dest) {
	
	for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
			(*dest)[i] = src[i];
	}
}

/********************************************
* This function initializes an empty board. *
********************************************/
void populate_board(int ***board, int difficultyLevel) {
	
	int DEFAULT_VALUE = 0;
	
	int *level = (int *) malloc (sizeof(int) * 81);
	switch(difficultyLevel) {
		case 1: duplicate_array(EASY_BOARD, &level); break;
		case 2: duplicate_array(AVERAGE_BOARD, &level); break;
		case 3: duplicate_array(DIFFICULT_BOARD, &level); break;
		case 4: duplicate_array(INSANE_BOARD, &level); break;
		default: break;
	}

	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			(*board)[i][j] = level[index];
			index++;
		}
	}

}

/********************************************************
* This functions resets the board to its original state *
********************************************************/
void reset_board(int **board, int **validityBoard) {

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (validityBoard[i][j] == 0)
				board[i][j] = 0;							
		}
	}
}