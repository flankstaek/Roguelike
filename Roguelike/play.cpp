


#include <iostream>
#include <conio.h>

#include "play.h"

using namespace std;

int main(){
	char map[MAXWIDTH][MAXLENGTH];
	generateMap(0, map);
	//printMap(map);
	//while(play() != 27){
	//	printMap(map);
	//}
	play(map);
	system("pause");
	exit(EXIT_SUCCESS);
}

int play(char map[MAXWIDTH][MAXLENGTH]){
	int c = 0;
	//cout << "Enter character: ";
	setCharLocation(1, 1, map);


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

int setCharLocation(int x, int y, char map[MAXWIDTH][MAXLENGTH]){
	if(map[y][x] == WALL){
		return 0;
	}
	int *pcLocation = locatePC(map);
	if(pcLocation){
		map[pcLocation[0]][pcLocation[1]] = FLOOR;
	}
	map[y][x] = CHARACTER;
	//printMap(map);

	free(pcLocation);
	return 1;
}

int* locatePC(char map[MAXWIDTH][MAXLENGTH]){
	int* result = (int*)malloc(sizeof(int)*2);
	for(int i = 0; i < MAXWIDTH; i++){
		for(int j = 0; j < MAXLENGTH; j++){
			if(map[i][j] == CHARACTER){
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	return NULL;
}

int moveCH(int direction, char map[MAXWIDTH][MAXLENGTH]){
	int* pcLocation = locatePC(map);
	//top row
	if(direction == 7){
		if(map[pcLocation[0]-1][pcLocation[1]-1] == FLOOR){
			setCharLocation(pcLocation[1]-1, pcLocation[0]-1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}
	else if(direction == 8){
		if(map[pcLocation[0]-1][pcLocation[1]] == FLOOR){
			setCharLocation(pcLocation[1], pcLocation[0]-1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}
	else if(direction == 9){
		if(map[pcLocation[0]-1][pcLocation[1]+1] == FLOOR){
			setCharLocation(pcLocation[1]+1, pcLocation[0]-1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}

	//middle row
	else if(direction == 4){
		if(map[pcLocation[0]][pcLocation[1]-1] == FLOOR){
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
		if(map[pcLocation[0]][pcLocation[1]+1] == FLOOR){
			setCharLocation(pcLocation[1]+1, pcLocation[0], map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}

	//bottom row
	else if(direction == 1){
		if(map[pcLocation[0]+1][pcLocation[1]-1] == FLOOR){
			setCharLocation(pcLocation[1]-1, pcLocation[0]+1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}
	else if(direction == 2){
		if(map[pcLocation[0]+1][pcLocation[1]] == FLOOR){
			setCharLocation(pcLocation[1], pcLocation[0]+1, map);
		}
		else{
			free(pcLocation);
			return 0;
		}
	}
	else if(direction == 3){
		if(map[pcLocation[0]+1][pcLocation[1]+1] == FLOOR){
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