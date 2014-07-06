
#include <vector>



#define MAXLENGTH 50
#define MAXHEIGHT 50
#define MINROOMSIZE 2

#ifndef MAPGEN_H
#define MAPGEN_H

class Tile;
class Point;

void generateMap(int, Tile[MAXHEIGHT][MAXLENGTH]);

int canFitRoom(Tile[MAXHEIGHT][MAXLENGTH], int, int, int, int);

int addRoom(Tile[MAXHEIGHT][MAXLENGTH]);

int* findNextPoint(Tile[MAXHEIGHT][MAXLENGTH], int, int);

void fillMap(Tile[MAXHEIGHT][MAXLENGTH]);

void printPath(std::vector<Point>);

void doFOV(Tile[MAXHEIGHT][MAXLENGTH], int, int, int);

void castLight(Tile[MAXHEIGHT][MAXLENGTH], int, int, int, int, float, float, int, int, int, int);

#endif