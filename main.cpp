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
    saveEvenToFile();
}


