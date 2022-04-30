#include <iostream>
#include <string_view>

class A
{
public:
    virtual std::string_view getName1(int x) { return "A"; }
    virtual std::string_view getName2(int x) { return "A"; }
    virtual std::string_view getName3(int x) { return "A"; }
};

class B: public A
{
public:
    virtual std::string_view getName1(short int x) { return "B"; } // note: parameter is a short int
    virtual std::string_view getName1(int x) const { return "B"; } // note: function is const
    std::string_view getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)
};

int main()
{
    //The override specifier:
    B b{};
    A& rBase{ b };
    
    //std::cout << rBase.getName1(1) << '\b';
    //std::cout << rBase.getName2(2) << '\b';
    std::cout << rBase.getName3(3) << '\b';
    
    //why nothing is printing ?! coment in leanrcpp.com....

    return 0;
}