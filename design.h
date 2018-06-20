
//	-- Constants: Printing
#define CLEAR_SCREEN "\e[1;1H\e[2J"
#define BASE_HORIZONTAL_DIVISOR " #######################################################\n"
#define BASE_VERTICAL_DIVISOR " #     |     |     #     |     |     #     |     |     #\n"
#define DIVISION "\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
#define HORIZONTAL_DIVISOR " #-----o-----o-----#-----o-----o-----#-----o-----o-----#\n"
#define NEW_LINE "\n"
#define SUBDIVISION_1 "\t\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
#define SUBDIVISION_2 " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
#define WAIT_INPUT "\t\t\t>> "

//	-- Constants: Error
#define INVALID_INPUT_ERROR 401
#define FILE_NOT_FOUND 501

//	-- Constants: Files
#define ABOUT_PAGE "./content/about.txt"

//	-- Imports
#include <stdlib.h>
#include <unistd.h>

//	-- Functions with Prototypes
	void print_error();
	void print_execute();
	void print_difficulty();
	void print_menu();
	void print_terminate();

void print_board_content(int a, int b, int c, int d, int e, int f, int g, int h, int i, char sector) {

	if (a == 0) a = ' '; else a = a + '0';
	if (b == 0) b = ' '; else b = b + '0';
	if (c == 0) c = ' '; else c = c + '0';
	if (d == 0) d = ' '; else d = d + '0';
	if (e == 0) e = ' '; else e = e + '0';
	if (f == 0) f = ' '; else f = f + '0';
	if (g == 0) g = ' '; else g = g + '0';
	if (h == 0) h = ' '; else h = h + '0';
	if (i == 0) i = ' '; else i = i + '0';
	
	printf(" #  %c  |  %c  |  %c  #  %c  |  %c  |  %c  #  %c  |  %c  |  %c  #  %c\n", a, b, c, d, e, f, g, h, i, sector);
}

/*******************************************************
* This function calls the print function of the board. *
*******************************************************/
void print_board(int **board) {
	printf(NEW_LINE);
	printf("    1     2     3     4     5     6     7     8     9\n");
	printf(BASE_HORIZONTAL_DIVISOR);
	printf(BASE_VERTICAL_DIVISOR);
	print_board_content(board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7], board[0][8], '1');
	printf(BASE_VERTICAL_DIVISOR);
	printf(HORIZONTAL_DIVISOR);
	printf(BASE_VERTICAL_DIVISOR);
	print_board_content(board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7], board[1][8], '2');
	printf(BASE_VERTICAL_DIVISOR);
	printf(HORIZONTAL_DIVISOR);
	printf(BASE_VERTICAL_DIVISOR);
	print_board_content(board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7], board[2][8], '3');
	printf(BASE_VERTICAL_DIVISOR);
	printf(BASE_HORIZONTAL_DIVISOR);
	printf(BASE_VERTICAL_DIVISOR);
	print_board_content(board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7], board[3][8], '4');
	printf(BASE_VERTICAL_DIVISOR);
	printf(HORIZONTAL_DIVISOR);
	printf(BASE_VERTICAL_DIVISOR);
	print_board_content(board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7], board[4][8], '5');
	printf(BASE_VERTICAL_DIVISOR);
	printf(HORIZONTAL_DIVISOR);
	printf(BASE_VERTICAL_DIVISOR);
	print_board_content(board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7], board[5][8], '6');
	printf(BASE_VERTICAL_DIVISOR);
	printf(BASE_HORIZONTAL_DIVISOR);
	printf(BASE_VERTICAL_DIVISOR);
	print_board_content(board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7], board[6][8], '7');
	printf(BASE_VERTICAL_DIVISOR);
	printf(HORIZONTAL_DIVISOR);
	printf(BASE_VERTICAL_DIVISOR);
	print_board_content(board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7], board[7][8], '8');
	printf(BASE_VERTICAL_DIVISOR);
	printf(HORIZONTAL_DIVISOR);
	printf(BASE_VERTICAL_DIVISOR);
	print_board_content(board[8][0], board[8][1], board[8][2], board[8][3], board[8][4], board[8][5], board[8][6], board[8][7], board[8][8], '9');
	printf(BASE_VERTICAL_DIVISOR);
	printf(BASE_HORIZONTAL_DIVISOR);
}

