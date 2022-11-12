#include "solution.cpp"
#include "generator.cpp"
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
void simple_binary_tree() {
    vector<vector<int>> tree1(4), tree2(4);
    add_link(tree1, 1, 0);
    add_link(tree1, 2, 0);
    add_link(tree1, 3, 2);

    add_link(tree2, 1, 0);
    add_link(tree2, 2, 0);
    add_link(tree2, 3, 1);

    assert(is_isomorphic(tree1, tree2) == 1);
    cout << "BinaryTree OK" << endl;
}

void simple_non_binary_tree() {
    vector<vector<int>> tree1(6), tree2(6);

    add_link(tree1, 1, 0);
    add_link(tree1, 2, 0);
    add_link(tree1, 3, 0);
    add_link(tree1, 4, 3);
    add_link(tree1, 5, 3);

    add_link(tree2, 1, 0);
    add_link(tree2, 2, 0);
    add_link(tree2, 3, 0);
    add_link(tree2, 4, 2);
    add_link(tree2, 5, 2);

    assert(is_isomorphic(tree1, tree2) == 1);
    cout << "NonBinaryTree OK" << endl;
}

void simple_several_permutations() {
    vector<vector<int>> tree1(10), tree2(10);

    add_link(tree1, 1, 0);
    add_link(tree1, 2, 0);
    add_link(tree1, 6, 1);
    add_link(tree1, 3, 2);
    add_link(tree1, 4, 2);
    add_link(tree1, 5, 2);
    add_link(tree1, 7, 3);
    add_link(tree1, 8, 3);
    add_link(tree1, 9, 4);

    add_link(tree2, 1, 0);
    add_link(tree2, 2, 0);
    add_link(tree2, 6, 2);
    add_link(tree2, 3, 1);
    add_link(tree2, 4, 1);
    add_link(tree2, 5, 1);
    add_link(tree2, 7, 4);
    add_link(tree2, 8, 4);
    add_link(tree2, 9, 3);

    assert(is_isomorphic(tree1, tree2) == 1);
    cout << "SeveralPermutations OK" << endl;
}

void check_speed_of_1000_vertex() {
    vector<vector<int>> tree1 = generate_tree(1000);
    auto start = high_resolution_clock::now();
    is_isomorphic(tree1, tree1);
    auto stop = high_resolution_clock::now();
    cout << "Time of detecting isomorphic -- " << duration_cast<milliseconds>(stop - start).count() << "ms";
}

int main () {
    simple_binary_tree();
    simple_non_binary_tree();
    simple_several_permutations();

    check_speed_of_1000_vertex();
}