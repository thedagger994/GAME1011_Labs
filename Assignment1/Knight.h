#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

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