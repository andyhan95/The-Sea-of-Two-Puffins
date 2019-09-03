#include "player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int determinePlayerClass();
void ambush(Player protagonist, string enemyName, int enemyHealth, int enemyDifficulty);

int main()
{
    srand((int)time(0)); // Testing!

    string playerName;
    int classIndex, initAttack, initDefense, initHealth;

    cout << "\n**************************************\n*****   The Sea of Two Puffins   *****\n*****         By Andy Han        *****\n**************************************\n\n";
    cout << "Brave warrior, what is your name?:\n";

    getline(cin, playerName);

    classIndex = determinePlayerClass();

    if(classIndex == 0)
    {
        initAttack = 4;
        initDefense = 2;
        initHealth = 100;
    }
    else if(classIndex == 1)
    {
        initAttack = 3;
        initDefense = 3;
        initHealth = 150;
    }
    else
    {
        initAttack = 2;
        initDefense = 4;
        initHealth = 100;
    }

    cout << "\nStoring player data...\n\n\n\n";

    Player protagonist(playerName, classIndex, 1000, initHealth, initAttack, initDefense);

    cout << "Welcome, " << protagonist.get_name() << ", to the Kingdom of Puffino, ruled by Elder Finpu.\n";
    cout << "Things are normally quaint and peaceful around here. But recently, a gang of seagulls has been causing quite some trouble.\n";
    cout << "It is up to you to defeat these seagulls and figure out why they are here.\n";
    cout << "\nOh goodness! A seagull suddenly approaches from behind!\n";

    ambush(protagonist, "SEAGULL JOE", 100, 1);

    return 0;
}

int determinePlayerClass()
{
    int index;
    string input;
    bool valid;
    do
    {
        cout << "\nWhat kind of warrior are you?\n";
        cout << "   Swordsman: capable of some potent attacks but not very resilient.\n";
        cout << "   Archer: balanced and broadly competent.\n";
        cout << "   Mage: not particularly powerful but magically robust.\n";
        cout << "\nSwordsman, archer, or mage?\n";
        getline(cin, input);
        if(input == "swordsman" || input == "Swordsman" || input == "s" || input == "S")
        {
            index = 0;
            valid = true;
        }
        else if(input == "archer" || input == "Archer" || input == "a" || input == "A")
        {
            index = 1;
            valid = true;
        }
        else if(input == "mage" || input == "Mage" || input == "m" || input == "M")
        {
            index = 2;
            valid = true;
        }
        else
        {
            cout << "\nWhat was that? Please, quit fooling around and tell me.\n";
            valid = false;
        }
    }
    while (valid == false);
    return index;
}

void ambush(Player protagonist, string enemyName, int enemyHealth, int enemyDifficulty)
{
    int enemyDamage, playerDamage, hitFactor;
    string input;
    cout << "\n* B A T T L E   S T A R T *\n";
    enemyDamage = rand() % 10 * enemyDifficulty + 1;
    cout << enemyName << " attacks first and deals " << enemyDamage << " damage.\n";
    protagonist.set_hp(protagonist.get_hp() - enemyDamage);
    cout << "You now have " << protagonist.get_hp() << " hp.\n";
    cout << "Would you like to slash (s), lance (l), or obliterate (o)?\n";
    getline(cin, input);
    if(input == "s")
    {
        hitFactor = rand() % 10 + 1;
        if(hitFactor <= 6)
        {
            playerDamage = 2 * protagonist.get_attack() * (rand() % 4 + 1);
        }
        else
        {
            playerDamage = 0;
        }
    }
    else if(input == "l")
    {
        hitFactor = rand() % 10 + 1;
        if(hitFactor <= 9)
        {
            playerDamage = protagonist.get_attack() * (rand() % 3 + 1);
        }
        else
        {
            playerDamage = 0;
        }
    }
    else if(input == "o")
    {
        hitFactor = rand() % 10 + 1;
        if(hitFactor <= 1)
        {
            playerDamage = 4 * protagonist.get_attack() * (rand() % 5 + 1);
        }
        else
        {
            playerDamage = 0;
        }
    }
    else
    {
        playerDamage = 0;
        enemyDamage = rand() % 6 + 1;
        cout << "You attempt a nonexistent attack and make a fool of yourself!\n";
    }
    enemyHealth -= playerDamage;
    cout << enemyName << " now has " << enemyHealth << " hp remaining.\n"; // Make all of this a loop
}