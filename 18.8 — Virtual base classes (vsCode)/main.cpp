#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner: virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power }
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice{ power }
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer
{
public:
    Copier(int scaner, int printer, int power)
        : PoweredDevice { power },
        Scanner{ scaner, power }, Printer{ printer, power }
    {
    }
};

int main()
{
    //The diamond problem:
    Copier copie1{ 12, 22, 110 };

    //Virtual base classes:
    Scanner scan1{ 34, 2 };




    return 0;
}