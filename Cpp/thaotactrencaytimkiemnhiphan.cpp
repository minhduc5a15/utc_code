#include <iostream>
#include <vector>
using namespace std;

struct node {
    int val;
    node *left;
    node *right;

    node(int _v) : val(_v), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    node *root;

    Tree() : root(nullptr) {}

    node *insert(node *current, int val) {
        if (current == nullptr) return new node(val);
        if (val < current->val) current->left = insert(current->left, val);
        else if (val > current->val) current->right = insert(current->right, val);
        return current;
    }

    node *remove(node *current, int val) {
        if (current == nullptr) return nullptr;
        if (val < current->val) current->left = remove(current->left, val);
        else if (val > current->val) current->right = remove(current->right, val);
        else {
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            }
            if (current->left != nullptr) {
                node *max_node = get_max(current->left);
                current->val = max_node->val;
                current->left = remove(current->left, max_node->val);
            }
            else if (current->right != nullptr) {
                node *min_node = get_min(current->right);
                current->val = min_node->val;
                current->right = remove(current->right, min_node->val);
            }
        }
        return current;
    }

    node *get_min(node *current) {
        while (current && current->left) current = current->left;
        return current;
    }

    node *get_max(node *current) {
        while (current && current->right) current = current->right;
        return current;
    }

    bool query(node *current, int val, vector<int> &path) {
        if (current == nullptr) return false;
        path.push_back(current->val);
        if (current->val == val) return true;
        if ((val < current->val && query(current->left, val, path)) or (val > current->val && query(current->right, val, path))) return true;
        path.pop_back();
        return false;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int val) {
        root = remove(root, val);
    }

    void solve(int val) {
        vector<int> path;
        if (query(root, val, path)) {
            for (int i = path.size() - 1; i >= 0; --i) {
                cout << path[i] << ' ';
            }
            cout << '\n';
            return;
        }
        cout << -1 << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    Tree tree;
    while (t--) {
        int u, v;
        cin >> u >> v;
        if (u == 1) tree.insert(v);
        else if (u == -1) tree.remove(v);
        else tree.solve(v);
    }
    return 0;
}