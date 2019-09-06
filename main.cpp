#include "player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int determinePlayerClass();
void battle(Player &protagonist, string enemyName, int enemyHealth, int enemyDifficulty, int initHealth, int ambush);
int attack(Player &protagonist, string enemyName, int origHealth, int initHealth);
void intermission(Player &protagonist, int initHealth);

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
        initHealth = 120;
    }
    else if(classIndex == 1)
    {
        initAttack = 3;
        initDefense = 3;
        initHealth = 160;
    }
    else
    {
        initAttack = 2;
        initDefense = 4;
        initHealth = 120;
    }

    cout << "\nStoring player data...\n\n\n\n";

    Player protagonist(playerName, classIndex, 10, initHealth, initAttack, initDefense);

    /*cout << "Welcome, " << protagonist.get_name() << ", to the Kingdom of Puffino, ruled by Elder Finpu.\n";
    cout << "Things are normally quaint and peaceful around here. But recently, a gang of seagulls has been causing quite some trouble.\n";
    cout << "It is up to you to defeat these seagulls and figure out why they are here.\n";
    cout << "\nAs a " << protagonist.get_class() << ", you can select from three basic moves.\n";

    if(protagonist.get_class() == "swordsman")
    {
        cout << "You can slash: this will deal decent damage, but it is not super accurate.\n";
        cout << "Or, you can lance: this move is a little weaker, but you will rarely miss.\n";
        cout << "If you're daring, you can obliterate: it is a very potent attack but you will likely miss.\n";
    }
    else if(protagonist.get_class() == "archer")
    {
        cout << "You can fire: this is your standard attack.\n";
        cout << "Or, you can sharpshoot: you will never miss.\n";
        cout << "You can also megarush: you only have a 50% chance of succeeding, but it is a powerful attack.\n";
    }
    else
    {
        cout << "You can sadden: this will always reduce your opponent's hp by 10% of its full health.\n";
        cout << "Or, you can anger: this might fail, but you could do reduce your opponent's hp by 25% of its full health.\n";
        cout << "You can focus: this will probably heal you by 25%. But it might instead heal your opponent by 10%.\n";
    }
    cout << "In addition, you could also...\n\nOh goodness! Pardon the interruption, but a seagull suddenly approaches from behind!\n";

    battle(protagonist, "SEAGULL JOE", 100, 1, initHealth, 1);

    cout << "Your attack stat went from " << protagonist.get_attack() << " to ";
    protagonist.set_attack(protagonist.get_attack() + 1);
    cout << protagonist.get_attack() << " and your defense stat went from " << protagonist.get_defense() << " to ";
    protagonist.set_defense(protagonist.get_defense() + 1);
    cout << protagonist.get_defense() << "! Well done.\n";

    cout << "\nThat was quite the surprise occurance... SEAGULL JOE scurries away badly injured. It is hard to tell what SEAGULL JOE wanted from you but alas.\n";
    cout << "Anyway, there will always be an intermission between battles and story moments. During intermission, you could shop or rest up!\n";*/

    // EVENTUALLY MAKE AN INVENTORY CLASS

    intermission(protagonist, initHealth);

    // THE NEXT PART OF THE STORY CONTINUES HERE!

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
        cout << "\nAre you a swordsman, archer, or mage?\n";
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

