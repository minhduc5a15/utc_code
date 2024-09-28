#include <stdio.h>
typedef long long ll;

ll calc(int begin, int end) {
    ll length = end - begin + 1;
    return (end + begin) * length * length;
}

int solve(int begin, int end) {
    int left = begin, right = end;
    int mid;
    while (right - left > 2) {
        mid = (right + left) >> 1;
        if (calc(begin, mid) < calc(mid + 1, end)) left = mid;
        else right = mid + 1;
    }
    return right - begin;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", solve(l, l + r - 1));
    }
    return 0;
}