#include "Tile.h"
#include "Character.h"
#include<iostream>

using namespace std;

Tile::Tile(char rep, int pass, int opaque){
	representation = rep;
	isPassible = pass;
	hasCharacter = false;
	hasItem = false;
	occupyingCharacter = 0;
	isOpaque = opaque;
	isVisible = 0;
}

Tile::Tile(){
	representation = WALL;
	isPassible = _WALL;
	isOpaque = 1;
	isVisible = 0;
}

int Tile::getPassable(){
	return isPassible;
}

int Tile::getOpaque(){
	return isOpaque;
}

int Tile::getVisible(){
	return isVisible;
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

void Tile::setVisible(int vis){
	isVisible = vis;
}

Wall::Wall() : Tile(WALL, _WALL, 1){

}

Floor::Floor() : Tile(FLOOR, _PASS, 0){

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