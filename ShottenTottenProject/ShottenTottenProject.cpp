#include <iostream>
#include "Hand.h"
#include "CardClan.h"

int main()
{

    Hand h = Hand();

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
    h.printCardSet();


    std::cout << "Hello World!!!" << std::endl;

    return 0;
}