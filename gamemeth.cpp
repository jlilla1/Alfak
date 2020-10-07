
#include "game.h"
#include <iostream>
//a Game oszt�ly met�dusai kifejtve, le�r�s az oszt�lyban

Game::Game(const Character& A, const Character& B) : A(A), B(B)
{
}

void Game::Fight() {

	//ez lesz a sz�mol�
	int i =0;
	
	
	
	//Itt megy az oda vissza pofozgat�s am�g az egyik �lete el nem �ri a 0-�t
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
	//Megn�zi hogy ki vesztett �s ki�rja, lehetne k�l�n met�dus is, lehet k�s�bb az is lesz ha a feladathoz kell.
	if (A.GetHp() == 0) {
		std::cout <<  B.Getname() << " WINS. Remaining Hp: "<<B.GetHp() << "\n\n";
	}
	else {
		std::cout << A.Getname() << " WINS. Remaining Hp: " << A.GetHp() << "\n\n";
	}
}


