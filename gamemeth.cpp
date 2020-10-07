
#include "game.h"
#include <iostream>
//a Game osztály metódusai kifejtve, leírás az osztályban

Game::Game(const Character& A, const Character& B) : A(A), B(B)
{
}

void Game::Fight() {

	//ez lesz a számoló
	int i =0;
	
	
	
	//Itt megy az oda vissza pofozgatás amíg az egyik élete el nem éri a 0-át
	while (A.GetHp() > 0 && B.GetHp() > 0)
	{
		if (i % 2 == 0) {
		
			B.Attackedby(A);
			
		}
		else {
			
			A.Attackedby(B);
			
		}

		i++;


	}
	//Megnézi hogy ki vesztett és kiírja, lehetne külön metódus is, lehet késöbb az is lesz ha a feladathoz kell.
	if (A.GetHp() == 0) {
		std::cout <<  B.Getname() << " WINS. Remaining Hp: "<<B.GetHp() << "\n\n";
	}
	else {
		std::cout << A.Getname() << " WINS. Remaining Hp: " << A.GetHp() << "\n\n";
	}
}


