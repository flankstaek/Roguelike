
#include "map.h"

#ifndef PLAY_H
#define PLAY_H


int play(Tile[MAXHEIGHT][MAXLENGTH]);

int setCharLocation(int, int, Tile[MAXHEIGHT][MAXLENGTH]);

int setEnemyLoc(int, int, Tile[MAXHEIGHT][MAXLENGTH]);

int* locatePC(Tile[MAXHEIGHT][MAXLENGTH]);

int moveCH(int, Tile[MAXHEIGHT][MAXLENGTH]);

#endif