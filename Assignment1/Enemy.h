#pragma once
#include <string>
#include "GameObject.h"


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