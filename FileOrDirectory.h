//
// Created by Mattia Riola on 07/05/21.
//

#ifndef LAB2_FILEORDIRECTORY_H
#define LAB2_FILEORDIRECTORY_H


#include <string>
#include <memory>


class FileOrDirectory {
std::string name;
std::weak_ptr<FileOrDirectory> self;
std::weak_ptr<FileOrDirectory> father;
};


#endif //LAB2_FILEORDIRECTORY_H
