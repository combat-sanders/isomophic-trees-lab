#include <bits/stdc++.h>
#include "isomorphic.h"
#include "generator.h"
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());

int rand(int a, int b) {
    uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

vector<int> generate_tree(int vertex_count) {
    vector<int> tree(vertex_count, -1);
    for (int i = 1; i < tree.size(); i++) {
        int vertex = rand(0, i - 1);
        tree[i] = vertex;
    }
    return tree;
}

vector<node> generate_isomorphic(std::vector<int>& source_tree, int parent_id) {

}




