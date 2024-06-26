#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
const int MAXN = 31;

struct Node {
    ll val;
    struct Node *child[2];
};
struct Node *root;

void add(ll n) {
    struct Node *current = root;
    for (int i = MAXN; i >= 0; --i) {
        int j = (n & (1LL << i)) ? 1 : 0;
        if (current->child[j] == NULL) {
            current->child[j] = (struct Node *) malloc(sizeof(struct Node));
            current->child[j]->child[0] = NULL;
            current->child[j]->child[1] = NULL;
        }
        current = current->child[j];
    }
    current->val = n;
}

ll solve(ll n) {
    struct Node *current = root;
    for (int i = MAXN; i >= 0; --i) {
        int j = (n & (1LL << i)) ? 1 : 0;
        if (current->child[1 - j]) {
            current = current->child[1 - j];
        }
        else {
            current = current->child[j];
        }
    }
    return n ^ current->val;
}

int main() {
    root = (struct Node *) malloc(sizeof(struct Node));
    root->child[0] = NULL;
    root->child[1] = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        add(x);
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        ll q;
        scanf("%lld", &q);
        printf("%lld\n", solve(q));
    }
    return 0;
}
