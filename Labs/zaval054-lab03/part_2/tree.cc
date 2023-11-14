#include "tree.h"

// Trees are on the ground, so do not have a z component
Tree::Tree(const std::string& name, double x, double y) : Entity(name) {
    SetPosition(x);
    SetPosition(y);
}

Tree::~Tree() {}