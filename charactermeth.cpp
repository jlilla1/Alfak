
#include "character.h" 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//a characters osztály metódusai kifejtve, leírás az osztályban

Character::Character(const std::string name, int Hp, const int Dpr) : name(name), Hp(Hp), Dpr(Dpr)
{


#include "character.h" 

//a characters osztály metódusai kifejtve, leírás az osztályban

Character::Character(const std::string name,int Hp,const int Dpr) : name(name), Hp(Hp), Dpr(Dpr)
{	

}




const std::string& Character::Getname() const {
	return name;
}

const int& Character::GetHp() const {
	return Hp;
}

const int& Character::GetDpr() const {

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



std::string Character::toString() const {
	std::string s;
	s = "Name: " + Getname() + " Hp: " + std::to_string(GetHp()) + " DPR: " + std::to_string(GetDpr());
	return s;
}


Character Character::parseUnit(std::string fajlnev) {
	ifstream fajl(fajlnev);
	if (fajl) {//létezik-e a fájl
		string data[3];//összes adat
		string name;
		int hp;
		int dmg;

		string sortores;//txt legelsõ "üres sora"
		getline(fajl, sortores);
		//fajl.get(sortores);
		for (int n = 0; n < 3; n++) {
			string check;//aktuális karakter
			getline(fajl, check);
			int kezdes;
			for (int i = 0; i < check.length(); i++) {
				if (check[i] == ':') {//aktuális karakter ellenõrzése
					kezdes = i + 1;
					for (int j = kezdes; j < check.length(); j++) {//adatok feldolgozása ':'-tól indulva
						if (check[j] != '"' and check[j] != ' ' and check[j] != ',') data[n] += check[j];
					}
					break;
				}
			}
		}
		name = data[0];
		hp = stoi(data[1]);
		dmg = stoi(data[2]);

		return Character(name, hp, dmg);
	}
	else {
		const std::string FajlHiba("File does not exist!");
		throw std::runtime_error(FajlHiba);
	}

 std::string Character::toString() const{
	std::string s; 
	s = "Name: " + Getname() + " Hp: " + std::to_string(GetHp()) + " DPR: " + std::to_string(GetDpr());
	return s;

}