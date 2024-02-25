#include <iostream>
#include <string>

using namespace std;

class GameObject
{
public:
    virtual void NormalAttack () = 0;
};

class Player : public GameObject
{
protected:
    string Name;
    int Health;

public:
    virtual void SpecialAttack () = 0;
    
    string getName () const
    {
        return Name;
    }
    void setName (const string& name)
    {
        Name = name;
    }

    int getHealth () const
    {
        return Health;
    }
    void setHealth (int health)
    {
        Health = health;
    }
};

class Enemy : public GameObject
{
protected:
    int Health;

public:
    virtual void TauntPlayer () = 0;
   
    int getHealth () const
    {
        return Health;
    }
    void setHealth (int health)
    {
        Health = health;
    }
};

class Wizard : public Player
{
public:
    static string SpecialAttackName;
    int SpecialAttackAmount;

    void NormalAttack () override
    {
        cout << "Wizard flails his wand." << endl;
    }

    void SpecialAttack () override
    {
        cout << "Wizard casts his spell!" << endl;
    }
};
string Wizard::SpecialAttackName = "Fireball"; 

class Knight : public Player
{
public:
    static string SpecialAttackName;
    int SpecialAttackAmount;

    void NormalAttack () override
    {
        cout << "Knight swung his sword." << endl;
    }

    void SpecialAttack () override
    {
        cout << "Knight charges at enemy!" << endl;
    }
};
string Knight::SpecialAttackName = "Charge"; 

class Orc : public Enemy
{
public:
    static string SpeciesName;
    string Taunts[3];

    void NormalAttack () override
    {
        cout << "Orc hammered its fist on the ground." << endl;
    }

    void TauntPlayer () override
    {
        cout << "Orc roared in rage!" << endl;
    }
};
string Orc::SpeciesName = "Orc"; 

class Undead : public Enemy
{
public:
    static string SpeciesName;
    string Taunts[3];

    void NormalAttack () override
    {
        cout << "Zombie bit the player." << endl;
    }

    void TauntPlayer () override
    {
        cout << "BRAINS!"<< endl;
    }
};
string Undead::SpeciesName = "Undead"; 

int main ()
{
    return 0;
}
