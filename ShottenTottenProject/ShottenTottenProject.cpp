#include <iostream>
#include "Hand.h"
#include "CardClan.h"
#include "Stack.h"
#include "Defausse.h"
#include "PlayerSide.h"
#include "Border.h"
#include "Bord.h"
#include "ColorCombination.h"
#include "ColorSequenceCombination.h"
#include "SetCombination.h"
#include "SequenceCombination.h"
#include "SumCombination.h"
#include "Exception.h"
#include "Game.h"


int main()
{

    /*Hand h = Hand();

    h.fillCardSet();
    h.push(std::move(std::make_unique<CardClan>()));
    h.push(std::move(std::make_unique<CardClan>()));
    h.push(std::move(std::make_unique<CardClan>()));

    h.setIndexToPopCard(2);

    h.pop();

    h.setIndexToPopCard(6);

    h.pop();

    h.setIndexToPopCard(4);

    h.pop();

    h.popCardFromHandByIndex(0);
    h.pushCardToHandByIndex(0, std::move(std::make_unique<CardClan>()));

    std::unique_ptr<CardClan> a = std::make_unique<CardClan>();
    a->setName("CL");

    h.pushCardToHandByIndex(0, std::move(a));

    h.printCardSet();



    std::cout << "Index : " << h.getPushIndex() << " ; " << h.getPopIndex() << std::endl;

    std::cout << "Clan : " << CardClan::counter << std::endl;

    auto b = std::move(h.popAndGetCardByIndex(0));

    std::cout << "Name Pop : " << ((CardClan*)b.get())->getName() << std::endl;
    h.printCardSet();*/

    /*Stack s = Stack(56);
    s.fillCardSet();
    s.printCardSet();//Have to be private.

    std::unique_ptr<CardInterface> cc = std::move(s.popAndGetBackCard());

    std::cout << "Name Pop : "; cc.get()->printCard();

    s.printCardSet();

    std::cout << "Clan : " << CardClan::counter << std::endl;*/

    /*Defausse d = Defausse();

    d.fillCardSet();

    d.printCardSet();

    d.pop();
    d.printCardSet();*/

    /*/PlayerSide p = PlayerSide();
    p.fillCardSet();
    p.printCardSet();

    p.pop();
    p.printCardSet();*/

    /*Border bd = Border();

    bd.printFirstPlayerBorderSide();
    bd.printSecondPlayerBorderSide();*/

    /*Bord& br = Bord::getInstance();
    br.fillBord(56, 12);
    br.printFirstPlayerBorderSide();
    std::cout << "BORD" << std::endl;
    br.printSecondPlayerBorderSide();*/

    /*Stack s = Stack(std::move(11));

    s.fillCardSet();

    std::cout << "Size = " << s.size() << std::endl;

    for (auto it = s.begin(); it != s.end()++; ++it) {
        std::cout << "A ::: "; (*it)->printCard();
    }

    std::cout << "\n";

    for (auto it = s.end(); it != s.begin()--; it--) {
        std::cout << "D ::: "; (*it)->printCard();
    }

    Iterator* itr = s.createIterator();

    std::cout << "IsDone = " << itr->isDone() << std::endl;
    int i = 0;
    while (itr->hasNext()) {
        std::cout << "B ::: "; (itr->next())->printCard();
        
    }

    std::cout << "IsDone = " << itr->isDone() << std::endl;

    Iterator* lit = s.createIterator((unsigned int)(s.size()));

    if (lit != nullptr) {
        while (lit->hasLast()) {
            std::cout << "C ::: "; (lit->last())->printCard();
        }
    }*/


/*Hand h = Hand();

h.fillCardSet();

std::cout << "Size = " << h.size() << std::endl;

for (auto it = h.begin(); it != h.end()++; ++it) {
    std::cout << "A ::: "; (*it)->printCard();
}

std::cout << "\n";

for (auto it = h.end(); it != h.begin()--; it--) {
    std::cout << "D ::: "; (*it)->printCard();
}

Iterator* itr = h.createIterator();

std::cout << "IsDone = " << itr->isDone() << std::endl;
int i = 0;
while (itr->hasNext()) {
    std::cout << "B ::: "; (itr->next())->printCard();
}

std::cout << "IsDone = " << itr->isDone() << std::endl;

Iterator* lit = h.createIterator((unsigned int)(h.size()));

if (lit != nullptr) {
    while (lit->hasLast()) {
        std::cout << "C ::: "; (lit->last())->printCard();
    }
}*/


/*Defausse h = Defausse();

h.fillCardSet();

std::cout << "Size = " << h.size() << std::endl;

for (auto it = h.begin(); it != h.end()++; ++it) {
    std::cout << "A ::: "; (*it)->printCard();
}

std::cout << "\n";

for (auto it = h.end(); it != h.begin()--; it--) {
    std::cout << "D ::: "; (*it)->printCard();
}

Iterator* itr = h.createIterator();

std::cout << "IsDone = " << itr->isDone() << std::endl;
int i = 0;
while (itr->hasNext()) {
    std::cout << "B ::: "; (itr->next())->printCard();
}

std::cout << "IsDone = " << itr->isDone() << std::endl;

Iterator* lit = h.createIterator((unsigned int)(h.size()));

if (lit != nullptr) {
    while (lit->hasLast()) {
        std::cout << "C ::: "; (lit->last())->printCard();
    }
}*/


/*PlayerSide h = PlayerSide();

h.fillCardSet();

std::cout << "Size = " << h.size() << std::endl;

for (auto it = h.begin(); it != h.end()++; ++it) {
    std::cout << "A ::: "; (*it)->printCard();
}

std::cout << "\n";

for (auto it = h.end(); it != h.begin()--; it--) {
    std::cout << "D ::: "; (*it)->printCard();
}

Iterator* itr = h.createIterator();

std::cout << "IsDone = " << itr->isDone() << std::endl;
int i = 0;
while (itr->hasNext()) {
    std::cout << "B ::: "; (itr->next())->printCard();
}

std::cout << "IsDone = " << itr->isDone() << std::endl;

Iterator* lit = h.createIterator((unsigned int)(h.size()));

if (lit != nullptr) {
    while (lit->hasLast()) {
        std::cout << "C ::: "; (lit->last())->printCard();
    }
}*/


/*ColorCombination cc = ColorCombination();

std::cout << "Are Same ?=? " << cc.cardAreSameColor<std::string>({"A","A","A","A"}) << std::endl;*/

/*ColorSequenceCombination cs = ColorSequenceCombination();

std::cout << "Are Same ?=? " << cs.cardAreSameColor<std::string>({ "A","A","A","A" }) << std::endl;
std::cout << "Are Sequence ?=? " << cs.cardAreSequence({ 25,1,2,3,4,5,7}) << std::endl;

SequenceCombination sc = SequenceCombination();

std::cout << "Sequenced : " << sc.cardAreSequence({ 8,2,5 }) << std::endl;
std::cout << "Sequenced bis : " << sc.cardAreSequence({ 8,6,7 }) << std::endl;

SetCombination st = SetCombination();

std::cout << "Set : " << st.cardAreSameColor({ 8,2,5 }) << std::endl;
std::cout << "Set bis : " << st.cardAreSameValue({ 8,6,7 }) << std::endl;

std::cout << "Set : " << st.cardAreSameColor({ 8,8,8 }) << std::endl;
std::cout << "Set bis : " << st.cardAreSameValue({ 1,1,1 }) << std::endl;*/

std::unique_ptr<PlayerSide> p1 = std::make_unique<PlayerSide>();
std::unique_ptr<PlayerSide> p2 = std::make_unique<PlayerSide>();
p1->fillCardSet();
p2->fillCardSet();

std::unique_ptr<BorderBase> b = std::make_unique<BorderBase>();

std::vector<std::string> firstVect = b->getAllCardColorInPlayerSide(std::move(1));
std::vector<std::string> secondVect = b->getAllCardColorInPlayerSide(std::move(2));

std::cout << "HGSDHJ : " << firstVect[0] << std::endl;

std::initializer_list<std::string> list = { firstVect[0],firstVect[1],firstVect[2] };
std::initializer_list<std::string> list1 = { secondVect[0],secondVect[1],secondVect[2] };

for (std::string s : list) {
    std::cout << "P : " << s << std::endl;
}

ColorCombination<std::string> cb = ColorCombination<std::string>();

std::cout << "Player1 ColorCombination : " << cb.playerCombination(list) << std::endl;
std::cout << "Player2 ColorCombination : " << cb.playerCombination(list1) << std::endl;

SequenceCombination<unsigned int> sc = SequenceCombination<unsigned int>();

std::cout << "P1 sequence : " << sc.playerCombination({ 1,2,3 }) << std::endl;
std::cout << "P2 sequence : " << sc.playerCombination({ 5,2,3 }) << std::endl;

ColorSequenceCombination<std::string, unsigned int> cs = ColorSequenceCombination<std::string, unsigned int>();
std::cout << "P1 cs : " << cs.cardAreSameColor<std::string>({ "A","A","A" }) << std::endl;
std::cout << "P2 cs : " << cs.cardAreSequence<unsigned int>({ 1,2,3 }) << std::endl;

std::cout << "PP3 cs : " << cs.playerCombinationBis({ "A","A","A" }, { 1,2,3 }) << std::endl;

SetCombination<std::string> stc = SetCombination<std::string>();

std::cout << "P1 SET : " << stc.cardAreSameColor({ "A","A","A" }) << std::endl;
std::cout << "P2 SET : " << stc.cardAreSameValue({ 1,1,1 }) << std::endl;
std::cout << "PP3 SET : " << stc.playerCobinationBis({ "A","A","A" } ,{ 1,1,1 }) << std::endl;

SumCombination<unsigned int> sm = SumCombination<unsigned int>();

std::cout << "P1 Sum : " << sm.playerCombination({ 1,8,3 }) << std::endl;


BorderBase bbs = BorderBase();


Bord& brd = Bord::getInstance();

brd.printBorders();

std::cout << "Size : " << brd.getBorderSize() << std::endl;

try {
    brd.putCardInBorderByPlayerIdAndColumnIndex(std::move(std::make_unique<CardClan>(1, Color::GREEN)),std::move(1),std::move(0));
    brd.putCardInBorderByPlayerIdAndColumnIndex(std::move(std::make_unique<CardClan>(2, Color::ORANGE)),std::move(1),std::move(0));
    brd.putCardInBorderByPlayerIdAndColumnIndex(std::move(std::make_unique<CardClan>(4, Color::PURPLE)),std::move(1),std::move(0));
    brd.printBorders();
    brd.putCardInBorderByPlayerIdAndColumnIndex(std::move(std::make_unique<CardClan>(3, Color::RED)),std::move(1),std::move(0));
    brd.printBorders();
}
catch (GameException& exp) {
    std::cout << "\aError while puting card : " << exp.what() << std::endl;
}
try {
    brd.putCardInBorderByPlayerIdAndColumnIndex(std::move(std::make_unique<CardClan>(1, Color::GREEN)),std::move(2),std::move(1));
    brd.putCardInBorderByPlayerIdAndColumnIndex(std::move(std::make_unique<CardClan>(2, Color::ORANGE)),std::move(2),std::move(1));
    brd.putCardInBorderByPlayerIdAndColumnIndex(std::move(std::make_unique<CardClan>(4, Color::PURPLE)),std::move(2),std::move(1));
    brd.printBorders();
    brd.putCardInBorderByPlayerIdAndColumnIndex(std::move(std::make_unique<CardClan>(3, Color::RED)),std::move(2),std::move(1));
    brd.printBorders();
}
catch (GameException& exp) {
    std::cout << "\aError while puting card : " << exp.what() << std::endl;
}

brd.printBorders();

std::cout << "-------------------------GAME PART-----------------------------" << std::endl;

Game g = Game();
g.putCardInBordersColumnUsingPlayerId(std::move(std::make_unique<CardClan>(3, Color::RED)), std::move(2), std::move(0));
g.putCardInBordersColumnUsingPlayerId(std::move(std::make_unique<CardClan>(5, Color::YELLOW)), std::move(1), std::move(1));
brd.printBorders();


    std::cout << "Hello World!!!" << std::endl;

    return 0;
}