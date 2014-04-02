
#ifndef TILE_H
#define TILE_H

class Character;

#define WALL (char)219 
#define FLOOR (char)249
#define CHARACTER (char)64
#define ENEMY (char)69
enum PASSABLE {_PASS, _WALL, _ENEMY};

class Tile{
	char representation;
	int isPassible;
	bool hasCharacter;
	bool hasItem;
	Character* occupyingCharacter;

public:
	Tile();
	Tile(char, int);
	Tile(char);
	int getPassable();
	char getRepresentation();
	void setPassable(int);
	void setRepresentation(char);
	void setOccupyingCharacter(Character *);
	Character * getOccupyingCharacter();
};

class Wall : public Tile{

public:
	Wall();
};

class Floor : public Tile{

public:
	Floor();
};

#endif