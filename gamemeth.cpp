
#include "game.h"
#include <iostream>
//a Game osztály metódusai kifejtve, leírás az osztályban

Game::Game(const Character& A, const Character& B) : A(A), B(B)
{
}

void Game::Fight() {


	//ez lesz a számoló
	int i =0;
	
	
	

	//Elindúl a játék
	std::cout << "Game start" << "\n" << "\n\n";
	//ez lesz a számoló
	int i;
	//Ki írja a kezdő értékeit a karaktereknek
	std::cout << A.toString() << "\n\n";
	std::cout << B.toString() << "\n\n";
	/*Itt lehet választani melyik karakter legyen az első aki támad, Feltételezzük, hogy 
	jó bementet kapunk amúgy input ellenörzés kéne. Habár itt csak 2 érték van de az i egyben kör számoló is ami elég nagy lehet ezért int a típusa.*/

	std::cout << "Choose starter. |0 is " << A.Getname() << "|  |1 is " << B.Getname() << "|" << "\n\n";
	std::cin >> i;

	//Itt megy az oda vissza pofozgatás amíg az egyik élete el nem éri a 0-át
	while (A.GetHp() > 0 && B.GetHp() > 0)
	{
		if (i % 2 == 0) {

		
			B.Attackedby(A);
			
		}
		else {
			
			A.Attackedby(B);
			

			std::cout << "Round: " << i + 1 << " " << A.Getname() << " -> " << B.Getname() << "\n\n";
			B.Attackedby(A);
			std::cout<<A.toString()<<"\n\n";
			std::cout << B.toString() << "\n\n";
			std::cout << "\n\n";
		}
		else {
			std::cout << "Round: " << i + 1 << " " << B.Getname() << " -> " << A.Getname() << "\n\n";
			A.Attackedby(B);
			std::cout << A.toString() << "\n\n";
			std::cout << B.toString() << "\n\n";
			std::cout << "\n\n";

		}

		i++;


	}
	//Megnézi hogy ki vesztett és kiírja, lehetne külön metódus is, lehet késöbb az is lesz ha a feladathoz kell.
	if (A.GetHp() == 0) {

		std::cout <<  B.Getname() << " WINS. Remaining Hp: "<<B.GetHp() << "\n\n";
	}
	else {
		std::cout << A.Getname() << " WINS. Remaining Hp: " << A.GetHp() << "\n\n";

		std::cout << A.Getname() << " DIED " << B.Getname() << " WINS\n" << "\n\n";
	}
	else {
		std::cout << B.Getname() << " DIED " << A.Getname() << " WINS\n" << "\n\n";

	}
}


