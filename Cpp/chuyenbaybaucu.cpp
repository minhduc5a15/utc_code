#include <iostream>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
typedef vector<ll> vll;
const int MOD = 1000000007;

struct Edge {
    ll tour, cost;
    struct Compare {
        bool operator()(const Edge &a, const Edge &b) const {
            return a.tour > b.tour;
        }
    };
};

void solve(int n, const vector<vector<Edge>> &graph) {
    vll dist(n, LONG_LONG_MAX);
    vll count(n, 0);
    vll min_flights(n, 0);
    vll max_flights(n, 0);
    dist[0] = 0;
    count[0] = 1;

    priority_queue<Edge, vector<Edge>, Edge::Compare> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll v_dist = pq.top().tour;
        ll v = pq.top().cost;
        pq.pop();
        if (v_dist != dist[v]) continue;
        for (const Edge &edge: graph[v]) {
            ll w = edge.tour;
            ll w_cost = edge.cost;
            if (dist[v] + w_cost < dist[w]) {
                dist[w] = dist[v] + w_cost;
                count[w] = count[v];
                min_flights[w] = min_flights[v] + 1;
                max_flights[w] = max_flights[v] + 1;
                pq.push({dist[w], w});
            }
            else if (dist[v] + w_cost == dist[w]) {
                count[w] += count[v];
                count[w] %= MOD;
                min_flights[w] = min(min_flights[w], min_flights[v] + 1);
                max_flights[w] = max(max_flights[w], max_flights[v] + 1);
            }
        }
    }

    cout << dist.back() << " " << count.back() << " " << min_flights.back() << " " << max_flights.back() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
    }
    solve(n, graph);
    return 0;
}
