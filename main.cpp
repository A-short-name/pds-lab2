#include <iostream>
#include "Directory.h"
#include <memory>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::shared_ptr<Directory> myRoot = Directory::getRoot();
    std::cout << "my root: " << myRoot->getName() <<std::endl;
    auto son1 = myRoot->addDirectory("1 Folder");
    auto son11 = son1->addDirectory("1.1 Subfolder");
    auto son2 = myRoot->addDirectory("2 Folder");
    auto son22 = son2->addDirectory("2.1 Subfolder");
    auto son111 = son11->addDirectory("1.1.1 Subfolder");
    auto son112 = son11->addDirectory("1.1.2 Subfolder");

//    std::cout << "First Child name: " << myRoot->children["1 Folder"]->getName() << std::endl;
//    std::cout << "Second Child name: " << myRoot->children["2 Folder"]->getName() << std::endl;
//    std::cout << "1.1 First subChild name: " << myRoot->children["1 Folder"]->children["1.1 Subfolder"]->getName() << std::endl;
//    std::cout << "1.1.1 First subChild name: " << myRoot->children["1 Folder"]->children["1.1 Subfolder"]->children["1.1.1 Subfolder"]->getName() << std::endl;

    myRoot->ls_recursive_withDots(2);
    son2->ls_recursive_withDots(2);
    std::cout << Directory::get("1.1.1 Subfolder")->getName() << std::endl;
    return 0;
}
