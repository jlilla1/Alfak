#include <string>
#include "game.h" 
#include <iostream>
//Alf�k megold�sa
//2020.09.23 javaslatok be�p�tve

int main(int argc, char* argv[])
{
	try {
		//argumentum ellen�rz�s. Ha valaki megadja az �sszes argumentumot az ind�t�sn�l akkor ezek sz�ma 7(a program neve+2*3 param�ter: n�v,hp,dpr)
		if (argc < 3) {
			std::cout << "Please give all of the arguments when you start the programe It will work. Or change the comments in the programe if "
				<< "you are a pussycat, it works just as well. #the programmer " << "\n\n"; //ha valaki nem adn� meg akkor a program nem hal meg.
			return 1;                                  //vicces �zenet ami jelzi a hib�t, ha kell a kommentek kiszed�s�vel lehet m�s fut�st is ind�tani
		}

		/*Ha megvan mind a 7 adat akkor l�trej�nnek a karakterek �s fut a program ahogy kell, a atoi
		az�rt kell mert arz argv t�mb alapvet�en karaktert�mb �s kell t�pus konvert�l�s a m�k�d�shez.*/
		else {

			Character A = Character::parseUnit(argv[1]);
			Character B = Character::parseUnit(argv[2]);



			Game NewGame(A, B);       /*A j�t�k oszt�ly p�ld�nya "elind�t" egy �j j�t�kot A �s B karakterrel.
										A karakterek sorrendje nem fontos mert az alap feladatot kieg�sz�tett�k azzal,
										hogy a fut�sn�l v�lasztani lehet hogy melyik karakter kezdje az �t�st.*/

			NewGame.Fight();    //Elind�tja a j�t�k Fight met�dus�t( A �s B karakter felv�tolt �t�se)
		}

		return 0;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}

}