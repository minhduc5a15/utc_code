#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    stack<int> st;
    map<int, bool> mp;
    st.push(n);
    mp[0] = true;
    mp[n] = true;
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
    for (int i = 0; i <= n; ++i) {
        if (mp[i]) cout << i << " ";
    }
    return 0;
}

