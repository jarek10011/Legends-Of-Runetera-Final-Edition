#include <iostream>
#include "header.h"

int main()
{
    BILL xd;
    std::cout << "Enter netto: ";
    xd.wczytajNetto();

    std::cout << "Oblicone  brutto: "<< xd.obliczBrutto();
	std::cout << "bye!";
	return 0;    
}
