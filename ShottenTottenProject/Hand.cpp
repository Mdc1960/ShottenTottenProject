#include "Hand.h"
#include "CardClan.h"
#include "Color.h"
#include <string>


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
    if (indexToPushCard < MAX_NUMBER_CARD_IN_HAND) {
        this->cardCollection.insert(this->cardCollection.begin() + indexToPushCard, std::move(card));
    }
}

void Hand::printCardSet()
{
    if (size()) {
        unsigned int pos = 0;
        for (auto& card : this->cardCollection) {
            std::cout << "(" << pos << ") :"; card->printCard();
            pos++;
        }
    }
    else {
        std::cout << "Card Collection is empty !!!" << std::endl;
    }

    
    
}

void Hand::fillCardSet()
{
    for (unsigned int index = 0; index < MAX_NUMBER_CARD_IN_HAND; index++) {
        setIndexToPushCard(index);
        push(std::move(std::make_unique<CardClan>(index, Color::BLUE)));
    }
}

Iterator* Hand::createIterator()
{
    return new HandIterator(this,0);
}

Iterator* Hand::createIterator(unsigned int&& pos)
{
    return (pos <= size()) ? new HandIterator(this, pos) : nullptr;
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

void Hand::pushBackCard(std::unique_ptr<CardInterface> card)
{
    if (size() < MAX_NUMBER_CARD_IN_HAND) {
        cardCollection.push_back(std::move(card));
    }
    else {
        std::cout << "Your hand is full." << std::endl;
    }
}

Hand::HandIterator Hand::begin()
{
    return HandIterator(this,0);
}

Hand::HandIterator Hand::end()
{
    return HandIterator(this,(int)(size() - 1));
}

CardInterface* Hand::HandIterator::currentItem()
{
    return this->hand->cardCollection[index].get();
}

bool Hand::HandIterator::isDone()
{
    return this->index == this->hand->size();
}

Hand::HandIterator::HandIterator(Hand* hand, unsigned int index) :
    hand(hand), index(index)
{
}

bool Hand::HandIterator::hasNext()
{
    return index < this->hand->size();
}

bool Hand::HandIterator::hasLast()
{
    return index > 0;
}

CardInterface* Hand::HandIterator::next()
{
    return this->hand->cardCollection[index++].get();
}

CardInterface* Hand::HandIterator::last()
{
    return this->hand->cardCollection[--index].get();
}

Hand::HandIterator Hand::HandIterator::operator++()
{
    this->index++;
    return *this;
}

Hand::HandIterator Hand::HandIterator::operator--()
{
    this->index--;
    return *this;
}

Hand::HandIterator Hand::HandIterator::operator--(int)
{
    --this->index;
    return *this;
}

Hand::HandIterator Hand::HandIterator::operator++(int)
{
    ++this->index;
    return *this;
}

bool Hand::HandIterator::operator==(const HandIterator& it)
{
    return (this->hand == it.hand) && (this->index == it.index);
}

CardInterface* Hand::HandIterator::operator*()
{
    return this->hand->cardCollection[index].get();
}

bool Hand::HandIterator::operator!=(const HandIterator& it)
{
    return !((this->hand == it.hand) && (this->index == it.index));
}
