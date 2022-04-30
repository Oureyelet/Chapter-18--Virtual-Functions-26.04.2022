#include <iostream>
#include <string_view>

//--------------------------------------------------------------------------------------------------------------
class A
{
public:
    //virtual std::string_view getName1(int x) { return "A"; }
    //virtual std::string_view getName2(int x) { return "A"; }
    virtual std::string_view getName3(int x) const { return "A"; }
};

class B: public A
{
public:
    //virtual std::string_view getName1(short int x) { return "B"; } // note: parameter is a short int
    //virtual std::string_view getName1(int x) const { return "B"; } // note: function is const
    std::string_view getName3(int x) const { return "B"; } // okay, function is an override of A::getName3(int)
};
//--------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------
class Base
{
public:
    // This version of getThis() returns a pointer to a Base class
    virtual Base* getThis() { std::cout << "called Base::getThis()\n"; return this; }
    void printType() { std::cout << "returned a Base\n"; }
};

class Derived: public Base
{
public:
    // Normally override functions have to return objects of the same type as the base function
	// However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
    Derived* getThis() override { std::cout << "called Derived::getThis()\n"; return this; }
    void printType() { std::cout << "returned a Derived\n"; }
};
//--------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------


int main()
{
    //The override specifier:
    B b{};
    A& rBase{ b };
    
    //std::cout << rBase.getName1(1) << '\b';
    //std::cout << rBase.getName2(2) << '\b';
    std::cout << rBase.getName3(3) << '\n';
    
    //The final specifier:

    //Covariant return types:
    Derived derived{};
    Base* base{ &derived };

    derived.getThis() -> printType(); // calls Derived::getThis(), returns a Derived*, calls Derived::printType
    base->getThis() -> printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType

    return 0;
}