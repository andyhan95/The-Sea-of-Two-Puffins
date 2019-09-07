#include "player.h"
#include "inventory.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

int determinePlayerClass();
void battle(Player &protagonist, Inventory &bag, string enemyName, int enemyHealth, int enemyDifficulty, int initHealth, int ambush, int reward);
int attackWithoutItems(Player &protagonist, Inventory &bag, string enemyName, int origHealth, int initHealth);
int attackWithItems(Player &protagonist, Inventory &bag, string enemyName, int origHealth, int initHealth);
void intermission(Player &protagonist, Inventory &bag, int initHealth);
void statBuff(Player &protagonist, int attackBuff, int defenseBuff);

int main()
{
    srand((int)time(0));

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
        initHealth = 160;
    }
    else if(classIndex == 1)
    {
        initAttack = 3;
        initDefense = 3;
        initHealth = 200;
    }
    else
    {
        initAttack = 2;
        initDefense = 4;
        initHealth = 160;
    }

    cout << "\nStoring player data...\n\n\n\n";

    Player protagonist(playerName, classIndex, 30, initHealth, initAttack, initDefense, 0, 0);
    Inventory bag(0, 0, 0, 0, 0);

    cout << "Welcome, " << protagonist.get_name() << ", to the Kingdom of Puffino, ruled by Elder Finpu.\n";
    cout << "Things are normally quaint and peaceful around here. But recently, a gang of seagulls has been causing quite some trouble.\n";
    cout << "It is up to you to defeat these seagulls and figure out why they are here.\n";
    cout << "\nAs a " << protagonist.get_class() << ", you can select from three basic moves.\n";

    if(protagonist.get_class() == "swordsman")
    {
        cout << "     You can slash: this will deal decent damage, but it is not super accurate.\n";
        cout << "     Or, you can lance: this move is a little weaker, but you will rarely miss.\n";
        cout << "     If you're daring, you can obliterate: it is a very potent attack but you will likely miss.\n";
    }
    else if(protagonist.get_class() == "archer")
    {
        cout << "     You can fire: this is your standard attack.\n";
        cout << "     Or, you can sharpshoot: you will never miss.\n";
        cout << "     You can also megarush: you only have a 50% chance of succeeding, but it is a powerful attack.\n";
    }
    else
    {
        cout << "     You can sadden: this will always reduce your opponent's hp by 10% of its full health.\n";
        cout << "     Or, you can anger: this might fail, but you could do reduce your opponent's hp by 25% of its full health.\n";
        cout << "     You can focus: this will probably heal you by 25%. But it might instead heal your opponent by 10%.\n";
    }

    cout << "In addition, you could also...\n\nOh goodness! Pardon the interruption, but a seagull suddenly approaches from behind!\n";

    battle(protagonist, bag, "SEAGULL JOE", 60, 1, initHealth, 1, 8);
    statBuff(protagonist, 1, 1);
    protagonist.set_killedJoe(1);

    cout << "\n\n\nThat was quite the surprise occurance... SEAGULL JOE scurries away badly injured. It is hard to tell what SEAGULL JOE wanted from you but alas.\n";
    cout << "Anyway, there will always be an intermission between battles and story moments. During intermission, you could shop or rest up!\n";

    intermission(protagonist, bag, initHealth);

    cout << "\n\n\nYou leave town feeling refreshed. You recall SEAGULL JOE scurrying away towards the southern side of the village, so you venture south towards the Woods of Hollowbird.\n";
    cout << "You hear a strange sound coming from the bushes and investigate. You see ALBATROSS JASMINE scolding SEAGULL JOE.\n";
    cout << "SEAGULL JOE, dejected, waddles away further into the woods. This is it! ALBATROSS JASMINE is alone! Charge?\n(y) / (n)\n";
    string yesno;
    bool yesnoValidity;
    do
    {
    getline(cin, yesno);
    if(yesno == "y")
    {
        cout << "You surge forward and attack!\n";
        yesnoValidity = 1;
        battle(protagonist, bag, "ALBATROSS JASMINE", 100, 2, initHealth, 0, 12);
        statBuff(protagonist, 2, 2);
    }
    else if(yesno == "n")
    {
        cout << "You decide to sneak around... And try to spy on ALBATROSS JASMINE to acquire more information about the recent seagull raids.\n";
        cout << "But suddenly, she vanishes into thin air and you lose sight of her.\n";
        cout << "...\n...\n...\n\nOh my! A sharp blade swings out of nowhere! You have been ambushed by ALBATROSS JASMINE!\n";
        yesnoValidity = 1;
        battle(protagonist, bag, "ALBATROSS JASMINE", 100, 2, initHealth, 1, 12);
        statBuff(protagonist, 2, 2);
    }
    else
    {
        cout << "You have to make a decision, " << protagonist.get_name() << ".\n";
        yesnoValidity = 0;
    }
    }
    while (yesnoValidity != 1);

    cout << "That was intense... ALBATROSS JASMINE lays on the ground and remains motionless.\n";
    cout << "You ask her why the seagulls are raiding and she mutters under her breath, 'boss... sick... at sea of puffins... wants pure ult--...'.\n";
    cout << "ALBATROSS JASMINE dies...\n* R E S T  I N  P E A C E *\nBut her last words are concerning. You decide that you should try to find this 'boss'.\n";
    cout << "But before you head towards the seaside, you take a quick rest stop.\n";

    intermission(protagonist, bag, initHealth);

    cout << "The seaside is quite distant but the walk is relatively managable.\n\n...\n...\n...\n\n";
    cout << "That is... Until you get ambushed by EAGLE RON!\n";

    battle(protagonist, bag, "EAGLE RON", 100, 2, initHealth, 1, 16);
    statBuff(protagonist, 1, 1);

    cout << "Phew! You reign victorious over EAGLE RON. Right when you reach for your water canister for a sip of water, EAGLE JIM swoops down!\n";
    cout << "No time for an intermission this time!\n";

    battle(protagonist, bag, "EAGLE JIM", 100, 2, initHealth, 1, 16);
    statBuff(protagonist, 1, 1);

    cout << "That was unbelivable...! Everyone seems to be after you!\n";
    cout << "You ask EAGLE JIM, who is barely alive, what the fuss is all about.\n";
    cout << "'boss... demands... pure ultimatum... alive...'\n";
    cout << "EAGLE JIM dies...\n* R E S T  I N  P E A C E *\n";
    cout << "It is clear at this point that this 'boss' is in dire need of this 'pure ultimatum', whatever that is.\n";
    cout << "Before you carry forth, you reckon you need a break.\n";

    intermission(protagonist, bag, initHealth);

    cout << "You continue your trek and eventually finally make it to the seaside. A worn sign reads: 'Welcome to the Sea of Two Puffins'\n";
    cout << "Would you like to head on over to the cliffside (c), examine the sign more closely (s), or turn back (t)?\n";

    do
    {
    getline(cin, yesno);
    if(yesno == "c")
    {
        cout << "You head over to the cliffside. It is completely silent. There seems to be no sign of life anywhere here.\n";
    }
    else if(yesno == "s")
    {
        cout << "You look behind the sign. Huh. You find 2 stunflowers, 1 potion, and 10 IFCs. You are rich!\n";
        bag.set_stunflowers(bag.get_stunflowers() + 2);
        bag.set_potions(bag.get_potions() + 1);
        protagonist.set_wealth(protagonist.get_wealth() + 10);
        cout << "You now have " << bag.get_stunflowers() << " stunflowers, " << bag.get_potions() << " potions, and " << protagonist.get_wealth() << " IFCs.\n";
        cout << "You feel great! Who does not feel great after finding some free goodies after all?\n";
    }
    else if(yesno == "t")
    {
        cout << "You have a weird feeling about this place. So you turn back.\n";
    }
    else
    {
        cout << "You have to make a decision, " << protagonist.get_name() << ".\n";
        yesnoValidity = 0;
    }
    }
    while (yesnoValidity != 1);

        cout << "\nBut then you hear a deep, thundering voice coming from behind.\n";
        cout << "'So... you are the elusive " << protagonist.get_name() << ", eh?'\n";
        cout << "You turn around and a massive puffin, the largest you have ever seen, towers above you.\n";
        cout << "'I have been looking for you, " << protagonist.get_name() << ". I need your blood to help me be free of disease.'\n";
        cout << "'You are the pure ultimatum, after all...'\n";
        cout << "You cannot believe it. You were the legendary pure ultimatum all this time? You suddenly feel stronger. Much stronger.\n";
        protagonist.set_attack(protagonist.get_attack() + 4);
        protagonist.set_defense(protagonist.get_defense() + 4);
        cout << "Your attack rises by 4 points to " << protagonist.get_attack() << " and your defense rises by 4 points to " << protagonist.get_defense()<< ".\n\n";
        cout << "'Give me your blood, litte one.'\n";
        cout << "F I N A L   B O S S\n";

    battle(protagonist, bag, "GREAT PUFFIN FINPU", 300, 3, initHealth, 1, 16);

    cout << "\nGREAT PUFFIN FINPU collapses......\n\n";
    cout << "As tired as you are, you feel an overwhelming sense of pride... But then you realize that you have just slain the ruler of the lands.\n";
    cout << "You had no choice though. With his final reserve of energy, GREAT PUFFIN FINPU mutters:\n";
    cout << "'" << protagonist.get_name() << ", you are strong. Real strong. Yes, it is now very clear to me that you indeed are the pure ultimatum. I was not fully certain prior to this battle. But I always believed it.'\n";
    cout << "'I perish here, by the Sea of Two Puffins. I perish, and this land is now to be called the Sea of One Puffin. If you so desire, you can find my other half, GREAT PUFFIN JARU, hiding in the Cave of Despair.'\n";
    cout << "'May your ventures prove fulfilling, " << protagonist.get_name() << "...'\n";
    cout << "\nGREAT PUFFIN FINPU dies...\n* R E S T  I N  P E A C E *\n\n";
    cout << "The wind suddenly picks up. You feel a strange calling. Will you head to the Cave of Despair to find GREAT PUFFIN JARU, " << protagonist.get_name() << "? Will you really?\n";
    cout << "\n* * * T H E  E N D * * *\n";
    cout << "Thank you for playing\n-Andy\n";

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
        cout << "\nAre you a swordsman (s), archer (a), or mage (m)?\n";
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

