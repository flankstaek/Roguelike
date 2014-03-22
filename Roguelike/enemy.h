#include "Character.h"

class Enemy:Character{
public:
	int damage;

	Enemy(int h, int e, int d) {
		health = h;
		experience = e;
		damage = d;
	}

	int attack() {
		//Damage calculation
		return damage;
	}
};