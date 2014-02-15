



#define WALL (char)219 
#define FLOOR (char)249
#define CHARACTER (char)64

#define MAXLENGTH 30
#define MAXHEIGHT 25
#define MINROOMSIZE 2

#ifndef MAPGEN_H
#define MAPGEN_H

void generateMap(int type, char map[MAXHEIGHT][MAXLENGTH]);

int canFitRoom(char map[MAXHEIGHT][MAXLENGTH], int y, int x, int len, int wid);

int addRoom(char map[MAXHEIGHT][MAXLENGTH]);

int* findNextPoint(char map[MAXHEIGHT][MAXLENGTH], int roomLen, int roomWid);

void fillMap(char map[MAXHEIGHT][MAXLENGTH]);

void printMap(char map[MAXHEIGHT][MAXLENGTH]);

#endif