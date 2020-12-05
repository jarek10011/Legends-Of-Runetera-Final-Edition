#include <iostream>
//dziala
// class BILL
// {
// public:
//     std::string data;
//     float netto;
//     float brutto;
//     int tax=23;
//     void wczytaj();;
//     float oblicz();
// };

//uj wie czy dziala
class BILL
{
private:
    // std::string data;
    float netto;
    float brutto;
    int tax = 23;
public:
    float getNetto()
    {
        return netto;
    }
    float wczytajNetto();
    float obliczBrutto();
};