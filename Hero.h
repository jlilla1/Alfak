
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

class Monster;

class Hero : public Character{
private:
    int level = 1;    
    int xp = 0;     
    int reqXp;     
    int Hp_boost;     
    int Dmg_boost;    
    double cooldownLVL; 
public:
	Hero(const std::string& name, const int maxHp,
    const int dmg, double attackcooldown,
    const int reqXp,const int Hp_boost,const int Dmg_boost, double cooldownLVL);
         Hero(const Hero& hero);
         int getLevel() const;
         int getXp() const;
         void setXp(int mxp);
         static Hero parse(const std::string& fname);
         void attack(Character* c);
         void levelup();
         void fightTilDeath(Monster& m);

};

#endif 