#include <iostream>
#include <vector>

int solve(const std::vector<int> &arr) {
	std::vector<int> list;
	for (const int &num: arr) {
		std::vector<int>::iterator pos = lower_bound(list.begin(), list.end(), num);
		if (pos == list.end()) {
			list.push_back(num);
		}
		else {
			*pos = num;
		}
	}
	return list.size();
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}
	std::cout << solve(arr);
	return 0;
}


// code by duck it1
