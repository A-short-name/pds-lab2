//
// Created by Mattia Riola on 07/05/21.
//

#include "Directory.h"

Directory* Directory::root = nullptr;
std::shared_ptr<Directory> Directory::addDirectory(const std::string& name){
    if(name == "/") {
        root->name = "/";
        std::shared_ptr<Directory> shared_self = shared_from_this();
//        root.self = std::make_shared<Directory>(this); // I can't use this https://en.cppreference.com/w/cpp/memory/enable_shared_from_this/shared_from_this
        root->self = shared_self;
        //Directory* voidDirectory = new Directory("");
        //root.father = std::shared_ptr<Directory>(voidDirectory);
        root->father = shared_self;       //we choose to insert weak self reference in father
        return shared_self;
    }else {
        // Directory *d = new Directory(name);
       // std::shared_ptr<Directory> dir = std::shared_ptr<Directory>(d);
       // this->son = dir;
       // this->son = makeDirectory(name, this->self);
        return makeDirectory(name, this->self);
    }
}


std::shared_ptr<Directory> Directory::makeDirectory(const std::string &name, std::weak_ptr<Directory> parent){
  //  Directory d(name);
  //  std::shared_ptr<Directory> dir = std::shared_ptr<Directory>(&d);
  if( auto s_parent = parent.lock()) {
      //std::shared_ptr<Directory> dir = s_parent->son;
      Directory* d = new Directory(name);
      std::shared_ptr<Directory> dir = std::shared_ptr<Directory>(d);
      dir->name = name;
      dir->father = parent;
//    dir->self = std::make_shared<Directory>(d);
      dir->self = dir;
      s_parent->children.insert({name, dir});
        return dir;
  }
  else {
      std::cerr << "Error parent cannot lock" << std::endl;
      //Directory* voidDirectory = new Directory("");
      return std::shared_ptr<Directory>(nullptr);
  }
//  return std::make_shared<Directory>(d);
}

std::shared_ptr<Directory> Directory::getRoot() {
    if(root == nullptr) {
        root= new Directory("/");
        std::shared_ptr<Directory> s_root(root);
        return s_root->addDirectory("/");
    }
    else
        return std::shared_ptr<Directory>(root);
}

const std::string &Directory::getName() const {
    return name;
}

void Directory::ls(int indent) {

    std::string ind;
    for (int i = 0; i<indent; i++)
        ind.append(" ");
    for (auto it=this->children.begin(); it!=this->children.end(); ++it)
        std::cout << ind << it->first << " => " << it->second << '\n';

}
void Directory::ls_recursive(int indent){
    std::string ind;
    for (int i = 0; i<indent; i++)
        ind.append(" ");

    for (auto it=this->children.begin(); it!=this->children.end(); ++it) {
        std::cout << ind << it->first << "\n";
        it->second->ls_recursive(indent + 4);
    }


}

void Directory::ls_recursive_withDots(int indent){
    std::string ind;
    for (int i = 0; i<indent; i++)
        ind.append(" ");
    std::cout << ind << ".\n";
    if(this->getName() != root->getName())
        std::cout << ind << "..\n";
    ls_recursive(indent);
}

std::shared_ptr<Directory> Directory::get(std::string name){
    if(root == nullptr)
        return std::shared_ptr<Directory>(root);
    static bool found = false;
    static std::shared_ptr<Directory> position(root);

    std::shared_ptr<Directory> result;
    //return first dir with equal name
    auto it= position->children.begin();
    for (; !found && it!=position->children.end(); ++it) {
        if ((it->first.compare(name)) == 0) {
            std::cout << "Found!! I'm " << it->first << "\n";
            found = true;
            return it->second;
        }
        std::cout << "I'm going to look into: " << it->first << "\n";
        position = it->second;
        return position->get(name);
    }
    if(found)
        return result;

    return std::shared_ptr<Directory>(nullptr);
}