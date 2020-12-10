/**
* \class Hero
*
* \author Alfak
*
* Last time code was modified: 2020/12/10
*
* Created on: 2020/12/10 16:00
*/

#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "JSON.h"
#include "character.h"
#include "Monster.h"

/**
* This is the class of the heros. This class contains the heros who will fight the monsters.
* The functions are explained further in Hero.cpp.
*/

class Monster;

class Hero : public Character{
private:
    int level = 1;              ///< The hero's level at the beginning.
    int xp = 0;                 ///< The hero's experience at the beginning.
    int reqXp;                  ///< The hero's experience per level.
    int Hp_boost;               ///< The hero's health points bonus per level.
    int Dmg_boost;              ///< The hero's damage bonus per level.
    double cooldownLVL;         ///< The hero's cooldown multiplier per level.
public:
	Hero(const std::string& name, const int maxHp,
    const int dmg, double attackcooldown,
    const int reqXp,const int Hp_boost,const int Dmg_boost, double cooldownLVL);
         Hero(const Hero& hero);
         int getLevel() const;      ///< Returns the level of the hero.
         int getXp() const;         ///< Returns the experience of the hero.
         /// Sets the experience od the hero.
         void setXp(int mxp);
         /// In this method the program reads in and checks the data of the hero.
         static Hero parse(const std::string& fname);
         /// This function will conduct the attack on the monster.
         void attack(Character* c);
         /// This function will conduct the level ups of the hero.
         void levelup();
         /// This function will conduct the fight between the heros and the monsters. The figth ends when one opponent dies so its health points reaches zero.
         void fightTilDeath(Monster& m);

};

#endif 