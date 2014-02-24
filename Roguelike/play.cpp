


#include <iostream>
#include <conio.h>

#include "play.h"

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
	//cout << "Enter character: ";
	setCharLocation(1, 1, map);
	setEnemyLoc(15, 15, map);


	printMap(map);


	c = _getch();
	while(c != 27){
		int redraw = 0;
		if(c == 49){
			redraw = moveCH(1, map);
		}
		if(c == 50){
			redraw = moveCH(2, map);
		}
		if(c == 51){
			redraw = moveCH(3, map);
		}
		if(c == 52){
			redraw = moveCH(4, map);
		}
		if(c == 53){
			redraw = moveCH(5, map);
		}
		if(c == 54){
			redraw = moveCH(6, map);
		}
		if(c == 55){
			redraw = moveCH(7, map);
		}
		if(c == 56){
			redraw = moveCH(8, map);
		}
		if(c == 57){
			redraw = moveCH(9, map);
		}
		if(redraw){
			printMap(map);
		}
		c = _getch();
	}
	return 1;
}

int setCharLocation(int x, int y, Tile map[MAXHEIGHT][MAXLENGTH]){
	if(!map[y][x].getPassable()){
		return 0;
	}
	int *pcLocation = locatePC(map);
	if(pcLocation){
		map[pcLocation[0]][pcLocation[1]].setPassable(true);
		map[pcLocation[0]][pcLocation[1]].setRepresentation(FLOOR);
	}
	map[y][x] = Tile(CHARACTER, false);
	/*map[y][x].setPassable(false);
	map[y][x].setRepresentation(CHARACTER); -- ******Commented this out, isn't it redundant with the above constructor?********/
	//printMap(map);

	free(pcLocation);
	return 1;
}

//Temporary Enemy location function
int setEnemyLoc(int x, int y, Tile map[MAXHEIGHT][MAXLENGTH]) {
	if (!map[y][x].getPassable()) {
		return 0;
	}

	map[y][x] = Tile(ENEMY, false);
	return 1;
}

int* locatePC(Tile map[MAXHEIGHT][MAXLENGTH]){
	int* result = (int*)malloc(sizeof(int)*2);
	for(int i = 0; i < MAXHEIGHT; i++){
		for(int j = 0; j < MAXLENGTH; j++){
			if(map[i][j].getRepresentation() == CHARACTER){
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	return NULL;
}

int moveCH(int direction, Tile map[MAXHEIGHT][MAXLENGTH]){
	int* pcLocation = locatePC(map);
	//top row
	if(direction == 7){
		if(map[pcLocation[0]-1][pcLocation[1]-1].getPassable()){
			setCharLocation(pcLocation[1]-1, pcLocation[0]-1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}
	else if(direction == 8){
		if(map[pcLocation[0]-1][pcLocation[1]].getPassable()){
			setCharLocation(pcLocation[1], pcLocation[0]-1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}
	else if(direction == 9){
		if(map[pcLocation[0]-1][pcLocation[1]+1].getPassable()){
			setCharLocation(pcLocation[1]+1, pcLocation[0]-1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}

	//middle row
	else if(direction == 4){
		if(map[pcLocation[0]][pcLocation[1]-1].getPassable()){
			setCharLocation(pcLocation[1]-1, pcLocation[0], map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}
	else if(direction == 5){
		free(pcLocation);
		return 1;
	}
	else if(direction == 6){
		if(map[pcLocation[0]][pcLocation[1]+1].getPassable()){
			setCharLocation(pcLocation[1]+1, pcLocation[0], map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}

	//bottom row
	else if(direction == 1){
		if(map[pcLocation[0]+1][pcLocation[1]-1].getPassable()){
			setCharLocation(pcLocation[1]-1, pcLocation[0]+1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}
	else if(direction == 2){
		if(map[pcLocation[0]+1][pcLocation[1]].getPassable()){
			setCharLocation(pcLocation[1], pcLocation[0]+1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}
	else if(direction == 3){
		if(map[pcLocation[0]+1][pcLocation[1]+1].getPassable()){
			setCharLocation(pcLocation[1]+1, pcLocation[0]+1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}

	else if(direction == 27){
		free(pcLocation);
		return 0;
	}

	free(pcLocation);
	return 1;
}