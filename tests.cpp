#include "algorytm/isomorphic.cpp"
#include "algorytm/generator.cpp"
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
    cout << "\tBinary tree OK" << endl;
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
    cout << "\tNon-binary tree OK" << endl;
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
    cout << "\tSeveral permutations OK" << endl;
}

void gen_test() {
   for (int i = 0; i < 100; i++) {
      int vertex_count = rand(1, 20000);
      vector<vector<int>> tree1 = generate_tree(vertex_count);
      vector<vector<int>> tree2 = generate_tree(vertex_count);
      cout << "\t Test " << i + 1 <<" OK, isomorphism ";
       auto start = high_resolution_clock::now();
      cout << (is_isomorphic(tree1, tree2) ? "found" : "not found");
       auto stop = high_resolution_clock::now();
      cout << " vertex count is  " << vertex_count;
      cout << ". Speed -- " << duration_cast<milliseconds>(stop - start).count() << "ms" << endl;
    }
}

int main () {
    cout << endl << "---SIMPLE TESTS---" << endl << endl;
    simple_binary_tree();
    simple_non_binary_tree();
    simple_several_permutations();
    cout << endl << "--GEN TESTS--" << endl << endl;
    gen_test();

}