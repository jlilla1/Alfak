#include <string>
#include "game.h" 
#include <iostream>
//Alfák megoldása
//2020.09.23 javaslatok beépítve

int main(int argc, char* argv[])
{
	try {
		//argumentum ellenörzés. Ha valaki megadja az összes argumentumot az indításnál akkor ezek száma 7(a program neve+2*3 paraméter: név,hp,dpr)
		if (argc < 3) {
			std::cout << "Please give all of the arguments when you start the programe It will work. Or change the comments in the programe if "
				<< "you are a pussycat, it works just as well. #the programmer " << "\n\n"; //ha valaki nem adná meg akkor a program nem hal meg.
			return 1;                                  //vicces üzenet ami jelzi a hibát, ha kell a kommentek kiszedésével lehet más futást is indítani
		}

		/*Ha megvan mind a 7 adat akkor létrejönnek a karakterek és fut a program ahogy kell, a atoi
		azért kell mert arz argv tömb alapvetõen karaktertömb és kell típus konvertálás a mûködéshez.*/
		else {

			Character A = Character::parseUnit(argv[1]);
			Character B = Character::parseUnit(argv[2]);



			Game NewGame(A, B);       /*A játék osztály példánya "elindít" egy új játékot A és B karakterrel.
										A karakterek sorrendje nem fontos mert az alap feladatot kiegészítettük azzal,
										hogy a futásnál választani lehet hogy melyik karakter kezdje az ütést.*/

			NewGame.Fight();    //Elindítja a játék Fight metódusát( A és B karakter felvátolt ütése)
		}

		return 0;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
		return 1;
	}

}