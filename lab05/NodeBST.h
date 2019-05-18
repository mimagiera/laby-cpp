//
// Created by micha on 18.05.2019.
//

#ifndef LAB05_NODEBST_H
#define LAB05_NODEBST_H

#include <iostream>

template <typename T>
class NodeBST {
    T val;
    NodeBST<T> *left;
    NodeBST<T> *right;

public:
    explicit NodeBST(T _val) : val(_val), left(nullptr), right(nullptr) {}
    ~NodeBST();

    bool insert(const T &val);
    bool contains(const T &val) const;
    void print() const;

    template <typename U>
    friend std::ostream& operator<<( std::ostream&, const NodeBST<U>& );
};

template<typename T>
bool NodeBST<T>::insert(const T &val) {
    if (val == this->val) return false;
    NodeBST* & next = (val < this->val) ? left : right;
    if (next == nullptr) {
        next = new NodeBST(val);
        return true;
    }
    else return next->insert(val);
}

template<typename T>
bool NodeBST<T>::contains(const T &val) const {
    if (val == this->val) return true;
    NodeBST* next = (val < this->val) ? left : right;
    if(next == nullptr)
    {
        return false;
    }
    return next->contains(val);
}

template<typename T>
void NodeBST<T>::print() const {
    if(left != nullptr)
    {
        left->print();
    }
    std::cout<<val<<" ";
    if(right != nullptr)
    {
        right->print();
    }
}

template<typename T>
NodeBST<T>::~NodeBST() {
    delete left;
    delete right;
}

template <typename T>
std::ostream& operator<<( std::ostream& os, const NodeBST<T>& nodeBST ) {
    if(nodeBST.left!=nullptr)
    {
        os<<*nodeBST.left;
    }
    os<<nodeBST.val<<" ";
    if(nodeBST.right!= nullptr)
    {
        os<<*nodeBST.right;
    }
    return os;
}


#endif //LAB05_NODEBST_H
