#include <iostream>
#include <vector>
#define BIT 8

using namespace std;

void solve(vector<int> &arr, int n) {
	vector<int> temp(n);
	for (int j = 0; j < 4; ++j) {
		int b = 1 << BIT;
		vector<int> freq(b), freq2(b);
		for (int i = 0; i < n; ++i) {
			freq[(arr[i] >> j * BIT) & (b - 1)]++;
		}
		for (int i = 1; i < b; ++i) {
			freq[i] += freq[i - 1];
		}
		for (int i = n - 1; i >= 0; --i) {
			temp[--freq[(arr[i] >> j * BIT) & (b - 1)]] = arr[i];
		}
		j++;
		for (int i = 0; i < n; ++i) {
			freq2[temp[i] >> j * BIT & (b - 1)]++;
		}
		for (int i = 1; i < b; ++i) {
			freq2[i] += freq2[i - 1];
		}
		for (int i = n - 1; i >= 0; --i) {
			arr[--freq2[temp[i] >> j * BIT & (b - 1)]] = temp[i];
		}
	}
	int mid = (n + 1) / 2, index = 0;
	while (mid < n) {
		if (arr[mid] >= arr[index] * 2) {
			++index;
			++mid;
		}
		else {
			++mid;
		}
	}
	cout << n - index;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	solve(arr, n);
	return 0;
}
