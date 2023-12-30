#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MOD 1000000007
#define ll long long
typedef std::pair<ll, ll> pll;
using namespace std;

struct Edge {
    ll to, cost;
};

struct Compare {
    bool operator()(const pll &a, const pll &b) const {
        return a.first > b.first;
    }
};

void solve(int n, const vector<vector<Edge>> &graph) {
    vector<ll> dist(n, LONG_LONG_MAX);
    vector<ll> count(n, 0);
    vector<ll> min_flights(n, 0);
    vector<ll> max_flights(n, 0);
    dist[0] = 0;
    count[0] = 1;
    min_flights[0] = 0;
    max_flights[0] = 0;

    priority_queue<pll, vector<pll>, Compare> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        ll v_dist = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        if (v_dist != dist[v]) {
            continue;
        }
        for (const Edge &edge: graph[v]) {
            ll w = edge.to;
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
    cin.tie(NULL);
    cout.tie(NULL);
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
