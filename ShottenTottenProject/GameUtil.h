#ifndef GAME_UTIL_H
#define GAME_UTIL_H




#include <iostream>
#include <string>
#include "Color.h"


static const unsigned int ZERO = 0;
static const unsigned int ONE = 1;
static const unsigned int TWO = 2;



enum class GameMode {
	BASE,
	TACTIC,
	EXPERT
};

enum class BorderStatus {
	FIRST_PLAYER_REVENDICATE,
	SECOND_PLAYER_REVENDICATE,
	BORDER_IS_NOT_REVENDICATED
};

enum class Combine {
	COLOR_SEQUENCE_ = 5,
	SET_ = 4,
	COLOR_ = 3,
	SEQUENCE_ = 2,
	SUM_ = 1
};

class Util {

public:

	static GameMode gameMode;
	static unsigned int opponentChoiseMade;

	static std::string playerName;
	static std::string opponetName;
	static std::string aitName;


	static bool rules;
	static void readRules();
	

	static const bool equalIngnoreCase(std::string& first, std::string&& second);
	static void configureGame();
	static void printMode();

	static std::string transformeColorToString(Color color);


};

#endif