
#include "map.h"

#ifndef PLAY_H
#define PLAY_H


int play(Tile map[MAXHEIGHT][MAXLENGTH]);

int setCharLocation(int x, int y, Tile map[MAXHEIGHT][MAXLENGTH]);

int* locatePC(Tile map[MAXHEIGHT][MAXLENGTH]);

int moveCH(int direction, Tile map[MAXHEIGHT][MAXLENGTH]);

#endif