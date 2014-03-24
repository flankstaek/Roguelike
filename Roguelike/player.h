
#include "Character.h"


class Player: public Character {

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

	

public:
	Player(int, char);
	void levelUp();
	int attack();
};