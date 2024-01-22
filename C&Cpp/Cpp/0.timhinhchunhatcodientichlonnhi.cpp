#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
typedef tuple<int, int, int> tup;

bool lambda(const tup &A, const tup &B) {
    return get<2>(A) < get<2>(B);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int k = n - 2;
    vector<tup> arr(n);
    for (int i = 0; i < n; ++i) {
        int length, width;
        cin >> length >> width;
        arr[i] = make_tuple(length, width, length * width);
    }
    sort(arr.begin(), arr.end(), lambda);
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