/*****************************************************************
* This function prints the controls of the game during the game. *
*****************************************************************/
void print_controls(int difficulty) {

	char *string;
	switch(difficulty) {
		case 1: string = "EASY"; break;
		case 2: string = "AVERAGE"; break;
		case 3: string = "DIFFICULT"; break;
		case 4: string = "INSANE"; break;
		default: break;
	}

	printf(NEW_LINE);
	printf("\t%s BOARD\n", string);
	printf(SUBDIVISION_2);
	printf(" [1] ADD/REPLACE NUMBER\n");
	printf(" [2] DELETE NUMBER\n");
	printf(" [3] RESET BOARD\n");
	printf(" [4] SUBMIT SOLUTION\n");
	printf(" [0] EXIT GAME\n");
	printf(SUBDIVISION_2);
	printf(WAIT_INPUT);
}

/************************************************************************
* This function reads and prints the contents from a file line by line. *
************************************************************************/
void print_file(FILE *file) {
	/* insert implementation here */
}

/****************************************************************************************
* This function prints all types of errors without any catch exceptions in the program. *
****************************************************************************************/
void print_error(int code) {

	char *description;
	switch (code) {

		case FILE_NOT_FOUND:
			description = "FILE NOT FOUND";
			break;

		case INVALID_INPUT_ERROR:
			description = "INVALID USER INPUT.";
			break;

		default: break;
	}

	printf(NEW_LINE);
	printf(" [ERROR %d] %s\n", code, description);
}

/***************************************************
* This function used at that start of the program. *
***************************************************/
void print_execute() {
	int seconds = 1; int offset = 2;
	printf("\n Reading libraries...\n");
	sleep(seconds);
	printf(" Installing packages...\n");
	sleep(seconds);
	printf(" Loading board configurations...\n");
	sleep(seconds);
	printf(" Please wait...\n");
	sleep(seconds); 
	printf(" Your program is about to start. Have fun!\n");
	sleep(seconds+offset);
}

