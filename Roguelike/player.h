#include "Character.h"


class Player: public Character {
public:

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

	

	Player(int, char);
	void levelUp();
	int attack(Character*);
	void damage(int);
};