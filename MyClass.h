//
// Created by linos on 31/03/2021.
//

#ifndef LAB2_MYCLASS_H
#define LAB2_MYCLASS_H


class MyClass {
public:
    MyClass(int number = -1);
    int getNumber() const;
    bool operator<(const MyClass &val) const;
private:
    int _number;
};



#endif //LAB2_MYCLASS_H
