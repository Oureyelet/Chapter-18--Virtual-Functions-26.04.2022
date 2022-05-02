#include <iostream>

void printValue(int value)
{
    std::cout << value << '\n';
}

int add(int x, int y)
{
    return x + y;
}

int substract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    //Early binding:
    printValue(777);// This is a direct function call

    int x{};
    std::cout << "Enter a number: ";
    std::cin >> x;

    int y{};
    std::cout << "Enter another number: ";
    std::cin >> y;

    int op;
    do
    {
        std::cout << "Enter an operation (0=add, 1=subtract, 2=multiply): ";
        std::cin >> op;

        switch (op)
        {
            // call the target function directly using early binding
            case 0: std::cout << "The answer is: " << add(x, y) << '\n'; break;
            case 1: std::cout << "The answer is: " << substract(x, y) << '\n'; break;
            case 2: std::cout << "The answer is: " << multiply(x, y) << '\n'; break;
            default: std::cout << "Try again please..." << '\n'; break;
        }

    } while (op < 0 || op > 2);

    //Late Binding:

    int(*pointerFunction)(int, int) = add; // Create a function pointer and make it point to the add function
    std::cout << pointerFunction(8, 12) << '\n'; // add 8 + 12

    // Create a function pointer named pFcn (yes, the syntax is ugly)
    int(*pFcn)(int, int) = nullptr;

    int z{};
    std::cout << "(With function pointer) Enter a number: ";
    std::cin >> z;

    int g{};
    std::cout << "(With function pointer) Enter another number: ";
    std::cin >> g;

    int operation;
    do
    {
        std::cout << "(With function pointer) Enter an operation (0=add, 1=subtract, 2=multiply): ";
        std::cin >> operation;

        // Set pFcn to point to the function the user chose
        switch (operation)
        {
            case 0: pFcn = add; break;
            case 1: pFcn = substract; break;
            case 2: pFcn = multiply; break;
            default: std::cout << "Try again please..." << '\n'; break;
        }
        // Call the function that pFcn is pointing to with z and g as parameters
        // This uses late binding
        std::cout << "The answer is: " << pFcn(z, g) << '\n';

    } while (op < 0 || op > 2);

    return 0;
}