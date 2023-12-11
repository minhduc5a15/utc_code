#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::ios_base;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cout << solve(arr);
	return 0;
}


// code by duck it1
