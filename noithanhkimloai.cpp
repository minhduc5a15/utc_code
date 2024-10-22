#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> heap;
    while (n--) {
        int x;
        cin >> x;
        heap.push(x);
    }
    int res = 0;
    while (!heap.empty()) {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        int s = a + b;
        res += s;
        if (heap.empty()) break;
        heap.push(s);
    }
    cout << res;
    return 0;
}