#ifndef GAME_UTIL_H
#define GAME_UTIL_H

#include <iostream>
#include <string>
#include "Color.h"

/**
 * Represents the numeric value zero used throughout the game logic.
 */
static const unsigned int ZERO = 0;

/**
 * Represents the numeric value one used throughout the game logic.
 */
static const unsigned int ONE = 1;

/**
 * Represents the numeric value two used throughout the game logic.
 */
static const unsigned int TWO = 2;

/**
 * Defines the available game modes for the application.
 */
enum class GameMode {
    BASE,      /**< Standard base game mode. */
    TACTIC,    /**< Tactical variant of the game. */
    EXPERT     /**< Expert difficulty game mode. */
};

/**
 * Indicates whether a border has been revendicated by a player.
 */
enum class BorderStatus {
    FIRST_PLAYER_REVENDICATE,          /**< The first player has revendicated the border. */
    SECOND_PLAYER_REVENDICATE,         /**< The second player has revendicated the border. */
    BORDER_IS_NOT_REVENDICATED         /**< The border has not been revendicated. */
};

/**
 * Defines the different combination categories used in scoring logic.
 */
enum class Combine {
    COLOR_SEQUENCE_ = 5, /**< A color sequence combination. */
    SET_ = 4,            /**< A set combination. */
    COLOR_ = 3,          /**< A color-based combination. */
    SEQUENCE_ = 2,       /**< A sequence combination. */
    SUM_ = 1             /**< A sum-based combination. */
};

/**
 * Utility class providing shared constants, game configuration helpers,
 * and common operations used by the application.
 */
class Util {

public:

    /**
     * Current game mode selected by the user.
     */
    static GameMode gameMode;

    /**
     * Tracks whether the opponent's choice has been made.
     */
    static unsigned int opponentChoiseMade;

    /**
     * Name of the current player.
     */
    static std::string playerName;

    /**
     * Name of the opponent player.
     */
    static std::string opponetName;

    /**
     * Name of the AI-controlled player, if used.
     */
    static std::string aitName;

    /**
     * Indicates whether the rules are enabled and displayed.
     */
    static bool rules;

    /**
     * Displays the game's rules to the player.
     */
    static void readRules();

    /**
     * Compares two strings while ignoring case differences.
     *
     * @param first The first string to compare.
     * @param second The second string to compare.
     * @return true if both strings are equal ignoring case, otherwise false.
     */
    static const bool equalIngnoreCase(std::string& first, std::string&& second);

    /**
     * Configures the game based on the selected settings.
     */
    static void configureGame();

    /**
     * Prints the current game mode to the console.
     */
    static void printMode();

    /**
     * Converts a color value into its display string representation.
     *
     * @param color The color to transform.
     * @return A string representation of the provided color.
     */
    static std::string transformeColorToString(Color color);

};

#endif
