#include "Defausse.h"
#include "CardClan.h"
#include "Color.h"
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
		push(std::move(std::make_unique<CardClan>(index, Color::BLEU)));
	}
}

Iterator* Defausse::createIterator()
{
	return new DefausseIterator(this,0);
}

Iterator* Defausse::createIterator(unsigned int&& pos)
{
	return (pos <= size()) ? new DefausseIterator(this, pos) : nullptr;
}

Defausse::DefausseIterator Defausse::begin()
{
	return DefausseIterator(this,0);
}

Defausse::DefausseIterator Defausse::end()
{
	return DefausseIterator(this, (int)(size() - 1));
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

CardInterface* Defausse::DefausseIterator::currentItem()
{
	return nullptr;
}

bool Defausse::DefausseIterator::isDone()
{
	return false;
}

Defausse::DefausseIterator::DefausseIterator(Defausse* defausse, unsigned int index) :
	defausse(defausse), index(index)
{
}

bool Defausse::DefausseIterator::hasNext()
{
	return index < this->defausse->size();
}

bool Defausse::DefausseIterator::hasLast()
{
	return index > 0;
}

CardInterface* Defausse::DefausseIterator::next()
{
	return this->defausse->cardCollection[index++].get();
}

CardInterface* Defausse::DefausseIterator::last()
{
	return this->defausse->cardCollection[--index].get();
}

Defausse::DefausseIterator Defausse::DefausseIterator::operator++()
{
	this->index++;
	return *this;
}

Defausse::DefausseIterator Defausse::DefausseIterator::operator--()
{
	this->index--;
	return *this;
}

Defausse::DefausseIterator Defausse::DefausseIterator::operator--(int)
{
	--this->index;
	return *this;
}

Defausse::DefausseIterator Defausse::DefausseIterator::operator++(int)
{
	++this->index;
	return *this;
}

bool Defausse::DefausseIterator::operator==(const DefausseIterator& it)
{
	return (this->defausse == it.defausse) && (this->index == it.index);
}

CardInterface* Defausse::DefausseIterator::operator*()
{
	return this->defausse->cardCollection[index].get();
}

bool Defausse::DefausseIterator::operator!=(const DefausseIterator& it)
{
	return !((this->defausse == it.defausse) && (this->index == it.index));
}
