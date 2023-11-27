#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string x, y;
    vector<ll> P, Q, R;
    cin >> x; reverse(x.begin(), x.end()); for (char z : x) P.push_back(z - '0');
    cin >> x; reverse(x.begin(), x.end()); for (char z : x) Q.push_back(z - '0');
    R.resize(P.size() + Q.size() - 1);
    for (int i = 0;i < P.size(); ++i)
        for (int j = 0;j < Q.size(); ++j) R[i + j] += P[i] * Q[j];
    ll t = 0;
    for (ll& z : R) { t = t + z; z = t % 10; t = t / 10; }
    while (t) { R.push_back(t % 10); t /= 10; }
    for (auto z = R.rbegin(); z != R.rend(); z++) cout << *z;

    return 0;

}