#include <iostream>
#include <memory>
#include <vector>
using namespace std;
typedef vector<int> vectori;
shared_ptr<vectori> add(const shared_ptr<vectori>& a, const shared_ptr<vectori>& b) {
    int size_a = a->size(), size_b = b->size();
    shared_ptr<vectori> result = make_shared<vectori>(max(size_a, size_b) + 1);
    int carry = 0;
    for (int i = 0; i < static_cast<int>(result->size()); ++i) {
        if (i < size_a) carry += (*a)[i];
        if (i < size_b) carry += (*b)[i];
        (*result)[i] = carry % 10;
        carry /= 10;
    }
    while (static_cast<int>(result->size()) > 1 && result->back() == 0) result->pop_back();
    return result;
}

void solve(const shared_ptr<vectori>& arr) {
    for (int i = static_cast<int>(arr->size()) - 1; i >= 0; --i) cout << (*arr)[i];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    shared_ptr<vectori> a = make_shared<vectori>(1, 1);
    shared_ptr<vectori> b = make_shared<vectori>(1, 1);
    if (n == 1) cout << 1;
    else {
        for (int i = 3; i <= n; ++i) {
            shared_ptr<vectori> c = add(a, b);
            a = b;
            b = c;
        }
        solve(b);
    }
    return 0;
}
