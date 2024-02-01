#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int item: arr) {
        if (isPrime(item)) cout << item << " ";
    }
    return 0;
}
