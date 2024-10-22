#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100005;

vector<int> BIT(MAXN * 3 + 5, 0);

void update(int id, int val = 1) {
    if (id > (MAXN * 3) + 5) return;
    return BIT[id] += val, update(id + (id & -id), val);
}

int get(int x) {
    return !x ? 0 : BIT[x] + get(x - (x & -x));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        x += MAXN;
        cout << get(x - 1) << ' ';
        update(x);
    }
    return 0;
}
