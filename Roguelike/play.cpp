


#include <iostream>

#include "play.h"
#include "Tile.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Point.h"

using namespace std;

int main(){
	Tile map[MAXHEIGHT][MAXLENGTH];
	generateMap(0, map);
	//printMap(map);
	//while(play() != 27){
	//	printMap(map);
	//}
	play(map);
	exit(EXIT_SUCCESS);
}

int play(Tile map[MAXHEIGHT][MAXLENGTH]){
	int c = 0;
	Character ** characters = populateMap(map);
	//setEnemyLoc(15, 15, map);


	printMap(map);


	c = _getch();
	while (c != 27){
		int redraw = 0;
		if (c == 49){
			redraw = moveCH(1, map, characters[0]);
		}
		if (c == 50){
			redraw = moveCH(2, map, characters[0]);
		}
		if (c == 51){
			redraw = moveCH(3, map, characters[0]);
		}
		if (c == 52){
			redraw = moveCH(4, map, characters[0]);
		}
		if (c == 53){
			redraw = moveCH(5, map, characters[0]);
		}
		if (c == 54){
			redraw = moveCH(6, map, characters[0]);
		}
		if (c == 55){
			redraw = moveCH(7, map, characters[0]);
		}
		if (c == 56){
			redraw = moveCH(8, map, characters[0]);
		}
		if (c == 57){
			redraw = moveCH(9, map, characters[0]);
		}
		if (redraw){
			printMap(map);
		}
		//Iterate through enemies, do shit
		Point p1 = Point(characters[1]->getX(), characters[1]->getY());
		Point p2 = Point(characters[0]->getX(), characters[0]->getY());
		vector<Point> test = p1.path(map, p1, p2);
		printPath(test);
		c = _getch();
	}
	return 1;
}

void printPath(vector<Point> p){
	cout << "\n\n";
	cout << p.size();
	for (int i = 0; i < (int)p.size(); i++){
		cout << p[i].xVal << ", " << p[i].yVal << "\n";
	}
}

Character ** populateMap(Tile map[MAXHEIGHT][MAXLENGTH]){
	Character ** result = (Character**)malloc(sizeof(Character**));
	Character * p = (Character*)malloc(sizeof(Player));
	p = new Player(10, '@');
	p->setPos(1, 1, map);
	Character * e = (Character*)malloc(sizeof(Enemy));
	e = new Enemy(5, 'e');
	e->setPos(MAXHEIGHT / 2, MAXLENGTH / 2, map);
	result[0] = p;
	result[1] = e;
	return result;
}

int moveCH(int direction, Tile map[MAXHEIGHT][MAXLENGTH], Character *c){
	//top row
	if (direction == 7){
		switch (map[c->getY() - 1][c->getX() - 1].getPassable()) {
		case _PASS:
			c->setPos(c->getY() - 1, c->getX() - 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() - 1][c->getX() - 1].getOccupyingCharacter());
			break;

		default:
			return 0;
		}
	}
	else if (direction == 8){
		switch (map[c->getY() - 1][c->getX()].getPassable()){
		case _PASS:
			c->setPos(c->getY() - 1, c->getX(), map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() - 1][c->getX()].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}
	else if (direction == 9){
		switch (map[c->getY() - 1][c->getX() + 1].getPassable()){
		case _PASS:
			c->setPos(c->getY() - 1, c->getX() + 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() - 1][c->getX() + 1].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}

	//middle row
	else if (direction == 4){
		switch (map[c->getY()][c->getX() - 1].getPassable()){
		case _PASS:
			c->setPos(c->getY(), c->getX() - 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY()][c->getX() - 1].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}
	else if (direction == 5){
		return 1;
	}
	else if (direction == 6){
		switch (map[c->getY()][c->getX() + 1].getPassable()){
		case _PASS:
			c->setPos(c->getY(), c->getX() + 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY()][c->getX() + 1].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}

	//bottom row
	else if (direction == 1){
		switch (map[c->getY() + 1][c->getX() - 1].getPassable()){
		case _PASS:
			c->setPos(c->getY() + 1, c->getX() - 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() + 1][c->getX() - 1].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}
	else if (direction == 2){
		switch (map[c->getY() + 1][c->getX()].getPassable()){
		case _PASS:
			c->setPos(c->getY() + 1, c->getX(), map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() + 1][c->getX()].getOccupyingCharacter());
			break;

		default:
			return 0;

		}
	}
	else if (direction == 3){
		switch (map[c->getY() + 1][c->getX() + 1].getPassable()){
		case _PASS:
			c->setPos(c->getY() + 1, c->getX() + 1, map);
			break;

		case _ENEMY:
			c->attack(map[c->getY() + 1][c->getX() + 1].getOccupyingCharacter());
			break;

		default:
			return 0;
		}
	}

	else if (direction == 27){
		return 0;
	}

	return 1;
}