//RPG parody project
//work on enemy decision algorithm, agility, items, multiple party members and multiple enemies.
//after skeletal structure is made, composed narrative structure and locations.

#include <iostream>

using namespace std;

//defined and intialized variables with arrays

/* these items have yet to be implemented
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
*/

//declare stats for player character function

struct herostatus
{
	int level = 1;
	int exp = 0;
	int gold = 0;
	int hp = 20;
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


void status()
{

	hero.level = 1;
	hero.exp = 0;
	hero.gold = 0;
	hero.hp = 20;
	hero.atk = 15;
	hero.mag = 10;
	hero.mp = 0;
	hero.def = 15;
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

	/* these items have yet to be implemented
	hero.atk = hero.atk + sword.cobblestonesword;
	hero.weapon = sword.cobblestonesword;

	hero.def = hero.def + helm.bandana + body.plainclothes + shield.potlid;
	hero.equipment = helm.bandana + body.plainclothes + shield.potlid;
	*/
}

//function that allows player to learn spells and abilities as they progress

void growth()
{
	while (hero.level <= 10)
	{
		switch (hero.level)
		{
		case 1:
			break;
		case 2:
			cout << hero.name << " learned kafrizz!" << endl;
			break;
		case 3:
			cout << hero.name << " learned flame slash!" << endl;
			break;
		case 4:
			cout << hero.name << " learned heal!" << endl;
			break;
		case 5:
			cout << hero.name << " learned miracle slash!" << endl;
			break;
		case 6:
			cout << hero.name << " learned buff!" << endl;
			break;
		case 7:
			cout << hero.name << " learned falcon slash!" << endl;
			break;
		case 8:
			cout << hero.name << " learned full heal!" << endl;
			break;
		case 9:
			cout << hero.name << " learned kazap!" << endl;
			break;
		case 10:
			cout << hero.name << " learned gigabreak!" << endl;
			break;
		}
	}
}


//level up function

void levelup()
{
	
	if (hero.exp >= hero.level * 10 && hero.level != 10)
	{
		hero.exp = 0;
		hero.level += 1;
		hero.hp = hero.level * 5 + 15;
		hero.atk = hero.level * 5 + 10;
		hero.mag = hero.level * 5 + 5;
		hero.mp = hero.level * 5 - 5;
		hero.def = hero.level * 5 + 10;
		hero.agility = hero.level * 5 + 1;
		cout << "LEVEL UP! " << hero.name << " increases to " << hero.level << "! " << hero.name << "'s attributes increase!" << endl;
		if (hero.level == 2)
		{
			cout << hero.name << " learned the spell Kafrizz!" << endl;
		}
		else if (hero.level == 3)
		{
			cout << hero.name << " learned the ability Flame slash!" << endl;
		}
		else if (hero.level == 4)
		{
			cout << hero.name << " learned the spell Heal!" << endl;
		}
		else if (hero.level == 5)
		{
			cout << hero.name << " learned the ability Miracle slash!" << endl;
		}
		else if (hero.level == 6)
		{
			cout << hero.name << " learned the spell Buff!" << endl;
		}
		else if (hero.level == 7)
		{
			cout << hero.name << " learned the ability Falcon slash!" << endl;
		}
		else if (hero.level == 8)
		{
			cout << hero.name << " learned the spell Full heal!" << endl;
		}
		else if (hero.level == 9)
		{
			cout << hero.name << " learned the spell Kazap!" << endl;
		}
		else if (hero.level == 10)
		{
			cout << hero.name << " learned the ability Gigaslash!" << endl;
		}
	}
	else if (hero.exp >= 100 && hero.level >= 10)
	{
		hero.exp = 0;
		hero.hp = hero.level * 5 + 15;
		hero.atk = hero.level * 5 + 10;
		hero.mag = hero.level * 5 + 5;
		hero.mp = hero.level * 5 - 5;
		hero.def = hero.level * 5 + 10;
		hero.agility = hero.level * 5 + 1;
	}
}

//stat reset
void statreset()
{
		hero.atk = hero.level * 5 + 10;
		hero.mag = hero.level * 5 + 5;
		hero.def = hero.level * 5 + 10;
		hero.agility = hero.level * 5 + 1;
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
		cout << hero.name << " attacks! miss, the " << enemy.name << " dodges swiftly!" << endl;
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

//function for enemy to attack player, will be expanded upon

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

//functions that describe ability effects

void Flameslash()
{
	printf("\33[1J\r");

	bool ehit;
	enemy.damage = enemy.def - (hero.atk + hero.mag);
	ehit = enemy.damage >= 0;
	enemy.hit = rand() % 2;
	if (hero.mp < 3)
	{
		cout << "you don't have enough mp!" << endl;
	}
	else if (ehit == true && enemy.hit == 0 && hero.mp >= 3)
	{
		cout << hero.name << " slashes with a scorching blade! miss, the " << enemy.name << " dodges swiftly!" << endl;
		hero.mp -= 3;
		hit();
	}
	else if (ehit == true && enemy.hit == 1 && hero.mp >= 3)
	{
		enemy.hp = enemy.hp - enemy.hit;
		cout << hero.name << " slashes with a scorching blade! the " << enemy.name << " takes " << -1 * enemy.hit << " damage" << endl;
		hero.mp -= 3;
		hit();
	}
	else if (ehit == false && hero.mp >= 3)
	{
		enemy.hp = enemy.hp + enemy.damage;
		cout << hero.name << " slashes with a scorching blade! the " << enemy.name << " takes " << enemy.damage << " damage" << endl;
		hero.mp -= 3;
		hit();
	}
}

void Miracleslash()
{
	printf("\33[1J\r");

	bool ehit;
	enemy.damage = enemy.def - hero.atk;
	ehit = enemy.damage >= 0;
	enemy.hit = rand() % 2;
	if (hero.mp < 4)
	{
		cout << "you don't have enough mp!" << endl;
	}
	else if (ehit == true && enemy.hit == 0 && hero.mp >= 4)
	{
		cout << hero.name << " slashes with a holy blade! miss, the " << enemy.name << " dodges swiftly!" << endl;
		hero.mp -= 4;
		hit();
	}
	else if (ehit == true && enemy.hit == 1 && hero.mp >= 4)
	{
		enemy.hp = enemy.hp - enemy.hit;
		cout << hero.name << " slashes with a holy blade! the " << enemy.name << " takes " << -1 * enemy.hit << " damage" << endl;
		hero.mp -= 4;
		hit();
	}
	else if (ehit == false && hero.mp >= 4)
	{
		enemy.hp = enemy.hp + enemy.damage;
		cout << hero.name << " slashes with a holy blade! the " << enemy.name << " takes " << enemy.damage << " damage" << endl;
		hero.hp += -1 * enemy.damage;
		hero.mp -= 4;
		if (hero.hp >= hero.level * 5 + 15)
		{
			hero.hp = hero.level * 5 + 15;
			cout << hero.name << " fully recovers!" << endl;
			hit();
		}
		else
		{
			cout << hero.name << " recovers " << -1 * enemy.damage << " hp!" << endl;
			hit();
		}
	}
}

void Falconslash()
{
	printf("\33[1J\r");

	bool ehit;
	enemy.damage = enemy.def - 2 * hero.atk;
	ehit = enemy.damage >= 0;
	enemy.hit = rand() % 2;
	if (hero.mp < 6)
	{
		cout << "you don't have enough mp!" << endl;
	}
	else if (ehit == true && enemy.hit == 0 && hero.mp >= 6)
	{
		cout << hero.name << " slashes with with the speed and ferocity of a falcon! miss, the " << enemy.name << " dodges swiftly!" << endl;
		hero.mp -= 6;
		hit();
	}
	else if (ehit == true && enemy.hit == 1 && hero.mp >= 6)
	{
		enemy.hp = enemy.hp - enemy.hit;
		cout << hero.name << " slashes with the speed and ferocity of a falcon! the " << enemy.name << " takes " << -1 * enemy.hit << " damage" << endl;
		hero.mp -= 6;
		hit();
	}
	else if (ehit == false && hero.mp >= 6)
	{
		enemy.hp = enemy.hp + enemy.damage;
		cout << hero.name << " slashes with the speed and ferocity of a falcon! the " << enemy.name << " takes " << enemy.damage << " damage" << endl;
		hero.mp -= 6;
		hit();
	}
}

void Gigabreak()
{
	printf("\33[1J\r");

	bool ehit;
	enemy.damage = -2 * (hero.atk + hero.mag);
	ehit = enemy.damage >= 0;
	if (hero.mp < 10)
	{
		cout << "you don't have enough mp!" << endl;
	}

	else if (ehit == false && hero.mp >= 10)
	{
		enemy.hp = enemy.hp + enemy.damage;
		cout << hero.name << " smites the " << enemy.name << " with a saber of holy lightning!the " << enemy.name << " takes " << enemy.damage << " damage" << endl;
		hero.mp -= 10;
		hit();
	}
}

//prints abilities if player has learned any

void displayAbilities()
{
	string abilities[11];
	abilities[3] = "flame slash";
	abilities[5] = "miracle slash";
	abilities[7] = "falcon slash";
	abilities[10] = "gigabreak";


	if (hero.level < 3)
	{
		cout << "no abilities learned yet!" << endl;
	}

	else if (hero.level >= 3)
	{
		for (int i = 0; i <= hero.level; i++)
		{
			cout << i << "\t" << abilities[i] << endl;
		}
		cout << "please enter a number" << endl;
		cin >> hero.ability;
	}

	if (hero.ability != 0)
	{
		switch (hero.ability)
		{
		case 1:
			cout << "that's not an ability!" << endl;
			break;
		case 2:
			cout << "that's not an ability!" << endl;
			break;
		case 3:
			Flameslash();
			break;
		case 4:
			cout << "that's not an ability!" << endl;
			break;
		case 5:
			Miracleslash();
			break;
		case 6:
			cout << "that's not an ability!" << endl;
			break;
		case 7:
			Falconslash();
			break;
		case 8:
			cout << "that's not an ability!" << endl;
			break;
		case 9:
			cout << "that's not an ability!" << endl;
			break;
		case 10:
			Gigabreak();
			break;
		}
	}
}

//functions that describe spell effects

void Kafrizz()
{
	printf("\33[1J\r");

	if (hero.level >= 2 && hero.mp < 2)
	{
		cout << "you don't have enough mp!" << endl;
	}
	else if (hero.level >= 2 && hero.mp >= 2)
	{
		enemy.hp = enemy.hp - hero.mag;
		cout << hero.name << " launches a blazing fire ball! the " << enemy.name << " takes " << -1 * hero.mag << " damage" << endl;
		hero.mp -= 2;
		hit();
	}

	else
	{
		cout << "that's not a spell!" << endl;
	}
}

void Heal()
{
	printf("\33[1J\r");

	if (hero.level >= 4 && hero.mp < 3)
	{
		cout << "you don't have enough mp!" << endl;
	}
	else if (hero.level >= 4 && hero.mp >= 3)
	{
		hero.hp += 25;
		if (hero.hp >= hero.level * 5 + 15)
		{
			hero.hp = hero.level * 5 + 15;
			cout << hero.name << " fully recovers!" << endl;
			hero.mp -= 3;
			hit();
		}
		else
		{
			hero.mp -= 3;
			cout << hero.name << " recovers 25 hp!" << endl;
			hit();
		}
	}

	else
	{
		cout << "that's not a spell!" << endl;
	}
}

void Buff()
{
	printf("\33[1J\r");

	if (hero.level >= 6 && hero.mp < 6)
	{
		cout << "you don't have enough mp!" << endl;
	}
	else if (hero.level >= 6 && hero.mp >= 6)
	{
		hero.def += .5 * hero.def;
		if (hero.def >= 100)
		{
			hero.mp -= 6;
			hero.def = 50;
			cout << hero.name << " buffs up to the max!" << endl;
			hit();
		}
		else
		{
			hero.mp -= 6;
			cout << hero.name << " buffs up by " << .5 * hero.def << " points!" << endl;
			hit();
		}
	}
	else
	{
		cout << "that's not a spell!" << endl;
	}
}

void Fullheal()
{
	printf("\33[1J\r");
	if (hero.level >= 8 && hero.mp < 8)
	{
		cout << "you don't have enough mp!" << endl;
	}
	else if (hero.level >= 8 && hero.mp >= 8)
	{
			hero.mp -= 8;
			hero.hp = hero.level * 5 + 15;
			cout << hero.name << " fully recovers!" << endl;
			hit();
	}

	else
	{
		cout << "that's not a spell!" << endl;
	}
}

void Kazap()
{
	printf("\33[1J\r");

	if (hero.level >= 9 && hero.mp < 12)
	{
		cout << "you don't have enough mp!" << endl;
	}
	if (hero.level >= 9 && hero.mp >= 12)
	{
		hero.mp -= 12;
		enemy.hp = enemy.hp - 2 * hero.mag;
		cout << hero.name << " calls forth bolts of holy lightning! the " << enemy.name << " takes " << -2 * hero.mag << " damage" << endl;
		hit();
	}

	else
	{
		cout << "that's not a spell!" << endl;
	}
}

//prints spells if the player has learned any

void displaySpells()
{
	string spells[10];
	spells[2] = "kafrizz";
	spells[4] = "heal";
	spells[6] = "buff";
	spells[8] = "full heal";
	spells[9] = "kazap";

	if (hero.level < 2)
	{
		cout << "no spells learned yet!" << endl;
	}

	else if (hero.level >= 2)
	{
		for (int i = 0; i <= hero.level; i++)
		{
			cout << i << "\t" << spells[i] << endl;
		}
		cout << "please enter a number" << endl;
		cin >> hero.spell;
	}

	if (hero.spell != 0)
	{
		switch (hero.spell)
		{
		case 1:
			cout << "that's not a spell!" << endl;
			break;
		case 2:
			Kafrizz();
			break;
		case 3:
			cout << "that's not a spell!" << endl;
			break;
		case 4:
			Heal();
			break;
		case 5:
			cout << "that's not a spell!" << endl;
			break;
		case 6:
			Buff();
			break;
		case 7:
			cout << "that's not a spell!" << endl;
			break;
		case 8:
			Fullheal();
			break;
		case 9:
			Kazap();
			break;
		}
	}
}

//function for random encounters allowing players to face different enemies as they progress

void monster()
{
	srand(time(0));
	enemy.roll = 1 + rand() % 5;
	if (hero.level <= 3)
	{
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
			enemy.exp = 4;
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
			enemy.exp = 5;
			enemy.gold = 5;
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
			enemy.exp = 6;
			enemy.gold = 6;
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
			enemy.exp = 5;
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
			enemy.exp = 4;
			enemy.gold = 4;
			enemy.roll = 0;
			enemy.name = "Cruelcumber";
			break;
		}
	}
	else if (hero.level >= 4 && hero.level <= 7)
	{
		switch (enemy.roll)
		{
		case 1:
			enemy.level = 1;
			enemy.hp = 30;
			enemy.atk = 40;
			enemy.mag = 0;
			enemy.mp = 0;
			enemy.def = 25;
			enemy.agility = 8;
			enemy.damage = 0;
			enemy.exp = 20;
			enemy.gold = 20;
			enemy.roll = 0;
			enemy.name = "Restless Armour";
			break;
		case 2:
			enemy.level = 1;
			enemy.hp = 50;
			enemy.atk = 40;
			enemy.mag = 0;
			enemy.mp = 0;
			enemy.def = 15;
			enemy.agility = 12;
			enemy.damage = 0;
			enemy.exp = 23;
			enemy.gold = 23;
			enemy.roll = 0;
			enemy.name = "Great Sabrecat";
			break;
		case 3:
			enemy.level = 1;
			enemy.hp = 40;
			enemy.atk = 30;
			enemy.mag = 0;
			enemy.mp = 0;
			enemy.def = 10;
			enemy.agility = 10;
			enemy.damage = 0;
			enemy.exp = 15;
			enemy.gold = 15;
			enemy.roll = 0;
			enemy.name = "Gryphon";
			break;
		case 4:
			enemy.level = 1;
			enemy.hp = 70;
			enemy.atk = 50;
			enemy.mag = 0;
			enemy.mp = 0;
			enemy.def = 30;
			enemy.agility = 6;
			enemy.damage = 0;
			enemy.exp = 25;
			enemy.gold = 25;
			enemy.roll = 0;
			enemy.name = "Block man";
			break;
		case 5:
			enemy.level = 1;
			enemy.hp = 20;
			enemy.atk = 30;
			enemy.mag = 0;
			enemy.mp = 0;
			enemy.def = 20;
			enemy.agility = 20;
			enemy.damage = 0;
			enemy.exp = 12;
			enemy.gold = 12;
			enemy.roll = 0;
			enemy.name = "Shadow";
			break;
		}
	}
	else if (hero.level >= 8)
	{
	switch (enemy.roll)
	{
	case 1:
		enemy.level = 1;
		enemy.hp = 100;
		enemy.atk = 75;
		enemy.mag = 0;
		enemy.mp = 0;
		enemy.def = 50;
		enemy.agility = 20;
		enemy.damage = 0;
		enemy.exp = 40;
		enemy.gold = 40;
		enemy.roll = 0;
		enemy.name = "Dragon";
		break;
	case 2:
		enemy.level = 1;
		enemy.hp = 75;
		enemy.atk = 50;
		enemy.mag = 0;
		enemy.mp = 0;
		enemy.def = 35;
		enemy.agility = 40;
		enemy.damage = 0;
		enemy.exp = 35;
		enemy.gold = 35;
		enemy.roll = 0;
		enemy.name = "Malroth";
		break;
	case 3:
		enemy.level = 1;
		enemy.hp = 90;
		enemy.atk = 45;
		enemy.mag = 0;
		enemy.mp = 0;
		enemy.def = 30;
		enemy.agility = 30;
		enemy.damage = 0;
		enemy.exp = 30;
		enemy.gold = 30;
		enemy.roll = 0;
		enemy.name = "Baramos";
		break;
	case 4:
		enemy.level = 1;
		enemy.hp = 80;
		enemy.atk = 35;
		enemy.mag = 0;
		enemy.mp = 0;
		enemy.def = 30;
		enemy.agility = 6;
		enemy.damage = 0;
		enemy.exp = 45;
		enemy.gold = 45;
		enemy.roll = 0;
		enemy.name = "Mordegon";
		break;
	case 5:
		enemy.level = 1;
		enemy.hp = 160;
		enemy.atk = 80;
		enemy.mag = 0;
		enemy.mp = 0;
		enemy.def = 60;
		enemy.agility = 10;
		enemy.damage = 0;
		enemy.exp = 50;
		enemy.gold = 50;
		enemy.roll = 0;
		enemy.name = "Calasmos";
		break;
	}
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

//function for defending action

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
		levelup();
		cout << "the " << enemy.name << " drops " << enemy.gold << " gold" << endl;
		cout << endl;
		statreset();
		cout << "would you like to fight another enemy y/n?" << endl;
		cin >> hero.engage;
	}

	else if (hero.hp <= 0)
	{
		cout << hero.name << " dies!" << endl;
		hero.gold = hero.gold * .5;
		hero.hp = hero.level * 5 + 15;
		hero.mp = hero.level * 5;
		cout << "would you like to fight another enemy y/n?" << endl;
		cin >> hero.engage;
	}
	
}


//function to describe structure of battles


void fightstruct()
{
	hero.engage = 'y';
	while (hero.engage == 'y')
	{
		printf("\33[1J\r");
		monster();
		cout << "a " << enemy.name << " draws near! do you want to engage y / n ? " << endl;
		cin >> hero.engage;
		while (enemy.hp >= 1 && hero.hp >= 1 && hero.flee != 1 && hero.engage == 'y')
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
				displaySpells();
				break;
			case 3:
				dhit();
				break;
			case 4:
				displayAbilities();
				break;
			case 5:
				//placeholder
				cout << hero.name << " doesn't have any items!" << endl;
				break;
			case 6:
				flee();
				break;
			}
		}
		conclusion();
	} 
	if (hero.engage != 'y')
	{
		exit;
	}
}



int main()
{

	


	tutorial();
	fightstruct();


	
	
}
