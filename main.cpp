#include <iostream>

#include "myList.h"
#include "MyClass.h"


int main() {
    myList list;
    myList ordList;

    MyClass *item1 = new MyClass(1);
    MyClass *item2 = new MyClass(2);
    MyClass *item3 = new MyClass(3);
    MyClass *item4 = new MyClass(0);
    MyClass *item5 = new MyClass(50);
    MyClass item6(42);
    list.push_front(*item1);
    list.push_front(*item2);
    list.push_front(*item3);
    list.push_back(*item4);

    list.insertNode(*item5,5);

    std::cout << list.popNode().getNumber() << "\n";
    std::cout << list.popNode().getNumber() << "\n";
    std::cout << list.popNode().getNumber() << "\n";
    std::cout << list.popNode().getNumber() << "\n";
    std::cout << list.popNode().getNumber() << "\n";

    std::cout << "Hello, World!" << std::endl;

    ordList.insertIncOrderedNode(*item5);
    ordList.insertIncOrderedNode(*item4);
    ordList.insertIncOrderedNode(*item2);
    ordList.insertIncOrderedNode(*item1);
    ordList.insertIncOrderedNode(item6);
    std::cout << ordList.popNode().getNumber() << "\n";
    std::cout << ordList.popNode().getNumber() << "\n";
    std::cout << ordList.popNode().getNumber() << "\n";
    std::cout << ordList.popNode().getNumber() << "\n";
    std::cout << ordList.popNode().getNumber() << "\n";


    myList decList;
    decList.insertDecOrderedNode(*item1);
    decList.insertDecOrderedNode(*item2);
    decList.insertDecOrderedNode(*item3);
    decList.insertDecOrderedNode(*item4);

    std::cout << "lista ordinata dec" << "\n";
    std::cout << decList.popNode().getNumber() << "\n";
    std::cout << decList.popNode().getNumber() << "\n";
    std::cout << decList.popNode().getNumber() << "\n";
    std::cout << decList.popNode().getNumber() << "\n";



    return 0;
}
