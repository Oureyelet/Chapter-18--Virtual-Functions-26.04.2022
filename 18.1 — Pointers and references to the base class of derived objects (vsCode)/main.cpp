#include <iostream>
#include <string_view>
#include <string>
#include <array>

class Base
{
protected:
    int m_value{};

public:
    Base(int value)
        :m_value{ value }
    {
    }

    std::string_view getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    std::string_view getName() const { return "Derived"; }
    int getValueDoubled() const { return m_value * 2; }

};

class Animal
{
protected:
    std::string m_name{};
    std::string m_speak{};

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name, std::string_view speak)
        : m_name{ name }, m_speak{ speak }
    {
    }

    // To prevent slicing (covered later)
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;

public:
    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return m_speak; }
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name, "Meow" }
    {
    }

    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name, "Woof" }
    {
    }

    std::string_view getName() const { return m_name; }
    std::string_view speak() const { return "Woof"; }
};

void report(const Animal& rAnimal)
{
    std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
}


int main()
{
    std::cout << "Hello World\n";

    //Pointers, references, and derived classes:
    Derived derived{ 5 };
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';

    Derived& rDerived{ derived };   
    std::cout << "rDerived is a " << rDerived.getName() << " and has value " << rDerived.getValue() << '\n';

    Derived* pDerived{ &derived };
    std::cout << "pDerived is a " << pDerived->getName() << " and has value " << pDerived->getValue() << '\n';

    // These are both legal!
    Base& rBase{ derived };
    Base* pBase{ &derived };



    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
    std::cout << "rBase is a " << rBase.getName() << " and has value " << rBase.getValue() << '\n';
    std::cout << "pBase is a " << pBase->getName() << " and has value " << pBase->getValue() << '\n';


    const Cat cat{ "Fred" };
    std::cout << "Cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

    const Dog dog{ "Garbo" };
    std::cout << "Dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

    const Animal* pAnimal{ &cat };
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    pAnimal = &dog;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    //Use for pointers and references to base classes:
    report(dog);


    // Cat and Dog from the example above (in array):
    const std::array<Cat, 3> cats { { { "Fred" }, { "Misty" }, { "Zeke" } } };
    const std::array<Dog, 3> dogs { { { "Garbo" }, { "Pooky" }, { "Truffle" } } };

    for(const auto& element : cats)
    {
        std::cout << element.getName() << " say " << element.speak() << '\n';
    }
    std::cout << std::endl;


    for(const auto& element : dogs)
    {
        std::cout << element.getName() << " say " << element.speak() << '\n';
    }
    std::cout << std::endl;


    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    const std::array<const Animal*, 6> animal{ &fred, &misty, &zeke, &garbo, &pooky, &truffle };

    for(const auto element : animal)
    {
        std::cout << element->getName() << " say " << element->speak() << '\n';
    }


    //Quiz Time:
    
    /*
    Our Animal/Cat/Dog example above doesn’t work like we want because a reference or pointer to an Animal can’t access the 
    derived version of speak() needed to return the right value for the Cat or Dog. One way to work around this issue would 
    be to make the data returned by the speak() function accessible as part of the Animal base class (much like the Animal’s 
    name is accessible via member m_name).

    Update the Animal, Cat, and Dog classes in the lesson above by adding a new member to Animal named m_speak. Initialize it 
    appropriately. The following program should work properly:


    */
    return 0;
}