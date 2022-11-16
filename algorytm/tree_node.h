#ifndef ISOMOPHIC_TREES_LAB_TREE_NODE_H
#define ISOMOPHIC_TREES_LAB_TREE_NODE_H

#endif //ISOMOPHIC_TREES_LAB_TREE_NODE_H
# pragma once
#include <vector>
struct node {
    int id;
    node* parent;
    std::vector<node> children;
    node(int data);
    node(int id, node* parent);
    void add_children(const std::vector<node>& nodes);
};