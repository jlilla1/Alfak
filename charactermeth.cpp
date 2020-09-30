#include "character.h" 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//a characters oszt�ly met�dusai kifejtve, le�r�s az oszt�lyban

Character::Character(const std::string name, int Hp, const int Dpr) : name(name), Hp(Hp), Dpr(Dpr)
{
}



const std::string& Character::Getname() const {
	return name;
}

const int& Character::GetHp() const {
	return Hp;
}

const int& Character::GetDpr() const {
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
	if (fajl) {//l�tezik-e a f�jl
		string data[3];//�sszes adat
		string name;
		int hp;
		int dmg;

		string sortores;//txt legels� "�res sora"
		getline(fajl, sortores);
		//fajl.get(sortores);
		for (int n = 0; n < 3; n++) {
			string check;//aktu�lis karakter
			getline(fajl, check);
			int kezdes;
			for (int i = 0; i < check.length(); i++) {
				if (check[i] == ':') {//aktu�lis karakter ellen�rz�se
					kezdes = i + 1;
					for (int j = kezdes; j < check.length(); j++) {//adatok feldolgoz�sa ':'-t�l indulva
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
}