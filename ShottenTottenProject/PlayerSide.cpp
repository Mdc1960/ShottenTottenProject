#include "PlayerSide.h"
#include "CardClan.h"
#include "Color.h"
#include <iostream>
#include <string>

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
    if (size() <= capacity) {
        this->cardCollection.push_back(std::move(card));
    }
}

void PlayerSide::printCardSet()
{
    for (auto& card : this->cardCollection) {
        std::cout << "Player Side : "; card->printCard();
    }
}

void PlayerSide::fillCardSet()
{
    for (unsigned int index = 0; index < capacity; index++) {
        push(std::move(std::make_unique<CardClan>(0, Color::BLEU)));
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
