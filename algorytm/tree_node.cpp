#include "tree_node.h"
#include <vector>
node::node(int data) : node(data,  nullptr){};
node::node(int id, node* parent) {
    this->id = id;
    this->parent = parent;
}

void node::add_children(const std::vector<node>& nodes) {
    for (auto &node : nodes) {
        this->children.push_back(node);
    }
}



