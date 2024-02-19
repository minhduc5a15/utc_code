#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<>> heap;
    while (n--) {
        int x;
        cin >> x;
        heap.push(x);
    }
    long long res = 0;
    while (!heap.empty()) {
        int s = 0;
        for (int i = 0; i < k && !heap.empty(); ++i) {
            int a = heap.top();
            heap.pop();
            s += a;
        }
        res += s;
        if (heap.empty()) break;
        heap.push(s);
    }
    cout << res;
    return 0;
}