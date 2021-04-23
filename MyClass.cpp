//
// Created by linos on 31/03/2021.
//

#include "MyClass.h"

MyClass::MyClass(int number) {
    _number = number;
}

int MyClass::getNumber() const {
    return _number;
}

bool MyClass::operator<(const MyClass &val) const {
    return this->_number<val._number;
}