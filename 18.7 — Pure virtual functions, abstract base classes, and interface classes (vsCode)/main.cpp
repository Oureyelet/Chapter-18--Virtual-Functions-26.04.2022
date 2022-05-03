#include <iostream>
#include <string>
#include <utility>
#include <string_view>

class Base
{
public:
    const char* sayHi() const { return "Hi"; } // a normal non-virtual function
    virtual const char* getName() const { return "Base"; } // a normal virtual function
    virtual int getValue() const = 0; // a pure virtual function
    // int doSomething() = 0; // Compile error: can not set non-virtual functions to 0
};

class Animal
{
protected:
    std::string m_name{};

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : m_name{ name }
    {
    }

public:
    std::string getName() const { return m_name; }
    virtual const char* speak() const { return "???"; }

    virtual ~Animal() = default;
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    const char* speak() const override { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    const char* speak() const override { return "Woof"; }
};

class Cow: public Animal
{
public:
    Cow(std::string_view name)
        : Animal{ name }
    {
    }

    const char* speak() const override { return "Moo"; }
};

int main()
{
    //Pure virtual (abstract) functions and abstract base classes:

    //A pure virtual function example:

    Cow cow{ "Betsy" };
    std::cout << cow.getName() << " say " << cow.speak() << '\n';

    //Pure virtual functions with bodies:

    //Interface classes:


    return 0;
}