#include <bits/stdc++.h>
#include "isomorphic.h"
#include "generator.h"
using namespace std;

int rand(int a, int b) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

vector<vector<int>> generate_tree(int vertex_count) {
    vector<vector<int>> matrix(vertex_count);
    for (int i = 1; i < matrix.size(); i++) {
        int vertex_to_pair = rand(0, i - 1);
        matrix[i].push_back(vertex_to_pair);
        matrix[vertex_to_pair].push_back(i);
    }
    return matrix;
}

node generate_isomorphic(node& root) {

}