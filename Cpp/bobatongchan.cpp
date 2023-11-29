#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    ll even_count = 0;
    cin >> n;
    vector <int> arr(n);
    for (int &item: arr) {
        cin >> item;
        if (item % 2 == 0) even_count++;     
    }
    ll odd_count = n - even_count;
    cout << even_count * (even_count - 1) * (even_count - 2) / 6 + odd_count * (odd_count - 1) / 2 * even_count;
    return 0;
}