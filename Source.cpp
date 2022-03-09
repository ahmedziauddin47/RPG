//RPG parody project
//work on spells, abilities, monster variety, level up, enemy decision algorithm, agility, crit rate, items, and multiple enemies.
//after skeletal structure is made, composed narrative structure and locations.

#include<iostream>

using namespace std;

//defined and intialized variables with arrays

struct weapons
{
	int cobblestonesword = 8;
	int cobblestonegreatsword = 12;
}sword, greatsword, spear, dagger, staff;

struct headarmour
{
	int bandana = 1;
}helm;

struct bodyarmour
{
	int plainclothes = 4;
}body;

struct lefthand
{
	int potlid = 1;
}shield;

struct accessory
{
	int charm = 1;
}accessory;

struct herostatus
{
	int level = 1;
	int exp = 0;
	int gold = 0;
	int hp = 22;
	int atk = 8;
	int weapon = 0;
	int equipment = 0;
	int mag = 5;
	int mp = 0;
	int def = 6;
	int agility = 6;
	int critical = 0;
	char engage = 0;

	int action = 0;
	int spell = 0;
	int ability = 0;
	int defend = 0;
	int item = 0;
	int status = 0;
	int flee = 0;

	int roll = 0;
	int damage = 0;

	string name = "hero";
}hero;

struct enemy
{
	int level = 0;
	int hp = 5;
	int atk = 0;
	int mag = 0;
	int mp = 0;
	int def = 0;
	int agility = 0;
	int damage = 0;
	int exp = 0;
	int roll = 0;
	int hit = 0;
	int gold = 0;
	string name = "default";
}enemy;

//declare stats for player character function

void status()
{

	hero.level = 1;
	hero.exp = 0;
	hero.gold = 0;
	hero.hp = 22;
	hero.atk = 8;
	hero.mag = 5;
	hero.mp = 0;
	hero.def = 6;
	hero.agility = 6;
	hero.critical = 0;
	hero.engage = 0;

	hero.action = 0;
	hero.spell = 0;
	hero.ability = 0;
	hero.defend = 0;
	hero.item = 0;
	hero.flee = 0;

	hero.roll = 0;
	hero.damage = 0;

	hero.atk = hero.atk + sword.cobblestonesword;
	hero.weapon = sword.cobblestonesword;

	hero.def = hero.def + helm.bandana + body.plainclothes + shield.potlid;
	hero.equipment = helm.bandana + body.plainclothes + shield.potlid;
}

//function for random encounters allowing players to face different enemies

void monster()
{
	srand(time(0));
	enemy.roll = 1 + rand() % 5;
	
	switch (enemy.roll)
	{
	case 1:
		enemy.level = 1;
		enemy.hp = 8;
		enemy.atk = 10;
		enemy.mag = 0;
		enemy.mp = 0;
		enemy.def = 7;
		enemy.agility = 7;
		enemy.damage = 0;
		enemy.exp = 2;
		enemy.gold = 4;
		enemy.roll = 0;
		enemy.name = "Slime";
		break;
	case 2:
		enemy.level = 1;
		enemy.hp = 10;
		enemy.atk = 11;
		enemy.mag = 0;
		enemy.mp = 0;
		enemy.def = 9;
		enemy.agility = 6;
		enemy.damage = 0;
		enemy.exp = 3;
		enemy.gold = 3;
		enemy.roll = 0;
		enemy.name = "Needler";
		break;
	case 3:
		enemy.level = 1;
		enemy.hp = 12;
		enemy.atk = 14;
		enemy.mag = 0;
		enemy.mp = 2;
		enemy.def = 12;
		enemy.agility = 5;
		enemy.damage = 0;
		enemy.exp = 3;
		enemy.gold = 4;
		enemy.roll = 0;
		enemy.name = "Stark raven";
		break;
	case 4:
		enemy.level = 1;
		enemy.hp = 11;
		enemy.atk = 12;
		enemy.mag = 0;
		enemy.mp = 2;
		enemy.def = 11;
		enemy.agility = 9;
		enemy.damage = 0;
		enemy.exp = 4;
		enemy.gold = 5;
		enemy.roll = 0;
		enemy.name = "Dracky";
		break;
	case 5:
		enemy.level = 1;
		enemy.hp = 10;
		enemy.atk = 11;
		enemy.mag = 0;
		enemy.mp = 0;
		enemy.def = 9;
		enemy.agility = 6;
		enemy.damage = 0;
		enemy.exp = 3;
		enemy.gold = 3;
		enemy.roll = 0;
		enemy.name = "Cruelcumber";
		break;
	}
	
}

//the prologue of the game

void tutorial()
{
	cout << "tell me your name" << endl;
	cin >> hero.name;
	printf("\33[1J\r");
	cout << hero.name << "... that name, I feel I've head of it before, but nevermind. A small test is in order, Look out!" << endl;
	cout << endl;
	status();
}

//displays decisions the player can take against enemies

void choice()
{
	cout << hero.name << ": " << endl;
	cout << "LV: " << hero.level << endl;
	cout << "HP: " << hero.hp << endl;
	cout << "MP: " << hero.mp << endl;
	cout << endl;
	cout << "1: Attack" << endl;
	cout << "2: Spells" << endl;
	cout << "3: Defend" << endl;
	cout << "4: Abilities" << endl;
	cout << "5: Items" << endl;
	cout << "6: Flee" << endl;
	cout << "choose an action (enter a number)" << endl;

}

