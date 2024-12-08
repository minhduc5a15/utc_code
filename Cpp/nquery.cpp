#include <iostream>
using namespace std;
typedef long long ll;
constexpr int MOD = 1000000007;

class Node {
public:
    Node *left, *right;
    ll size, depth, prefix, suffix, sum, value;

    explicit Node(ll val) {
        left = right = nullptr;
        size = 1;
        depth = 1;
        prefix = suffix = sum = value = val;
    }

    void update() {
        if (left == nullptr || right == nullptr) return;

        size = left->size + right->size;
        depth = max(left->depth, right->depth) + 1;
        prefix = (left->prefix + right->prefix + left->sum * right->size) % MOD;
        suffix = (right->suffix + left->suffix + right->sum * left->size) % MOD;
        sum = (left->sum + right->sum) % MOD;
        value = (left->value + right->value + left->suffix * right->size + right->prefix * left->size) % MOD;
    }

    Node(Node *l, Node *r) {
        left = l;
        right = r;
        update();
    }

    void insert(int i, ll v) {
        if (size == 1 && i == 0) {
            left = new Node(v);
            right = new Node(sum);
            update();
            return;
        }

        if (size == 1 && i == 1) {
            left = new Node(sum);
            right = new Node(v);
            update();
            return;
        }

        if (i <= left->size) {
            left->insert(i, v);
        }
        else {
            right->insert(i - left->size, v);
        }

        balance();
        update();
    }

    void remove(int i) {
        if (size == 1 && i == 0) {
            size = 0;
            depth = 0;
            prefix = suffix = sum = value = 0;
            return;
        }

        if (i < left->size) {
            left->remove(i);
        }
        else {
            right->remove(i - left->size);
        }

        update();
    }

    Node *query(int i, int j) {
        if (i <= 0 && size - 1 <= j) return this;

        if (j < 0 || i >= size) {
            auto temp = new Node(0);
            temp->size = 0;
            return temp;
        }

        return new Node(left->query(i, j), right->query(i - left->size, j - left->size));
    }

    void rotateRight() {
        right = new Node(left->right, right);
        left = left->left;
        update();
    }

    void rotateLeft() {
        left = new Node(left, right->left);
        right = right->right;
        update();
    }

    void balance() {
        if (depth <= 5) return;

        if (left->depth > right->depth + 1) {
            if (left->left->depth < left->right->depth) left->rotateLeft();
            rotateRight();
        }

        if (right->depth > left->depth + 1) {
            if (right->right->depth < right->left->depth) right->rotateRight();
            rotateLeft();
        }

        update();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    auto root = new Node(arr[0]);
    for (int i = 1; i < n; ++i) {
        root->insert(i, arr[i]);
    }
    while (n--) {
        char type;
        cin >> type;
        int i;
        ll v;
        switch (type) {
            case 'C': {
                cin >> i >> v;
                root->insert(i - 1, v);
                break;
            }
            case 'R': {
                int l, r;
                cin >> l >> r;
                cout << root->query(l - 1, r - 1)->value << '\n';
                break;
            }
            case 'U': {
                cin >> i >> v;
                root->remove(i - 1);
                root->insert(i - 1, v);
                break;
            }
            case 'D': {
                cin >> i;
                root->remove(i - 1);
                break;
            }
            default: {
                break;
            };
        }
    }

    delete root->right;
    delete root->left;
    delete root;
    return 0;
}