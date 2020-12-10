/**
* \author Alfak
*
* Last time code was modified: 2020/12/10
*
* Created on: 2020/12/10 16:00
*/

#include "character.h"
#include <iostream>
#include <string>

/**
*The functions of character.h are explained below.
*/

Character::Character(const std::string& name, const int maxHp, const int dmg, double attackcooldown) : name(name), maxHp(maxHp), dmg(dmg), attack_cooldown(attackcooldown)
{
	this->Hp = maxHp;
}

std::string Character::getName() const {
	return name;
}

int Character::getHp() const {
	return Hp;
}

int Character::getDmg() const {
	return dmg;
}

double Character::getAttackCoolDown() const {
	return attack_cooldown;
}

int Character::getMaxHp() const {
	return maxHp;
}

void Character::setHp(int value) {
	Hp -= value;
}

void Character::setHp_to_zero(){
	Hp = 0;
}

bool Character::isAlive() const {
	if (this->getHp() == 0) {
		return false;
	}else{
		return true;
	}
}


std::ostream& operator<<(std::ostream& os, const Character& C) {
	os << C.getName() << ": HP: " << C.getHp() << ", MaxHP:" << C.getMaxHp() << ", DMG: " << C.getDmg() << ", XP: " << '\n';
	return os;
}