/********************************************************************
* This function prints the 'Choose Difficulty' page of the program. *
********************************************************************/
void print_difficulty() {

	printf(CLEAR_SCREEN); printf(NEW_LINE);

	printf("\t\t\t─────────────────────────────▄██▄\n");
	printf("\t\t\t─── LABAN ISKO AT ISKA ──────▀███\n");
	printf("\t\t\t─── PATAPOS NA SEM!    ─────────█\n");
	printf("\t\t\t───────────────▄▄▄▄▄────────────█\n");
	printf("\t\t\t──────────────▀▄────▀▄──────────█\n");
	printf("\t\t\t──────────▄▀▀▀▄─█▄▄▄▄█▄▄─▄▀▀▀▄──█\n");
	printf("\t\t\t─────────█──▄──█────────█───▄─█─█\n");
	printf("\t\t\t─────────▀▄───▄▀────────▀▄───▄▀─█\n");
	printf("\t\t\t──────────█▀▀▀────────────▀▀▀─█─█\n");
	printf("\t\t\t──────────█───────────────────█─█\n");
	printf("\t\t\t▄▀▄▄▀▄────█──▄█▀█▀█▀█▀█▀█▄────█─█\n");
	printf("\t\t\t█▒▒▒▒█────█──█████████████▄───█─█\n");
	printf("\t\t\t█▒▒▒▒█────█──██████████████▄──█─█\n");
	printf("\t\t\t█▒▒▒▒█────█───██████████████▄─█─█\n");
	printf("\t\t\t█▒▒▒▒█────█────██████████████─█─█\n");
	printf("\t\t\t█▒▒▒▒█────█───██████████████▀─█─█\n");
	printf("\t\t\t█▒▒▒▒█───██───██████████████──█─█\n");
	printf("\t\t\t▀████▀──██▀█──█████████████▀──█▄█\n");
	printf("\t\t\t──██───██──▀█──█▄█▄█▄█▄█▄█▀──▄█▀\n");
	printf("\t\t\t──██──██────▀█─────────────▄▀▓█\n");
	printf("\t\t\t──██─██──────▀█▀▄▄▄▄▄▄▄▄▄▀▀▓▓▓█\n");
	printf("\t\t\t──████────────█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█\n");
	printf("\t\t\t──███─────────█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█\n");
	printf("\t\t\t──██──────────█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█\n");
	printf("\t\t\t──██──────────█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█\n");
	printf("\t\t\t──██─────────▐█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█\n");
	printf("\t\t\t──██────────▐█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█\n");
	printf("\t\t\t──██───────▐█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▌\n");
	printf("\t\t\t──██──────▐█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▌\n");
	printf("\t\t\t──██─────▐█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▌\n");
	printf("\t\t\t──██────▐█▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓█▌\n");

	printf(NEW_LINE); printf("\t\t\t\tCHOOSE DIFFICULTY:\n");

	printf(SUBDIVISION_1);
	printf("\t\t\t[1] NOOB (EASY)\n");
	printf("\t\t\t[2] HOMO SAPIENS (AVERAGE)\n");
	printf("\t\t\t[3] UP STUDENT (HARD)\n");
	printf("\t\t\t[4] CHALLENGE (INSANE)\n");
	printf("\t\t\t[0] GO BACK\n");

	printf(SUBDIVISION_1); printf(WAIT_INPUT);

}

/**********************************************************
* This function prints the 'landing page' of the program. *
**********************************************************/
void print_menu() {

	printf(CLEAR_SCREEN);
	for (int i = 0; i < 10; i++) printf(NEW_LINE);

	printf ("\t      ███████╗██╗   ██╗██████╗  ██████╗ ██╗  ██╗██╗   ██╗ \n");
	printf ("\t      ██╔════╝██║   ██║██╔══██╗██╔═══██╗██║ ██╔╝██║   ██║ \n");
	printf ("\t      ███████╗██║   ██║██║  ██║██║   ██ █████╔╝ ██║   ██║ \n");
	printf ("\t      ╚════██║██║   ██║██║  ██║██║   ██║██╔═██╗ ██║   ██║ \n");
	printf ("\t      ███████║╚██████╔╝██████╔╝╚██████╔╝██║  ██╗╚██████╔╝ \n");
	printf ("\t      ╚══════╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ ╚═════╝  \n");
	printf ("\t\t\t██████╗  ██████╗  ██╗ █████╗ \n");
	printf ("\t\t\t╚════██╗██╔═████╗███║██╔══██╗\n");
	printf ("\t\t\t █████╔╝██║██╔██║╚██║╚█████╔╝\n");
	printf ("\t\t\t██╔═══╝ ████╔╝██║ ██║██╔══██╗\n");
	printf ("\t\t\t███████╗╚██████╔╝ ██║╚█████╔╝\n");
	printf ("\t\t\t╚══════╝ ╚═════╝  ╚═╝ ╚════╝\n");

	printf(NEW_LINE); printf(DIVISION);
	printf("\t\t\t    [1] NEW GAME\n");
	printf("\t\t\t    [2] HOW TO PLAY\n");
	printf("\t\t\t    [3] ABOUT THE GAME\n");
	printf("\t\t\t    [0] EXIT\n");

	printf(DIVISION); printf(WAIT_INPUT);
}

/*************************************************
* This function used at that end of the program. *
*************************************************/
void print_terminate() {
	int seconds = 3;
	printf(" Program terminating...\n");
	sleep(seconds);
	printf(CLEAR_SCREEN);
	printf("\n PROGRAM TERMINATED.\n\n");
}