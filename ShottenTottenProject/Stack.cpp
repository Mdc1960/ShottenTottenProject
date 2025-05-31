#include "Stack.h"
#include "CardClan.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <random>

Stack::Stack(unsigned int&& capacity)
{
    this->capacity = capacity;
    fillCardSet();
}

std::size_t Stack::size()
{
    return this->cardCollection.size();
}

void Stack::pop()
{
    if (size() > 0) {
        this->cardCollection.pop_back();
    }
}

void Stack::push(std::unique_ptr<CardInterface> card)
{
    if (size() <= this->capacity) {
        this->cardCollection.emplace_back(std::move(card));
    }
    
}

void Stack::printCardSet()
{
    if (size()) {
        for (auto& card : this->cardCollection) {
            card.get()->printCard();
        }
    }
    else {
        std::cout << "Stack is empty" << std::endl;
    }
}

void Stack::fillCardSet()
{
    for (unsigned int index = 0; index < this->capacity; index++) {

        std::unique_ptr<CardInterface> currentCard = std::make_unique<CardClan>(std::to_string(index));
        push(std::move(currentCard));
        
    }
}

std::unique_ptr<CardInterface> Stack::popAndGetBackCard()
{
    std::unique_ptr<CardInterface> currentCard = std::move(cardCollection[size() - 1]);
    pop();
    return currentCard;
}

void Stack::shuffledStack()
{
    std::random_device randomDivice;
    std::mt19937       generator(randomDivice());
    std::shuffle(cardCollection.begin(), cardCollection.end(), generator);
}
