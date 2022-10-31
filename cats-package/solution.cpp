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
        for (auto node : nodes) {
            this->children.push_back(node);
        }
    }
};

vector<int> find_centers(vector<pair<int, int>>& graph) {

}
// .first - текущий id
// .second - id родителя
node build_tree(vector<pair<int,int>>& graph, node& _node) {
    for (pair<int,int> current : graph) {

        if (current.first == _node.id) continue;

        else if (current.second == _node.id){

            node *child = new node(current.first, &_node);
            _node.add_children({*child});

            build_tree(graph, *child);
        }
    }
}

node root_tree(vector<pair<int, int>>& graph, int root_id) {
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

bool is_isomorphic(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
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
    vector<pair<int,int>> tree1(n);
    vector<pair<int,int>> tree2(n);

    for (int i = 0; i < n; i++) {
        cin >> tree1[i].first >> tree1[i].second;
    }

    for (int i = 0; i < n; i++) {
        cin >> tree2[i].first >> tree2[i].second;
    }


}

