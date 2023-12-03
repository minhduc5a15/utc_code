#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void solve(vector<int>& arr, int n, int k) {
    deque<int> Qi(k);
    int i;
    for (i = 0; i < k; ++i) {
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) {
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    for (; i < n; ++i) {
        cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && Qi.front() <= i - k) {
            Qi.pop_front();
        }
        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) {
            Qi.pop_back();
        }
        Qi.push_back(i);
    }
    cout << arr[Qi.front()] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    solve(arr, n, k);
    return 0;
}

// code by duck it1
