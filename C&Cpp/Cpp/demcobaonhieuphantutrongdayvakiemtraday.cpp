#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, c, d, count = 0;
	cin >> n;
	cin >> c >> d;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] >= -c && arr[i] <= d) ++count;
	}
	cout << count << '\n';
	bool check = arr[0] < arr[1];
	if (!check) cout << "NO";
	else {
		for (int i = 2; i < n - 1; ++i) {
			if (check != arr[i] < arr[i + 1]) {
				check = false;
				cout << "NO";
				break;
			}
		}
		if (check) cout << "YES";
	}
}
