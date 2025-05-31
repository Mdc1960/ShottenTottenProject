#include <iostream>
#include "Hand.h"
#include "CardClan.h"
#include "Stack.h"
#include "Defausse.h"
#include "PlayerSide.h"
#include "Border.h"
#include "Bord.h"

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

    Bord& br = Bord::getInstance();
    br.fillBord(56, 12);
    br.printFirstPlayerBorderSide();
    std::cout << "BORD" << std::endl;
    br.printSecondPlayerBorderSide();



    std::cout << "Hello World!!!" << std::endl;

    return 0;
}