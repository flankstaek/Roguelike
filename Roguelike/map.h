



#define WALL (char)219 
#define FLOOR (char)249
#define CHARACTER (char)64

#define MAXLENGTH 30
#define MAXWIDTH 30
#define MINROOMSIZE 2

#ifndef MAPGEN_H
#define MAPGEN_H

void generateMap(int type, char map[MAXWIDTH][MAXLENGTH]);

int canFitRoom(char map[MAXWIDTH][MAXLENGTH], int y, int x, int len, int wid);

int addRoom(char map[MAXWIDTH][MAXLENGTH]);

int* findNextPoint(char map[MAXWIDTH][MAXLENGTH], int roomLen, int roomWid);

void fillMap(char map[MAXWIDTH][MAXLENGTH]);

void printMap(char map[MAXWIDTH][MAXLENGTH]);

#endif