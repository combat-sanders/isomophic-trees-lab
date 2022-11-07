#include <bits/stdc++.h>
using namespace std;

vector<int> find_centers(vector<vector<int>>& graph) {
    int vertex_count = graph.size();

    vector<int> degree(vertex_count, 0);
    vector<int> leaves;

    for (int i = 0; i < vertex_count; i++) {
        degree[i] = graph[i].size();
        if (degree[i] == 0 || degree[i] == 1) {
            leaves.push_back(i);
            degree[i] = 0;
        }
    }

    int count = leaves.size();

    while (count < vertex_count) {
        vector<int> new_leaves;
        for (int node : leaves) {
            for (int neighbour : graph[node]) {
                degree[neighbour] = degree[neighbour] - 1;
                if (degree[neighbour] == 1) new_leaves.push_back(neighbour);
            }
            degree[node] = 0;
        }
        count += new_leaves.size();
        leaves = new_leaves;
    }
    return leaves;
}
string encode(vector<vector<int>>& graph, int parent) {
    vector<string> labels;
    string tree_hash = "";
    if (graph[parent].empty()) return "(0)";
    else {
        for (auto i : graph[parent]) {
            { labels.push_back(encode(graph, i)); }
        }
        sort(labels.begin(), labels.end());
        for (auto & label : labels) {
            tree_hash += label;
        }
    }
    return '(' + tree_hash + ')';
}

bool is_isomorphic(vector<vector<int>>& a, vector<vector<int>>& b) {
    if (&a == nullptr && &b == nullptr) return true;
    if (&a == nullptr || &b == nullptr) return false;

    vector<int> a_centers = find_centers(a);
    vector<int> b_centers = find_centers(b);

    node a_rooted = root_tree(a, a_centers[0]);
    string a_encoded = encode(a_rooted);

    for (int center : b_centers) {
        node b_rooted = root_tree(b, center);
        string b_encoded = encode(b_rooted);

        if (a_encoded == b_encoded) return true;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree1(n), tree2(n);
    addUndirectedEdge(tree1, 0, 1);
    addUndirectedEdge(tree1, 2, 1);
    cout << encode(tree1, 0);

