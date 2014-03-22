



#define WALL (char)219 
#define FLOOR (char)249
#define CHARACTER (char)64
#define ENEMY (char)69

#define MAXLENGTH 30
#define MAXHEIGHT 25
#define MINROOMSIZE 2

#ifndef MAPGEN_H
#define MAPGEN_H

class Tile{
	char representation;
	bool isPassible;
	bool hasCharacter;
	bool hasItem;

	public:
		Tile();
		Tile(char rep, bool pass);
		bool getPassable();
		char getRepresentation();
		void setPassable(bool pass);
		void setRepresentation(char rep);
};

class Wall : public Tile{

public:
	Wall();
};

class Floor : public Tile{
	
public:
	Floor();
};





void generateMap(int, Tile[MAXHEIGHT][MAXLENGTH]);

int canFitRoom(Tile[MAXHEIGHT][MAXLENGTH], int, int, int, int);

int addRoom(Tile[MAXHEIGHT][MAXLENGTH]);

int* findNextPoint(Tile[MAXHEIGHT][MAXLENGTH], int, int);

void fillMap(Tile[MAXHEIGHT][MAXLENGTH]);

void printMap(Tile[MAXHEIGHT][MAXLENGTH]);

#endif