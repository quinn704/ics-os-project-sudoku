//	-- Constants
#define TRUE 1
#define FALSE 0
#define MAIN_FUNCTIONS "main.h"

//	-- Imports
#include <stdio.h>
#include MAIN_FUNCTIONS

//	-- Main Program

int main() {

	int choice, hasNoError = TRUE;

	print_execute(); // notes: uncomment this after the program is to be deployed
	while(choice = is_running()) {

		switch (choice) {

			case 1: hasNoError = create_new_game(); break;
			case 3: hasNoError = display_about(); break;
			default: break;
		}

		if (hasNoError == FALSE) break;
	}
	
	print_terminate(); // notes: uncomment this after the program is to be deployed
	return 0;

}