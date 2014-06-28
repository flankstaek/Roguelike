


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>





#include <iostream>
#include <cstdlib>
#include <ctime>

#include "map.h"
#include "Tile.h"
#include "Player.h"
#include "Character.h"

using namespace std;

static int multipliers[4][8] = {
	{ 1, 0, 0, -1, -1, 0, 0, 1 },
	{ 0, 1, -1, 0, 0, -1, 1, 0 },
	{ 0, 1, 1, 0, 0, -1, -1, 0 },
	{ 1, 0, 0, 1, -1, 0, 0, -1 }
};

/*int main(){
	srand(time(0));
	int type = 0;
	char buff;
	cout << "Enter map type (0 for arena, 1 for random generation): ";
	cin >> buff;
	cout << "\n\n";
	type = atoi(&buff);
	Tile map[MAXHEIGHT][MAXLENGTH];
	generateMap(type, map);
	printMap(map);
	system("pause");
	exit(EXIT_SUCCESS);
}*/

void generateMap(int type, Tile map[MAXHEIGHT][MAXLENGTH]){
	fillMap(map);
	if(type == 0){
		for(int j = 0; j < MAXLENGTH; j++){
			map[0][j] = Wall();
		}
		for(int i = 1; i < MAXHEIGHT-1; i++){
			map[i][0] = Wall();
			for(int j = 1; j < MAXLENGTH-1; j++){
				map[i][j] = Floor();
			}
			map[i][MAXLENGTH-1] = Wall();
		}
		for(int j = 0; j < MAXLENGTH; j++){
			map[MAXHEIGHT-1][j] = Wall();
		}
		map[6][7] = Wall();
		map[6][8] = Wall();
		map[6][9] = Wall();
	}
	else if(type == 1){
		while(addRoom(map)){
		}
	}
	else{
		cout << "ERROR: Invalid map type";
	}
}

int canFitRoom(Tile map[MAXHEIGHT][MAXLENGTH], int y, int x, int len, int wid){

	for(int i = y; i < y + wid; i++){
		for(int j = x; j < x + len; j++){
			if (!(map[i][j].getRepresentation() == WALL && map[i][j - 1].getRepresentation() == WALL && map[i - 1][j].getRepresentation() == WALL && map[i][j + 1].getRepresentation() == WALL && map[i + 1][j].getRepresentation() == WALL)){
				return 0;
			}
		}
	}
	return 1;
}

int addRoom(Tile map[MAXHEIGHT][MAXLENGTH]){
	int roomLen = rand() % (MAXLENGTH/2-MINROOMSIZE) + MINROOMSIZE;
	int roomWid = rand() % (MAXHEIGHT/2-MINROOMSIZE) + MINROOMSIZE;
	int* nextPoint = findNextPoint(map, roomLen, roomWid);
	if(nextPoint == NULL){
		free(nextPoint);
		return 0;
	}
	for(int i = nextPoint[0]; i < roomLen + nextPoint[0]; i++){
		for(int j = nextPoint[1]; j < roomWid + nextPoint[1]; j++){
			map[i][j] = Floor();
		}
	}
	free(nextPoint);
	return 1;
}

int* findNextPoint(Tile map[MAXHEIGHT][MAXLENGTH], int roomLen, int roomWid){
	int *result = (int*)malloc(sizeof(int)*2);
	for(int i = 1; i < MAXLENGTH-roomLen; i++){
		for(int j = 1; j < MAXHEIGHT-roomWid; j++){
			if(canFitRoom(map, i, j, roomLen, roomWid)){
					result[0] = i;
					result[1] = j;
					return result;
			}
		}
	}
	return NULL;
}

void fillMap(Tile map[MAXHEIGHT][MAXLENGTH]){
	for(int i = 0; i < MAXHEIGHT; i++){
		for(int j = 0; j < MAXLENGTH; j++){
			map[i][j] = Wall();
		}
	}
}

void printMap(Tile map[MAXHEIGHT][MAXLENGTH]){
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(1) | A_BOLD);
	doFOV(map, Player::playerCharacter->getX(), Player::playerCharacter->getY(), Player::playerCharacter->getSight());
	for(int i = 0; i < MAXHEIGHT; i++){
		//if (i != 0) { addch('\n'); }
		for(int j = 0; j < MAXLENGTH; j++){
			//cout << map[i][j].getVisible();
			if (map[i][j].getVisible()){
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
				attron(A_BOLD);
				//init_color(COLOR_WHITE, 225, 225, 225);
			}
			else{
				addch(32);
			}
		}
	}
	attroff(COLOR_PAIR(0) | A_BOLD);
}

void doFOV(Tile map[MAXHEIGHT][MAXLENGTH], int x, int y, int radius){
	for (int i = 0; i < MAXHEIGHT; i++){
		for (int j = 0; j < MAXLENGTH; j++){
			map[i][j].setVisible(0);
		}
	}
	for (int i = 0; i < 8; i++){
		castLight(map, x, y, radius, 1, 1.0, 0.0, multipliers[0][i], multipliers[1][i], multipliers[2][i], multipliers[3][i]);
	}
	map[Player::playerCharacter->getY()][Player::playerCharacter->getX()].setVisible(1);
}

void castLight(Tile map[MAXHEIGHT][MAXLENGTH], int x, int y, int radius, int row, float startSlope, float endSlope, int xx, int xy, int yx, int yy){
	if (startSlope < endSlope){
		return;
	}
	float nextStartSlope = startSlope;
	for (int i = row; i <= radius; i++){
		bool blocked = false;
		for (int dx = -i, dy = -i; dx <= 0; dx++){
			float lSlope = (dx - .5) / (dy + .5);
			float rSlope = (dx + .5) / (dy - .5);
			if (startSlope < rSlope){
				continue;
			}
			else if (endSlope > lSlope){
				break;
			}

			int sax = dx * xx + dy * xy;
			int say = dx * yx + dy * yy;
			if ((sax < 0 && abs(sax) > x) || (say < 0 && abs(say) > y)){
				continue;
			}
			int ax = x + sax;
			int ay = y + say;
			if (ax >= MAXLENGTH || ay >= MAXHEIGHT){
				continue;
			}

			int radius2 = radius * radius;
			if ((dx*dx + dy*dy) < radius2){
				map[ay][ax].setVisible(1);
				map[ay][ax].setExplored(1);
			}

			if (blocked){
				if (map[ay][ax].getOpaque()){
					nextStartSlope = rSlope;
					continue;
				}
				else{
					blocked = false;
					startSlope = nextStartSlope;
				}
			}
			else if (map[ay][ax].getOpaque()){
				blocked = true;
				nextStartSlope = rSlope;
				castLight(map, x, y, radius, i + 1, startSlope, lSlope, xx, xy, yx, yy);
			}
		}
		if (blocked){
			break;
		}
	}
}
