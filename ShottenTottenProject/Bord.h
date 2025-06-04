#ifndef GAME_BORD_H
#define GAME_BORD_H

#include "Border.h"
#include "Stack.h"
#include "Defausse.h"
#include "BorderBase.h"
#include <vector>


class Bord
{

private :

	std::unique_ptr<Stack> clanStack;
	std::unique_ptr<Stack> tacticStack;
	std::vector<std::unique_ptr<Border>> borders;
	std::unique_ptr<Defausse> defausse;

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
	

	void shuffledClanStack();
	void shuffledTacticStack();

	void printBorders();

	size_t getBorderSize() const;

	void printFirstPlayerBorderSide();
	void printSecondPlayerBorderSide();
	void fillBord(unsigned int&& clanCapacity, unsigned int&& tacticCapacity);


};

#endif