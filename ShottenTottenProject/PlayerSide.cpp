#include "PlayerSide.h"
#include "CardClan.h"
#include "Color.h"
#include <iostream>
#include <string>

#include "ColorCombination.h"
#include "ColorSequenceCombination.h"
#include "SequenceCombination.h"
#include "SetCombination.h"
#include "SumCombination.h"

PlayerSide::PlayerSide() : capacity(3)
{
}

std::size_t PlayerSide::size()
{
    return this->cardCollection.size();
}

void PlayerSide::pop()
{
    if (size()) {
        this->cardCollection.pop_back();
    }
}

void PlayerSide::push(std::unique_ptr<CardInterface> card)
{
    if (size() < capacity) {
        this->cardCollection.push_back(std::move(card));
    }
}

void PlayerSide::printCardSet()
{
    unsigned int counter = 0;
    for (auto& card : this->cardCollection) {
        std::cout << "Player Side : "; card->printCard(); std::cout << "\n";
    }
}

void PlayerSide::fillCardSet()
{
    for (unsigned int index = 0; index < capacity; index++) {
        push(std::move(std::make_unique<CardClan>(0, Color::BLUE)));
    }
}

Iterator* PlayerSide::createIterator()
{
    return new PlayerSideIterator(this, 0);
}

Iterator* PlayerSide::createIterator(unsigned int&& pos)
{
    return new PlayerSideIterator(this, pos);
}

void PlayerSide::printCardSetInReverse()
{
    for (auto it = end(); it != begin()--; it--) {
        std::cout << "Player Side : "; (*it)->printCard(); std::cout << "\n";
    }
}

void PlayerSide::printCardByIndex(unsigned int&& index)
{
    if (index < size()) {
        this->cardCollection[index]->printCard();
    }
    
}

void PlayerSide::increaseCapacity()
{
    this->capacity++;
}

unsigned int PlayerSide::getCapacity() const
{
    return capacity;
}

CardInterface* PlayerSide::getCardByIndex(unsigned int&& indexCard)
{
    if (indexCard < size()) {
        return this->cardCollection[indexCard].get();
    }
    return nullptr;
}

std::vector<std::string> PlayerSide::getAllCardColor()
{
    std::vector<std::string> vect = std::vector<std::string>();

    for (const auto& card : cardCollection) {
        vect.push_back(card->getNamecard());
    }

    return vect;
}

void PlayerSide::putCardInCardSet(std::unique_ptr<CardInterface> card)
{
    if (putCardIndex < 3) {
        this->cardCollection[putCardIndex] = std::move(card);
        putCardIndex++;
    }
    else {
        throw GameException("This player side is full. You cannot put a card in this border.");
    }
}

const unsigned int PlayerSide::getPutCardIndex() const
{
    return putCardIndex;
}

const unsigned int PlayerSide::getPlayerSideCombination(unsigned int&& combinationId)
{
    unsigned int combinationPower = 0;

    std::vector<std::string> colorVect = getAllCardColorInPlayerSide();
    std::vector<unsigned int> numberVect = getAllCardNumberInPlayerSide();

    std::initializer_list<std::string> colorList;
    std::initializer_list<unsigned int> numberList;

    if (colorVect.size() == 3) {
        colorList = { colorVect[0],colorVect[1],colorVect[2] };
    }
    else {
        if (colorVect.size() == 4) {
            colorList = { colorVect[0],colorVect[1],colorVect[2],colorVect[3] };
        }
    }
    
    if (numberVect.size() == 3) {
        numberList = { numberVect[0],numberVect[1],numberVect[2] };
    }
    else {
        if (numberVect.size() == 4) {
            numberList = { numberVect[0],numberVect[1],numberVect[2],numberVect[3] };
        }
    }

    std::cout << "COLOR LIST == " << colorList.size() << std::endl;
    std::cout << "NUMBER LIST == " << numberList.size() << std::endl;

    unsigned int counter = 0;

    switch (std::move(combinationId)) {
    case 1:
        for (auto& n : numberList) {
            if (n == 0) {
                counter++;
            }
        }
        if (counter == 0) {
            combinationPower = ColorSequenceCombination<std::string, unsigned int>().playerCombinationBis(colorList, numberList);
        }
        
        break;
    case 2:
        for (auto& n : numberList) {
            if (n == 0) {
                counter++;
            }
        }
        if (counter == 0) {
            combinationPower = SetCombination<std::string>().playerCobinationBis(colorList, numberList);
        }
        
        break;
    case 3:
        for (auto& n : numberList) {
            if (n == 0) {
                counter++;
            }
        }
        if (counter == 0) {
            combinationPower = ColorCombination<std::string>().playerCombination(colorList);
        }
        
        break;
    case 4:
        for (auto& n : numberList) {
            if (n == 0) {
                counter++;
            }
        }
        if (counter == 0) {
            combinationPower = SequenceCombination<unsigned int>().playerCombination(numberList);
        }
        
        break;
    case 5:
        for (auto& n : numberList) {
            if (n == 0) {
                counter++;
            }
        }
        if (counter == 0) {
            combinationPower = SumCombination<unsigned int>().playerCombination(numberList);
        }
        
        break;
    default:
        break;
    }

    return combinationPower;
}

