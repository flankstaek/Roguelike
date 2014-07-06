
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "map.h"
#include "panel.h"

void printMap(Tile[MAXHEIGHT][MAXLENGTH]);

void initGraphics();

void redrawScreen(Tile map[MAXHEIGHT][MAXLENGTH]);

void printToConsole(char*);

void printToStatus(char*);

//WINDOW * mainWindow;

#endif