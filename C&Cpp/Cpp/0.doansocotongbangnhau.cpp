#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> arr;

void divisor(int x) {
	int root = sqrt(x);
	if (root * root == x) arr.push_back(root);
	for (int i = 1; i < root; ++i) {
		if (x % i == 0) {
			arr.push_back(i);
			arr.push_back(x / i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int index, n;
	while (t--) {
		cin >> index >> n;
		vector<int> a(n + 1);
		int sum = 0;
		a[0] = 0;
		for (int i = 1; i <= n; ++i) {
            int x;
			cin >> x;
			sum += x;
			a[i] = sum;
		}
		int max_sum = a.back();
		divisor(max_sum);
		sort(arr.begin(), arr.end());
		int step = 0;
		for (const int &item: arr) {
            int step_arr = max_sum / item;
			int d = 0, count = 0;
            bool check;
			while (true) {
				check = false;
				for (int j = d + 1; j <= n; ++j) {
					if (a[j] - a[d] == item) {
						check = true;
						d = j;
						count++;
						break;
					}
				}
				if (!check) break;
			}
			if (count == step_arr) {
				step = step_arr;
				break;
			}
		}
		int result = max_sum / step;
		if (result) cout << index << " " << result << '\n';
		else cout << index << " " << '\n';
		arr.clear();
	}
	return 0;
}


