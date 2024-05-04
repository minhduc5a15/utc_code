#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    stack<int> st;
    map<int, bool> mp;
    st.push(n);
    mp[0] = mp[n] = true;
    while (!st.empty()) {
        int num = st.top();
        st.pop();
        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                int j = (i - 1) * (num / i + 1);
                if (j && !mp[j]) {
                    st.push(j);
                    mp[j] = true;
                }
            }
        }
    }
    for (const pair<const int, bool> it: mp) {
        cout << it.first << ' ';
    }
    return 0;
}

