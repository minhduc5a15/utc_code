#include <iostream>
#include <algorithm>
#include <vector>
typedef std::vector<int> List;

List solve(List &arr, const List &queries) {
	std::sort(arr.begin(), arr.end());
	List result;
	for (int query: queries) {
		int count = std::upper_bound(arr.begin(), arr.end(), query) - arr.begin();
		result.push_back(count);
	}
	return result;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	List arr(n), queries(m);
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> queries[i];
	}
	List result = solve(arr, queries);
	for (const int &item: result) { std::cout << item << '\n'; }
	return 0;
}


// code by duck it1
