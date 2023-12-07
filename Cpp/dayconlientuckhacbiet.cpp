#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(const vector<int> &arr, int n) {
	unordered_map<int, int> distinct_elements;
	int result = 0;
	int start = 0;
	for (int end = 0; end < n; end++) {
		if (distinct_elements.find(arr[end]) != distinct_elements.end()) {
			start = max(start, distinct_elements[arr[end]] + 1);
		}
		distinct_elements[arr[end]] = end;
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


// code by duck it1
