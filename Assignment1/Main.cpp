#include <iostream>
#include <string>
#include "Knight.h"
#include "Wizard.h"
#include "Orc.h"
#include "Undead.h"

using namespace std;

int main ()
{
    string type;
    string Name;
    int Health;
    cout << "Hello Player Welcome to the game!" << endl;
    cout << "Would you like to play as a Wizard or Knight?" << endl;
    cout << "   Enter 'Wizard' or 'Knight' to continue" << endl;
    cin >> type;
    srand (static_cast<int>(time (NULL)));
    int randNumber = rand () % 10;

    if (type == "Wizard" && randNumber > 5)
    {
        Player* Hero1 = new Wizard;
        Enemy* Enemy1 = new Undead;
        cout << "What is your name?" << endl;
        cin >> Name;
        cout << "What is your health?" << endl;
        cin >> Health;
        Hero1->setName (Name);
        Hero1->setHealth (Health);
        cout << "Wizard!" << endl;
        cout << "Player name: " << Hero1->getName () << endl;
        cout << "Player health: " << Health << endl;
        cout << "Are you ready to witness a great Battle?" << endl;
        Enemy1->TauntPlayer ();
        Hero1->NormalAttack ();
        Enemy1->TauntPlayer ();
        Hero1->SpecialAttack ();
        cout << Wizard::SpecialAttackName << endl;
        Enemy1->NormalAttack ();
        Enemy1->NormalAttack ();
        Hero1->SpecialAttack ();
        cout << Wizard::SpecialAttackName << endl;
        Enemy1->TauntPlayer ();
        Hero1->SpecialAttack ();
        cout << Wizard::SpecialAttackName << endl;
        cout << Undead::SpeciesName << " Has died!! " << endl;
        cout << "Hero " << Hero1->getName () << " has won! " << endl;
    }
    else if (type == "Knight" && randNumber <= 5)
    {
        Player* Hero1 = new Knight;
        Enemy* Enemy1 = new Undead;
        cout << "What is your name?" << endl;
        cin >> Name;
        cout << "What is your health?" << endl;
        cin >> Health;
        Hero1->setName (Name);
        Hero1->setHealth (Health);
        cout << "Knight!" << endl;
        cout << "Player name: " << Hero1->getName () << endl;
        cout << "Player health: " << Health << endl;
        cout << "Are you ready to witness a great Battle?" << endl;
        Enemy1->TauntPlayer ();
        Hero1->NormalAttack ();
        Enemy1->TauntPlayer ();
        Hero1->SpecialAttack ();
        cout << Knight::SpecialAttackName << endl;
        Enemy1->NormalAttack ();
        Enemy1->NormalAttack ();
        Hero1->SpecialAttack ();
        cout << Knight::SpecialAttackName << endl;
        Enemy1->TauntPlayer ();
        Hero1->SpecialAttack ();
        cout << Knight::SpecialAttackName << endl;
        cout << Undead::SpeciesName << " Has died!! " << endl;
        cout << "Hero " << Hero1->getName () << " has won! " << endl;
    }
    else if (type == "Wizard" && randNumber <= 5)
    {
        Player* Hero1 = new Wizard;
        Enemy* Enemy1 = new Orc;
        cout << "What is your name?" << endl;
        cin >> Name;
        cout << "What is your health?" << endl;
        cin >> Health;
        Hero1->setName (Name);
        Hero1->setHealth (Health);
        cout << "Player Type: " << type << endl;
        cout << "Player name: " << Hero1->getName () << endl;
        cout << "Player health: " << Health << endl;
        cout << "Are you ready to witness a great Battle?" << endl;
        Enemy1->TauntPlayer ();
        Hero1->NormalAttack ();
        Enemy1->TauntPlayer ();
        Hero1->SpecialAttack ();
        cout << Wizard::SpecialAttackName << endl;
        Enemy1->NormalAttack ();
        Enemy1->NormalAttack ();
        Hero1->SpecialAttack ();
        cout << Wizard::SpecialAttackName << endl;
        Enemy1->TauntPlayer ();
        Hero1->SpecialAttack ();
        cout << Wizard::SpecialAttackName << endl;
        cout << Undead::SpeciesName << " Has died!! " << endl;
        cout << "Hero " << Hero1->getName () << " has won! " << endl;
    }
    else if (type == "Knight" && randNumber > 5)
    {
        Player* Hero1 = new Knight;
        Enemy* Enemy1 = new Orc;
        cout << "What is your name?" << endl;
        cin >> Name;
        cout << "What is your health?" << endl;
        cin >> Health;
        Hero1->setName (Name);
        Hero1->setHealth (Health);
        cout << "Player Type: " << type << endl;
        cout << "Player name: " << Hero1->getName () << endl;
        cout << "Player health: " << Health << endl;
        cout << "Are you ready to witness a great Battle?" << endl;
        Enemy1->TauntPlayer ();
        Hero1->NormalAttack ();
        Enemy1->TauntPlayer ();
        Hero1->SpecialAttack ();
        cout << Knight::SpecialAttackName << endl;
        Enemy1->NormalAttack ();
        Enemy1->NormalAttack ();
        Hero1->SpecialAttack ();
        cout << Knight::SpecialAttackName << endl;
        Enemy1->TauntPlayer ();
        Hero1->SpecialAttack ();
        cout << Knight::SpecialAttackName << endl;
        cout << Undead::SpeciesName << " Has died!! " << endl;
        cout << "Hero " << Hero1->getName () << " has won! " << endl;
    }
    return 0;
}