//function for attacking an enemy

void strike()
{
	printf("\33[1J\r");

	bool ehit;
	enemy.damage = enemy.def - hero.atk;
	ehit = enemy.damage >= 0;
	enemy.hit = rand() % 2;
	if (ehit == true && enemy.hit == 0)
	{
		cout << "the " << hero.name << " attacks! miss, the " << enemy.name << " dodges swiftly!" << endl;
	}
	else if (ehit == true && enemy.hit == 1)
	{
		enemy.hp = enemy.hp - enemy.hit;
		cout << hero.name << " attacks! the " << enemy.name << " takes " << -1 * enemy.hit << " damage" << endl;
	}
	else if (ehit == false)
	{
		enemy.hp = enemy.hp + enemy.damage;
		cout << hero.name << " attacks! the " << enemy.name << " takes " << enemy.damage << " damage" << endl;
	}
}

//function for taking damage by an enemy

void hit()
{
	bool defhit;

	hero.damage = hero.def - enemy.atk;
	defhit = hero.damage >= 0;
	hero.roll = rand() % 2;

		if (defhit == true && hero.roll == 0 && enemy.hp >= 1)
		{
			cout << "the " << enemy.name << " attacks! miss, no damage taken!" << endl;
		}
		else if (defhit == true && hero.roll == 1 && enemy.hp >= 1)
		{
			hero.hp = hero.hp - hero.roll;
			cout << "the " << enemy.name << " attacks! " << hero.name << " takes " << -1 * hero.roll << " damage" << endl;
		}
		else if (defhit == false && enemy.hp >= 1)
		{
			hero.hp = hero.hp + hero.damage;
			cout << "the " << enemy.name << " attacks! " << hero.name << " takes " << hero.damage << " damage" << endl;
		}
		else if (enemy.hp <= 0)
		{
			cout << endl;
		}
}

//function for defending against an enemy

void dhit()
{
	printf("\33[1J\r");
	bool defendhit;

	hero.defend = 2 * hero.def - enemy.atk;
	defendhit = hero.defend >= 0;
	hero.roll = rand() % 2;

	if (defendhit == true && hero.roll == 0)
	{
		cout << hero.name << " braces themself! miss, no damage taken!" << endl;
	}
	else if (defendhit == true && hero.roll == 1)
	{
		hero.hp = hero.hp - hero.roll;
		cout << hero.name << " braces themself! " << hero.name << " takes " << -1 * hero.roll << " damage" << endl;
	}
	else if (defendhit == false)
	{
		hero.hp = hero.hp + hero.defend;
		cout << hero.name << " braces themself! " << hero.name << " takes " << hero.defend << " damage" << endl;
	}
}

//function for fleeing the battle

void flee()
{
	printf("\33[1J\r");
	hero.flee = 1 + rand() % 2;
	cout << hero.name << " runs away like a pansy" << endl;
	cout << "you lose!" << endl;

	if (hero.flee != 1)
	{
		cout << "the " << enemy.name << " blocks the way" << endl;
		hero.hp = hero.hp + hero.def - enemy.atk;
		hero.damage = hero.def - enemy.atk;
		cout << "the " << enemy.name << " attacks! " << hero.name << " takes " << hero.damage << " damage" << endl;
	}
}

//function to display battle results


void conclusion()
{
	if (enemy.hp <= 0)
	{
		hero.exp = hero.exp + enemy.exp;
		hero.gold = hero.gold + enemy.gold;
		cout << "the " << enemy.name << " was defeated! " << hero.name << " gains " << enemy.exp << " points of experience" << endl;
		cout << "the " << enemy.name << " drops " << enemy.gold << " gold" << endl;
		cout << endl;
		cout << "would you like to fight another enemy y/n?" << endl;
		cin >> hero.engage;
		if (hero.engage == 'y')
		{
			monster();
			printf("\33[1J\r");
			cout << "a " << enemy.name << " draws near!" << endl;
		}
	}

	else if (hero.hp <= 0)
	{
		cout << hero.name << " dies!" << endl;
		hero.gold = hero.gold * .5;
		cout << "would you like to fight another enemy y/n?" << endl;
		cin >> hero.engage;
		if (hero.engage == 'y')
		{
			status();
			monster();
			printf("\33[1J\r");
			cout << "a " << enemy.name << " draws near!" << endl;
		}
	}
	
}


//function to describe structure of battles


void fightstruct()
{
	cout << "a " << enemy.name << " draws near! do you want to engage y / n ? " << endl;
	cin >> hero.engage;
	printf("\33[1J\r");
	if (hero.engage == 'y');
	{
		while (enemy.hp >= 1 && hero.hp >= 1 && hero.flee != 1)
		{
			choice();
			cin >> hero.action;
			printf("\33[1J\r");
			switch (hero.action)
			{
			case 1:
				strike();
				hit();
				break;
			case 2:
				//placeholder
				cout << hero.name << " doesn't know any spells!" << endl;
				break;
			case 3:
				dhit();
				break;
			case 4:
				//placeholder
				cout << hero.name << " doesn't know any abilities!" << endl;
				break;
			case 5:
				//placeholder
				cout << hero.name << " doesn't have any items!" << endl;
				break;
			case 6:
				flee();
				break;
			}
			conclusion();
		}
	} 
}



int main()
{

	


	tutorial();
	monster();
	fightstruct();


	
	
}
