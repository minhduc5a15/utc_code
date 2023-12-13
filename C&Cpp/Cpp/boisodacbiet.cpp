#include <iostream>
#include <queue>
#include <string>
using namespace std;

string solve(int n) {
    queue<string> q;
    q.push("9");
    while (!q.empty()) {
        string num = q.front();
        q.pop();
        int rem = 0;
        for (char i : num) rem = (rem * 10 + (i - '0')) % n;
        if (rem == 0) return num;
        q.push(num + "0");
        q.push(num + "9");
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int item;
        cin >> item;
        cout << solve(item) << '\n';
    }
    return 0;
}


// code by duck it1
