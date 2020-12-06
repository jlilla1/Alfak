/**
* \author Alfak
*
* Last time code was modified: 2020.12.06
*
* \date 2020/12/06 06:39
*
* Created on: 2020/12/06 06:39
*/


#pragma once
#include "character.h"

/**
* \calss Game
*/
class Game
{
public:
	/// This is a constructor that waits for 2 character references. These references will not change so they are constants.
	Game(const Character& A, const Character& B);

	/// This method runs the fight between the 2 characters.
	void Fight();

private:				
	Character A;		///< One of the characters.
	Character B;		///< The other character.

};

