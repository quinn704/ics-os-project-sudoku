
//	-- Constants
#define BOARD "board.h"
#define CHECKER "checkers.h"

//	-- Imports
#include BOARD
#include CHECKER

//	-- Functions with Prototypes
	int is_running();
	int is_playing();
	int display_about();
	int new_game();
	int start_game();

/*************************************************************
* This function serves as the main menu in the main program. *
*************************************************************/
int is_running() {

	int choice; char temp;

	print_menu();
	if (scanf("%d%c", &choice, &temp) != 2 || temp != '\n') {
		print_error(INVALID_INPUT_ERROR); return 0;
	} return choice;
}

/********************************************************
* This function serves as the choose difficulty module. *
********************************************************/
int is_setting_up() {

	int choice; char temp;

	print_difficulty();
	if (scanf("%d%c", &choice, &temp) != 2 || temp != '\n') {
		print_error(INVALID_INPUT_ERROR); return 0;
	} return choice;
}

/****************************************************
* This function serves as the choose option module. *
****************************************************/
int is_playing(int **board, int difficulty) {

	int choice; char temp;

	display_board(board);
	print_controls(difficulty);
	if (scanf("%d%c", &choice, &temp) != 2 || temp != '\n') {
		print_error(INVALID_INPUT_ERROR); return -1;
	} return choice;
}


/*************************************************************
* This function reads and prints the about page from a file. *
*************************************************************/
int display_about() {

	FILE *file = fopen(ABOUT_PAGE, "r");
	const int SUCCESS = 0;

	if (file != NULL) {
		print_file(file);
		fclose(file);
		while (fgetc(stdin) != '\n');

	} else {
		print_error(FILE_NOT_FOUND);
		return 0;
	}

	return 1;
}

/**************************************************************
* This function creates the sub-menu for creating a new game. *
**************************************************************/
int create_new_game() {

	int choice, hasNoError = TRUE;
	int **board, **copy;

	while (choice = is_setting_up()) {

		switch(choice) {

			case 0:
				return 1;

			case 1: case 2: case 3: case 4:
				create_board(&board, choice);
				populate_board(&board, choice);
				create_validity_board(board, &copy);
				hasNoError = start_game(&board, &copy, choice);
				break;
	
			default: break;		
		}

		if (board == NULL) break;
		else if (hasNoError == FALSE) break;
	}

	return 1;
}

/*****************************************************************
* This function calls all necessary functions to start the game. *
*****************************************************************/
int start_game(int ***board, int ***validityBoard, int difficulty) {

	/* TODO: Fill validity board with 1s and 0s to determine which cells are immutable. */

	int choice; int isComplete = FALSE;
	while(choice = is_playing(*board, difficulty)) {
	
		switch(choice) {

			case -1: return 0;
			case 0: return 1;
			case 1: add_number(*board, *validityBoard); break;
			case 2: delete_number(*board, *validityBoard); break;
			case 3: reset_board(*board, *validityBoard); break;
			case 4: isComplete = submit_solution(*board); break;
			default: break;
		}

		if (isComplete == TRUE) {
			printf(" CONGRATULATIONS!\n");
			sleep(4);
			break;
		}
	}
	
}