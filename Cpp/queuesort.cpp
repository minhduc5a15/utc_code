#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    queue<int> q1, q2;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q1.push(x);
    }
    int res = 0;
    while (!q1.empty()) {
        int t1 = q1.front();
        if (q2.empty()) q2.push(t1), q1.pop();
        else if (t1 > q1.back() and q2.front() > q1.back()) {
            if (t1 < q2.front()) q1.push(t1), q1.pop();
            else q1.push(q2.front()), q2.pop();
        }
        else if (t1 > q1.back() and t1 > q2.back()) {
            if (q1.back() > q2.back()) q1.push(t1);
            else q2.push(t1);
            q1.pop();
        }
        else if (t1 > q1.back() or q2.front() > q1.back()) {
            if (t1 > q1.back()) q1.push(t1), q1.pop();
            else q1.push(q2.front()), q2.pop();
        }
        else if (t1 > q1.back() or t1 > q2.back()) {
            if (t1 > q1.back()) q1.push(t1), q1.pop();
            else q2.push(t1), q1.pop();
        }
        else {
            if (t1 < q2.front()) q1.push(t1), q1.pop();
            else q1.push(q2.front()), q2.pop();
        }
        ++res;
    }
    cout << res;
    return 0;
}
