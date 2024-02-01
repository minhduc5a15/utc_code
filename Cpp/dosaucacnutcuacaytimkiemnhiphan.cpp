#include <iostream>
#include <unordered_map>
using namespace std;

class Tree {
private:
    unordered_map<int, int> map;
    struct Node {
        int data;
        Node *left;
        Node *right;
        explicit Node(int data, Node *left = nullptr, Node *right = nullptr) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
    };
public:
    void add(Node *&root, int data, int count) {
        if (root == nullptr) {
            root = new Node(data);
        }
        else {
            if (data > root->data) {
                if (root->right == nullptr) {
                    root->right = new Node(data);
                }
                else {
                    add(root->right, data, ++count);
                }
            }
            else if (data < root->data) {
                if (root->left == nullptr) {
                    root->left = new Node(data);
                }
                else {
                    add(root->left, data, ++count);
                }
            }
        }
    }
    void preOrder(Node *current_node, int position) {
        if (current_node != nullptr) {
            map[current_node->data] = position;
            preOrder(current_node->left, ++position);
            preOrder(current_node->right, position);
        }
    }
    void inOrder(Node *current_node) {
        if (current_node != nullptr) {
            inOrder(current_node->left);
            cout << current_node->data << " " << map[current_node->data] << '\n';
            inOrder(current_node->right);
        }
    }
    void solve(int n) {
        Node *root = nullptr;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (!map[x]) {
                add(root, x, 0);
            }
        }
        preOrder(root, 0);
        inOrder(root);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Tree tree;
    tree.solve(n);
    return 0;
}
