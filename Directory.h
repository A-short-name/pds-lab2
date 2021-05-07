//
// Created by Mattia Riola on 07/05/21.
//

#ifndef LAB2_DIRECTORY_H
#define LAB2_DIRECTORY_H


#include <string>
#include <memory>
#include <iostream>
#include <map>

class Directory : public std::enable_shared_from_this<Directory> {
    static Directory* root;
    std::string name;
    std::weak_ptr<Directory> self;
    Directory(std::string name): name(name) {
        std::cout << "Making " << name << std::endl;
    };

public:


    std::weak_ptr<Directory> father;
    std::map<std::string,std::shared_ptr<Directory>> children;
    /**
     *
     * @param name of the directory you are looking for
     * @return shared_ptr of the directory with that path if it exists shared_ptr<Directory>(nullptr)
     */
    static std::shared_ptr<Directory> get(std::string name);
    const std::string &getName() const;

    static std::shared_ptr<Directory> getRoot();
    void ls(int indent);
    void ls_recursive(int indent);
    void ls_recursive_withDots(int indent);

    /**
     * add a new directory
     * @param name
     * @return the pointer of the directory created
     */
    std::shared_ptr<Directory> addDirectory(const std::string& name);

    /**
     * (this method replace the constructor)
     * makeDirectory must create a child object of father (parent)
     * @param name of the directory
     * @param parent weak_ptr of the father
     * @return self pointer
     */
    static std::shared_ptr<Directory> makeDirectory(const std::string &name, std::weak_ptr<Directory> parent);

};

#endif //LAB2_DIRECTORY_H
