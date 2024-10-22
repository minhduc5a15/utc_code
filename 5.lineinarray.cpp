#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    char m;
    cin >> n >> m;
    vector<vector<float>> arr(12, vector<float>(12));
    float res = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 12; ++i) {
        res += arr[n][i];
    }
    if (m == 'S') cout << fixed << setprecision(1) << res;
    else cout << fixed << setprecision(1) << res / 12;
    return 0;
}