



#define WALL (char)219 
#define FLOOR (char)249
#define CHARACTER (char)64

#define MAXLENGTH 30
#define MAXHEIGHT 25
#define MINROOMSIZE 2

#ifndef MAPGEN_H
#define MAPGEN_H

class Tile{
	char representation;
	bool isPassible;

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





void generateMap(int type, Tile map[MAXHEIGHT][MAXLENGTH]);

int canFitRoom(Tile map[MAXHEIGHT][MAXLENGTH], int y, int x, int len, int wid);

int addRoom(Tile map[MAXHEIGHT][MAXLENGTH]);

int* findNextPoint(Tile map[MAXHEIGHT][MAXLENGTH], int roomLen, int roomWid);

void fillMap(Tile map[MAXHEIGHT][MAXLENGTH]);

void printMap(Tile map[MAXHEIGHT][MAXLENGTH]);

#endif