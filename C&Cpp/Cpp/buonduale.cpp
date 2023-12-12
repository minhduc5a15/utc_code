#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	long long res = 0;
	cin >> n >> m >> k;
	vector<int> arr(n);
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n + m - 1; ++i) {
		int num = k;
		q.push((i < n) ? arr[i] : 0);
		while (static_cast<int>(q.size()) > m) {
			q.pop();
		}
		while (q.size() && num) {
			if (q.front() <= num) {
				num -= q.front();
				res += q.front();
				q.pop();
			}
			else {
				q.front() -= num;
				res += num;
				num = 0;
			}
		}
	}
	cout << res;
	return 0;
}