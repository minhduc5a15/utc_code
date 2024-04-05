#include <stdio.h>
typedef long long ll;

ll arr[40][40];

void solve(int n) {
    for (int i = 0; i < n; ++i) {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n + 1);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
