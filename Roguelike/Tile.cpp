#include "Tile.h"

Tile::Tile(char rep, bool pass){
	representation = rep;
	isPassible = pass;
}

Tile::Tile(){
	representation = WALL;
	isPassible = false;
}

bool Tile::getPassable(){
	return isPassible;
}

char Tile::getRepresentation(){
	return representation;
}

void Tile::setPassable(bool pass){
	isPassible = pass;
}

void Tile::setRepresentation(char rep){
	representation = rep;
}

Wall::Wall() : Tile(WALL, false){

}

Floor::Floor() : Tile(FLOOR, true){

}