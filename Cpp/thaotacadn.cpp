#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Treap {
private:
    struct Node {
        char c;
        int priority;
        Node *left, *right;
        int size;
        int countA, countT, countG, countC;

        explicit Node(char ch) : c(ch), priority(rand()), left(nullptr), right(nullptr), size(1) {
            countA = ch == 'A';
            countT = ch == 'T';
            countG = ch == 'G';
            countC = ch == 'C';
        }

        void update() {
            size = 1;
            countA = c == 'A';
            countT = c == 'T';
            countG = c == 'G';
            countC = c == 'C';

            if (left) {
                size += left->size;
                countA += left->countA;
                countT += left->countT;
                countG += left->countG;
                countC += left->countC;
            }
            if (right) {
                size += right->size;
                countA += right->countA;
                countT += right->countT;
                countG += right->countG;
                countC += right->countC;
            }
        }
    };

    Node *root;

    Node *merge(Node *left, Node *right) {
        if (!left) return right;
        if (!right) return left;

        if (left->priority > right->priority) {
            left->right = merge(left->right, right);
            left->update();
            return left;
        }
        right->left = merge(left, right->left);
        right->update();
        return right;
    }

    void split(Node *root, int k, Node *&left, Node *&right) {
        if (!root) {
            left = right = nullptr;
            return;
        }

        if (int left_size = root->left ? root->left->size : 0; left_size + 1 <= k) {
            Node *new_right = nullptr;
            split(root->right, k - (left_size + 1), new_right, right);
            root->right = new_right;
            left = root;
        }
        else {
            Node *new_left = nullptr;
            split(root->left, k, left, new_left);
            root->left = new_left;
            right = root;
        }
        root->update();
    }

    Node *build(const string &s) {
        Node *treap = nullptr;
        for (char c: s) {
            auto node = new Node(c);
            treap = merge(treap, node);
        }
        return treap;
    }

    void remove(Node *&root, int pos) {
        Node *left, *mid, *right;
        split(root, pos, left, right);
        split(right, 1, mid, right);
        root = merge(left, right);
        delete mid;
    }

public:
    Treap() : root(nullptr) {}

    void add_right(const string &s) {
        Node *new_treap = build(s);
        root = merge(root, new_treap);
    }

    void add_left(const string &s) {
        Node *new_treap = build(s);
        root = merge(new_treap, root);
    }

    void remove_at(int i) {
        if (int curr_len = root ? root->size : 0; i < 1 || i > curr_len) {
            cout << "ERROR\n";
            return;
        }
        remove(root, i - 1);
    }

    void stat(int l, int r) {
        if (int curr_len = root ? root->size : 0; l < 1 || r > curr_len || l > r) {
            cout << "ERROR\n";
            return;
        }
        Node *left, *midRight, *middle, *right;
        split(root, l - 1, left, midRight);
        split(midRight, r - l + 1, middle, right);
        int T_count = middle ? middle->countT : 0;
        int A_count = middle ? middle->countA : 0;
        int C_count = middle ? middle->countC : 0;
        int G_count = middle ? middle->countG : 0;
        cout << T_count << ' ' << A_count << ' ' << C_count << ' ' << G_count << '\n';
        Node *temp = merge(left, middle);
        root = merge(temp, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(nullptr));
    int q;
    cin >> q;
    Treap treap;
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADDR") {
            string x;
            cin >> x;
            treap.add_right(x);
        }
        else if (cmd == "ADDL") {
            string x;
            cin >> x;
            treap.add_left(x);
        }
        else if (cmd == "REMOVE") {
            int i;
            cin >> i;
            treap.remove_at(i);
        }
        else if (cmd == "STAT") {
            int l, r;
            cin >> l >> r;
            treap.stat(l, r);
        }
    }

    return 0;
}
