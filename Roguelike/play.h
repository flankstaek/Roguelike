
#include "map.h"

#ifndef PLAY_H
#define PLAY_H


int play(char map[MAXWIDTH][MAXLENGTH]);

int setCharLocation(int x, int y, char map[MAXWIDTH][MAXLENGTH]);

int* locatePC(char map[MAXWIDTH][MAXLENGTH]);

int moveCH(int direction, char map[MAXWIDTH][MAXLENGTH]);

#endif