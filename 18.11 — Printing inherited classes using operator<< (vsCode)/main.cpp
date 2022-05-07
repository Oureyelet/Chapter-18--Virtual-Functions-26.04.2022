#include <iostream>

class Base
{
public:
    virtual void print() const { std::cout <<  "Base" << '\n'; }

    // Here's our overloaded operator<<
    friend std::ostream& operator<<(std::ostream& out, const Base& base)
    {
        // Delegate printing responsibility for printing to member function print()
        return base.getName(out);
    }

    virtual std::ostream& getName(std::ostream& out) const
    {
        out << "Base" << '\n';
        return out;
    }
};

class Derived: public Base
{
public:
    void print() const override { std::cout << "Derived" << '\n';  }

    std::ostream& override (std::ostream& out, const Derived& base)
    {
        out << "Derived" << '\n';
        return out;
    }
};

int main()
{
    Derived d{};
    Base& b{ d };

    //b.print();// will call Derived::print()

    //The challenges with operator<<:

    Base oldTestament{};
    Derived newTestament{};
    
    //std::cout << oldTestament;
    //std::cout << newTestament;

    //Can we make Operator << virtual?:
    // - no.

    //The solution:

    Derived legs{};
    Base* head{ &legs };
    Base& chest{ legs };

    std::cout << legs; // print Derived
   /* std::cout << *head; // print Derived
    std::cout << chest; // print Derived

    Base hear{};

    std::cout << hear; // print Base
*/

// check what is printed...

    return 0;
}