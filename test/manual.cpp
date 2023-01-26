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
    std::vector<int> tree2 = {-1, 0, 1};
    assert(is_isomorphic(tree1, tree2));
    cout << "ThreeNode OK" << endl;
}

void five_node() {
    std::vector<int> tree1 = {-1, 0, 0, 1, 1};
    std::vector<int> tree2 = {-1,0,0,2,2};
    assert(is_isomorphic(tree1, tree2));
    cout << "FiveNode OK" << endl;
}

void ten_node() {
    std::vector<int> tree1 = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4};
    std::vector<int> tree2 = {-1, 0, 0, 2, 2, 1, 1, 4, 4, 3};
    assert(is_isomorphic(tree1, tree2));
    cout << "TenNode OK" << endl;
}

void fifteen_node() {
    std::vector<int> tree1 = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
    std::vector<int> tree2 = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    assert(is_isomorphic(tree1, tree2));
    cout << "FifteenNode OK" << endl;
}

void different_count() {
    std::vector<int> tree1 = {-1};
    std::vector<int> tree2 = {-1, 0};
    assert(!is_isomorphic(tree1, tree2));
    cout << "DifferentCount OK" << endl;
}

void five_node_not_iso() {
    std::vector<int> tree1 = {-1, 0, 1, 2, 3};
    std::vector<int> tree2 = {-1, 0, 0, 0, 0};
    assert(!is_isomorphic(tree1, tree2));
    cout << "FiveNodesNotIsomorphic OK" << endl;
}

void ten_node_not_iso() {
    std::vector<int> tree1 = {-1, 0, 0, 1, 1, 2, 2, 3, 3, 4};
    std::vector<int> tree2 = {-1, 0, 0, 0, 0, 1, 1, 2, 2, 2};
    assert(!is_isomorphic(tree1, tree2));
    cout << "TenNodesNotIsomorphic OK" << endl;
}



void run_manual() {
    // OK если деревья изоморфны
    one_node();
    two_node();
    three_node();
    five_node();
    ten_node();
    fifteen_node();
    // ОК если деревья не изоморфны
    different_count();
    five_node_not_iso();
    ten_node_not_iso();

}