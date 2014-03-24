#include "Tile.h"
#include "Character.h"

using namespace std;
#include<iostream>

Tile::Tile(char rep, bool pass){
	representation = rep;
	isPassible = pass;
	hasCharacter = false;
	hasItem = false;
	occupyingCharacter = 0;
}

Tile::Tile(){
	representation = WALL;
	isPassible = false;
}

bool Tile::getPassable(){
	return isPassible;
}

char Tile::getRepresentation(){
	//cout << hasCharacter;
	if (hasCharacter){
		return occupyingCharacter->getRep();
	}
	else if (hasItem){
		//return item representation
	}
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

Character * Tile::getOccupyingCharacter(){
	return occupyingCharacter;
}

void Tile::setOccupyingCharacter(Character * c){
	occupyingCharacter = c;
	if (c == 0){
		hasCharacter = false;
	}
	else{
		hasCharacter = true;
	}
	//cout << "What's going on here? " << occupyingCharacter << ", " << c << ", " << getRepresentation() << "  ";
}