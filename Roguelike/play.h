
#include "map.h"

#ifndef PLAY_H
#define PLAY_H


int play(char map[MAXHEIGHT][MAXLENGTH]);

int setCharLocation(int x, int y, char map[MAXHEIGHT][MAXLENGTH]);

int* locatePC(char map[MAXHEIGHT][MAXLENGTH]);

int moveCH(int direction, char map[MAXHEIGHT][MAXLENGTH]);

#endif