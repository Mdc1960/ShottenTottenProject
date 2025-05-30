#include "Hand.h"

Hand::Hand() : indexToPopCard(0), indexToPushCard(0)
{
}

std::size_t Hand::size()
{
    return this->cardCollection.size();
}

void Hand::pop()
{
    if (size() <= MAX_NUMBER_CARD_IN_HAND) {
        if (indexToPopCard < size()) {
            this->cardCollection.erase(this->cardCollection.begin() + indexToPopCard);
        }
    }
}

void Hand::push(std::unique_ptr<CardInterface> card)
{
    if (size() <= MAX_NUMBER_CARD_IN_HAND) {
        if (indexToPushCard < size()) {
            this->cardCollection.insert(this->cardCollection.begin() + indexToPushCard, std::move(card));
        }
    }
}

void Hand::printCardSet()
{
    if (size()) {
        for (auto& card : this->cardCollection) {
            //TODO : Print Playe Hand.
            std::cout << "Player Hand" << std::endl;
        }
    }
    else {
        std::cout << "Card Collection is empty !!!" << std::endl;
    }
    
}

void Hand::fillCardSet()
{
    for (unsigned int index = 0; index < MAX_NUMBER_CARD_IN_HAND; ++index) {
        setIndexToPushCard(index);
        std::unique_ptr<CardInterface> u = std::make_unique<CardInterface>();
        push(std::move(u));
    }
}

void Hand::setIndexToPushCard(const unsigned int& indexToPushCard)
{
    this->indexToPushCard = indexToPushCard;
}

void Hand::setIndexToPopCard(const unsigned int& indexToPopCard)
{
    this->indexToPopCard = indexToPopCard;
}
