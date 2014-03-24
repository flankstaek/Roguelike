#include "Character.h"

class Enemy: public Character{
	int damage;

public:
	Enemy(int, char);
	int attack();
};