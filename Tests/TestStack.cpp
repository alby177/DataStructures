#include <iostream>
#include "../Stack.h"

int main()
{
    Stack<int> stack;

    stack.push(12);

    std::cout << stack << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack << std::endl;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    for(auto it : stack)
    {
        std::cout << "Stack element value is: " << *it << std::endl;
    }

    return 0;
}