#include "Character.h"

class Enemy: public Character{
public:
	int dmg;

	Enemy(int, char);
	int attack(Character*);
	void damage(int);
	void checkAttack(Tile[MAXHEIGHT][MAXLENGTH]);
};