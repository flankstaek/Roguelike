


#include <iostream>
#include <conio.h>

#include "play.h"
#include "Tile.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"

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
	while(c != 27){
		int redraw = 0;
		if(c == 49){
			redraw = moveCH(1, map, characters[0]);
		}
		if(c == 50){
			redraw = moveCH(2, map, characters[0]);
		}
		if(c == 51){
			redraw = moveCH(3, map, characters[0]);
		}
		if(c == 52){
			redraw = moveCH(4, map, characters[0]);
		}
		if(c == 53){
			redraw = moveCH(5, map, characters[0]);
		}
		if(c == 54){
			redraw = moveCH(6, map, characters[0]);
		}
		if(c == 55){
			redraw = moveCH(7, map, characters[0]);
		}
		if(c == 56){
			redraw = moveCH(8, map, characters[0]);
		}
		if(c == 57){
			redraw = moveCH(9, map, characters[0]);
		}
		if(redraw){
			printMap(map);
		}
		c = _getch();
	}
	return 1;
}

Character ** populateMap(Tile map[MAXHEIGHT][MAXLENGTH]){
	Character ** result = (Character**)malloc(sizeof(Character**));
	Player * p = (Player*)malloc(sizeof(Player));
	*p = Player(10, '@');
	p->setPos(1, 1, map);
	result[0] = p;
	return result;
}

int moveCH(int direction, Tile map[MAXHEIGHT][MAXLENGTH], Character *c){
	//top row
	if(direction == 7){
		if (map[c->getY() - 1][c->getX() - 1].getPassable()){
			c->setPos(c->getY() - 1, c->getX() - 1, map);
			printMap(map);
		}
		else{
			return 0;
		}
	}
	else if(direction == 8){
		if (map[c->getY() - 1][c->getX()].getPassable()){
			c->setPos(c->getY() - 1, c->getX(), map);
		}
		else{
			return 0;
		}
	}
	else if(direction == 9){
		if (map[c->getY() - 1][c->getX() + 1].getPassable()){
			c->setPos(c->getY() - 1, c->getX() + 1, map);
		}
		else{
			return 0;
		}
	}

	//middle row
	else if(direction == 4){
		if (map[c->getY()][c->getX() - 1].getPassable()){
			c->setPos(c->getY(), c->getX() - 1, map);
		}
		else{
			return 0;
		}
	}
	else if(direction == 5){
		return 1;
	}
	else if(direction == 6){
		cout << c->getX() << ", " << c->getY();
		if (map[c->getY()][c->getX() + 1].getPassable()){
			c->setPos(c->getY(), c->getX() + 1, map);
			cout << c->getX() << ", " << c->getY();
		}
		else{
			return 0;
		}
	}

	//bottom row
	else if(direction == 1){
		if (map[c->getY() + 1][c->getX() - 1].getPassable()){
			c->setPos(c->getY() + 1, c->getX() - 1, map);
		}
		else{
			return 0;
		}
	}
	else if(direction == 2){
		if (map[c->getY() + 1][c->getX()].getPassable()){
			c->setPos(c->getY() + 1, c->getX(), map);
		}
		else{
			return 0;
		}
	}
	else if(direction == 3){
		if (map[c->getY() + 1][c->getX() + 1].getPassable()){
			c->setPos(c->getY() + 1, c->getX() + 1, map);
		}
		else{
			return 0;
		}
	}

	else if(direction == 27){
		return 0;
	}

	return 1;
}