#include "Stack.h"
#include "CardClan.h"
#include <string>

Stack::Stack()
{
    gameMode = GameMode::BASE;
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
    if (size() <= MAX_NUMBER_CARD_IN_STACK) {
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
    for (unsigned int index = 0; index < MAX_NUMBER_CARD_IN_STACK; index++) {

        std::unique_ptr<CardClan> currentCard = nullptr;

        switch (gameMode) {
            case GameMode::BASE:
                currentCard = std::make_unique<CardClan>(std::to_string(index));
                push(std::move(currentCard));
                break;
            case GameMode::TACTIC:
                break;

            case GameMode::EXPERT:
                break;
        
        }
        
    }
}

std::unique_ptr<CardInterface> Stack::popAndGetBackCard()
{
    std::unique_ptr<CardInterface> currentCard = std::move(cardCollection[size() - 1]);
    pop();
    return currentCard;
}
