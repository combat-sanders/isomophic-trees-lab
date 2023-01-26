#include <bits/stdc++.h>
#include "isomorphic.h"
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
int rand(int a, int b) {
    uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

vector<vector<int>> generate_tree(int vertex_count) {
    vector<vector<int>> matrix(vertex_count);
    for (int i = 1; i < matrix.size(); i++) {
        int vertex_to_pair = rand(0, i - 1);
        add_link(matrix, i, vertex_to_pair);
    }
    return matrix;
}


