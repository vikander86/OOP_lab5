// main.cpp
#include <iostream>
#include "doubleLinkedList.cpp"

int main()
{
    Container<double> test;
    std::cout << "Is empty? " << std::boolalpha << test.empty() << std::endl;
    test.pushFront(3.2);
    test.pushFront(34.2);
    test.pushFront(3251.5);
    test.pushFront(31.2312);
    test.pushFront(92924992492435905.32904);
    test.pushBack(5123.2145);
    test.insert(123523, 4);
    test.insert(123.523, 0);
    test.insert(123.523, 12);
    test.print();
    std::cout << "size of container: " << test.size() << std::endl;

    std::cout << "testing pop front" << std::endl;
    test.popFront();
    test.print();
    std::cout << "size of container: " << test.size() << std::endl;
    std::cout << "Is empty? " << std::boolalpha << test.empty() << std::endl;

    std::cout << "testing pop back" << std::endl;
    test.popBack();
    test.print();
    std::cout << "size of container: " << test.size() << std::endl;

    std::cout << "testing erase Index1" << std::endl;
    test.erase(1);
    test.print();
    std::cout << "size of container: " << test.size() << std::endl;

    std::cout << "testing erase Index0" << std::endl;
    test.erase(0);
    test.print();
    std::cout << "size of container: " << test.size() << std::endl;

    test.clear();
    std::cout << "Is empty? " << std::boolalpha << test.empty() << std::endl;
    test.popBack();
    test.pushFront(4124);
    test.print();
    std::cout << "size of container: " << test.size() << std::endl;

    return 0;
}