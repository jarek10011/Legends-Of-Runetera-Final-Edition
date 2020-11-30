
#include <iostream>
#include <fstream>
class person_data
{
private:
    std::string name;
    std::string surname;
    int phoneNumber;

public:
    person_data(const std::string &name, const std::string &surname, int phoneNumber)
    {
        this->name = name;
        this->surname = surname;
        this->phoneNumber = phoneNumber;
    }
    
    person_data(std::istream &input_stream)
    {
        input_stream >> name >> surname >> phoneNumber;
    }
    std::string getName() const
    {
        return name;
    }
    std::string gegetSurname() const
    {
        return surname;
    }
    unsigned int getNumber() const
    {
        return phoneNumber;
    }
    bool isEven() const
    {
        return phoneNumber % 2 == 0;
    }
    void saveToFile()
    {
        std::ofstream ofile;
        ofile.open("person_data.txt", std::ios_base::app);
        if (ofile.is_open())
        {
            ofile << getName() << " " << gegetSurname() << " " << getNumber() << std::endl;
            ofile.close();
        }
        else
        {
            std::cout << "Unable to open file";
        }
    }
};
void saveEvenToFile()
{
    std::ifstream ifile;
    ifile.open("person_data.txt");
    std::ofstream ofile;
    ofile.open("isEven.txt");
    std::ofstream oddfile;
    oddfile.open("odd.txt");
    //create  open file  oddFIle
    if (ifile.is_open() && ofile.is_open())
    {
        while (!ifile.eof())
        {
            person_data p(ifile);
            if (p.isEven())
            {
                ofile << p.getName() << " " << p.gegetSurname() << " " << p.getNumber() << std::endl;
            }
            else
            {
                oddfile << p.getName() << " " << p.gegetSurname() << " " << p.getNumber() << std::endl;
            }
        }

        ofile.close();
        ifile.close();
        oddfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
}
person_data readData()
{
    std::string name;
    std::string surname;
    int phoneNumber;
    std::cout << "Enter name and surname: ";
    std::cin >> name >> surname;
    std::cout << "And pls give me ur mobile phone: ";
    std::cin >> phoneNumber;
    person_data pd(name, surname, phoneNumber);
    return pd;
};

void showdata(const person_data &show)
{
    std::cout << show.getName();
    std::cout << show.gegetSurname();
    std::cout << show.getNumber();
}

int main()
{
    int howMany;
    std::cout << "how many people will you introduce?" << std::endl;
    std::cout << "Enter:  ";
    std::cin >> howMany;
    for (int i = 0; i < howMany; i++)
    {
        person_data pd = readData();
        showdata(pd);
        pd.saveToFile();
    }
std::cout << "AABJASDBJSA"<<std::endl;
    saveEvenToFile();
}


 #include <iostream>
 #include <vector>
 #include <utility>

/********** ZADANIE 1 ****************/
class Pojazd
{
protected:
    Pojazd(int maxPredkosc, int iloscKol)
        :maxPredkosc_(maxPredkosc), iloscKol_(iloscKol){}
    const unsigned maxPredkosc_;
    const unsigned iloscKol_;
    float aktualnaPredkosc_ {};
    virtual void jazda(float predkosc) = 0;
public:
    float getPredkosc(){return aktualnaPredkosc_;}

};

class Auto : public Pojazd
{
public:
    Auto() : Pojazd(140, 4) {};
    void jazda(float predkosc) override {
        if (predkosc <= maxPredkosc_){
            aktualnaPredkosc_ = predkosc;
        }
    }
};

class Motor : public Pojazd
{
public:
    Motor() : Pojazd(140, 2) {};
    void przyspiesz(float przyspieszenie){
        if (aktualnaPredkosc_ + przyspieszenie < maxPredkosc_){
            aktualnaPredkosc_ += przyspieszenie;
        }
    }
    void jazda(float predkosc) override {
        if (predkosc <= maxPredkosc_){
            aktualnaPredkosc_ = predkosc;
        }
    }
};

class Tir : public Pojazd
{
public:
    Tir() : Pojazd(80, 8) {};
    void zaladoj() {};
    void jazda(float predkosc) override {
        if (predkosc <= maxPredkosc_){
            aktualnaPredkosc_ = predkosc;
        }
    }
};

/********** ZADANIE 2 ****************/

int maxSequence(const std::vector<int>& arr){
    int max = 0;
    int suma = 0;
    for (int i=0; i<arr.size(); i++) {
        suma += arr.at(i);
        if (suma>max) { max=suma;}
        if (suma<0) { suma=0;}
    }
    return max;
}


int main(){
    /********** ZADANIE 1 TEST ****************/
    float prędkoscDlaKazdego = 50;
    float prędkoscDlaAutaMotor = 110;
    float prędkoscZaWysoka = 160;

    Tir tir;
    Auto pojazd;
    Motor motor;

    tir.jazda(prędkoscDlaKazdego);
    pojazd.jazda(prędkoscDlaKazdego);
    motor.jazda(prędkoscDlaKazdego);
    
    if(tir.getPredkosc()!=prędkoscDlaKazdego){std::cout<<"Niedziała Tir\n";}
    if(pojazd.getPredkosc()!=prędkoscDlaKazdego){std::cout<<"Niedziała Auto\n";}
    if(motor.getPredkosc()!=prędkoscDlaKazdego){std::cout<<"Niedziała Motor\n";}
    
    tir.jazda(prędkoscDlaAutaMotor);
    if(tir.getPredkosc()!=prędkoscDlaKazdego){std::cout<<"Niedziała Tir\n";}
   
    pojazd.jazda(prędkoscDlaAutaMotor);
    motor.jazda(prędkoscDlaAutaMotor);
    if(pojazd.getPredkosc()!=prędkoscDlaAutaMotor){std::cout<<"Niedziała Auto\n";}
    if(motor.getPredkosc()!=prędkoscDlaAutaMotor){std::cout<<"Niedziała Motor\n";}

    motor.przyspiesz(20);
    if(motor.getPredkosc()!=130){std::cout<<"Niedziała Motor\n";}

   
    /********** ZADANIE 2 TEST ****************/
    std::vector<std::pair<int,std::vector<int>>> test =
    {
        {155,{7, 4, 11, -11, 39, 36, 10, -6, 37, -10, -32, 44, -26, -34, 43, 43}},
        {90,{-22, -15, -7, -11, 10, -2, -17, 21, 21, 27, 21, -8, -17, 21, 1, -28, -1, -15, -29, -1, -20, -18, 25, -20, 13, 7, 7, 7, -19, 24, -13, -8, -22, 12, 11, 19, -19, 26, 9, -29, 22, -1, -4, -24, -9, 27, -21, 20, -17, -20}},
        {92,{-19, -6, 7, -2, 3, 9, 14, -20, 20, 20, 29, -10, 22, -27, 2, -14, -28, -6, -2, -21, 24, 5, 4, -19, 0, -22, 13, -9, -23, -15, 12, -10, 11, -9, 19, -16, -29, 4, -4, 21, -7, -3, -20, -15, 2, 15, 3, 4, -20, -29}},
        {194,{6, 28, 10, 19, 12, 28, -15, 26, -6, -6, -18, 21, 8, 16, -19, 6, 18, 3, 17, -28, 7, -15, -2, -24, 9, -19, 20, -29, 18, 20, 15, -7, 18, -3, -17, 1, -6, -2, -4, 20, 22, 11, 12, 2, -2, 23, -21, -15, -4, 26}},
        {11,{1, 2, 3, 5}},
        {6,{-2, 1, -3, 4, -1, 2, 1, -5, 4}},
        {0,{}},
        {0,{-2, -3, -5}}

    };
    for(auto it : test){
        if(it.first != maxSequence(it.second)){
            std::cout<<"Zadanie 2 Niedziała\n";
        }
    }


    return 0;
}

