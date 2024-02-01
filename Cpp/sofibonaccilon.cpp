#include <iostream>
#include <memory>
#include <vector>
using namespace std;
typedef vector<int> vi;

shared_ptr<vi> add(const shared_ptr<vi> &a, const shared_ptr<vi> &b) {
    int size_a = a->size(), size_b = b->size();
    int carry = 0;
    shared_ptr<vi> result = make_shared<vi>(max(size_a, size_b) + 1);
    for (int i = 0; i < static_cast<int>(result->size()); ++i) {
        if (i < size_a) carry += (*a)[i];
        if (i < size_b) carry += (*b)[i];
        (*result)[i] = carry % 10;
        carry /= 10;
    }
    while (static_cast<int>(result->size()) > 1 && result->back() == 0) result->pop_back();
    return result;
}

void solve(const shared_ptr<vi> &arr) {
    for (int i = static_cast<int>(arr->size()) - 1; i >= 0; --i) {
        cout << (*arr)[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    shared_ptr<vi> a = make_shared<vi>(1, 1);
    shared_ptr<vi> b = make_shared<vi>(1, 1);
    if (n == 1) cout << 1;
    else {
        for (int i = 3; i <= n; ++i) {
            shared_ptr<vi> c = add(a, b);
            a = b;
            b = c;
        }
        solve(b);
    }
    return 0;
}

