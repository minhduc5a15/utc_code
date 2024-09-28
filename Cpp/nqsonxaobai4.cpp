#include <iostream>
using namespace std;

struct Node {
    Node *left, *right;
    int w, s, val;
    bool f;

    Node(int x) {
        left = right = nullptr;
        w = rand();
        s = 1;
        val = x;
        f = 0;
    }
};

class Treap {
private:
    Node *root;
public:

    Treap(): root(nullptr) {}

    int size(Node *treap) {
        return treap == nullptr ? 0 : treap->s;
    }

    void push(Node *treap) {
        if (treap && treap->f) {
            treap->f = 0;
            swap(treap->left, treap->right);
            if (treap->left) treap->left->f ^= 1;
            if (treap->right) treap->right->f ^= 1;
        }
    }

    void split(Node *treap, Node *&left, Node *&right, int k) {
        if (treap == nullptr) {
            left = right = nullptr;
        }
        else {
            push(treap);
            if (size(treap->left) < k) {
                split(treap->right, treap->right, right, k - size(treap->left) - 1);
                left = treap;
            }
            else {
                split(treap->left, left, treap->left, k);
                right = treap;
            }
            treap->s = size(treap->left) + size(treap->right) + 1;
        }
    }

    void merge(Node *&treap, Node *left, Node *right) {
        if (left == nullptr) {
            treap = right;
        }
        else if (right == nullptr) {
            treap = left;
        }
        else {
            push(left);
            push(right);
            if (left->w < right->w) {
                merge(left->right, left->right, right);
                treap = left;
            }
            else {
                merge(right->left, left, right->left);
                treap = right;
            }
            treap->s = size(treap->left) + size(treap->right) + 1;
        }
    }

    void print_treap(Node *treap) {
        if (treap == nullptr) return;
        push(treap);
        print_treap(treap->left);
        cout << treap->val << ' ';
        print_treap(treap->right);
    }

    void insert(int x) {
        merge(root, root, new Node(x));
    }

    void handle(int l, int r) {
        Node *A, *B, *C;
        split(root, A, B, l - 1);
        split(B, B, C, r - l + 1);
        merge(root, A, C);
        merge(root, root, B);
    }

    void print() {
        print_treap(root);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Treap treap;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        treap.insert(x);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        treap.handle(l, r);
    }
    treap.print();
    return 0;
}