﻿


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
	for(int i = 0; i < MAXHEIGHT; i++){
		//if (i != 0) { addch('\n'); }
		for(int j = 0; j < MAXLENGTH; j++){
			if (Player::playerCharacter->hasLOS(i, j)){
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
			else{
				addch(32);
			}
		}
	}
}




