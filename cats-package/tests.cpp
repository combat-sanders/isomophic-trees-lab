#include "solution.cpp"
#include <bits/stdc++.h>
using namespace std;
int main () {
    vector<vector<int>> tree1(5), tree2(5);
    addUndirectedEdge(tree1, 2, 0);
    addUndirectedEdge(tree1, 3, 4);
    addUndirectedEdge(tree1, 2, 1);
    addUndirectedEdge(tree1, 2, 3);

    addUndirectedEdge(tree2, 1, 0);
    addUndirectedEdge(tree2, 1, 4);
    addUndirectedEdge(tree2, 1, 3);
    addUndirectedEdge(tree2, 1, 2);
    cout << is_isomorphic(tree1, tree2);
}