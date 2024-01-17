#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ll long long

bool check(ll mid, const ll *arr, int n, int k) {
    int count = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > mid) return false;
        sum += arr[i];
        if (sum > mid) {
            sum = arr[i];
            ++count;
        }
    }
    ++count;
    return count <= k;
}

int main() {
    int n, k;
    ll left = 0, right = 0;
    scanf("%d%d", &n, &k);
    ll *arr = (ll *) malloc((n + 1) * sizeof(ll));
    for (ll i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
        if (arr[i] > left) left = arr[i];
        right += arr[i];
    }
    while (left < right) {
        ll mid = left + ((right - left) >> 1);
        if (check(mid, arr, n, k)) {
            right = mid;
        }
        else left = mid + 1;
    }
    printf("%lld", left);
    free(arr);
    return 0;
}