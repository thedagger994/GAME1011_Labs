#pragma once
#include <iostream>
#include "Enemy.h"

using namespace std;

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