void battle(Player &protagonist, Inventory &bag, string enemyName, int enemyHealth, int enemyDifficulty, int initHealth, int ambush, int reward)
{
    int enemyDamage, playerDamage, hitFactor, origHealth;
    origHealth = enemyHealth;
    if(protagonist.get_killedJoe() == 0) // First ambush/battle without the option to use items
    {
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
            cout << "You have " << protagonist.get_hp() << "/" << initHealth << " hp remaining.\n";

            enemyHealth -= attackWithoutItems(protagonist, bag, enemyName, origHealth, initHealth);

        if(enemyHealth > 0)
        {
            cout << enemyName << " has " << enemyHealth << "/" << origHealth << " hp remaining.\n";
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
        enemyHealth -= attackWithoutItems(protagonist, bag, enemyName, origHealth, initHealth);

        if(enemyHealth > 0)
        {
            cout << enemyName << " has " << enemyHealth << "/" << origHealth << " hp remaining.\n";
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
            cout << "You have " << protagonist.get_hp() << "/" << initHealth << " hp remaining.\n";
        }
    }
    }
    }
    else // Every ambush/battle after defeating SEAGULL JOE (items are present)
    {
    if(ambush == 1)
    {
    cout << "\n* A M B U S H   S T A R T *\n";
    while(enemyHealth > 0 && protagonist.get_hp() > 0)
    {
        if(protagonist.get_stunnedEnemy() == 0)
        {
        enemyDamage = rand() % 10 * enemyDifficulty + 1;
        cout << "\n" << enemyName << " attacks and deals " << enemyDamage << " damage.\n";
        protagonist.set_hp(protagonist.get_hp() - enemyDamage);
        }
        else
        {
            cout << "\n*** " << enemyName << " is stunned and cannot move! ***\n\n";
            protagonist.set_stunnedEnemy(0);
        }
        if(protagonist.get_hp() <= 0)
        {
            cout << "You died.\n";
        }
        else
        {
            cout << "You have " << protagonist.get_hp() << "/" << initHealth << " hp remaining.\n";
            enemyHealth -= attackWithItems(protagonist, bag, enemyName, origHealth, initHealth);

        if(enemyHealth > 0)
        {
            cout << enemyName << " has " << enemyHealth << "/" << origHealth << " hp remaining.\n";
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
        enemyHealth -= attackWithItems(protagonist, bag, enemyName, origHealth, initHealth);

        if(enemyHealth > 0)
        {
            cout << enemyName << " has " << enemyHealth << "/" << origHealth << " hp remaining.\n";
            if(protagonist.get_stunnedEnemy() == 0)
        {
        enemyDamage = rand() % 10 * enemyDifficulty + 1;
        cout << "\n" << enemyName << " attacks and deals " << enemyDamage << " damage.\n";
        protagonist.set_hp(protagonist.get_hp() - enemyDamage);
        }
        else
        {
            cout << "\n*** " << enemyName << " is stunned and cannot move! ***\n\n";
            protagonist.set_stunnedEnemy(0);
        }
        if(protagonist.get_hp() <= 0)
        {
            cout << "You died.\n";
        }
        else
        {
            cout << "You have " << protagonist.get_hp() << "/" << initHealth << " hp remaining.\n";
        }
        }
        else
        {
            // Do nothing
        }
    }
    }
    }

if(enemyHealth <= 0)
{
    cout << "\nCongratulations. You have defeated " << enemyName << "!\n\n";
    cout << "You loot " << reward << " imperial Finpu coins.\n";
    protagonist.set_wealth(protagonist.get_wealth() + reward);
}
else
{
    cout << "Game over.\n";
    exit(0);
}
}

int attackWithoutItems(Player &protagonist, Inventory &bag, string enemyName, int origHealth, int initHealth)
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

int attackWithItems(Player &protagonist, Inventory &bag, string enemyName, int origHealth, int initHealth)
{
    int playerDamage = 0, hitFactor;
    string input;
    if(protagonist.get_class() == "swordsman") // Moveset if player is a swordsman
    {
    cout << "\nWould you like to slash (s), lance (l), or obliterate (o)? Or alternatively, would you like to use a potion (pp) or stunflower(ss)?\n";
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
    else if(input == "pp")
    {
        if(bag.get_potions() == 0)
        {
            cout << "You do not have any potions...\nYou spend quite some time fumbling in your bag and your turn ends. Sad.\n";
        }
        else
        {
            cout << "You consume a potion!\n";
            protagonist.set_hp(protagonist.get_hp() + 40);
            if(protagonist.get_hp() > initHealth)
            {
                protagonist.set_hp(initHealth);
            }
            else
            {
                // Do nothing
            }
            cout << "You now have " << protagonist.get_hp() << "/" << initHealth << " hp.\n";
            bag.set_potions(bag.get_potions() - 1);
        }
        playerDamage = 0;
    }
    else if(input == "ss")
    {
        if(bag.get_stunflowers() == 0)
        {
            cout << "You do not have any stunflowers...\nYou spend quite some time fumbling in your bag and your turn ends. Sad.\n";
        }
        else
        {
            cout << "You throw a stunflower towards " << enemyName << ". Bam!\n\n";
            protagonist.set_stunnedEnemy(1);
            bag.set_stunflowers(bag.get_stunflowers() - 1);
        }
        playerDamage = 0;
    }
    else
    {
        playerDamage = 0;
        cout << "You attempt a nonexistent attack and end up doing nothing...\n";
    }
    }
    else if(protagonist.get_class() == "archer") // Moveset if player is an archer
    {
    cout << "\nWould you like to fire (f), sharpshoot (s), or megarush (m)? Or alternatively, would you like to use a potion (pp) or stunflower(ss)?\n";
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
    else if(input == "pp")
    {
        if(bag.get_potions() == 0)
        {
            cout << "You do not have any potions...\nYou spend quite some time fumbling in your bag and your turn ends. Sad.\n";
        }
        else
        {
            cout << "You consume a potion!\n";
            protagonist.set_hp(protagonist.get_hp() + 40);
            if(protagonist.get_hp() > initHealth)
            {
                protagonist.set_hp(initHealth);
            }
            else
            {
                // Do nothing
            }
            cout << "You now have " << protagonist.get_hp() << "/" << initHealth << " hp.\n";
            bag.set_potions(bag.get_potions() - 1);
        }
        playerDamage = 0;
    }
    else if(input == "ss")
    {
        if(bag.get_stunflowers() == 0)
        {
            cout << "You do not have any stunflowers...\nYou spend quite some time fumbling in your bag and your turn ends. Sad.\n";
        }
        else
        {
            cout << "You throw a stunflower towards " << enemyName << ". Bam!\n\n";
            protagonist.set_stunnedEnemy(1);
            bag.set_stunflowers(bag.get_stunflowers() - 1);
        }
        playerDamage = 0;
    }
    else
    {
        playerDamage = 0;
        cout << "You attempt a nonexistent attack and end up doing nothing...\n";
    }
    }
    else // Moveset if player is a mage
    {
    cout << "\nWould you like to sadden (s), anger (a), or focus (f)? Or alternatively, would you like to use a potion (pp) or stunflower(ss)?\n";
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
    else if(input == "pp")
    {
        if(bag.get_potions() == 0)
        {
            cout << "You do not have any potions...\nYou spend quite some time fumbling in your bag and your turn ends. Sad.\n";
        }
        else
        {
            cout << "You consume a potion!\n";
            protagonist.set_hp(protagonist.get_hp() + 40);
            if(protagonist.get_hp() > initHealth)
            {
                protagonist.set_hp(initHealth);
            }
            else
            {
                // Do nothing
            }
            cout << "You now have " << protagonist.get_hp() << "/" << initHealth << " hp.\n";
            bag.set_potions(bag.get_potions() - 1);
        }
        playerDamage = 0;
    }
    else if(input == "ss")
    {
        if(bag.get_stunflowers() == 0)
        {
            cout << "You do not have any stunflowers...\nYou spend quite some time fumbling in your bag and your turn ends. Sad.\n";
        }
        else
        {
            cout << "You throw a stunflower towards " << enemyName << ". Bam!\n\n";
            protagonist.set_stunnedEnemy(1);
            bag.set_stunflowers(bag.get_stunflowers() - 1);
        }
        playerDamage = 0;
    }
    else
    {
        playerDamage = 0;
        cout << "You attempt a nonexistent attack and end up doing nothing...\n";
    }
    }
    return playerDamage;
}

void statBuff(Player &protagonist, int attackBuff, int defenseBuff)
{
    cout << "Your attack stat went from " << protagonist.get_attack() << " to ";
    protagonist.set_attack(protagonist.get_attack() + attackBuff);
    cout << protagonist.get_attack() << " and your defense stat went from " << protagonist.get_defense() << " to ";
    protagonist.set_defense(protagonist.get_defense() + defenseBuff);
    cout << protagonist.get_defense() << "! Well done.\n";
}

void intermission(Player &protagonist, Inventory &bag, int initHealth)
{
    string input;
    cout << "\n* I N T E R M I S S I O N *\n";
    do
    {
    cout << "\nWould you like access to the shop (s), inventory (i), player data (p), or just move forward (m)?\n";
    getline(cin, input);
    if(input == "s")
    {
        string shopInput;
        cout << "\n******** SHOP ********\n";
        cout << "Welcome to the shop! Shopkeeper LUCINE warmly welcomes you.\n";
        do
        if(bag.get_attackUpgrades() == 0 && bag.get_defenseUpgrades() == 0)
        {
        {
        cout << "\nWhat would you like to buy? You have " << protagonist.get_wealth() << " imperial Finpu coins.\n";
        cout << "Potion (p) (8 IFCs): heals 40 hp and can be used during battle - you currently have " << bag.get_potions() << " potion(s).\n";
        cout << "Ultimatum (u) (16 IFCs): restores health fully but can only be used during intermission - you currently have " << bag.get_ultimatums() << " ultimatum(s).\n";
        cout << "Stunflower (s) (8 IFCs): stuns opponent for one turn and can only be used during battle - you currently have " << bag.get_stunflowers() << " stunflower(s).\n";
        cout << "Hefty blade (h) (20 IFCs): permanantly buffs attack stat by 2.\n";
        cout << "Mighty armor (m) (20 IFCs): permanantly buffs defense stat by 2.\n";
        cout << "Cancel (c)\n";
        getline(cin, shopInput);
        if(shopInput == "p")
        {
            if(protagonist.get_wealth() >= 8)
            {
                bag.set_potions(bag.get_potions() + 1);
                cout << "\nPurchased one potion! You now have " << bag.get_potions() << " potion(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 8);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "u")
        {
            if(protagonist.get_wealth() >= 16)
            {
                bag.set_ultimatums(bag.get_ultimatums() + 1);
                cout << "\nPurchased one ultimatum! You now have " << bag.get_ultimatums() << " ultimatum(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 16);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "s")
        {
            if(protagonist.get_wealth() >= 8)
            {
                bag.set_stunflowers(bag.get_stunflowers() + 1);
                cout << "\nPurchased one stunflower! You now have " << bag.get_stunflowers() << " stunflower(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 8);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "h")
        {
            if(protagonist.get_wealth() >= 20)
            {
                protagonist.set_attack(protagonist.get_attack() + 2);
                cout << "\nYou upgraded your blade!\n";
                cout << "Your attack stat is now " << protagonist.get_attack() << ".\n";
                bag.set_attackUpgrades(bag.get_attackUpgrades() + 1);
                protagonist.set_wealth(protagonist.get_wealth() - 20);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "m")
        {
            if(protagonist.get_wealth() >= 20)
            {
                protagonist.set_defense(protagonist.get_defense() + 2);
                cout << "\nYou upgraded your armor!\n";
                cout << "Your defense stat is now " << protagonist.get_defense() << ".\n";
                bag.set_defenseUpgrades(bag.get_defenseUpgrades() + 1);
                protagonist.set_wealth(protagonist.get_wealth() - 20);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else
        {
            cout << "Please enter a valid input or press (c) to exit shop.\n";
        }
        }
        }
        else if(bag.get_attackUpgrades() == 1 && bag.get_defenseUpgrades() == 0)
        {
        cout << "\nWhat would you like to buy? You have " << protagonist.get_wealth() << " imperial Finpu coins.\n";
        cout << "Potion (p) (8 IFCs): heals 40 hp and can be used during battle - you currently have " << bag.get_potions() << " potion(s).\n";
        cout << "Ultimatum (u) (16 IFCs): restores health fully but can only be used during intermission - you currently have " << bag.get_ultimatums() << " ultimatum(s).\n";
        cout << "Stunflower (s) (8 IFCs): stuns opponent for one turn and can only be used during battle - you currently have " << bag.get_stunflowers() << " stunflower(s).\n";
        cout << "Hefty blade: SOLD.\n";
        cout << "Mighty armor (m) (20 IFCs): permanantly buffs defense stat by 1.\n";
        cout << "Cancel (c)\n";
        getline(cin, shopInput);
        if(shopInput == "p")
        {
            if(protagonist.get_wealth() >= 8)
            {
                bag.set_potions(bag.get_potions() + 1);
                cout << "\nPurchased one potion! You now have " << bag.get_potions() << " potion(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 8);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "u")
        {
            if(protagonist.get_wealth() >= 16)
            {
                bag.set_ultimatums(bag.get_ultimatums() + 1);
                cout << "\nPurchased one ultimatum! You now have " << bag.get_ultimatums() << " ultimatum(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 16);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "s")
        {
            if(protagonist.get_wealth() >= 8)
            {
                bag.set_stunflowers(bag.get_stunflowers() + 1);
                cout << "\nPurchased one stunflower! You now have " << bag.get_stunflowers() << " stunflower(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 8);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "m")
        {
            if(protagonist.get_wealth() >= 20)
            {
                protagonist.set_defense(protagonist.get_defense() + 1);
                cout << "\nYou upgraded your armor!\n";
                cout << "Your defense stat is now " << protagonist.get_defense() << ".\n";
                bag.set_defenseUpgrades(bag.get_defenseUpgrades() + 1);
                protagonist.set_wealth(protagonist.get_wealth() - 20);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else
        {
            cout << "Please enter a valid input or press (c) to exit shop.\n";
        }
        }
        else if(bag.get_attackUpgrades() == 0 && bag.get_defenseUpgrades() == 1)
        {
        cout << "\nWhat would you like to buy? You have " << protagonist.get_wealth() << " imperial Finpu coins.\n";
        cout << "Potion (p) (8 IFCs): heals 40 hp and can be used during battle - you currently have " << bag.get_potions() << " potion(s).\n";
        cout << "Ultimatum (u) (16 IFCs): restores health fully but can only be used during intermission - you currently have " << bag.get_ultimatums() << " ultimatum(s).\n";
        cout << "Stunflower (s) (8 IFCs): stuns opponent for one turn and can only be used during battle - you currently have " << bag.get_stunflowers() << " stunflower(s).\n";
        cout << "Hefty blade (h) (20 IFCs): permanantly buffs attack stat by 1.\n";
        cout << "Mighty armor: SOLD.\n";
        cout << "Cancel (c)\n";
        getline(cin, shopInput);
        if(shopInput == "p")
        {
            if(protagonist.get_wealth() >= 8)
            {
                bag.set_potions(bag.get_potions() + 1);
                cout << "\nPurchased one potion! You now have " << bag.get_potions() << " potion(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 8);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "u")
        {
            if(protagonist.get_wealth() >= 16)
            {
                bag.set_ultimatums(bag.get_ultimatums() + 1);
                cout << "\nPurchased one ultimatum! You now have " << bag.get_ultimatums() << " ultimatum(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 16);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "s")
        {
            if(protagonist.get_wealth() >= 8)
            {
                bag.set_stunflowers(bag.get_stunflowers() + 1);
                cout << "\nPurchased one stunflower! You now have " << bag.get_stunflowers() << " stunflower(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 8);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "h")
        {
            if(protagonist.get_wealth() >= 20)
            {
                protagonist.set_attack(protagonist.get_attack() + 1);
                cout << "\nYou upgraded your blade!\n";
                cout << "Your attack stat is now " << protagonist.get_attack() << ".\n";
                bag.set_attackUpgrades(bag.get_attackUpgrades() + 1);
                protagonist.set_wealth(protagonist.get_wealth() - 20);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else
        {
            cout << "Please enter a valid input or press (c) to exit shop.\n";
        }
        }
        else if(bag.get_attackUpgrades() == 1 && bag.get_defenseUpgrades() == 1)
        {
        cout << "\nWhat would you like to buy? You have " << protagonist.get_wealth() << " imperial Finpu coins.\n";
        cout << "Potion (p) (8 IFCs): heals 40 hp and can be used during battle - you currently have " << bag.get_potions() << " potion(s).\n";
        cout << "Ultimatum (u) (16 IFCs): restores health fully but can only be used during intermission - you currently have " << bag.get_ultimatums() << " ultimatum(s).\n";
        cout << "Stunflower (s) (8 IFCs): stuns opponent for one turn and can only be used during battle - you currently have " << bag.get_stunflowers() << " stunflower(s).\n";
        cout << "Hefty blade: SOLD.\n";
        cout << "Mighty armor: SOLD.\n";
        cout << "Cancel (c)\n";
        getline(cin, shopInput);
        if(shopInput == "p")
        {
            if(protagonist.get_wealth() >= 8)
            {
                bag.set_potions(bag.get_potions() + 1);
                cout << "\nPurchased one potion! You now have " << bag.get_potions() << " potion(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 8);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "u")
        {
            if(protagonist.get_wealth() >= 16)
            {
                bag.set_ultimatums(bag.get_ultimatums() + 1);
                cout << "\nPurchased one ultimatum! You now have " << bag.get_ultimatums() << " ultimatum(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 16);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else if(shopInput == "s")
        {
            if(protagonist.get_wealth() >= 8)
            {
                bag.set_stunflowers(bag.get_stunflowers() + 1);
                cout << "\nPurchased one stunflower! You now have " << bag.get_stunflowers() << " stunflower(s).\n";
                protagonist.set_wealth(protagonist.get_wealth() - 8);
            }
            else
            {
                cout << "You do not have enough imperial Finpu coins...\n";
            }
        }
        else
        {
            cout << "Please enter a valid input or press (c) to exit shop.\n";
        }
        }
        while(shopInput != "c");
    }
    else if(input == "i")
    {
        string inventoryInput;
        do
        {
        cout << "\n****** INVENTORY ******\n";
        cout << "You currently possess " << protagonist.get_wealth() << " imperial Finpu coins.\n\n";
        cout << bag.get_potions() << " potion(s) - press (p) to consume a potion\n";
        cout << bag.get_ultimatums() << " ultimatum(s) - press (u) to consume an ultimatum\n";
        cout << bag.get_stunflowers() << " stunflower(s) - these can only be used during battle\n";
        cout << "Cancel (c)\n";
        getline(cin, inventoryInput);
        if(inventoryInput == "p")
        {
            if(bag.get_potions() == 0)
            {
                cout << "\nYou do not have any potions to consume...\n";
            }
            else
            {
                if(protagonist.get_hp() >= initHealth)
                {
                    cout << "\nYou already have full health.\n";
                }
                else
                {
                bag.set_potions(bag.get_potions() - 1);
                protagonist.set_hp(protagonist.get_hp() + 40);
                if(protagonist.get_hp() > initHealth)
                {
                    protagonist.set_hp(initHealth);
                }
                else
                {
                    // Do nothing
                }
                cout << "\nYou have consumed one potion. You now have " << protagonist.get_hp() << "/" << initHealth << " hp!\n";
                }
            }
        }
        else if(inventoryInput == "u")
        {
            if(bag.get_ultimatums() == 0)
            {
                cout << "\nYou do not have any ultimatums to consume...\n";
            }
            else
            {
                if(protagonist.get_hp() >= initHealth)
                {
                    cout << "\nYou already have full health.\n";
                }
                else
                {
                    bag.set_ultimatums(bag.get_ultimatums() - 1);
                    protagonist.set_hp(initHealth);
                    cout << "\nYou have consumed one ultimatum. You now have full health! " << initHealth << " hp.\n";
                }
            }
        }
        }
        while (inventoryInput != "c");
    }
    else if(input == "p")
    {
        cout << "\n***** PLAYER DATA *****\n";
        cout << protagonist.get_name() << ", you currently have " << protagonist.get_hp() << "hp out of a possible maximum of " << initHealth << ".\n";
        if(protagonist.get_hp() == initHealth)
        {
            cout << "Looks like you need not any potions before your next move.\n";
        }
        else if(protagonist.get_hp() > 0.5 * initHealth)
        {
            cout << "You still have a lot of health, but it may not be a bad idea to top off it you can.\n";
        }
        else if(protagonist.get_hp() <= 0.5 * initHealth)
        {
            cout << "You are a bit weak. It may be wise to charge up before your next move.\n";
        }
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