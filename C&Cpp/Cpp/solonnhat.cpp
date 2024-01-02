#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    while (m--) {
        int x;
        cin >> x;
        x -= 1;
        s.erase(s.find(arr[x]));
        arr[x] *= -1;
        s.insert(arr[x]);
        cout << *s.rbegin() << ' ';
    }
    return 0;
}
