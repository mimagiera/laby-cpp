#include <iostream>
#include "TreeBST.h"

template <typename T>
bool equals(const T a,const T b,const T c)
{
    return a==b && b==c;
}

template <>
bool equals<const char *>(const char* a, const char* b, const char*c) {
    std::cout<<"chars function ";
    return a==b && b==c;
}

int main() {
    std::cout<<equals(1.1, 1.1, 1.1)<<std::endl;
    std::cout<<equals("aa", "aa", "aa")<<std::endl;
    try {
        TreeBST<int> intTree;
        intTree.insert(23);
        intTree.insert(50);
        intTree.insert(5);
        intTree.insert(5);
        intTree.insert(12);
        std::cout << intTree.contains(33) << " " << intTree.contains(20) << std::endl;
        std::cout << intTree;
    }
    catch (TreeBST<int>::ValueAlreadyExists &e)
    {
        std::cout<<e.what();
    }
    catch (std::exception &e)
    {
        std::cout<<e.what();
    }

    return 0;
}