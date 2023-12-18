#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(const vector<int> &arr, int n) {
	unordered_map<int, int> map;
	int result = 0;
	int start = 0;
	for (int end = 0; end < n; ++end) {
		if (map.find(arr[end]) != map.end()) {
			start = max(start, map[arr[end]] + 1);
		}
		map[arr[end]] = end;
		result = max(result, end - start + 1);
	}

	return result;
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
	cout << solve(arr, n);
	return 0;
}

