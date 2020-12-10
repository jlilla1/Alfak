/**
* \author Alfak
*
* Last time code was modified: 2020/12/10
*
* Created on: 2020/12/10 16:00
*/

#include "Hero.h"

/**
*The functions of Hero.h are explained here.
*/

Hero::Hero(const std::string& name, const int maxHp, const int dmg, const double attack_cooldown, const int reqXp, const int Hp_boost, const int Dmg_boost, const double cooldownLVL): Character(name, maxHp, dmg, attack_cooldown){
    this->reqXp=reqXp;
    this->Hp_boost=Hp_boost;
    this->Dmg_boost=Dmg_boost;
    this->cooldownLVL=cooldownLVL;
}
Hero Hero::parse(const std::string& charSheetName) {
	std::vector <std::string> necessaryKeys {"experience_per_level","health_point_bonus_per_level", "damage_bonus_per_level",
							 "cooldown_multiplier_per_level","name", "base_health_points", "base_damage", "base_attack_cooldown"};
	JSON parsedCreature = JSON::parseFromFile(charSheetName);
	bool successfullRead = true;
	for (auto key : necessaryKeys){
    	if(!parsedCreature.count(key)){
			successfullRead = false;
			break;
		}
	}

	if (successfullRead) 
	     return Hero(parsedCreature.get<std::string>("name"), 
			parsedCreature.get<int>("base_health_points"),
			parsedCreature.get<int>("base_damage"),
			parsedCreature.get<double>("base_attack_cooldown"),
			parsedCreature.get<int>("experience_per_level"),
			parsedCreature.get<int>("health_point_bonus_per_level"),
			parsedCreature.get<int>("damage_bonus_per_level"),
			parsedCreature.get<double>("cooldown_multiplier_per_level"));
	else throw JSON::ParseException("Incorrect attributes in " + charSheetName + "!");
}
int Hero::getLevel() const
{
    return level;
}

int Hero::getXp() const
{
    return xp;
}

void Hero::setXp(int mxp)
{
    xp += mxp;
}

void Hero::attack(Character* c)
{
	if(Hp - c->getDmg() > 0)
    {
        setHp(c->getDmg());
    }
    else
    {
        setHp_to_zero();
    }
    this->levelup();
}

void Hero::levelup()
{
    while (xp >= reqXp)
	{
		level++;
		dmg += Dmg_boost;
		maxHp += Hp_boost;
		Hp = maxHp;
		xp -= reqXp;
		attack_cooldown *= cooldownLVL;
	}
}

void Hero::fightTilDeath(Monster& m)
{
    bool player_last_hit=false;
    double time_player=this->getAttackCoolDown();
    double time_enemy=m.getAttackCoolDown();
	while(this->isAlive() && m.isAlive()){
		if(time_player==time_enemy){
            if(player_last_hit){
                m.attack(this);
				if(m.isAlive()){
					this->attack(&m);
                }
				time_player = this->getAttackCoolDown();
				time_enemy = m.getAttackCoolDown();
				player_last_hit = false;
            }
            else
			{
				this->attack(&m);
				if(this->isAlive()){
					m.attack(this);
                }
				time_player = this->getAttackCoolDown();
				time_enemy = m.getAttackCoolDown();
				player_last_hit = true;
			}
		}
        
        else if((time_player - time_enemy) < 0)
		{
			m.attack(this);
			time_enemy -= time_player;
			time_player = this->getAttackCoolDown();
		    player_last_hit = true;
		}
        else 
		{
			this->attack(&m);
			time_player -= time_enemy;
			time_enemy = m.getAttackCoolDown();
			player_last_hit = false;
		}
	}
} 