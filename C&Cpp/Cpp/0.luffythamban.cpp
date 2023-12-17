#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int solve(const vector<int> &arr) {
	int minDiff = INT_MAX;
	for (int k = *min_element(arr.begin(), arr.end()); k <= *max_element(arr.begin(), arr.end()); ++k) {
		int diffSum = 0;
		for (const int &num: arr) {
			diffSum += abs(num - k);
		}
		minDiff = min(minDiff, diffSum);
	}
	return minDiff;
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
	cout << solve(arr) << endl;
	return 0;
}

