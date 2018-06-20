

#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"
#include "./checkers.h"

void edit_board();
void erase();
void gray(int x, int y);
void light(int r, int c, int x, int y);
void print_board(int x, int y);
void print_bulb(int r, int c, int x, int y);
void set_coordinates(int x, int y);
void setup_level();

/* constants */
#define maxrow 9
#define maxcol 9
#define max_level 6
#define pause_length 25

#define on 1
#define son 2
#define off 3
#define soff 4
#define flip 'l'
#define up_key 'w'
#define down_key 's'
#define left_key 'a'
#define right_key 'd'
#define quit 'x'
#define reset 'r'
#define yes 'y'
#define no 'n'
#define start 's'
#define quit_game 'q'
#define one '1'
#define two '2'
#define three '3'
#define four '4'
#define five '5'
#define six '6'
#define seven '7'
#define eight '8'
#define nine '9'
#define SPACE 'p'

#define YELLOW 54
#define PALE_YELLOW 62
#define ROYAL_BLUE 1
#define DARK_BLUE 8
#define GRAY 56
#define WHITE 63
#define LIGHT_GREEN 30
#define PURPLE 40
#define SKY_BLUE 15
#define RED 4

#define X_coord 85
#define Y_coord 35

/* global variables */
int row, col, oldrow=0, oldcol=0;
int actions=0, remaining_bulb;
int level, count=0, hour=0, min=0;
int bulbs_x[maxrow][maxcol];
int bulbs_y[maxrow][maxcol];

// char easy_board[maxrow][maxcol] = {{6,1,0,9,7,0,4,0,0},{0,0,0,4,3,0,0,0,1},{0,0,4,0,0,0,0,0,9},{0,5,7,3,0,0,0,4,6},{0,0,1,0,0,6,8,2,0},{4,0,0,0,2,7,0,3,0},{8,0,0,7,0,9,5,0,0},{0,4,6,8,0,0,7,0,2},{0,0,0,2,0,0,6,8,3}};
char easy_board[maxrow][maxcol] = { {1,2,3,4,5,6,7,8,9} , {4,5,6,7,8,9,1,2,3}, {7,8,9,1,2,3,4,5,6} , {2,3,4,5,6,7,8,9,1} , {5,6,7,8,9,1,2,3,4} , {8,9,1,2,3,4,5,6,7} , {3,4,5,6,7,8,9,1,2}, {6,7,8,9,1,2,3,4,5} , {9,1,2,3,4,5,6,7,0}};
char board[maxrow][maxcol];
char game_board[maxrow][maxcol];


