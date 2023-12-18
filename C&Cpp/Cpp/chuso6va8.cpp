#include <iostream>
#include <queue>
#include <string>
using namespace std;

string solve(int n) {
    if (n % 5 == 0) return "0";
    queue<string> q;
    q.push("6");
    while (true) {
        string num = q.front();
        q.pop();
        if (stoll(num) % n == 0) return num;
        q.push(num + "6");
        q.push(num + "8");
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}


// code by duck it1
