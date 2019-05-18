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

class Sample
{
public:
    int val;
    Sample* left;
    Sample* right;

    explicit Sample(int val) : val(val), left(nullptr), right(nullptr) {}
    friend std::ostream& operator<<( std::ostream& os, const Sample& sample) {
        if(sample.left != nullptr)
        {
            os<<*sample.left;
        }
        os<<sample.val;
        return os;
    }
};

int main() {
    std::cout<<equals(1.1, 1.1, 1.1)<<std::endl;
    std::cout<<equals("aa", "aa", "aa")<<std::endl;
    TreeBST<int> intTree;
    intTree.insert(23);
    intTree.insert(2);
    intTree.insert(33);
    intTree.insert(43);
    intTree.insert(1);
    intTree.print();
    std::cout<<intTree.contains(33)<<" "<<intTree.contains(20)<<std::endl;
    std::cout<<intTree;

    return 0;
}