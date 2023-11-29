#include <stdio.h>

const int nums[] = { 3, 15, 120, 528, 4095, 17955, 139128, 609960, 4726275, 20720703, 160554240, 703893960 };
const int n = 12;

void solve(int l, int r) {
    r -= 2;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int num = nums[i];
        if (l <= num && num <= r) {
            ++count;
        }
        if (num > r) break;
    }
    printf("%d\n", count);
    return;
}

int main() {
    int l, r;
    while (scanf("%d %d", &l, &r) == 2 && l && r) {
        solve(l, r);
    }
    return 0;
}
