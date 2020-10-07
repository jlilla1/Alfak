#pragma once
#include <string>




//A harcoló karakterek osztálya
class Character
{
public:


	//Paraméteres konstruktor Konstans Név(nem változik), élet, konstans ütés erõsség(nem változik)
	Character(const std::string name, int Hp, const int Dpr);

	//Vissza adja a karakter nevét
	const std::string& Getname() const;

	//Vissza adja a karakter életét
	const int& GetHp() const;

	//Vissza adja a karakter ütés erõsségét a végére a const az Attackedby miatt kell, hogy meg lehessen hívni
	const int& GetDpr() const;

	/*Egyik karakter megtámadja a másikat. Konstans karakter referenciát vár paraméterként*/
	void Attackedby(const Character& X);
	//Egyszerû tostring metótus ami egy stringet ad vissza a karakter paramétereivel, szebb lesz a kód.
	std::string toString() const;

	static Character parseUnit(std::string fajlnev);

	//Privát adattagok
private:
	const std::string name; //A karakter neve
	int Hp;  //A karakter élete
	const int Dpr; //A karakter ütés erõssége, Dpr = damage per round
};

