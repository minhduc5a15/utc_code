#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    string name;
    vector<Node *> child;
};

map<string, Node *> nodes;

void add_node(string parent, string child) {
    if (nodes.find(parent) == nodes.end()) {
        nodes[parent] = new Node{parent, {}};
    }
    if (nodes.find(child) == nodes.end()) {
        nodes[child] = new Node{child, {}};
    }
    nodes[parent]->child.push_back(nodes[child]);
}

void inorder(Node *node) {
    if (!node->child.empty()) inorder(node->child[0]);
    cout << node->name << ' ';
    for (int i = 1; i < node->child.size(); ++i) inorder(node->child[i]);
}

int max_size(Node *node) {
    int res = node->child.size();
    for (Node *child: node->child) res = max(res, max_size(child));
    return res;
}

int gens(Node *node, int gen) {
    int res = gen;
    for (Node *child: node->child) res = max(res, gens(child, gen + 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string root;
    for (int i = 0; i < n - 1; ++i) {
        string x, y;
        cin >> x >> y;
        if (i == 0) root = x;
        add_node(x, y);
    }
    inorder(nodes[root]);
    cout << '\n' << max_size(nodes[root]) << '\n' << gens(nodes[root], 1);
    return 0;
}
