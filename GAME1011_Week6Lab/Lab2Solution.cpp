#include <iostream>
#include <string>
#include <array>
using namespace std;

struct Weapon;
struct Armour;
struct Character
{
	string name;
	string species = "Human";
	string story;
	float maxHealth = 100.0f;
	Weapon* weapon;
	Armour* armour;
};

struct Weapon
{
	string name;
	array<string, 2> abilities { "Melee", "Spell" };
	float damage = 25.0f;
};

struct Armour
{
	string name;
	float durability = 50.0f;
	string description;
};

ostream& operator<<(ostream& out, const Weapon& weapon)
{
	out << "Weapon name: " << weapon.name << endl;
	out << "Weapon damage: " << weapon.damage << endl;
	out << "Weapon abilities: ";
	for (const string& ability : weapon.abilities)
		out << ability << ", ";
	out << endl;
	return out;
}

ostream& operator<<(ostream& out, const Armour& armour)
{
	out << "Armour name: " << armour.name << endl;
	out << "Armour durability: " << armour.durability << endl;
	out << "Armour description: " << armour.description << endl;
	return out;
}

bool operator==(const Weapon& a, const Weapon& b)
{
	return a.damage == b.damage;
}

bool operator==(const Armour& a, const Armour& b)
{
	return a.durability == b.durability;
}

bool operator>(const Character& a, const Character& b)
{
	return a.maxHealth > b.maxHealth;
}

int main ()
{
	array<Weapon, 2> weapons;
	weapons[0].name = "Excalibur";
	weapons[0].damage = 1000.0f;
	weapons[1].name = "Silver Sword";
	weapons[1].damage = 200.0f;

	array<Armour, 2> armours;
	armours[0].name = "Leviathan";
	armours[0].description = "Hide of the Sea Monster";
	armours[0].durability = 1000.0f;
	armours[1].name = "Scales";
	armours[1].description = "Scales from the Mythical Dragon";
	armours[1].durability = 200.0f;

	size_t characterCount = 0;
	Character* characters;
	cout << "Welcome to character creation. Please enter the number of characters to create. (Max 3)" << endl;
	cin >> characterCount;

	characters = new Character[characterCount];
	for (size_t i = 0; i < characterCount; i++)
	{
		Character& character = characters[i];
		cout << "What is the name of your character?" << endl;
		cin >> character.name;
		cout << "How much health does " << character.name << " have?" << endl;
		cin >> character.maxHealth;

		cout << "Weapon Selection: " << endl;
		for (size_t weaponIndex = 0; weaponIndex < weapons.size (); weaponIndex++)
		{
			cout << "Press " << weaponIndex + 1 << " for " << weapons[weaponIndex].name << endl;
		}
		size_t weaponIndex = 0;
		cin >> weaponIndex;

		cout << "Armour Selection: " << endl;
		for (size_t armourIndex = 0; armourIndex < armours.size (); armourIndex++)
		{
			cout << "Press " << armourIndex + 1 << " for " << armours[armourIndex].name << endl;
		}
		size_t armourIndex = 0;
		cin >> armourIndex;

		character.weapon = &weapons[weaponIndex - 1];
		character.armour = &armours[armourIndex - 1];

		cout << character.name << " complete: " << endl << *character.weapon << endl << *character.armour << endl;
	}

	size_t strongestIndex = 0;

	for (size_t i = 0; i < characterCount; i++)
	{
		if (characters[i] > characters[strongestIndex])
			strongestIndex = i;
	}

	cout << characters[strongestIndex].name << " is the strongest of them all!";
	delete[] characters;

	return 0;
}