std::vector<std::string> PlayerSide::getAllCardColorInPlayerSide()
{
    std::vector<std::string> vect = std::vector<std::string>();

    for (auto& card : cardCollection) {
        if (dynamic_cast<CardClan*>(card.get())) {
            vect.push_back(((CardClan*)(card.get()))->getCardColor());
        }
        
    }

    return vect;
}

std::vector<unsigned int> PlayerSide::getAllCardNumberInPlayerSide()
{
    std::vector<unsigned int> vect = std::vector<unsigned int>();

    for (auto& card : cardCollection) {
        if (dynamic_cast<CardClan*>(card.get())) {
            vect.push_back(((CardClan*)(card.get()))->getCardNumber());
        }

    }

    return vect;
}

PlayerSide::PlayerSideIterator PlayerSide::begin()
{
    return PlayerSideIterator(this,0);
}

PlayerSide::PlayerSideIterator PlayerSide::end()
{
    return PlayerSideIterator(this,((int)(size() - 1)));
}

CardInterface* PlayerSide::PlayerSideIterator::currentItem()
{
    return this->playerSide->cardCollection[index].get();
}

bool PlayerSide::PlayerSideIterator::isDone()
{
    return index == this->playerSide->size();
}

PlayerSide::PlayerSideIterator::PlayerSideIterator(PlayerSide* playerSide, unsigned int index) :
    playerSide(playerSide), index(index)
{
}

bool PlayerSide::PlayerSideIterator::hasNext()
{
    return index < this->playerSide->size();
}

bool PlayerSide::PlayerSideIterator::hasLast()
{
    return index > 0;
}

CardInterface* PlayerSide::PlayerSideIterator::next()
{
    return this->playerSide->cardCollection[index++].get();
}

CardInterface* PlayerSide::PlayerSideIterator::last()
{
    return this->playerSide->cardCollection[--index].get();
}

PlayerSide::PlayerSideIterator PlayerSide::PlayerSideIterator::operator++()
{
    this->index++;
    return *this;
}

PlayerSide::PlayerSideIterator PlayerSide::PlayerSideIterator::operator--()
{
    this->index--;
    return *this;
}

PlayerSide::PlayerSideIterator PlayerSide::PlayerSideIterator::operator--(int)
{
    --this->index;
    return *this;
}

PlayerSide::PlayerSideIterator PlayerSide::PlayerSideIterator::operator++(int)
{
    ++this->index;
    return *this;
}

bool PlayerSide::PlayerSideIterator::operator==(const PlayerSideIterator& it)
{
    return (this->playerSide == it.playerSide) && (this->index == it.index);
}

CardInterface* PlayerSide::PlayerSideIterator::operator*()
{
    return this->playerSide->cardCollection[index].get();
}

bool PlayerSide::PlayerSideIterator::operator!=(const PlayerSideIterator& it)
{
    return !((this->playerSide == it.playerSide) && (this->index == it.index));
}
