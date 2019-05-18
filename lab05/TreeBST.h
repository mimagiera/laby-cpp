//
// Created by micha on 18.05.2019.
//

#ifndef LAB05_TREEBST_H
#define LAB05_TREEBST_H

#include "NodeBST.h"

template <typename T>
class TreeBST {
    NodeBST<T>* root;

public:

    TreeBST() : root(nullptr) {}

    TreeBST(const TreeBST &) = delete;
    void operator=(const TreeBST &) = delete;

    virtual ~TreeBST();

    bool contains(const T &val) const { return (root != nullptr) ? root->contains(val) : false; }
    bool insert(const T &val);
    void print() const;

    template <typename U>
    friend std::ostream& operator<<( std::ostream&, const TreeBST<U>& );

    class ValueAlreadyExists : public std::exception
    {
    public:
        T val;

        explicit ValueAlreadyExists(T val) : val(val) {}
        std::string what(){
            return "Value "+std::to_string(val)+" already exists!";
        }

    };
};

template<typename T>
bool TreeBST<T>::insert(const T &val) {
    if(root == nullptr)
    {
        root = new NodeBST<T>(val);
        return true;
    }
    bool inserted = root->insert(val);
    if(!inserted)
    {
        throw ValueAlreadyExists(val);
    }
    return inserted;
}

template<typename T>
void TreeBST<T>::print() const {
    std::cout << "tree: [";
    if (root == NULL) std::cout << "empty" << std::endl;
    else root->print();
    std::cout << "]" << std::endl;
}

template<typename T>
TreeBST<T>::~TreeBST() {
    delete root;
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const TreeBST<U> & treeBST) {
    os<<"tree: [";
    if(treeBST.root== nullptr) os<<"empty";
    else os<<*treeBST.root;
    os<<"]";
    return os;
}

#endif //LAB05_TREEBST_H