int main()
{
  
	char keypress = start;
	int i,j;
	char str[15];
	int champion = 0;

	set_graphics(VGA_320X200X256);
  	set_coordinates(X_coord, Y_coord); //initialize bulb coordinates

	do{
	erase(1,1,400,220);

  	header(8,5); //print menu

	level=1; //initialize level
	champion = 0; //falsify championhood
	
	keypress=(char)getch();
	erase(1,1,400,220); //erase menu

	if(keypress==start){
	do{

		if(keypress == start){
			setup_level(); 
			row=0;
			col=0;
			actions=0;

			//update level display
			erase(25,140,40,30);
			write_text("0",25,140,WHITE,0);

		}		
		else
			print_board(X_coord, Y_coord);

		do{

			if (keypress=(char)getch()){
			
				// update selected bulb
				if(keypress==right_key){
					oldrow = row;
					oldcol = col;
					col = (col + 1) % maxcol;
				}
				
				else if(keypress==left_key){
					oldrow = row;
					oldcol = col;
					if(col <= 0)
						col = maxcol - 1;
					else
						col--;
				}
				
				else if(keypress==up_key){
					oldrow = row;
					oldcol = col;
					if(row <= 0)
						row = maxrow - 1;
					else
						row--;
				}
				
				else if(keypress==down_key){
					oldrow = row;
					oldcol = col;
					row = (row + 1) % maxrow;
				}

				else if (keypress == one){
					if (board[row][col]!=son){
						actions++;
						erase(25,140,30,30);
						sprintf(str,"%d",actions);
						write_text(str,25,140,WHITE,0);
						game_board[row][col] = 1;
					}
					// write_text("1",85,35,DARK_BLUE,0);
				}
				else if (keypress == two){
					if (board[row][col]!=son){
						actions++;
						erase(25,140,30,30);
						sprintf(str,"%d",actions);
						write_text(str,25,140,WHITE,0);
						game_board[row][col] = 2;
					}				
				}
				else if (keypress == three){
					if (board[row][col]!=son){
						actions++;
						erase(25,140,30,30);
						sprintf(str,"%d",actions);
						write_text(str,25,140,WHITE,0);
						game_board[row][col] = 3;
					}				
				}
				else if (keypress == four){
					if (board[row][col]!=son){
						actions++;
						erase(25,140,30,30);
						sprintf(str,"%d",actions);
						write_text(str,25,140,WHITE,0);
						game_board[row][col] = 4;
					}				
				}
				else if (keypress == five){
					if (board[row][col]!=son){
						actions++;
						erase(25,140,30,30);
						sprintf(str,"%d",actions);
						write_text(str,25,140,WHITE,0);
						game_board[row][col] = 5;
					}				
				}
				else if (keypress == six){
					if (board[row][col]!=son){
						actions++;
						erase(25,140,30,30);
						sprintf(str,"%d",actions);
						write_text(str,25,140,WHITE,0);
						game_board[row][col] = 6;
					}				
				}
				else if (keypress == seven){
					if (board[row][col]!=son){
						actions++;
						erase(25,140,30,30);
						sprintf(str,"%d",actions);
						write_text(str,25,140,WHITE,0);
						game_board[row][col] = 7;
					}				
				}
				else if (keypress == eight){
					if (board[row][col]!=son){
						actions++;
						erase(25,140,30,30);
						sprintf(str,"%d",actions);
						write_text(str,25,140,WHITE,0);
						game_board[row][col] = 8;
					}				
				}
				else if (keypress == nine){
					if (board[row][col]!=son){
						actions++;
						erase(25,140,30,30);
						sprintf(str,"%d",actions);
						write_text(str,25,140,WHITE,0);
						game_board[row][col] = 9;
					}
				} else if(keypress == SPACE) {
					write_text("PUMASOK", 5, 160, WHITE, 0);
					if (submit_solution_char(game_board) == 1) {
						write_text("Congratulations!",89,160,YELLOW,0);
						write_text("You finished all levels.",65,170,YELLOW,0);
						write_text("(Press any key)",101, 180,YELLOW,0);
						erase(1,1,350,280); //clear screen
					}
				}

				if(remaining_bulb < 0){

					level++; //update level
					if(level==max_level){ //finished all puzzles

						write_text("Congratulations!",89,160,YELLOW,0);
						write_text("You finished all levels.",65,170,YELLOW,0);
						write_text("(Press any key)",101, 180,YELLOW,0);
						keypress=(char)getch();
						erase(1,1,350,280); //clear screen
						champion=1; //player is now champion

					}else{ //finished a puzzle
						write_text("Congratulations!",89,160,WHITE,0);
						write_text("Press any key",101, 170,WHITE,0);
						keypress=(char)getch();
						erase(80,160,150,40); //erase congratulations
						keypress = start;
					}
					break;
				}
				
				// update the display of the selected and previously selected
				if(keypress==right_key || keypress==left_key || keypress==up_key || keypress==down_key){
					board[row][col] = board[row][col] == on? son: soff;
					board[oldrow][oldcol] = board[oldrow][oldcol] == son? on: off;					
					edit_board();
				}
			}			
	      		
		} while (keypress != quit && keypress != reset && champion!=1);
			//continue while player is not quitting, restarting or champion

		if(champion==1){keypress = yes;}
		else if(keypress == quit){
			//prompt confirmation then erase message
			write_text("Do you want to exit? y/n ",60,160,RED,0); 
			keypress=(char)getch();
			erase(60,160,220,40);			
		}
		else if(keypress == reset){
			//prompt confirmation then erase message
			write_text("Do you want to restart? y/n ",50,160,RED,0);
			keypress=(char)getch();
			if(keypress == yes) keypress = start;
			erase(50,160,260,40);			
		}
		
		

	} while (keypress != yes);
	}
	} while (keypress != quit_game);

	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

void set_coordinates(int x, int y){ //initialize bulb coordinates
	int i, j, a, b;
	
	a = x;
	b = y;
	
	for(i=0; i<maxrow; i++, b+=19){
		for(j=0; j<maxcol; j++, a+=25){
			bulbs_x[i][j] = a;
			bulbs_y[i][j] = b;
		}
		a=x;
	}
}

void setup_level(){ //self explanatory
 
	int i, j, k, l;
   
	for(i=0; i<maxrow; i++)
		for(j=0; j<maxcol; j++)
			board[i][j]=off;

	switch(level){
	
		case 1:
			for (k = 0; k < maxrow; ++k){
				for (l = 0; l < maxcol; ++l){
					game_board[k][l] = easy_board[k][l];
					if (easy_board[k][l]!=0){
						board[k][l]=on;
						// write_text(":P", 5, 160, WHITE, 0);
					}
				}
			}
			break;
	}	

	// starting point
	board[0][0] = board[0][0] == on? son : soff;

	erase(190,5,30,20); //erase menu
	print_board(85, 35);
}


void gray(int x, int y){ //prints a gray bulb socket 
int i, h;

	for (i=0;i<25;i++)write_pixel(i+x,0+y,GRAY);
	for (h = 1; h < 19; ++h){
		write_pixel(0+x,h+y,GRAY);
		write_pixel(24+x,h+y,GRAY);	
	}
	for (i=0;i<25;i++)write_pixel(i+x,18+y,GRAY);

}

void vline(int x, int y){
	int i;
	//vertical line
	for (i = 0; i < 19; ++i)write_pixel(x-75, i+y,ROYAL_BLUE);
	for (i = 0; i < 19; ++i)write_pixel(x, i+y,ROYAL_BLUE);
	for (i = 0; i < 19; ++i)write_pixel(x-1, i+y,ROYAL_BLUE);
	for (i = 0; i < 19; ++i)write_pixel(x+74, i+y,ROYAL_BLUE);
	for (i = 0; i < 19; ++i)write_pixel(x+75, i+y,ROYAL_BLUE);
	for (i = 0; i < 19; ++i)write_pixel(x+149, i+y,ROYAL_BLUE);
	
}

void hline(int x, int y){
	int i;
	//horizontal line
	for (i = 0; i < 25; ++i)write_pixel(i+x, y-57,ROYAL_BLUE);
	for (i = 0; i < 25; ++i)write_pixel(i+x, y,ROYAL_BLUE);
	for (i = 0; i < 25; ++i)write_pixel(i+x, y-1,ROYAL_BLUE);
	for (i = 0; i < 25; ++i)write_pixel(i+x, y+56,ROYAL_BLUE);
	for (i = 0; i < 25; ++i)write_pixel(i+x, y+57,ROYAL_BLUE);
	for (i = 0; i < 25; ++i)write_pixel(i+x, y+113,ROYAL_BLUE);
}



void light(int r, int c, int x, int y){ //prints a bulb light 
	int i, color, h;
 	char str[15];
	
	switch(board[r][c]){ //sets the bulb's color
		case on: color = WHITE; break;
		case son: color = YELLOW; break;
		case off: color = WHITE; break;
		case soff: color = YELLOW; break;
	}
	for (h = 1; h < 18; ++h){
		for (i=1;i<24;i++)write_pixel(i+x,h+y,color);		
	}
	if (game_board[r][c]!=0){
		sprintf(str,"%d",game_board[r][c]);
		write_text(str,x+10,y+5,DARK_BLUE,0);
	}
}

void print_bulb(int r, int c, int x, int y){ //print a bulb 

	gray(x, y-10);
	light(r, c, x, y-10);
	vline(160, y-10);
	hline(x, 82);
}


void print_board(int x, int y){ //set up initial board 

	int i, j, a, b;
 	a=x;
 	b=y;
 	char str[15];

	//display level
   	write_text("Level",135,5,WHITE,0); 
	sprintf(str,"%d",level);
	write_text(str,190,5,WHITE,0);

	//print the 81 bulbs
	for(i=0; i<maxrow; i++, b+=19){
		for(j=0; j<maxcol; j++, a+=25)
			print_bulb(i, j, a, b);
		a=x;
	}
	
	//display legend
	write_text("Up-W",5,30,WHITE,0);
	write_text("Dn-S",5,40,WHITE,0);
	write_text("Lf-A",5,50,WHITE,0);
	write_text("Rt-D",5,60,WHITE,0);
	
	write_text("Num-[1-9]",5,70,WHITE,0);
	write_text("Exit-X",5,80,WHITE,0);
	write_text("Reset-R",5,90,WHITE,0);
	write_text("Sbt:",5,100,WHITE,0);
	write_text("<SPACE>",8,110,WHITE,0);

	//show number of number pressed
	write_text("ACTIONS:",5,130,WHITE,0);
	
}

// update selected and previously selected bulb colors 
void edit_board(){

	light(oldrow, oldcol, bulbs_x[oldrow][oldcol], bulbs_y[oldrow][oldcol]-10);
	light(row, col, bulbs_x[row][col], bulbs_y[row][col]-10);
}

void erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

bulb_row2(int x, int y){ //displays header top and bottom borders

	gray(25+x,0+y);
	write_text("1",25+x+8,0+y+2,WHITE,1); 

	gray(50+x,0+y);
	write_text("2",50+x+8,0+y+2,WHITE,1); 

	gray(75+x,0+y);
	write_text("3",75+x+8,0+y+2,WHITE,1); 

	gray(100+x,0+y);
	write_text("4",100+x+8,0+y+2,WHITE,1); 

	gray(125+x,0+y);
	write_text("5",125+x+8,0+y+2,WHITE,1); 

	gray(150+x,0+y);
	write_text("6",150+x+8,0+y+2,WHITE,1); 

	gray(175+x,0+y);
	write_text("7",175+x+8,0+y+2,WHITE,1); 

	gray(200+x,0+y);
	write_text("8",200+x+8,0+y+2,WHITE,1); 

	gray(225+x,0+y);
	write_text("9",225+x+8,0+y+2,WHITE,1); 

	gray(250+x,0+y);
	write_text("0",250+x+8,0+y+2,WHITE,1); 


}

//displays header left and right borders
bulb_pair1(int x, int y){ 

	gray(25+x,0+y);
	write_text("1",25+x+8,0+y+2,WHITE,1); 

	gray(250+x,0+y);
	write_text("0",250+x+8,0+y+2,WHITE,1); 
}

bulb_pair2(int x, int y){

	gray(25+x,0+y);
	write_text("1",25+x+8,0+y+2,WHITE,1); 

	gray(250+x,0+y);
	write_text("0",250+x+8,0+y+2,WHITE,1); 
}

//displays header - header(8,5)
header(int x, int y){

	bulb_row2(x,0+y);
	bulb_pair1(x,18+y);
	bulb_pair2(x,36+y);
	bulb_pair1(x,54+y);
	bulb_row2(x,72+y);
	
	write_text("SUDOKU",130,35,WHITE,1); //title
	write_text("2018",138,50,WHITE,1); //title

	//menu options
	write_text("s - Start",40,160,WHITE,0); 
	write_text("q - Quit",200,160,WHITE,0);
}


