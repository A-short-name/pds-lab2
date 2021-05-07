//
// Created by Mattia Riola on 07/05/21.
//

#include "FileOrDirectory.h"

std::shared_ptr<FileOrDirectory> FileOrDirectory::makeDirectory(const std::string &name, std::weak_ptr<FileOrDirectory> parent){
    auto dir = std::make_shared<FileOrDirectory>();

    return dir;
}