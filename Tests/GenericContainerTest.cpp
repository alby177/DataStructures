#include <iostream>
#include "../GenericContainer.h"

struct Key1;
struct Key2;

int main()
{
    GenericContainer<Slot<int>, Slot<std::string>> container;

    container.set(12);
    container.set<std::string>("Allora");

    std::cout << container.get<int>() << std::endl;
    std::cout << container.get<std::string>() << std::endl;

    GenericContainer<Slot<std::string, Key1>, Slot<std::string, Key2>> MultipleContainer;
    MultipleContainer.set<std::string, Key1>("Foo");
    MultipleContainer.set<std::string, Key2>("Bar");

    std::cout << MultipleContainer.get<std::string, Key2>() << std::endl;
    std::cout << MultipleContainer.get<std::string, Key1>() << std::endl;
}
