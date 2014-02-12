


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>





#include <iostream>
#include <cstdlib>
#include <ctime>

#include "map.h"

using namespace std;

/*int main(){
	srand(time(0));
	int type = 0;
	char buff;
	cout << "Enter map type (0 for arena, 1 for random generation): ";
	cin >> buff;
	cout << "\n\n";
	type = atoi(&buff);
	char map[MAXWIDTH][MAXLENGTH];
	generateMap(type, map);
	printMap(map);
	system("pause");
	exit(EXIT_SUCCESS);
}*/

void generateMap(int type, char map[MAXWIDTH][MAXLENGTH]){
	fillMap(map);
	if(type == 0){
		for(int j = 0; j < MAXLENGTH; j++){
			map[0][j] = WALL;
		}
		for(int i = 1; i < MAXWIDTH-1; i++){
			map[i][0] = WALL;
			for(int j = 1; j < MAXLENGTH-1; j++){
				map[i][j] = FLOOR;
			}
			map[i][MAXLENGTH-1] = WALL;
		}
		for(int j = 0; j < MAXLENGTH; j++){
			map[MAXWIDTH-1][j] = WALL;
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

int canFitRoom(char map[MAXWIDTH][MAXLENGTH], int y, int x, int len, int wid){

	for(int i = y; i < y + wid; i++){
		for(int j = x; j < x + len; j++){
			if(!(map[i][j] == WALL && map[i][j-1] == WALL && map[i-1][j] == WALL && map[i][j+1] == WALL && map[i+1][j] == WALL)){
				return 0;
			}
		}
	}
	return 1;
}

int addRoom(char map[MAXWIDTH][MAXLENGTH]){
	int roomLen = rand() % (MAXLENGTH/2-MINROOMSIZE) + MINROOMSIZE;
	int roomWid = rand() % (MAXWIDTH/2-MINROOMSIZE) + MINROOMSIZE;
	int* nextPoint = findNextPoint(map, roomLen, roomWid);
	if(nextPoint == NULL){
		free(nextPoint);
		return 0;
	}
	for(int i = nextPoint[0]; i < roomLen + nextPoint[0]; i++){
		for(int j = nextPoint[1]; j < roomWid + nextPoint[1]; j++){
			map[i][j] = FLOOR;
		}
	}
	free(nextPoint);
	return 1;
}

int* findNextPoint(char map[MAXWIDTH][MAXLENGTH], int roomLen, int roomWid){
	int *result = (int*)malloc(sizeof(int)*2);
	for(int i = 1; i < MAXLENGTH-roomLen; i++){
		for(int j = 1; j < MAXWIDTH-roomWid; j++){
			if(canFitRoom(map, i, j, roomLen, roomWid)){
					result[0] = i;
					result[1] = j;
					return result;
			}
		}
	}
	return NULL;
}

void fillMap(char map[MAXWIDTH][MAXLENGTH]){
	for(int i = 0; i < MAXLENGTH; i++){
		for(int j = 0; j < MAXWIDTH; j++){
			map[i][j] = WALL;
		}
	}
}

void printMap(char map[MAXWIDTH][MAXLENGTH]){
	for(int i = 0; i < MAXLENGTH; i++){
		for(int j = 0; j < MAXWIDTH; j++){
			cout << map[i][j];
		}
		cout << "\n";
	}
}