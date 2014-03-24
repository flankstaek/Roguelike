
#ifndef TILE_H
#define TILE_H

class Character;

#define WALL (char)219 
#define FLOOR (char)249
#define CHARACTER (char)64
#define ENEMY (char)69

class Tile{
	char representation;
	bool isPassible;
	bool hasCharacter;
	bool hasItem;
	Character* occupyingCharacter;

public:
	Tile();
	Tile(char, bool);
	bool getPassable();
	char getRepresentation();
	void setPassable(bool);
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