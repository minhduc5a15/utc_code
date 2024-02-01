#include <iostream>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::deque<int> dq;
    while (n--) {
        int x;
        std::cin >> x;
        if (dq.empty() || dq.back() != x) {
            dq.push_back(x);
        }
    }
    int m;
    std::cin >> m;
    int rank = dq.size();
    while (m--) {
        int x;
        std::cin >> x;
        while (!dq.empty() && dq.back() <= x) {
            dq.pop_back();
            --rank;
        }
        dq.push_back(x);
        std::cout << ++rank << "\n";
    }

    return 0;
}


