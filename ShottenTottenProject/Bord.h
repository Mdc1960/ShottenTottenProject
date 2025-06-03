#ifndef GAME_BORD_H
#define GAME_BORD_H

#include "Border.h"
#include "Stack.h"
#include "Defausse.h"
#include "BorderBase.h"


class Bord
{

private :

	std::unique_ptr<Stack> clanStack;
	std::unique_ptr<Stack> tacticStack;
	std::unique_ptr<Border> borders;
	std::unique_ptr<Defausse> defausse;

	static Bord* instance;

	Bord();
	~Bord();

	Bord(const Bord& bord) = delete;
	Bord(Bord&& bord) = delete;

	void createClanStack(unsigned int&& capacity);
	void createTacticStack(unsigned int&& capacity);


public :

	static Bord& getInstance();
	

	void shuffledClanStack();
	void shuffledTacticStack();

	void printFirstPlayerBorderSide();
	void printSecondPlayerBorderSide();
	void fillBord(unsigned int&& clanCapacity, unsigned int&& tacticCapacity);


};

#endif