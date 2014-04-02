#include "Tile.h"
#include "Character.h"

using namespace std;
#include<iostream>

Tile::Tile(char rep, int pass){
	representation = rep;
	isPassible = pass;
	hasCharacter = false;
	hasItem = false;
	occupyingCharacter = 0;
}

Tile::Tile(){
	representation = WALL;
	isPassible = _WALL;
}

int Tile::getPassable(){
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

void Tile::setPassable(int pass){
	isPassible = pass;
}

void Tile::setRepresentation(char rep){
	representation = rep;
}

Wall::Wall() : Tile(WALL, _WALL){

}

Floor::Floor() : Tile(FLOOR, _PASS){

}

Character * Tile::getOccupyingCharacter(){
	return occupyingCharacter;
}

void Tile::setOccupyingCharacter(Character * c){
	occupyingCharacter = c;
	if (c == 0){
		hasCharacter = false;
		isPassible = _PASS;
	}
	else{
		hasCharacter = true;
		isPassible = _ENEMY; //Currently done poorly, if it's not a wall and not nothing, then it's probably an enemy. I like enum's, seems fitting for future use.
	}
	//cout << "What's going on here? " << occupyingCharacter << ", " << c << ", " << getRepresentation() << "  ";
}