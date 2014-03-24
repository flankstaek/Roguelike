
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Map.h"

class Tile;

class Character
{
	int exp;
	int health;
	char rep;
	int xPos;
	int yPos;
public:
	void damage(int d);
	void addExp(int e);
	void setRep(char c);
	void resetExp();
	int attack();
	char getRep();
	Character(int, char);
	int getX();
	int getY();
	void setPos(int x, int y, Tile[MAXHEIGHT][MAXLENGTH]);
};

#endif


