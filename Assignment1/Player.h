#pragma once
#include <string>
#include "GameObject.h"

using namespace std;

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