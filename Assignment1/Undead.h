#pragma once
#include <iostream>
#include "Enemy.h"

using namespace std;

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
        cout << "BRAINS!" << endl;
    }
};
string Undead::SpeciesName = "Undead";
