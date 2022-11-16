
#ifndef ISOMOPHIC_TREES_LAB_ISOMORPHIC_H
#define ISOMOPHIC_TREES_LAB_ISOMORPHIC_H

#endif //ISOMOPHIC_TREES_LAB_ISOMORPHIC_H
#include "tree_node.h"
using namespace std;

vector<int> find_centers(vector<vector<int>>& graph);
node build_tree(vector<vector<int>>& graph, node& _node);
node root_tree(vector<vector<int>>& graph, int root_id);
bool is_isomorphic(vector<vector<int>>& a, vector<vector<int>>& b);
void add_link(vector<vector<int>>& graph, int id, int parent);