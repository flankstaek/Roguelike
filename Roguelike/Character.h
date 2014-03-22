class Character
{
public:
	int experience;
	int health;
	char rep;

	int attack();
	void damage(int d) { health -= d; }
	void addExp(int e) { experience += e; }
	void setRep(char c) { rep = c; }

};


