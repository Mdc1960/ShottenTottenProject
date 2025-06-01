#include "Defausse.h"
#include "CardClan.h"
#include <string>
#include <iostream>

void Defausse::pop()
{
	if (size()) {
		this->cardCollection.pop_back();
	}
}

void Defausse::fillCardSet()
{
	for (unsigned int index = 0; index < MAX_NUMBER_CARD_IN_DEFAUSSE; index++) {
		push(std::move(std::make_unique<CardClan>(std::to_string(index))));
	}
}

Iterator* Defausse::createIterator()
{
	return nullptr;
}

Defausse::Defausse()
{
}

std::size_t Defausse::size()
{
	return this->cardCollection.size();
}

void Defausse::push(std::unique_ptr<CardInterface> card)
{
	if (size() <= MAX_NUMBER_CARD_IN_DEFAUSSE) {
		this->cardCollection.push_back(std::move(card));
	}
}

void Defausse::printCardSet()
{
	for (auto& card : this->cardCollection) {
		std::cout << "Defausse : "; card->printCard();
	}
}
