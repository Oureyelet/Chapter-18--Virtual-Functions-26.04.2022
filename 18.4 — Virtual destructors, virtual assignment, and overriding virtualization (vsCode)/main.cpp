#include <iostream>

class Base
{
public:
    virtual ~Base() // note: virtual
    {
        std::cout << "Calling ~Base()\n";
    }
};

class Derived: public Base
{
private:
    int* m_array;

public:
    Derived(int lenght)
        : m_array{ new int[lenght] }
    {
    }

    virtual ~Derived() // note: virtual
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

class A
{
public:
    virtual ~A() = default;
    virtual const char* getName() const { return "A"; }
};

class B: public A
{
public:
    virtual const char* getName() const { return "B"; }
};

int main()
{
    //Virtual destructors:
    
    Derived* derived{ new Derived(5) };
    Base* base{ derived };

    delete base;

    //Virtual assignment:

    //Ignoring virtualization:
    A aDerived{};
    const A &bBase{ aDerived };
    // Calls A::getName() instead of the virtualized B::getName()
    std::cout << bBase.A::getName() << '\n';

    //Should we make all destructors virtual?:
    

    return 0;
}