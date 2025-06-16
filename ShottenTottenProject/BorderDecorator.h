#ifndef BORDER_DECORATOR_H
#define BORDER_DECORATOR_H

#include "Border.h"

class BorderDecorator : public Border
{

protected :

	std::unique_ptr<Border> innerBorder;

public :

	BorderDecorator(unique_ptr<Border> param) : innerBorder(std::move(param)) {};

	void setBorderCapacity(unsigned int newCap) override;
	unsigned int getBorderCapacity() override;
	virtual std::vector<std::string> getAllCardColorInPlayerSide(unsigned int&& playerSideId) override;

	virtual void pushCardInBorder(std::unique_ptr<CardInterface> card) override;
	virtual void popCardInBorder(std::unique_ptr<CardInterface> card)override;

	virtual unsigned int getMaxCapacityInPlayerSide() const override;

	virtual void setFirstPlayerSide(std::unique_ptr<PlayerSide> playerSide) override;
	virtual void setSecondPlayerSide(std::unique_ptr<PlayerSide> playerSide) override;

	virtual void printBorder();

	virtual void printFirtPlayerSideCardByIndex(unsigned int&& index) override;
	virtual void printSecondPlayerSideCardByIndex(unsigned int&& index) override;

	virtual void putCardInFirstPlayerSide(std::unique_ptr<CardInterface> card) override;
	virtual void putCardInSecondPlayerSide(std::unique_ptr<CardInterface> card) override;

	virtual void printFirstPlayerBorderSide() override;
	virtual void printSecondPlayerBorderSide() override;

	virtual const unsigned int getFirstPlayerSidePutCardIndex() const override;
	virtual const unsigned int getSecondPlayerSidePutCardIndex() const override;

	virtual std::unordered_map<std::string, unsigned int> fillPlayerRevendicateMap(unsigned int&& playerSideId) override;

	virtual CardInterface* getCardInPlayerSide(unsigned int&& playerSideId, unsigned int&& indexCard) override;

	virtual const unsigned int determineBorderWinnerByCombination(unsigned int& firstCombination, unsigned int& secondCombination) override;
	virtual const unsigned int getRevendicateBorderTotalValueFromMap(std::unordered_map<std::string, unsigned int>& map) override;

	virtual std::vector<unsigned int> getFirstPlayerSideAllCardNumber() override;
	virtual std::vector<unsigned int> getSecondPlayerSideAllCardNumber() override;
	unsigned int claim() override;

};

#endif