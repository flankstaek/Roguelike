
#include "Character.h"


class Player:Character {

	int level;

	int hunger;

	int speed;
	int armor;

	int intelligence;
	int dexterity;
	int wisdom;
	int charisma;
	int agility;
	int strength;
	int luck;

	void levelUp();

public:
	int attack() {
		//Damage calculation
		return 0;
	}
};