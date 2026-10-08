#include <iostream>
#include "Hand.h"
#include "CardClan.h"
#include "Stack.h"
#include "Defausse.h"
#include "PlayerSide.h"
#include "Border.h"
#include "Bord.h"
#include "ColorCombination.h"
#include "ColorSequenceCombination.h"
#include "SetCombination.h"
#include "SequenceCombination.h"
#include "SumCombination.h"
#include "Exception.h"
#include "Game.h"
#include "GameBase.h"
#include "ColinMaillardCard.h"
#include "CombatDeBoueCard.h"


int main()
{

    Util::readRules();

    std::shared_ptr<Game> game;



    switch (Util::gameMode) {
    case GameMode::BASE:

        game = std::make_shared<GameBase>();

        game->startGame();

        break;
    case GameMode::TACTIC:
        std::cout << "Game Tactic" << std::endl;
        break;
    case GameMode::EXPERT:
        std::cout << "Game Expert" << std::endl;
        break;
    default:
        break;
    }

    return 0;
}