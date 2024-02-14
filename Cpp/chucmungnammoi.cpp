#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int half = n >> 1;
    int mid = (n - 7) >> 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < half) {
                if (j < half - i || j >= half + i + 1) cout << "---";
                else cout << s;
            }
            else if (i == half) {
                if (j == mid) cout << "--CHUC MUNG NAM MOI--";
                if (j < mid || j > mid + 6) cout << "---";
            }
            else {
                if (j < i - half || j >= n - (i - half)) cout << "---";
                else cout << s;
            }
        }
        cout << "\n";
    }
    return 0;
}
