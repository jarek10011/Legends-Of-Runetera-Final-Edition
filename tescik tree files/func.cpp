#include <iostream>
#include "header.h"
//dziala
// void  BILL::wczytaj()
// {
//     std::cout << "enter data: ";
//     std::cin >> data;
//     std::cout << "enter netto: ";
//     std::cin >> netto;
// }
// float BILL::oblicz()
// {
//  return netto*tax/100;
// }
//czy  dziala?
float BILL::wczytajNetto()
{

    std::cin  >>  netto;
    return netto;
}
float BILL::obliczBrutto()
{
    return netto*tax/100;
}