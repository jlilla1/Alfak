/**
* \class Monster
*
* \author Alfak
*
* Last time code was modified: 2020/12/10
*
* Created on: 2020/12/10 16:00
*/

#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "JSON.h"
#include "character.h"
#include "Hero.h"

/**
* This is the class of the monsters. This class contains the different monsters the heros will fight.
* The functions are explained further in Monster.cpp.
*/

class Hero;

class Monster : public Character {
public:
         Monster(const std::string& name, const int maxHp, 
         int dmg, 
         double attack_cooldown);
         /// In this method the program reads in and checks the data of the monster.
         static Monster parse(const std::string& charSheetName);
         /// This function will conduct the attack on the hero.
         void attack(Hero* h);
};

#endif 