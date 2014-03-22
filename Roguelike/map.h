#include "Tile.h"

#define MAXLENGTH 30
#define MAXHEIGHT 25
#define MINROOMSIZE 2

#ifndef MAPGEN_H
#define MAPGEN_H





void generateMap(int, Tile[MAXHEIGHT][MAXLENGTH]);

int canFitRoom(Tile[MAXHEIGHT][MAXLENGTH], int, int, int, int);

int addRoom(Tile[MAXHEIGHT][MAXLENGTH]);

int* findNextPoint(Tile[MAXHEIGHT][MAXLENGTH], int, int);

void fillMap(Tile[MAXHEIGHT][MAXLENGTH]);

void printMap(Tile[MAXHEIGHT][MAXLENGTH]);

#endif