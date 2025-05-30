#include "Hand.h"
#include "CardClan.h"


Hand::Hand()
{
    indexToPushCard = 0;
    indexToPopCard = 0;
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
        else {
            std::cout << "Index out of bound, you cannot pop at this index." << std::endl;
        }
    }
}

void Hand::push(std::unique_ptr<CardInterface> card)
{
    if (size() >= 0 && size() < MAX_NUMBER_CARD_IN_HAND) {
        if (indexToPushCard <= size()) {
            this->cardCollection.insert(this->cardCollection.begin() + indexToPushCard, std::move(card));
        }
    }
    
    
}

void Hand::printCardSet()
{
    if (size()) {
        for (auto& card : this->cardCollection) {
            //TODO : Print Player Hand.
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
        std::unique_ptr<CardInterface> u = std::make_unique<CardClan>();
        push(std::move(u));
        std::cout << "Index Push : " << indexToPushCard << std::endl;
    }
}

void Hand::setIndexToPushCard(unsigned int& indexToPushCard)
{
    this->indexToPushCard = indexToPushCard;
}

void Hand::setIndexToPopCard(const unsigned int& indexToPopCard)
{
    this->indexToPopCard = indexToPopCard;
}

unsigned int Hand::getPushIndex() const
{
    return indexToPushCard;
}

unsigned int Hand::getPopIndex() const
{
    return indexToPopCard;
}

void Hand::pushCardToHandByIndex(unsigned int&& indexToPush,std::unique_ptr<CardInterface>card)
{
    setIndexToPushCard(indexToPush);
    push(std::move(card));
}

void Hand::popCardFromHandByIndex(unsigned int&& indexToPop)
{
    setIndexToPopCard(indexToPop);
    pop();
}

std::unique_ptr<CardInterface> Hand::popAndGetCardByIndex(unsigned int&& index)
{
    std::unique_ptr<CardInterface> card = nullptr;
    if (index < size()) {
        card = std::move(this->cardCollection[index]);
        popCardFromHandByIndex(std::move(index));
    }
    return card;
}
