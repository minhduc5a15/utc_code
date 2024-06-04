#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tup;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int k = n - 2;
    vector<tup> arr(n);
    for (int i = 0; i < n; ++i) {
        int length, width;
        cin >> length >> width;
        arr[i] = make_tuple(length, width, length * width);
    }
    sort(arr.begin(), arr.end(), [](const tup &a, const tup &b) {
        return get<2>(a) < get<2>(b);
    });
    while (k >= 0) {
        if (get<2>(arr[k]) < get<2>(arr[n - 1]) && ((k > 0 && get<2>(arr[k]) != get<2>(arr[k - 1])) || k == 0)) {
            cout << get<0>(arr[k]) << " " << get<1>(arr[k]);
            break;
        }
        else {
            k--;
        }
    }
    if (k < 0) cout << "NO";
    return 0;
}
