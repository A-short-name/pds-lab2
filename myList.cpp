//
// Created by linos on 31/03/2021.
//

#include "myList.h"

myList::myList() {
    _head = nullptr;
    _tail = nullptr;
    _current_el = nullptr;
}

myList::~myList() {

}

/* Insert an element at the head of the list . Current element moved to
the new head .*/
void myList::push_front(const MyClass &val) {
    nodes *node = _new_node();
    node->value = val;
    node->next = _head;

    _head = node;

    if(_tail==nullptr) {
        _tail = _head;
    }

    _current_el = _head;

    std::cout << "Inserted node into head, value: " << _head->value.getNumber() << "\n";
}

/* Return the value of the node at the head of the list and delete the
head node . Current element moved to the new head . */
MyClass myList::popNode () {
    if(_head == nullptr)
        return MyClass();

    MyClass value = _head->value;
    nodes *node = _head;

    _head = _head->next;
    _current_el = _head;

    delete node;

    return value;
}
/* Insert an element at the tail of the list . Current element moved to
the tail . */
void myList::push_back ( const MyClass &val ) {
    nodes *node = _new_node();
    node->value = val;
    node->next = nullptr;

    if(_tail!= nullptr) {
        _tail->next = node;
    }else{
        _head = node;
    }
    _tail = node;
    _current_el = _tail;
}

/* Insert an element at the pos -th element of the list . Current
element moved to the new element */
void myList::insertNode ( const MyClass &val , int pos ) {
    if(pos<1) {
        std::cerr << "Pos non valido" << "\n";
        return;
    }

    //Se pos = 1 inserimento in testa
    if(pos==1) {
        push_front(val);
        return;
    }

    int  i = 2;
    nodes *node = _new_node();
    node->value=val;

    for(nodes *x = _head;x!=nullptr;x=x->next,i++) {
        if(i==pos) {
            if(x->next == nullptr) {
                _tail = node;
            }
            node->next = x->next;
            x->next = node;

            return;
        }
    }

    std::cerr << "Valore pos non valido";
}

/* Insert an element in a sorted list with increasing values . Current
element moved to the new element .*/
void myList::insertIncOrderedNode ( const MyClass &val ) {
    if(_head == nullptr) {
        push_front(val);
        return;
    }

    nodes *node = _new_node();
    node->value=val;

    if(_head == _tail) {
        if(val<_head->value) {
            //push_front(val);
            node->next = _head;
            _head = node;
            return;
        }
        //push_back(val);
        _head->next = node;
        node->next = nullptr;
        _tail = node;
        return;
    }

    if(val<_head->value) {
        push_front(val);
        return;
    }
    for(nodes *x = _head;x!=nullptr;x=x->next) {
        if(x->next != nullptr) {
            if(val<x->next->value) {
                node->next = x->next;
                x->next = node;
                return;
            }
        }
        else{
            push_back(val);
            return;
        }
    }

}

/* Insert an element in a sorted list with decreasing values . Current
element moved to the new element .*/
void myList::insertDecOrderedNode ( const MyClass &val ) {
    if(_head == nullptr) {
        push_front(val);
        return;
    }

    nodes *node = _new_node();
    node->value=val;

    if(_head == _tail) {
        if(val>_head->value) {
            //push_front(val);
            node->next = _head;
            _head = node;
            return;
        }
        //push_back(val);
        _head->next = node;
        node->next = nullptr;
        _tail = node;
        return;
    }

    if(val>_head->value) {
        push_front(val);
        return;
    }
    for(nodes *x = _head;x!=nullptr;x=x->next) {
        if(x->next != nullptr) {
            if (val > x->next->value) {
                node->next = x->next;
                x->next = node;
                return;
            }
        }
        else {
            push_back(val);
            return;
        }
    }
}

/* Delete the pos -th node of the list . Current element moved to the
pos -th previous element . */
void myList::deleteNodeByPos ( const int &pos ) {

}

/* Delete all the nodes of the list containing val . Current element
moved to the previous element of the deleted element .*/
void myList::deleteNodeByVal ( const MyClass &val ) {

}

/* Swap the content of nodes at pos0 and pos1 . Current element moved
to the pos0 -th element . */
void myList::swapNodes ( const int &pos0 , const int & pos1 ) {

}

/* Return the value of the pos -th node . Current element moved to the
found element .*/
MyClass myList::findNodeByPos ( const int &pos ) const {

}

/* Return the position of the first occurrence of a node containing
val . Current element moved to the found element . */
int myList::findNodeByVal ( const char &val) const {

}

myList::nodes *myList::_new_node() {
    nodes *node = new nodes();
    return node;
}
