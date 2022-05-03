#include <iostream>

class Base
{
public:
    virtual void function1() { std::cout << "I'm Base function 1" << '\n'; }
    virtual void function2() { std::cout << "I'm Base function 2" << '\n'; }
};

class D1: public Base
{
public:
    virtual void function1() { std::cout << "I'm D1 function 1" << '\n'; }
};

class D2: public Base
{
public:
    virtual void function2() { std::cout << "I'm D2 function 2" << '\n'; }
};

int main()
{
    D1 d1; //d1 is a D1 object, d1 has its *__vptr set to the D1 virtual table.
    Base* dPtr{ &d1 };
    dPtr->function1();

    Base base;
    Base* pBase{ &base };
    pBase->function1();


    return 0;
}