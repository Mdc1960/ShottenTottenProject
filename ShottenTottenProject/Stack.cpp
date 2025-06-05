#include "Stack.h"
#include "CardClan.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <random>

Stack::Stack(unsigned int&& capacity)
{
    this->capacity = capacity;
    //fillCardSet();
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
    if (size() < this->capacity) {
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

Iterator* Stack::createIterator()
{
    return new StackIterator(this,0);
}

Iterator* Stack::createIterator(unsigned int&& index)
{
    return (index <= size()) ? new StackIterator(this, index) : nullptr;
}

void Stack::fillClanStack()
{
    fillCardSet();
}

void Stack::fillTacticStack()
{
}

void Stack::fillCardSet()
{
    for (unsigned int index = 0; index < (this->capacity)/6; index++) {
        push(std::move(creatSingleCard(index + 1,Color::BLACK)));
        push(std::move(creatSingleCard(index + 1,Color::BLUE)));
        push(std::move(creatSingleCard(index + 1,Color::GREEN)));
        push(std::move(creatSingleCard(index + 1,Color::MALLOW)));
        push(std::move(creatSingleCard(index + 1,Color::PURPLE)));
        push(std::move(creatSingleCard(index + 1,Color::RED)));
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

std::unique_ptr<CardClan> Stack::creatSingleCard(unsigned int&& power, Color&& color)
{
    return std::move(std::make_unique<CardClan>(std::move(power), std::move(color)));
}

Stack::StackIterator Stack::begin()
{
    return StackIterator(this,0);
}

Stack::StackIterator Stack::end()
{
    return StackIterator(this, (int)(size() - 1));
}

Stack::StackIterator::StackIterator(Stack* stack, unsigned int index) :
    stack(stack),index(index)
{
}


bool Stack::StackIterator::hasNext()
{
    return this->index < this->stack->size();
}

bool Stack::StackIterator::hasLast()
{
    
    return index > 0;
}

bool Stack::StackIterator::isDone()
{
    return index == stack->size();
}

CardInterface* Stack::StackIterator::currentItem()
{
    return this->stack->cardCollection[index].get();
}

CardInterface* Stack::StackIterator::next()
{
    return this->stack->cardCollection[index++].get();
}

CardInterface* Stack::StackIterator::last()
{
    return this->stack->cardCollection[--index].get();
}



Stack::StackIterator Stack::StackIterator::operator++()
{
    this->index++;
    return *this;
}

Stack::StackIterator Stack::StackIterator::operator--()
{
    this->index--;
    return *this;
}

Stack::StackIterator Stack::StackIterator::operator--(int)
{
    --this->index;
    return *this;
}

Stack::StackIterator Stack::StackIterator::operator++(int)
{
    ++this->index;
    return *this;
}

bool Stack::StackIterator::operator==(const StackIterator& it)
{
    return (this->stack == it.stack) && (this->index == it.index);
}

CardInterface* Stack::StackIterator::operator*()
{
    return this->stack->cardCollection[index].get();
}

bool Stack::StackIterator::operator!=(const StackIterator& it)
{
    return !((this->stack == it.stack) && (this->index == it.index));
}
