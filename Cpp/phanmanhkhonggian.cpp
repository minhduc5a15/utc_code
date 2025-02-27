#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rect {
    int xA, yA, xB, yB;

    Rect(int xA, int yA, int xB, int yB) : xA(xA), yA(yA), xB(xB), yB(yB) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Rect> rects;
        vector<int> xs, ys;
        for (int i = 0; i < n; ++i) {
            int xA, yA, xB, yB;
            cin >> xA >> yA >> xB >> yB;
            if(xA > xB) swap(xA, xB);
            if(yA < yB) swap(yA, yB);
            rects.push_back({xA, yA, xB, yB});

            rects.push_back({xA, yA, xB, yB});
            xs.push_back(xA);
            xs.push_back(xB);
            ys.push_back(yA);
            ys.push_back(yB);
        }

        int minX = *min_element(xs.begin(), xs.end());
        int maxX = *max_element(xs.begin(), xs.end());
        int minY = *min_element(ys.begin(), ys.end());
        int maxY = *max_element(ys.begin(), ys.end());
        xs.push_back(minX - 1);
        xs.push_back(maxX + 1);
        ys.push_back(minY - 1);
        ys.push_back(maxY + 1);

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        int nx = xs.size(), ny = ys.size();
        vector v(nx, vector(ny - 1, false));
        vector h(nx - 1, vector(ny, false));

        for (const auto &[xA, yA, xB, yB]: rects) {
            int idxX = static_cast<int>(lower_bound(xs.begin(), xs.end(), xA) - xs.begin());
            for (int j = 0; j < ny - 1; ++j) {
                if (ys[j] >= yB && ys[j + 1] <= yA) {
                    v[idxX][j] = true;
                }
            }
            idxX = static_cast<int>(lower_bound(xs.begin(), xs.end(), xB) - xs.begin());
            for (int j = 0; j < ny - 1; ++j) {
                if (ys[j] >= yB && ys[j + 1] <= yA) {
                    v[idxX][j] = true;
                }
            }
            int idxY = static_cast<int>(lower_bound(ys.begin(), ys.end(), yA) - ys.begin());
            for (int i = 0; i < nx - 1; ++i) {
                if (xs[i] >= xA && xs[i + 1] <= xB) {
                    h[i][idxY] = true;
                }
            }
            idxY = static_cast<int>(lower_bound(ys.begin(), ys.end(), yB) - ys.begin());
            for (int i = 0; i < nx - 1; ++i) {
                if (xs[i] >= xA && xs[i + 1] <= xB) {
                    h[i][idxY] = true;
                }
            }
        }

        int cx = nx - 1, cy = ny - 1;
        vector visited(cx, vector(cy, false));
        int res = 0;

        auto dfs = [&](auto self, int i, int j) -> void {
            visited[i][j] = true;
            if (i > 0 && !visited[i - 1][j] && !v[i][j]) self(self, i - 1, j);
            if (i < cx - 1 && !visited[i + 1][j] && !v[i + 1][j]) self(self, i + 1, j);
            if (j > 0 && !visited[i][j - 1] && !h[i][j]) self(self, i, j - 1);
            if (j < cy - 1 && !visited[i][j + 1] && !h[i][j + 1]) self(self, i, j + 1);
        };

        for (int i = 0; i < cx; ++i) {
            for (int j = 0; j < cy; ++j) {
                if (!visited[i][j]) {
                    res++;
                    dfs(dfs, i, j);
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}