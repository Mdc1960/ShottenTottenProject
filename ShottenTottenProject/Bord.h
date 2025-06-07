#ifndef GAME_BORD_H
#define GAME_BORD_H

#include "Border.h"
#include "Stack.h"
#include "Defausse.h"
#include "BorderBase.h"
#include <vector>
#include "Observer.h"

static const unsigned int MAX_BORDER_NUMBER_IN_BORD = 9;

class Game;


class Bord : public Observer
{

private :

	std::unique_ptr<Stack> clanStack;
	std::unique_ptr<Stack> tacticStack;
	std::vector<std::unique_ptr<Border>> borders;
	std::unique_ptr<Defausse> defausse;

	bool isClanStackEmpty = false;

	unsigned int clanStackCapacity;
	unsigned int tacticStackCapacity;

	static Bord* instance;

	Bord();
	~Bord();

	Bord(const Bord& bord) = delete;
	Bord(Bord&& bord) = delete;

	void createClanStack(unsigned int&& capacity);
	void createTacticStack(unsigned int&& capacity);
	void fillBorders();


public :

	static Bord& getInstance();

	void update(Observable* observable) override;
	

	void shuffledClanStack();
	void shuffledTacticStack();

	const unsigned int getBorderSidePutCardIndex(unsigned int&& borderIndex, unsigned int&& sideId);

	

	void printBorders();

	size_t getBorderSize() const;

	void printFirstPlayerBorderSide();
	void printSecondPlayerBorderSide();
	void createBordStacks(unsigned int&& clanCapacity, unsigned int&& tacticCapacity);

	void putCardInBorderByPlayerIdAndColumnIndex(std::unique_ptr<CardInterface> card,unsigned int&& playerId, unsigned int&& columnIndex);

	void showClanStack();
	void showTacticStack();

	std::unique_ptr<CardInterface> popAndGetCardFromClanStack();
	std::unique_ptr<CardInterface> popAndGetCardFromTacticStack();

	void setIsClanStackEmpty(bool&& b);
	const bool getIsClanStackEmpty() const;

};

#endif