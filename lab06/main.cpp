#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include "Tree.h"

std::vector < Tree > generate(int number_of){
    std::vector < Tree > trees;
    for(int i = 1;i<number_of+1;i++)
    {
        Tree tree(i);
        trees.push_back(tree);
    }
    return trees;
}

Tree min_element(const std::vector < Tree > &trees){
    return *std::min_element(trees.begin(), trees.end(), Tree::ByDiameter());
}

int count_if(const std::vector < Tree > &trees, const std::string &species)
{
    return std::count_if(trees.begin(), trees.end(), [&species](Tree const &tree){
        return tree.getSpecies()==species;
    });
}

std::vector < Tree > for_each(std::vector < Tree > &trees){
    std::for_each(trees.begin(), trees.end(), [](Tree &tree){
        try {
            tree.increase_diameter_by(0.1);
        }
        catch(Tree::CannotIncreaseDiameter &e)
        {
            std::cout<<"Tree: "<<tree<<" "<<e.what()<<std::endl;
        }
    });
    return trees;
}

std::vector < Tree > remove_if(std::vector < Tree > &trees)
{
    trees.erase(std::remove_if(trees.begin(), trees.end(), [](Tree const &tree){
        return tree.getDiameter()>1.0;
    }), trees.end());
    return trees;
}

std::set<Tree> vector_to_set(const std::vector < Tree > &trees)
{
    std::set<Tree> trees_set;
    for (auto &tree : trees)
    {
        if( !trees_set.insert(tree).second )
        {
            std::cout<<"Tree already exists: "<< tree<<std::endl;
        }
    }
    return trees_set;
}

std::map < size_t , Tree > generate_map(int number_of){
    std::map < size_t , Tree > map_of_trees;
    for(int i =0;i<number_of;i++)
    {
        Tree tree;
        map_of_trees.insert({tree.key(), tree});
    }
    return map_of_trees;
}

int main() {
    srand (time(0));
    std::vector < Tree > trees = generate(15);
    for (std::vector<Tree>::iterator it = trees.begin() ; it != trees.end(); ++it)
        std::cout<< *it<<std::endl;

    std::cout<<std::endl;

    std::cout<<"Min: "<<min_element(trees)<<std::endl;
    std::cout<<std::endl;

    std::cout<<"Dab: "<<count_if(trees, "Dab")<<std::endl;
    std::cout<<"Orzech: "<<count_if(trees, "Orzech")<<std::endl;
    std::cout<<"Topola: "<<count_if(trees, "Topola")<<std::endl;

    std::cout<<std::endl;

    for_each(trees);

    std::cout<<std::endl;

    for (auto &tree : trees)
        std::cout<< tree <<std::endl;

    std::cout<<std::endl;

    remove_if(trees);
    for (auto &tree : trees)
        std::cout<< tree <<std::endl;
    //Tree tree1;
    //trees.push_back(tree1);
    //trees.push_back(tree1);
    std::set<Tree> trees_set = vector_to_set(trees);
    std::cout<<std::endl;

    for (auto &tree : trees_set)
        std::cout<< tree <<std::endl;
    std::map < size_t , Tree > map_of_trees = generate_map(5);

    for (const auto &map_of_tree : map_of_trees) {
        std::cout << map_of_tree.first << " " << map_of_tree.second<< "\n";
    }
    return 0;
}