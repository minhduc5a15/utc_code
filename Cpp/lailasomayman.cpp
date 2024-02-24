#include <iostream>
#include <queue>
#define ll long long
using namespace std;

bool check(const string &s) {
    int count = 0;
    for (char ch: s) {
        if (ch == '4') ++count;
        else --count;
    }
    return !count;
}

string solve(ll n) {
    queue<string> q;
    q.push("4");
    while (!q.empty()) {
        string num = q.front();
        q.pop();
        if (stoll(num) >= n && check(num)) return num;
        q.push(num + '4');
        q.push(num + '7');
    }
    return "";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    cout << solve(n);
    return 0;
}