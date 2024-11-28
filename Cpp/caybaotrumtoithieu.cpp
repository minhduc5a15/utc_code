#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node *parent, *left, *right;
    int key, min_key;
    bool reversed;

    explicit Node(int value): parent(nullptr), left(nullptr), right(nullptr), key(value), min_key(value), reversed(false) {}
};

class Tree {
public:
    void access(Node *x) const {
        for (Node *y = nullptr; x; y = x, x = x->parent) {
            splay(x);
            x->right = y;
            update(x);
        }
    }

    void make_root(Node *x) const {
        access(x);
        splay(x);
        x->reversed = !x->reversed;
    }

    Node *find_root(Node *x) const {
        access(x);
        splay(x);
        while (x->left) x = x->left;
        splay(x);
        return x;
    }

m
    void link(Node *x, Node *y) const {
        make_root(x);
        x->parent = y;
    }

private:
    void update(Node *x) const {
        x->min_key = x->key;
        if (x->left) x->min_key = min(x->min_key, x->left->min_key);
        if (x->right) x->min_key = min(x->min_key, x->right->min_key);
    }

    void splay(Node *x) const {
        while (!is_root(x)) {
            Node *p = x->parent;
            Node *g = p->parent;
            if (!is_root(p)) rotate((x == p->left) == (p == g->left) ? p : x);
            rotate(x);
        }
        update(x);
    }

    bool is_root(const Node *x) const {
        return !x->parent || (x != x->parent->left && x != x->parent->right);
    }

    void rotate(Node *x) const {
        Node *p = x->parent;
        Node *g = p->parent;
        if (x == p->left) {
            p->left = x->right;
            if (x->right) x->right->parent = p;
            x->right = p;
        }
        else {
            p->right = x->left;
            if (x->left) x->left->parent = p;
            x->left = p;
        }
        p->parent = x;
        x->parent = g;
        if (g) {
            if (p == g->left) g->left = x;
            else g->right = x;
        }
        update(p);
        update(x);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<Node *> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = new Node(i);
    }
    Tree tree;
    vector<tuple<int, int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = {c, u, v};
    }
    sort(edges.begin(), edges.end());
    long long res = 0;
    for (auto [c, u, v]: edges) {
        if (tree.find_root(nodes[u]) != tree.find_root(nodes[v])) {
            tree.link(nodes[u], nodes[v]);
            res += c;
        }
    }
    cout << res;
    return 0;
}
