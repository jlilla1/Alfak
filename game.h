#pragma once
#include "character.h"





class Game
{
public:
	//Konstruktor ami 2 karakter referenciát vár és ezek végig maradnak tehát konstans
	Game(const Character& A, const Character& B);

	  /*Ez a metódus futtatja le a harcot a megadott 2 karakter között.
		A megadott feladathoz képest minimális különbség, hogy ki lehet választani a kezdõ karaktert 0 vagy 1 és hogy 
		kiírjuk a köröket. Mod 2 vel döntjük el melyik kör van(0 illetve páros szám vagy páratlan szám alapján)*/

	void Fight();

	//Privát adattagok
private:
	Character A; //Az egyik karakter
	Character B; //A másik karakter.

};

