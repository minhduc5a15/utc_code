#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, count = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i < n - 1; ++i) {
        if ((arr[i] > arr[i - 1]) && arr[i] > arr[i + 1]) {
            count++;
        }
    }
    cout << count;
    delete[] arr;
    return 0;
}
