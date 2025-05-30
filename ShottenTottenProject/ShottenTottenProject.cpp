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

    h.printCardSet();

    std::cout << "Index : " << h.getPushIndex() << " ; " << h.getPopIndex() << std::endl;




    std::cout << "Hello World!!!" << std::endl;

    return 0;
}