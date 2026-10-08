#include "BorderDecorator.h"

void BorderDecorator::setBorderCapacity(unsigned int newCap)
{
    innerBorder->setBorderCapacity(newCap);
}

unsigned int BorderDecorator::getBorderCapacity()
{
    return innerBorder->getBorderCapacity();
}

std::vector<std::string> BorderDecorator::getAllCardColorInPlayerSide(unsigned int&& playerSideId)
{
    return innerBorder->getAllCardColorInPlayerSide(std::move(playerSideId));
}

void BorderDecorator::pushCardInBorder(std::unique_ptr<CardInterface> card)
{
    innerBorder->pushCardInBorder(std::move(card));
}

void BorderDecorator::popCardInBorder(std::unique_ptr<CardInterface> card)
{
    innerBorder->popCardInBorder(std::move(card));
}

unsigned int BorderDecorator::getMaxCapacityInPlayerSide() const
{
    return innerBorder->getMaxCapacityInPlayerSide();
}

void BorderDecorator::setFirstPlayerSide(std::unique_ptr<PlayerSide> playerSide)
{
    innerBorder->setFirstPlayerSide(std::move(playerSide));
}

void BorderDecorator::setSecondPlayerSide(std::unique_ptr<PlayerSide> playerSide)
{
    innerBorder->setSecondPlayerSide(std::move(playerSide));
}

void BorderDecorator::printBorder()
{
    innerBorder->printBorder();
}

void BorderDecorator::printFirtPlayerSideCardByIndex(unsigned int&& index)
{
    innerBorder->printFirtPlayerSideCardByIndex(std::move(index));
}

void BorderDecorator::printSecondPlayerSideCardByIndex(unsigned int&& index)
{
    innerBorder->printSecondPlayerSideCardByIndex(std::move(index));
}

void BorderDecorator::putCardInFirstPlayerSide(std::unique_ptr<CardInterface> card)
{
    innerBorder->putCardInFirstPlayerSide(std::move(card));
}

void BorderDecorator::putCardInSecondPlayerSide(std::unique_ptr<CardInterface> card)
{
    innerBorder->putCardInSecondPlayerSide(std::move(card));
}

void BorderDecorator::printFirstPlayerBorderSide()
{
    innerBorder->printFirstPlayerBorderSide();
}

void BorderDecorator::printSecondPlayerBorderSide()
{
    innerBorder->printSecondPlayerBorderSide();
}

const unsigned int BorderDecorator::getFirstPlayerSidePutCardIndex() const
{
    return innerBorder->getFirstPlayerSidePutCardIndex();
}

const unsigned int BorderDecorator::getSecondPlayerSidePutCardIndex() const
{
    return innerBorder->getSecondPlayerSidePutCardIndex();
}

std::unordered_map<std::string, unsigned int> BorderDecorator::fillPlayerRevendicateMap(unsigned int&& playerSideId)
{
    return innerBorder->fillPlayerRevendicateMap(std::move(playerSideId));
}

CardInterface* BorderDecorator::getCardInPlayerSide(unsigned int&& playerSideId, unsigned int&& indexCard)
{
    return innerBorder->getCardInPlayerSide(std::move(playerSideId), std::move(indexCard));
}

const unsigned int BorderDecorator::determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination)
{
    return innerBorder->determineBorderWinnerByCombination(firstCombination, secondCombination);
}

const unsigned int BorderDecorator::getRevendicateBorderTotalValueFromMap(std::unordered_map<std::string, unsigned int>& map)
{
    return innerBorder->getRevendicateBorderTotalValueFromMap(map);
}

std::vector<unsigned int> BorderDecorator::getFirstPlayerSideAllCardNumber()
{
    return innerBorder->getFirstPlayerSideAllCardNumber();
}

std::vector<unsigned int> BorderDecorator::getSecondPlayerSideAllCardNumber()
{
    return innerBorder->getSecondPlayerSideAllCardNumber();
}

unsigned int BorderDecorator::claim()
{

    return innerBorder->claim();
}

