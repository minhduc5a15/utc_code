#include <iostream>
#include <vector>

int kadane(const std::vector<int> &arr, int n) {
	int max_so_far = arr.front(), current_max = arr.front();
	for (int i = 1; i < n; ++i) {
		current_max = std::max(arr[i], current_max + arr[i]);
		max_so_far = std::max(current_max, max_so_far);
	}
	return max_so_far;
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
	std::cout << kadane(arr, n);
	return 0;
}

