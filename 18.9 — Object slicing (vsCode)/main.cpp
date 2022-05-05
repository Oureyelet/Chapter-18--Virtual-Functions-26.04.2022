#include <iostream>
#include <vector>
#include <functional> // for std::reference_wrapper

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    virtual const char* getName() const { return "Base"; }
    int getValue() const { return m_value; }
};


//FUNCTION PROTOTYPE:
void printName_by_value(const Base base);
void printName_by_references(const Base& base);

class Derived: public Base
{
private:
    double m_value{};

public:
    Derived(int value)
        : Base{ value }
    {
    }

    virtual const char* getName() const { return "Derived"; }
    double getValue() const { return m_value; }

    friend std::ostream& operator<<(std::ostream& out, const Base& pcos)
    {
        out << pcos.getValue() << '\n';
        return out;
    }
};

int main()
{
    std::cout << "Hello World my name is Sophie <3\n";

    Derived derived{ 5 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Base& ref{ derived };
    std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Base* ptr{ &derived };
    std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';

    Base base{ derived };
    std::cout << "base is a " << base.getName() << " and has value " << base.getValue() << '\n';

    //Slicing and functions:
    printName_by_value(base);
    printName_by_value(*ptr);
    printName_by_value(derived);

    std::cout << "Now with references... no copie ! :D" << '\n';

    printName_by_references(base);
    printName_by_references(*ptr);
    printName_by_references(derived);

    //TEST FOR FUN:
    std::string array[3]{ ref.getName(), ptr->getName(), base.getName() };
    for(int i{ 0 }; i < std::size(array); ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    Base array_test[3]{ ref.getValue(), ptr->getValue(), base.getValue() };
    for(int i{ 0 }; i < std::size(array_test); ++i)
    {
        std::cout << array_test->getValue() << ' ';
    }
    std::cout << std::endl;

    //Slicing vectors:
    std::vector<Base*> v{};

    Base b{ 5 };// b and d can't be anonymous objects
    Derived d{ 6 };
    
    v.push_back(&b);
    v.push_back(&d);

    // Print out all of the elements in our vector
    for( const auto& element : v )
        std::cout << "I'm a " << element->getName() << " with value " << element->getValue() << '\n';


    //same example with // for std::reference_wrapper:

    std::vector<std::reference_wrapper<Base>> t{};// a vector of reassignable references to Base

    Base o{ 12 };// b and d can't be anonymous objects
    Derived p{ 13 };

    t.push_back(o);// add a Base object to our vector
    t.push_back(p);// add a Derived object to our vector

    // Print out all of the elements in our vector
	// we use .get() to get our element out of the std::reference_wrapper
    for(const auto& element : t)// element has type const std::reference_wrapper<Base>&
        std::cout << "I am a " << element.get().getName() << " with value " << element.get().getValue() << '\n';

    //The Frankenobject:
    

    

    return 0;
}

void printName_by_value(const Base base)// note: base passed by value, not reference
{
    std::cout << "I'm a " << base.getName() << '\n';
}

void printName_by_references(const Base& base)// note: base now passed by reference
{
    std::cout << "I'm a " << base.getName() << '\n';
}