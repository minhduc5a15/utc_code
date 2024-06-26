#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<>> cards;
    for (int i = 0; i < n; ++i) {
        int card;
        cin >> card;
        cards.push(card);
    }
    while (cards.size() > 1) {
        ll a = cards.top();
        cards.pop();
        ll b = cards.top();
        cards.pop();
        if (a + b <= a * b) {
            cards.push(a + b);
        }
        else {
            cards.push(a * b);
        }
    }
    cout << cards.top() << endl;
    return 0;
}
