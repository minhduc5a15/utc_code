//svmc 2017 code1 - secret Code
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int xr, xi, br, bi;
        scanf("%d%d%d%d", &xr, &xi, &br, &bi);
        int bb = br * br + bi * bi;
        int b = static_cast<int>(sqrt(static_cast<double>(bb)) - 1e-6);
        stack<int> ans;
        bool decrypted = true;
        while (xr != 0 || xi != 0) {
            bool found = false;
            for (int a = 0; a <= b; ++a) {
                int r = (xr - a) * br - xi * (-bi);
                int i = (xr - a) * (-bi) + xi * br;
                if (r % bb == 0 && i % bb == 0) {
                    xr = r / bb;
                    xi = i / bb;
                    ans.push(a);
                    found = true;
                    break;
                }
            }

            if (!found || ans.size() > 100) {
                decrypted = false;
                break;
            }
        }

        if (!decrypted) {
            puts("The code cannot be decrypted.");
        }
        else {
            while (!ans.empty()) {
                printf("%d", ans.top());
                ans.pop();
                putchar(ans.empty() ? '\n' : ',');
            }
        }
    }

    return 0;
}