void battle(Player &protagonist, string enemyName, int enemyHealth, int enemyDifficulty, int initHealth, int ambush)
{
    int enemyDamage, playerDamage, hitFactor, origHealth;
    origHealth = enemyHealth;
    if(ambush == 1)
    {
    cout << "\n* A M B U S H   S T A R T *\n";
    while(enemyHealth > 0 && protagonist.get_hp() > 0)
    {
        enemyDamage = rand() % 10 * enemyDifficulty + 1;
        cout << "\n" << enemyName << " attacks and deals " << enemyDamage << " damage.\n";
        protagonist.set_hp(protagonist.get_hp() - enemyDamage);
        if(protagonist.get_hp() <= 0)
        {
            cout << "You died.\n";
        }
        else
        {
            cout << "You have " << protagonist.get_hp() << " hp remaining.\n";

            enemyHealth -= attack(protagonist, enemyName, origHealth, initHealth);

        if(enemyHealth > 0)
        {
            cout << enemyName << " has " << enemyHealth << " hp remaining.\n";
        }
        else
        {
            // Do nothing
        }
        }
    }
    }
    else
    {
    cout << "\n* B A T T L E   S T A R T *\n";
    while(enemyHealth > 0 && protagonist.get_hp() > 0)
    {
        enemyHealth -= attack(protagonist, enemyName, origHealth, initHealth);

        if(enemyHealth > 0)
        {
            cout << enemyName << " has " << enemyHealth << " hp remaining.\n";
        }
        else
        {
            cout << "Could it be? " << enemyName << " was destroyed in one blow! But it collects its last bit of energy and delivers a final retaliation!\n";
        }
        enemyDamage = rand() % 10 * enemyDifficulty + 1;
        cout << "\n" << enemyName << " attacks and deals " << enemyDamage << " damage.\n";
        protagonist.set_hp(protagonist.get_hp() - enemyDamage);
        if(protagonist.get_hp() <= 0)
        {
            cout << "You died.\n";
        }
        else
        {
            cout << "You have " << protagonist.get_hp() << " hp remaining.\n";
        }
    }
    }

if(enemyHealth <= 0)
{
    cout << "\nCongratulations. You have defeated " << enemyName << "!\n";
}
else
{
    cout << "Game over.\n";
    // Start game over sequence
}
}

int attack(Player &protagonist, string enemyName, int origHealth, int initHealth)
{
    int playerDamage = 0, hitFactor;
    string input;
    if(protagonist.get_class() == "swordsman") // Moveset if player is a swordsman
    {
    cout << "\nWould you like to slash (s), lance (l), or obliterate (o)?\n";
    getline(cin, input);
    if(input == "s")
    {
        hitFactor = rand() % 10 + 1;
        if(hitFactor <= 6)
        {
            playerDamage = 2 * protagonist.get_attack() * (rand() % 4 + 1);
            cout << "Your slash is successful and you deal " << playerDamage << " damage to " << enemyName << "!\n";
        }
        else
        {
            playerDamage = 0;
            cout << "Oops. You miss.\n";
        }
    }
    else if(input == "l")
    {
        hitFactor = rand() % 10 + 1;
        if(hitFactor <= 8)
        {
            playerDamage = protagonist.get_attack() * (rand() % 3 + 1);
            cout << "Your lance is successful and you deal " << playerDamage << " damage to " << enemyName << "!\n";
        }
        else
        {
            playerDamage = 0;
            cout << "Oops. You miss.\n";
        }
    }
    else if(input == "o")
    {
        hitFactor = rand() % 10 + 1;
        if(hitFactor <= 1)
        {
            playerDamage = 4 * protagonist.get_attack() * (rand() % 5 + 1);
            cout << "Wow! That hit? You deal a massive " << playerDamage << " damage to " << enemyName << "!\n";
        }
        else
        {
            playerDamage = 0;
            cout << "As expected, you miss.\n";
        }
    }
    else
    {
        playerDamage = 0;
        cout << "You attempt a nonexistent attack and end up doing nothing...\n";
    }
    }
    else if(protagonist.get_class() == "archer") // Moveset if player is an archer
    {
    cout << "\nWould you like to fire (f), sharpshoot (s), or megarush (m)?\n";
    getline(cin, input);
    if(input == "f")
    {
        hitFactor = rand() % 10 + 1;
        if(hitFactor <= 8)
        {
            playerDamage = protagonist.get_attack() * (rand() % 6 + 1);
            cout << "Your fire is successful and you deal " << playerDamage << " damage to " << enemyName << "!\n";
        }
        else
        {
            playerDamage = 0;
            cout << "Oops. You miss.\n";
        }
    }
    else if(input == "s")
    {
            playerDamage = protagonist.get_attack() * (rand() % 2 + 1);
            cout << "Your sharpshoot is successful as expected and you deal " << playerDamage << " damage to " << enemyName << "!\n";
    }
    else if(input == "m")
    {
        hitFactor = rand() % 2 + 1;
        if(hitFactor <= 1)
        {
            playerDamage = 2 * protagonist.get_attack() * (rand() % 5 + 1);
            cout << "Let's go! You deal a massive " << playerDamage << " damage to " << enemyName << "!\n";
        }
        else
        {
            playerDamage = 0;
            cout << "Damn. Missed.\n";
        }
    }
    else
    {
        playerDamage = 0;
        cout << "You attempt a nonexistent attack and end up doing nothing...\n";
    }
    }
    else // Moveset if player is a mage
    {
    cout << "\nWould you like to sadden (s), anger (a), or focus (f)?\n";
    getline(cin, input);
    if(input == "s")
    {
            playerDamage = 0.1 * origHealth;
            cout << "Your sadden is successful and you deal " << playerDamage << " damage to " << enemyName << "!\n";
    }
    else if(input == "a")
    {
        hitFactor = rand() % 10 + 1;
        if(hitFactor <= 7)
        {
            playerDamage = 0.25 * origHealth;
            cout << "Your anger is successful and you deal " << playerDamage << " damage to " << enemyName << "!\n";
        }
        else
        {
            playerDamage = 0;
            cout << "Oops. You miss.\n";
        }
    }
    else if(input == "f")
    {
        hitFactor = rand() % 10 + 1;
        if(hitFactor <= 7)
        {
            protagonist.set_hp(protagonist.get_hp() + (0.25 * initHealth));
            if(protagonist.get_hp() > initHealth)
            {
                protagonist.set_hp(initHealth);
            }
            else
            {
                // Do nothing
            }
            cout << "Very nice. You healed a bit and now have " << protagonist.get_hp() << " hp.\n";
        }
        else
        {
            cout << "Uhhh... Nothing seems to have happened.\n";
        }
    }
    else
    {
        playerDamage = 0;
        cout << "You attempt a nonexistent attack and end up doing nothing...\n";
    }
    }
    return playerDamage;
}

