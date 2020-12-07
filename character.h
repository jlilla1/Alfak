/**
* \class Character
*
* \Author Alfak
*
* Last time code was modified: 2020/12/07
*
* Created on: 2020/12/07 15:02
*/

#ifndef CHARACTER_H
#define CHARACTER_H

/**
* This is the class of the fighting characters. This class contains the character properties.
* The functions are explained further in character.cpp.
*/

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "JSON.h"

class Character {
protected:
	std::string name;		///< The name of the character.
	int maxHp; 				///< The maximum health points of the character.
	int dmg; 				///< The damage of the character.
	int Hp; 				///< The health points of the character.
	double attack_cooldown; ///< The time elapsed between the character's two strikes.
	public:
	Character(const std::string& name, const int maxHp, const int dmg,
		double attackcooldown);


	std::string getName() const;			///< Returns the character's name.
	 	int getHp() const;					///< Returns the character's health points.
	 	int getDmg() const;					///< Returns the character's damage.
 	int getMaxHp() const;					///< Returns the character's maximum health points.


	     double getAttackCoolDown() const;	///< Returns the character's attack cooldown.
	  	 bool isAlive() const;				///< This bool teels you wether the character is still alive or it is dead. The value is 1 if the character is alive, 0 if it is not.
		 /// Sets the character's health points.
		 void setHp(int value);	
		 /// Sets the character's health points to zero.
		 void setHp_to_zero();				
  	friend std::ostream& operator<<(std::ostream& os, const Character& C);


};


#endif // !CHARACTER_H 