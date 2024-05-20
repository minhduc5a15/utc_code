#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        string res = arr[i];
        for (int l = 1; l <= 9; ++l) {
            for (int start = 0; start + l <= 9; ++start) {
                string sub = arr[i].substr(start, l);
                int count = 0;
                for (string s: arr) {
                    if (s.find(sub) != string::npos) {
                        ++count;
                    }
                }
                if (count == 1 && (sub.size() < res.size() || (sub.size() == res.size() && sub < res))) {
                    res = sub;
                }
            }
        }
        cout << res << ' ';
    }
    return 0;
}
