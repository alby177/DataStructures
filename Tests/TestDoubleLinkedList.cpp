#include <iostream>
#include <iterator>
#include "../DoubleLinkedList.h"

int main()
{
    DoubleLinkedList<int> list;
    list.append(12);
    list.append(13);
    list.append(14);
    list += 16;
    std::cout << "At position " << 2 << " the data is: " << list.at(2) << std::endl;
    std::cout << list.toString() << std::endl;
    std::cout << list << std::endl;
    std::cout << "List size is: " << list.getSize() << std::endl;

    list.remove(2);
    std::cout << list.toString() << std::endl;
    std::cout << "List size is: " << list.getSize() << std::endl;
    std::cout << "List is empty? " << list.isEmpty() << std::endl;

    std::cout << "At position " << 1 << " the data is: " << list.at(1) << std::endl;
    list.insert(0, 15);
    list.insert(1, 17);
    std::cout << list << std::endl;
    std::cout << "List size is: " << list.getSize() << std::endl;
    std::cout << "At position " << 3 << " the data is: " << list.at(3) << std::endl;
    std::cout << "At position " << 3 << " the data is: " << list[3] << std::endl;

    std::cout << "Begin value is: " << *list.begin() << std::endl;
    std::cout << "End value is: " << *list.end() << std::endl;
    DoubleLinkedList<int>::iterator dataIt = list.begin();
    std::cout << "Iterator value is: " << *dataIt << std::endl;
    std::cout << "Next Iterator value is: " << *(++dataIt) << std::endl;

    for(DoubleLinkedList<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
        std::cout << "Element value is: " << *it << std::endl;
    }

    for(auto element : list)
    {
        std::cout << "Element value is: " << element << std::endl;  
    }

    while(dataIt.hasNext())
    {
        std::cout << "Element value is: " << *dataIt << std::endl;
        dataIt.next();  
    }

    list.removeLast();
    list.append(50);
    std::cout << list << std::endl;
    
    DoubleLinkedList<std::string> stringList;
    stringList.append("Foo");
    stringList.append("Bar");
    std::cout << stringList << std::endl;

    return 0;
}