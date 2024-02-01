#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<>> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
    while (n--) {
        int x;
        cin >> x;
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        }
        else {
            minHeap.push(x);
        }
        while (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        while (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        cout << maxHeap.top() << ' ';
    }

    return 0;
}
