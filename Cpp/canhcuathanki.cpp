#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    string arr[] = { "dangdungcntt", "tienquanutc", "quang123", "maianh", "nguyenminhduc2820" };
    while (t--) {
        int n;
        cin >> n;
        ll i = 1;
        while (i * 5 < n) {
            n -= i * 5;
            i <<= 1;
        }
        cout << arr[n / i + (n % i != 0) - 1]  << '\n';
    }
    return 0;
}
