//
// Created by bazdu on 27.01.2023.
//

#include "manual.h"
#include "isomorphic.h"
#include <bits/stdc++.h>
void one_node() {
    std::vector<int> tree1 = {-1};
    std::vector<int> tree2 = {-1};
    assert(is_isomorphic(tree1, tree2));
    cout << "OneNode OK" << endl;
}

void two_node() {
    std::vector<int> tree1 = {-1, 0};
    std::vector<int> tree2 = {-1, 0};
    assert(is_isomorphic(tree1, tree2));
    cout << "TwoNode OK" << endl;
}

void three_node() {
    std::vector<int> tree1 = {-1, 0, 0};
    std::vector<int> tree2 = {-1, 1, 0};
    assert(is_isomorphic(tree1, tree2));
    cout << "ThreeNode OK" << endl;
}

void five_node() {
    std::vector<int> tree1 = {-1, 0, 0};
    std::vector<int> tree2 = {-1, 1, 0};
    assert(is_isomorphic(tree1, tree2));
    cout << "FiveNode OK" << endl;
}

void run_manual() {
    one_node();
    two_node();
    three_node();
}