#include <iostream>
#include <stack>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	stack<pair<int, int>> st;
	st.push({INT_MAX, 0});
	int res = 0;
	while (n--) {
		int x;
		cin >> x;
		while (st.top().first < x) {
			res += st.top().second;
			st.pop();
		}
		if (st.top().first == x) {
			if (st.size() > 2) ++res;
			res += st.top().second++;
		}
		else {
			res += st.size() > 1;
			st.push({x, 1});
		}
	}
	cout << res;
	return 0;
}
