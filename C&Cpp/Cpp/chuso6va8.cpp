#include <iostream>
#include <queue>
#include <string>
using namespace std;

string solve(int n) {
    if (n % 5 == 0) return "0";
    queue<string> queue;
    queue.push("6");
    while (true) {
        string num = queue.front();
        queue.pop();
        if (stoll(num) % n == 0) return num;
        queue.push(num + "6");
        queue.push(num + "8");
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
