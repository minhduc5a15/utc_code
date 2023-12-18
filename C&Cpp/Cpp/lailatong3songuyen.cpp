#include <iostream>

using namespace std;

long long solve(int n, int s) {
	long long count = 0;
	for (int X = 0; X <= min(n, s); ++X) {
		int min_YZ = max(0, s - X - n);
		int max_YZ = min(n, s - X);
		if (min_YZ <= max_YZ) {
			count += max_YZ - min_YZ + 1;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, s;
	cin >> n >> s;
	cout << solve(n, s) << endl;
	return 0;
}


