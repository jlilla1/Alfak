#pragma once
#include <string>




//A harcol� karakterek oszt�lya
class Character
{
public:


	//Param�teres konstruktor Konstans N�v(nem v�ltozik), �let, konstans �t�s er�ss�g(nem v�ltozik)
	Character(const std::string name, int Hp, const int Dpr);

	//Vissza adja a karakter nev�t
	const std::string& Getname() const;

	//Vissza adja a karakter �let�t
	const int& GetHp() const;

	//Vissza adja a karakter �t�s er�ss�g�t a v�g�re a const az Attackedby miatt kell, hogy meg lehessen h�vni
	const int& GetDpr() const;

	/*Egyik karakter megt�madja a m�sikat. Konstans karakter referenci�t v�r param�terk�nt*/
	void Attackedby(const Character& X);
	//Egyszer� tostring met�tus ami egy stringet ad vissza a karakter param�tereivel, szebb lesz a k�d.
	std::string toString() const;

	static Character parseUnit(std::string fajlnev);

	//Priv�t adattagok
private:
	const std::string name; //A karakter neve
	int Hp;  //A karakter �lete
	const int Dpr; //A karakter �t�s er�ss�ge, Dpr = damage per round
};

