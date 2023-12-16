#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lambda(string a, string b) {
    while (true) {
        for (int i = 0; i < a.size() and i < b.size(); ++i) {
            if (a[i] > b[i]) return true;
            else if (a[i] < b[i]) return false;
        }
        if (a.size() > b.size()) a.erase(0, b.size());
        else if (a.size() < b.size()) b.erase(0, a.size());
        else return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), lambda);
    for_each(arr.begin(), arr.end(), [](const string &num) { cout << num; });
    return 0;
}