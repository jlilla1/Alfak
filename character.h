#ifndef CHARACTER_H
#define CHARACTER_H



#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "JSON.h"

class Character {
protected:
	std::string name;
	int maxHp; 	
	int dmg; 	
	int Hp; 	
	double attack_cooldown; 
	public:
	Character(const std::string& name, const int maxHp, const int dmg,
		double attackcooldown);


	std::string getName() const;
	 	int getHp() const;
	 	int getDmg() const;
 	int getMaxHp() const;


	     double getAttackCoolDown() const;
	  	 bool isAlive() const;
	       void setHp(int value);
     	void setHp_to_zero();
  	friend std::ostream& operator<<(std::ostream& os, const Character& C);


};


#endif // !CHARACTER_H 