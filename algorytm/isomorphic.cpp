
#include <bits/stdc++.h>
using namespace std;

struct node {
    int id;
    node* parent;
    vector<node> children;

    node(int id, node* parent) {
        this->id = id;
        this->parent = parent;
    }

    node(int data) : node(data,  nullptr){};

    void add_children(const vector<node>& nodes) {
        for (auto &node : nodes) {
            this->children.push_back(node);
        }
    }
};

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

node build_tree(vector<vector<int>>& graph, node& _node) {
    for (int neighbour : graph[_node.id]) {
        // игнорируем добавление ребра, указывающего обратно на родителя
        if (_node.parent != nullptr && neighbour == _node.parent->id) {
            continue;
        }

        node *child = new node(neighbour, &_node);
        _node.add_children({*child});

        build_tree(graph, *child);
    }

    return _node;
}

node root_tree(vector<vector<int>>& graph, int root_id) {
    node* root = new node(root_id);
    return build_tree(graph, *root);
}

string encode(node& _node) {
    if (&_node == nullptr) return "";
    vector<string> labels;
    for(node child : _node.children) {
        labels.push_back(encode(child));
    }
    sort(labels.begin(), labels.end());
    string result = "";
    for (string label : labels) {
        result += label;
    }
    return '(' + result + ')';
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
void add_link(vector<vector<int>>& graph, int id, int parent) {
    graph[id].push_back(parent);
    graph[parent].push_back(id);
}
