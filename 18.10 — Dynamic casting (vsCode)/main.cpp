#include <iostream>
#include <string>

class Base
{
protected:
    int m_value{};
    
public:
    Base(int value)
        : m_value{ value }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Base& base)
    {
        out << base.m_value;
        return out;
    }

    virtual ~Base() = default;
};

class Derived: public Base
{
protected:
    std::string m_name{};

public:
    Derived(int value, std::string_view name)
        : Base{ value }, m_name{ name }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Derived& base)
    {
        out << base.m_value << ' ' << base.m_name;
        return out;
    }

    std::string_view getName() const { return m_name; }
};

Base* getObject(bool returnDerived)
{
    if(returnDerived)
    {
        return new Derived{1, "Apple"};
    }
    else
    {
        return new Base{ 2 };
    }
}

int main()
{
    //The need for dynamic_cast:

    Base* b{ getObject(true) };// how do we print the Derived object's name here, having only a Base pointer?

    std::cout << *b << '\n';


    //dynamic_cast:

    Derived* d{ dynamic_cast<Derived*>(b) }; // use dynamic cast to convert Base pointer into Derived pointer
    
    //dynamic_cast failure: :)

    if(d)// make sure d is non-null:  So simple check !
        std::cout << "The name of the Derived is: " << d->getName() << '\n';
    
    delete b;

    //Downcasting with static_cast:

    //dynamic_cast and references:

    Derived Banana{77, "Banana"};// create an banana
    Base& base{ Banana };// set base reference to object
    Derived& derived{ dynamic_cast<Derived&>(base) };// dynamic cast using a reference instead of a pointer 

    std::cout << "With references: The name of the Derived is: " << derived.getName() << '\n';// we can access Derived::getName through derived

    //dynamic_cast vs static_cast:

    //Downcasting vs virtual functions:

    //A warning about dynamic_cast and RTTI:



    


    return 0;
}