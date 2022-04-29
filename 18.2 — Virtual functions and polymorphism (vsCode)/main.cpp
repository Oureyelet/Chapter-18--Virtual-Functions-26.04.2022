#include <iostream>
#include <string_view>
#include <string>

//--------------------------------------------------------------------------------------------------------------------------
class Base
{
public:
    std::string_view getName() const { return "Base"; }
    virtual std::string_view getName_with_Virtual_Function() const { return "Base"; }// note addition of virtual keyword
};

class Derived: public Base
{
public:
    std::string_view getName() const { return "Derived"; }
    virtual std::string_view getName_with_Virtual_Function() const { return "Derived"; }// note addition of virtual keyword
};
//--------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------
class A
{
public:
    virtual std::string_view getName() const { return "A"; }
};

class B: public A
{
public:
    virtual std::string_view getName() const { return "B"; }
};

class C: public B
{
public:
    virtual std::string_view getName() const { return "C"; }
};

class D: public C
{
public:
    virtual std::string_view getName() const { return "D"; }
};
//--------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------
class Animal
{
protected:
    std::string m_name{};

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view animal)
        : m_name{ animal }
    {
    }

public:
    std::string_view getName() const { return m_name; }
    virtual std::string_view speak() const { return "???"; }

};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    virtual std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    virtual std::string_view speak() const { return "Woof"; }
};

void report(const Animal& animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}


int main()
{
    Derived derived;
    Base& rBase{ derived };

    std::cout << "rBase is a " << rBase.getName() << '\n';

    //Virtual functions and polymorphism:
    std::cout << "rBase is a " << rBase.getName_with_Virtual_Function() << '\n';

    C c;
    A& referenceBase{ c };
    std::cout << "referenceBase is a " << referenceBase.getName() << '\n';

    //A more complex example:
    Cat cat{ "Fred" };
    Dog dog{ "Garbo" };

    report(cat);
    report(dog);

    //array example:
    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };

    Dog garbo{ "garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };

    Animal* animal[]{ &fred, &misty, &zeke, &garbo, &pooky, &truffle };


    for(const auto& element : animal)
    {
        std::cout << element->getName() << " say  " << element->speak() << '\n';
    }
    
    //Return types of virtual functions:

    //Do not call virtual functions from constructors or destructors:

    //The downside of virtual functions:
    


    return 0;
}