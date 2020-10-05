
#include "character.h" 

//a characters osztály metódusai kifejtve, leírás az osztályban

Character::Character(const std::string name,int Hp,const int Dpr) : name(name), Hp(Hp), Dpr(Dpr)
{	
}



const std::string& Character::Getname() const{
	return name;
}

const int& Character::GetHp() const{
	return Hp;
}

const int&  Character::GetDpr() const{
	return Dpr;
}

void Character::Attackedby(const Character& X) {

	
	if (Hp - X.GetDpr() < 0) {
		Hp = 0;
	}
	else {
		Hp = Hp - X.GetDpr();
	}


}



 std::string Character::toString() const{
	std::string s; 
	s = "Name: " + Getname() + " Hp: " + std::to_string(GetHp()) + " DPR: " + std::to_string(GetDpr());
	return s;
}