# Alfak
Ezt a programot az Alfak csapata készítette a Modern Szoftverfejlesztési Eszközök tantárgy részeként.

## A program rövid ismertetése:
Ez a program egy egyszerű PRG játék szimuláció, melyben a megadott karakter paraméterek alapján levezényel egy párbalyt az adott két karakter között, majd kiírja a győztes nevét. A karakteradatok megadhatóak manuálisan vagy pedig fájlok segítségével.

## Működés:

Az `alpha.cpp` fájlban történik az adatok beolvasása, mely a korábbiakban említettek szerint történhet manuálisan vagy pedig `.json` fájlok segítségével. A program 9 adatot vár, melyek a játék neve, valamint karakterenként 4-4 paraméter, amik a **name**, a **Hp**, a **Dpr** (damage per round) és az **AttackCooldown**. Amennyiben az adatok helyesek, az ellenőrzés lezárul és elindul a játék. Hogyha valamilyen adat nem megfelelő, a kód egy hibaüzenettel jelzi ezt a felhasználó felé. A fájlbeolvasás esetén az adatok sorrendje felcserélhető, a program így is képes lesz felhasználni az adatokat. 

A **Game** class felel a játék levezényléséért. A `game.h` fájlban található függvények a `game.cpp`-ben vannak kifejtve. A **Fight** metódusban látható a játék menete, ami a következő: először **A** karakter üti meg **B**-t, majd a játékot a továbbiakban az **attackspeed** határozza meg. Mindig az fog ütni, akinek hamarabb lejár az időzítője. A programba egy **level up** funkció is be lett építve, erről a továbbiakban fogok még részletesebben írni. A pofozgatás addig folytatódik, amíg az egyik karakter HP-ja eléri a 0-t. Ekkor a program kiírja a győztes nevét, valamint a megmaradt HP-ját.

A **Character** classban a karakterekkel végzett műveletek találhatók. A korábbiakhoz hasonlóan a `character.h`-ban létrehozott osztály folyamatait a `character.ccp` fájlban láthatjuk kifejtve. A **Character** függvény egy paraméteres konstruktor, mely a beolvasásból származó 4 adatot várja paraméterként, valamint mindkét karakter kezdeti **xp**-jét és **level**-jét 0-ra állítja. Egy adott karakter **xp**-je, akkor fog nőni, hogyha ő sebzi meg az ellenfelét. Amikor ez az **xp** eléri a 100-at, akkor a karakter szintet lép. A **toString** metódus egy egyszerű string-é konvertáló függvény, mely a karakterek adatait fűzi egy string-be. A `character.cpp` végén található **parseUnit** függvény felel a fájlbeolvasásért.

A kód rendeklezik egy ellenőrző script-tel is, mely a GitHub Actions-ben is látható. Ez vizsgálja, hogy a generált output helyes-e. Emellett a programhoz tartozik Doxygen dokumentáció, melyet szintén nyomonkövethetünk az actions-ben, valamint a GitHub Pages-ben.

A programhoz tartozó dokumentáció linkje [itt](https://jlilla1.github.io/Alfak/) elérhető.

