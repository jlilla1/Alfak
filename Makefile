SHELL := /bin/bash
OBJS := main.o character.o Hero.o Monster.o
CFLAGS := -Wall -std=c++17
CC := clang++

build: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

main.o: main.cpp character.h JSON.h Hero.h Monster.h
	$(CC) $(CFLAGS) -c main.cpp

character.o: character.cpp character.h JSON.h
	$(CC) $(CFLAGS) -c character.cpp

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

Hero.o: Hero.cpp Hero.h JSON.h Monster.h character.h
	$(CC) $(CFLAGS) -c Hero.cpp

Monster.o: Monster.cpp Monster.h Hero.h character.h JSON.h
	$(CC) $(CFLAGS) -c Monster.cpp

clean:
	rm -rf *.o add