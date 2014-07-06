
#include "graphics.h"
#include "Tile.h"
#include "Player.h"


using namespace std;

WINDOW * consoleWindow;
WINDOW * statusWindow;

void printMap(Tile map[MAXHEIGHT][MAXLENGTH]){
	//resize_term(MAXHEIGHT, MAXLENGTH);
	//wclear(mySub);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(0) | A_BOLD);
	doFOV(map, Player::playerCharacter->getX(), Player::playerCharacter->getY(), Player::playerCharacter->getSight());
	int mapYStart = Player::playerCharacter->getY() - (DISPLAY_HEIGHT - CONSOLE_HEIGHT) / 2 - 1;
	int mapXStart = Player::playerCharacter->getX() - (DISPLAY_LENGTH - STATUS_LENGTH) / 2 - 1;


	for (int i = mapYStart; i < DISPLAY_HEIGHT - CONSOLE_HEIGHT; i++){
		if(i < 0){
			for (int j = 0; j < DISPLAY_LENGTH - STATUS_LENGTH; j++){
				addch(32);
			}
			for (int j = 0; j < STATUS_LENGTH; j++){
				addch(32);
			}
		}
		else{
			for (int j = mapXStart; j < DISPLAY_LENGTH - STATUS_LENGTH; j++){
				//cout << map[i][j].getVisible();
				if (j < 0){
					addch(32);
				}
				else if (map[i][j].getVisible()){
					if (map[i][j].getRepresentation() != WALL && map[i][j].getRepresentation() != FLOOR) {
						addch(map[i][j].getRepresentation());
					}
					else if (map[i][j].getRepresentation() == WALL) {
						addch(ACS_BLOCK);
					}
					else if (map[i][j].getRepresentation() == FLOOR) {
						addch(ACS_BULLET);
					}
				}
				else if (map[i][j].getExplored()){
					init_pair(1, COLOR_YELLOW, COLOR_BLACK);

					//init_color(COLOR_RED, 204, 0, 0);
					attron(COLOR_PAIR(1));
					attroff(A_BOLD);
					if (map[i][j].getRepresentation() == WALL) {
						addch(ACS_BLOCK);
					}
					else{// if (map[i][j].getRepresentation() == FLOOR) {
						addch(ACS_BULLET);
					}
					attroff(COLOR_PAIR(1));
					//attro
					attron(A_BOLD);
					//init_color(COLOR_WHITE, 225, 225, 225);
				}
				else{
					addch(32);
				}
			}
			for (int j = 0; j < STATUS_LENGTH + mapXStart; j++){
				addch(32);
			}
		}
	}
	//waddch(mySub, ACS_BULLET);
	//wrefresh(mySub);
	printToConsole("swagger");
	printToStatus("swag");
	attroff(COLOR_PAIR(0) | A_BOLD);
}

void initGraphics(){
	//curses initialization
	initscr();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	resize_term(DISPLAY_HEIGHT, DISPLAY_LENGTH);
	consoleWindow = subwin(stdscr, CONSOLE_HEIGHT, DISPLAY_LENGTH, DISPLAY_HEIGHT - CONSOLE_HEIGHT, 0);
	statusWindow = subwin(stdscr, DISPLAY_HEIGHT, STATUS_LENGTH, 0, DISPLAY_LENGTH - STATUS_LENGTH);
	//waddch(mySub, ACS_BULLET);
	//touchwin(mySub);
	//wrefresh(mySub);
}

void redrawScreen(Tile map[MAXHEIGHT][MAXLENGTH]){
	clear();
	printMap(map);
	//waddch(mySub, ACS_BULLET);
	//wrefresh(mySub);
	refresh();
}

void printToConsole(char* s){
	wclear(consoleWindow);
	for (int i = 0; i < DISPLAY_LENGTH; i++){
		waddch(consoleWindow, 32);
	}
	waddch(consoleWindow, 32);
	box(consoleWindow, 0, 0);

	int i = 0;
	while (s[i]){
		waddch(consoleWindow, s[i]);
		i++;
	}
	wrefresh(consoleWindow);
}

void printToStatus(char* s){
	wclear(statusWindow);
	for (int i = 0; i < STATUS_LENGTH; i++){
		waddch(statusWindow, 32);
	}
	waddch(statusWindow, 32);
	box(statusWindow, 0, 0);

	int i = 0;
	while (s[i]){
		waddch(statusWindow, s[i]);
		i++;
	}
	wrefresh(statusWindow);
}