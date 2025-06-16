#include "BorderBase.h"

BorderBase::BorderBase() :
	Border()
{
	
}

unsigned int BorderBase::claim()
{

	std::unordered_map<std::string, unsigned int> playerCombinationMap = fillPlayerRevendicateMap(std::move(1));
	std::unordered_map<std::string, unsigned int> opponentCombinationMap = fillPlayerRevendicateMap(std::move(2));

	unsigned int playerCombination = getRevendicateBorderTotalValueFromMap(playerCombinationMap);
	std::cout << "----------------------------------------------------------------" << std::endl;
	unsigned int opponentCombination = getRevendicateBorderTotalValueFromMap(opponentCombinationMap);

	return determineBorderWinnerByCombination(playerCombination, opponentCombination);

}
