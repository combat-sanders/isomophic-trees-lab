//
// Created by bazdu on 27.01.2023.
//

#ifndef ISOMOPHIC_TREES_LAB_ISOMORPHIC_H
#define ISOMOPHIC_TREES_LAB_ISOMORPHIC_H

#endif //ISOMOPHIC_TREES_LAB_ISOMORPHIC_H

#include <bits/stdc++.h>

using namespace std;

extern double average;
struct node {
    int id;
    node* parent;
    std::vector<node> children;
    node(int id, node* parent);
    node(int data);


    void add_children(const vector<node>& nodes);
};

void add_link(vector<vector<int>>& graph, int id, int parent);
vector<vector<int>> to_adj(vector<int>& tree);
vector<int> find_centers(vector<vector<int>>& graph);
node build_tree(vector<vector<int>>& graph, node& _node);
node root_tree(vector<vector<int>>& graph, int root_id);
string encode(node& _node);
bool is_isomorphic(vector<int>& _a, vector<int>& _b);