#include "enemy.h"

using namespace std;

Enemy::Enemy(int h, char r) : Character(h, r){

}

int Enemy::attack(Character* c){
	//damage calculation
	int d = 5;

	if (c != 0) {
		c->damage(d);
		return 1;
	}
	else
		return 0;

	//return dmg;
}

void Enemy::damage(int d) {
	//dodge/resistance
	health -= d;

	//Check for death in here?
}