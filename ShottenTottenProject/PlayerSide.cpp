#include "PlayerSide.h"
#include "CardClan.h"
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
        push(std::move(std::make_unique<CardClan>(std::to_string(index))));
    }
}

Iterator* PlayerSide::createIterator()
{
    return nullptr;
}

void PlayerSide::increaseCapacity()
{
    this->capacity++;
}

unsigned int PlayerSide::getCapacity() const
{
    return capacity;
}
