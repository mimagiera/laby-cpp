//
// Created by micha on 24.05.2019.
//

#ifndef LAB06_TREE_H
#define LAB06_TREE_H


#include <string>
#include <ostream>

class Tree {
    std::string species;
    double diameter;
    int age;
    static const std::string possible_species[3];
    double random_diameter(){
        return ((double)rand() / RAND_MAX)*1.9 + 0.1;
    }
    std::string random_species()
    {
        return possible_species[rand()%3];
    }

public:
    double getDiameter() const;

public:
    const std::string &getSpecies() const;

    Tree() : diameter(random_diameter()), species(random_species()) {
        age = rand()%(100) + 1;
    }
    explicit Tree(int age) : age(age), diameter(random_diameter()), species(random_species()){};

    std::size_t key() const {
        return age + std::hash<std::string>()(species);
    }

    bool operator==(const Tree &) const;
    bool operator!=(const Tree &) const;
    friend std::ostream &operator<<(std::ostream &os, const Tree &tree);
    bool operator<(const Tree & tree) const;

    struct ByDiameter{
        bool operator()(const Tree &tree1, const Tree &tree2) const {
            return tree1.diameter < tree2.diameter;
        }
    };
    void increase_diameter_by(double increase_by)
    {
        if(diameter+increase_by>2.0)
        {
            throw CannotIncreaseDiameter(increase_by);
        }
        diameter+=increase_by;
    }
    class CannotIncreaseDiameter : public std::exception
    {
        double increase_by;
    public:
        explicit CannotIncreaseDiameter(double increase_by) : increase_by(increase_by) {}

        std::string what(){
            return "Cannot increase by: " + std::to_string(increase_by) + " maximum is 2.0";
        }

    };
};

const std::string Tree::possible_species[3] = {"Dab", "Orzech", "Topola"};

std::ostream &operator<<(std::ostream &os, const Tree &tree) {
    os << "species: " << tree.species << " diameter: " << tree.diameter << " age: " << tree.age;
    return os;
}

bool Tree::operator==(const Tree &tree) const {
    return this->key() == tree.key();
}

bool Tree::operator!=(const Tree &tree) const {
    return !(tree == *this);
}

const std::string &Tree::getSpecies() const {
    return species;
}

double Tree::getDiameter() const {
    return diameter;
}

bool Tree::operator<(const Tree &tree) const {
    return tree.key()<key();
}

#endif //LAB06_TREE_H
