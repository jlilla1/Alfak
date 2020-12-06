/**
* \author Alfak
*
* Last time code was modified: 2020.12.06
*
* Created on: 2020/12/06 07:41
*
*/


#pragma once
#include <string>

/**
* 
*\calss Character
*
*  This class contains the data of the characters.
*/
class Character
{
public:

	/// This is a parametric constructor. The parameters: name, health points, damage per round, attack speed. Some of them are constants because they are not changing during the program running.
	Character(const std::string name, int Hp, const int Dpr, float AttackCooldown);

	const std::string& Getname() const;			///< Returns the name of the character.

	const int& GetHp() const;					///< Returns the HP of the character.

	const int& GetDpr() const;					///< Returns the Dpr of the character. We need the const at the end because of Attackedby, without it we would not be able to call the function.

	const float& GetAttackCooldown() const;		///< Returns the attack speed of the character

	/// It is a simple toString method that returns a string with the character's parameters in it, it makes the code nicer.
	std::string toString() const;

	static Character parseUnit(std::string fajlnev);

	const void getAttackedby(const Character& X);

	const void setAkthp();						///< Sets the actual HP of the character.
	const int& getAkthp();						///< Returns the actual HP of the character.
	const void setDpr();						///< Sets the Dpr of the character according to its level.
	const void setXP(int amount);				///< Sets the XP of the character.
	const int& getLvl();						///< Returns the character's level.

	/// This method does the characters level ups according to the XP they collected.
	void lUp();

	static Character ManualUnit(std::string _name, int _hp, int _dmg, int _cdown);

private:						
	const std::string name;		///< The name of the character.
	int Hp;						///< The Health Points of the character.
	int aktHP;					///< The actual Health Points of the character.
	const int Dpr;				///< The character's strength, Dpr = damage per round.
	float AttackCooldown;		///< The required time between two punches.
	int xp;						///< The eXPerience of the character.
	int level;					///< The level the character is on.

	/// In this funcion one character attacks the other. It expects a constant character reference as parameter.
	void Attackedby(const Character& X);
};


