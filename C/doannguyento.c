#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

const int MAXN = 1000005;

int *prime;
ll *prefix_sum;

void pre() {
    prime = (int *) malloc(sizeof(int) * MAXN);
    prefix_sum = (ll *) malloc(sizeof(ll) * MAXN);
    for (int i = 2; i < MAXN; ++i) {
        if (prime[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                prime[j] = i;
            }
        }
    }

    for (int i = 1; i < MAXN; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + prime[i];
    }
}

ll query(int l, int r) {
    return prefix_sum[r] - prefix_sum[l - 1];
}

int main() {
    pre();
    int t;
    scanf("%d", &t);
    while (t--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%lld\n", query(l, r));
    }
    return 0;
}