void intermission(Player &protagonist, int initHealth)
{
    string input;
    cout << "\nI N T E R M I S S I O N\n";
    do
    {
    cout << "\nWould you like access to the shop (s), inventory (i), player data (p), or just move forward (m)?\n";
    getline(cin, input);
    if(input == "s")
    {
        cout << "\n******** SHOP ********\n"; // Gotta make this a loop that takes a new, separate input
        cout << "Welcome to the shop! Shopkeeper LUCINE warmly welcomes you. What would you like to buy? You have " << protagonist.get_wealth() << " imperial Finpu coins.\n";
        cout << "Potion (p): heals 40 hp and can be used during battle\n";
        cout << "Ultimatum (u): restores health fully but can only be used during intermission\n";
        cout << "Stunflower (s): stuns opponent for three turns and can only be used during battle\n";
        cout << "Hefty blade (h): permanantly buffs attack stat by 1\n";
        cout << "Mighty armor (m): permanantly buffs defense stat by 1\n";
        cout << "Cancel (c)\n";
    }
    else if(input == "i")
    {
        cout << "\n****** INVENTORY ******\n"; // Gotta make this a loop that takes a new, separate input
        cout << "You currently possess " << protagonist.get_wealth() << " imperial Finpu coins.\n\n";
        cout << "X potion(s) (p)\n";
        cout << "X ultimatum(s) (u)\n";
        cout << "X stunflower(s)\n"; // Implement conditional considering singular/plural
        cout << "Cancel (c)\n";
    }
    else if(input == "p")
    {
        cout << "\n***** PLAYER DATA *****\n";
        cout << protagonist.get_name() << ", you currently have " << protagonist.get_hp() << "hp out of a possible maximum of " << initHealth << ".\n";
        // Remark the relative hp level and give a recommendation... This one's not too hard
        cout << "Your attack stat is at " << protagonist.get_attack() << " and your defense stat is at " << protagonist.get_defense() << ".\n";
    }
    else if(input == "m")
    {
        cout << "Moving forward!\n";
    }
    else
    {
        cout << "Please enter a valid input.\n\n";
    }
    }
    while (input != "m");
}