#ifndef GAME_UTIL_H
#define GAME_UTIL_H

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

#endif