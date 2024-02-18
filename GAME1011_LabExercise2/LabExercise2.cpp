#include <iostream>
#include <string>

using namespace std;

class Weapon
{
private:
    string epicWeaponName;
    int damageValue;
    string* specialAbilities; 
    int numAbilities; 

public:
    Weapon (string name, int damage, string abilities[], int num)
        : epicWeaponName (name), damageValue (damage), numAbilities (num)
    {
        specialAbilities = new string[numAbilities]; 
        for (int i = 0; i < numAbilities; ++i)
            specialAbilities[i] = abilities[i];
    }

    ~Weapon ()
    { 
        delete[] specialAbilities; 
    }

    Weapon (const Weapon& other)
        : epicWeaponName (other.epicWeaponName), damageValue (other.damageValue), numAbilities (other.numAbilities)
    {
        specialAbilities = new string[numAbilities];
        for (int i = 0; i < numAbilities; ++i)
            specialAbilities[i] = other.specialAbilities[i];
    }

    Weapon& operator=(const Weapon& other)
    {
        if (this != &other)
        {
            epicWeaponName = other.epicWeaponName;
            damageValue = other.damageValue;
            numAbilities = other.numAbilities;
            delete[] specialAbilities; 
            specialAbilities = new string[numAbilities];
            for (int i = 0; i < numAbilities; ++i)
                specialAbilities[i] = other.specialAbilities[i];
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Weapon& weapon)
    {
        os << "Name: " << weapon.epicWeaponName << endl << "Damage: " << weapon.damageValue << endl;
        os << "Special Abilities:" << endl;
        for (int i = 0; i < weapon.numAbilities; ++i)
            os << "- " << weapon.specialAbilities[i] << endl;
        return os;
    }

    bool operator==(const Weapon& other) const
    {
        return (epicWeaponName == other.epicWeaponName && damageValue == other.damageValue);
    }
};

class Armour
{
private:
    string epicArmourName;
    string description;
    int armourValue;

public:
    Armour (string name, string desc, int value)
        : epicArmourName (name), description (desc), armourValue (value)
    {
    }

    friend ostream& operator<<(ostream& os, const Armour& armour)
    {
        os << "Name: " << armour.epicArmourName << endl << "Description: " << armour.description << endl << "Armour Value: " << armour.armourValue << endl;
        return os;
    }

    bool operator==(const Armour& other) const
    {
        return (epicArmourName == other.epicArmourName && description == other.description && armourValue == other.armourValue);
    }
};

class Character
{
private:
    string name;
    string species;
    string epicBackstory;
    int startingHealth;
    Weapon* weapon;
    Armour* armour;

public:
    Character () {}

    Character (string n, string s, string eb, int sh, Weapon* w, Armour* a)
        : name (n), species (s), epicBackstory (eb), startingHealth (sh), weapon (w), armour (a)
    {
    }

    void displayInfo ()
    {
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Epic Backstory: " << epicBackstory << endl;
        cout << "Health: " << startingHealth << endl << endl;
        cout << "Weapon: " << (*weapon) << endl << endl;
        cout << "Armour: " << (*armour) << endl;
    }

    bool operator==(const Character& other) const
    {
        return (name == other.name && species == other.species);
    }
};

int main ()
{
    cout << "Welcome to Character Customizer!" << endl;

    Character characters[3];

    // A set of default weapon ablility arrays
    string swordAbilities[] = { "Slash", "Thrust", "Parry" };
    string axeAbilities[] = { "Cleave", "Crush", "Chop" };
    string bowAbilities[] = { "Shoot", "Pierce", "Aim" };

    // A set of default weapons
    Weapon weapons[] = {
        Weapon ("Sword", 10, swordAbilities, 3),
        Weapon ("Axe", 12, axeAbilities, 3),
        Weapon ("Bow", 8, bowAbilities, 3)
    };

    // A set of default armours
    Armour armours[3] = {
        Armour ("Iron Armor", "Basic armor for protection", 20),
        Armour ("Leather Armor", "Lightweight armor for agility", 15),
        Armour ("Plate Armor", "Heavy armor for defense", 25)
    };

    // Create 3 characters
    for (int i = 0; i < 3; ++i)
    {
        cout << "\nCreating Character " << i + 1 << endl;
        string name, species, epicBackstory;
        int startingHealth;
        int weaponChoice, armourChoice;

        cout << "Enter character name: ";
        cin >> name;
        cout << "Enter species: ";
        cin >> species;
        cout << "Enter epic backstory: ";
        cin >> epicBackstory;
        cout << "Enter starting health value: ";
        cin >> startingHealth;

        cout << "\nAvailable Weapons:" << endl;
        for (int j = 0; j < 3; ++j)
        {
            cout << j + 1 << ". " << weapons[j] << endl;
        }
        cout << "Select starting weapon (1-3): ";
        cin >> weaponChoice;
        weaponChoice--;

        cout << "\nAvailable Armours:" << endl;
        for (int j = 0; j < 3; ++j)
        {
            cout << j + 1 << ". " << armours[j] << endl;
        }
        cout << "Select starting armour (1-3): ";
        cin >> armourChoice;
        armourChoice--;

        characters[i] = Character (name, species, epicBackstory, startingHealth, &weapons[weaponChoice], &armours[armourChoice]);

        cout << "Character " << name << " created!" << endl;
    }

    for (int i = 0; i < 3; ++i)
    {
        cout << "\nCharacter " << i + 1 << " Information:" << endl;
        characters[i].displayInfo ();
    }

    int char1, char2;
    cout << "\nEnter character numbers to compare stats (1-3): ";
    cin >> char1 >> char2;
    if (char1 >= 1 && char1 <= 3 && char2 >= 1 && char2 <= 3)
    {
        if (characters[char1 - 1] == characters[char2 - 1])
        {
            cout << "Characters are the same." << endl;
        }
        else
        {
            cout << "Characters are different." << endl;
        }
    }
    else
    {
        cout << "Invalid character numbers." << endl;
    }

    return 0;
}