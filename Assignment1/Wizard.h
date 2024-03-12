#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

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