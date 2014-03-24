#include "player.h"

using namespace std;

Player::Player(int h, char r) : Character(h, r){

}

void Player::levelUp(){
	resetExp();
	level++;

	//increase stats by some sort of modifiers here. possibly dependent on race or something
}

int Player::attack(){
	//damage calculation
	return 0;
}