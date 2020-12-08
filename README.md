# Alfak
Ezt a projektet az Alfak csapata készítette a Modern Szoftverfejlesztési Eszközök tantárgy keretein belül.

## A program rövid ismertetése:
Ez a program egy egyszerű PRG játék szimuláció, melyben a megadott karakter paraméterek alapján levezényel egy párbajt az adott hős és szörny(ek) között. A karakteradatok megadhatóak manuálisan vagy pedig fájlok segítségével.

## Működés:

A `main.cpp` fájlban történik az adatok beolvasása, mely a korábbiakban említettek szerint történhet manuálisan vagy pedig `.json` fájlok segítségével. A program bemenetként a hős és a szörnyek adatait várja, melyek a `name`, a `health_points`, a `damage` és az `attack_cooldown`. Amennyiben az adatok helyesek, az ellenőrzés lezárul és elindul a játék. Hogyha valamilyen adat nem megfelelő, a kód hibaüzenettel jelzi ezt a felhasználó felé.

A `Character` classban a karakter adatokhoz kapcsolódó műveletek találhatók. A `character.h`-ban létrehozott osztály folyamatait a `character.ccp` fájlban láthatjuk kifejtve. Az itt található függvények állítják be a karakterek életét, azaz `Hp`-ját, valamint itt követhetjük nyomon, hogy mely karakter van még életben.

A `Monster` class-ban tárolódnak a szörnyek adatai, a `Monster.h` és a `Monster.cpp` fájlokban találjuk a hozzájuk kapcsolódó kódrészeket. Itt található egy beolvasást ellenőrző függvény, valamint egy olyan metódus, ami levezényli a harcos elleni támadást.

A `Hero` class részben hasonlít a fent említett `Monster`-re, azonban itt más föggvények is jelen vannak. Az ehhez tartozó fájlok a `Hero.h` és a `Hero.cpp`. Itt is vagy egy `attack` függvény, mely levezényli a támadás (természetesen ezúttal a szörny(ek) irányába), valamint egy beolvasáshoz használt ellenőrző metódus. Emellett a hősök szintet is léphetnek, melyhez tudnunk kell, hogy a karakternek pontosan mennyi `xp`-je van, mely kezdetben 0, valamint a kezdeti szintje 1. A szintlépés folyamatáért a `levelup` függvény felel. Emellett jelen van egy `fightTilDeath` metódus is, mely a harc menetéért felel. A névből is látszik, hogy a küzdelem addig tart, míg az egyik fél meg nem hal, azaz a `Hp`-ja nulla nem lesz.

Mindezek mellett szerepel egy `JSON` osztály is, melyhez a `JSON.h` és a `JSON.cpp` tartozik. Ebben láthatóak a különböző fájlbeolvasáshoz tartozó check-ek és itt történik az adatbeolvasás.

A kód rendelkezik egy ellenőrző script-tel, mely a `GitHub Actions`-ben is látható. Ehhez egy `Makefile`-t használunk. Ez vizsgálja, hogy a generált output helyes-e. Emellett a programhoz tartozik Doxygen dokumentáció, melyet szintén nyomon követhetünk a `GitHub Actions`-ben, valamint a `GitHub Pages`-ben.

A programhoz tartozó dokumentáció [itt](https://jlilla1.github.io/Alfak/) elérhető.
