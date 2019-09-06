#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player
{
    public:
        Player();
        Player(string name, int classIndex, int wealth, int hp, int attack, int defense);
        string get_name() const;
        string get_class() const;
        string get_class_capitalized() const;
        int get_wealth() const;
        int get_hp() const;
        int get_attack() const;
        int get_defense() const;
        void set_wealth(int new_wealth);
        void set_hp(int new_hp);
        void set_attack(int new_attack);
        void set_defense(int new_defense);
    private:
        string name;
        int classIndex;
        int wealth;
        int hp;
        int attack;
        int defense;
};

Player::Player()
{
    name = "";
    classIndex = 0;
    wealth = 0;
    hp = 0;
    attack = 0;
    defense = 0;
}

Player::Player(string new_name, int new_classIndex, int new_wealth, int new_hp, int new_attack, int new_defense)
{
    name = new_name;
    classIndex = new_classIndex;
    wealth = new_wealth;
    hp = new_hp;
    attack = new_attack;
    defense = new_defense;
}

string Player::get_name() const
{
    return name;
}

string Player::get_class() const
{
    if(classIndex == 0)
    {
        return "swordsman";
    }
    else if(classIndex == 1)
    {
        return "archer";
    }
    else
    {
        return "mage";
    }
}

string Player::get_class_capitalized() const
{
    if(classIndex == 0)
    {
        return "Swordsman";
    }
    else if(classIndex == 1)
    {
        return "Archer";
    }
    else
    {
        return "Mage";
    }
}

int Player::get_wealth() const
{
    return wealth;
}

int Player::get_hp() const
{
    return hp;
}

int Player::get_attack() const
{
    return attack;
}

int Player::get_defense() const
{
    return defense;
}

void Player::set_wealth(int change)
{
    wealth = change;
}

void Player::set_hp(int change)
{
    hp = change;
}

void Player::set_attack(int change)
{
    attack = change;
}

void Player::set_defense(int change)
{
    defense = change;
}

#endif