#include <iostream>
#include "../Stack.h"

int main()
{
    Stack<int> stack;

    stack.push(12);

    std::cout << stack << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack << std::endl;

    return 0;
}