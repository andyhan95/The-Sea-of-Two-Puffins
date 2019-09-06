#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
using namespace std;

class Inventory
{
    public:
        Inventory();
        Inventory(int potions, int ultimatums, int stunflowers, int attackUpgrades, int defenseUpgrades);
        int get_potions() const;
        int get_ultimatums() const;
        int get_stunflowers() const;
        int get_attackUpgrades() const;
        int get_defenseUpgrades() const;
        void set_potions(int new_potions);
        void set_ultimatums(int new_ultimatums);
        void set_stunflowers(int new_stunflowers);
        void set_attackUpgrades(int new_attackUpgrades);
        void set_defenseUpgrades(int new_defenseUpgrades);
    private:
        int potions, ultimatums, stunflowers, attackUpgrades, defenseUpgrades;
};

Inventory::Inventory()
{
    potions = 0;
    ultimatums = 0;
    stunflowers = 0;
    attackUpgrades = 0;
    defenseUpgrades = 0;
}

Inventory::Inventory(int new_potions, int new_ultimatums, int new_stunflowers, int new_attackUpgrades, int new_defenseUpgrades)
{
    potions = new_potions;
    ultimatums = new_ultimatums;
    stunflowers = new_stunflowers;
    attackUpgrades = new_attackUpgrades;
    defenseUpgrades = new_defenseUpgrades;
}

int Inventory::get_potions() const
{
    return potions;
}

int Inventory::get_ultimatums() const
{
    return ultimatums;
}

int Inventory::get_stunflowers() const
{
    return stunflowers;
}

int Inventory::get_attackUpgrades() const
{
    return attackUpgrades;
}

int Inventory::get_defenseUpgrades() const
{
    return defenseUpgrades;
}

void Inventory::set_potions(int change)
{
    potions = change;
}

void Inventory::set_ultimatums(int change)
{
    ultimatums = change;
}

void Inventory::set_stunflowers(int change)
{
    stunflowers = change;
}

void Inventory::set_attackUpgrades(int change)
{
    attackUpgrades = change;
}

void Inventory::set_defenseUpgrades(int change)
{
    defenseUpgrades = change;
}

#endif