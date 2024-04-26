#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 200005;

struct Node {
    int data;
    Node *parent;
    vector<Node *> child;
};

vector<int> changed(MAXN, 0), up_map(MAXN, 0), down_map(MAXN, 0);
vector<bool> visited(MAXN, false);
vector<Node *> arr;
int up_bonus;
bool check;

Node *create_node(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    return new_node;
}

void add(Node *parent, Node *child) {
    parent->child.push_back(child);
    child->parent = parent;
}

void dfs(const Node *start, const Node *end) {
    ++changed[start->data];
    if (start == end) {
        check = true;
        return;
    }
    for (const Node *u: start->child) {
        dfs(u, end);
        if (check) return;
    }
    --changed[start->data];
}

void downcast(const Node *u, int down_bonus) {
    visited[u->data] = true;
    changed[u->data] += down_bonus;
    for (Node *v: u->child) {
        if (visited[v->data]) continue;
        if (down_map[v->data]) downcast(v, down_bonus + down_map[v->data]);
        else downcast(v, down_bonus);
    }
}

void downcast(Node *start) {
    queue<Node *> q;
    ++changed[start->data];
    q.push(start);
    while (!q.empty()) {
        Node *top = q.front();
        q.pop();
        for (Node *u: top->child) {
            ++changed[u->data];
            q.push(u);
        }
    }
}

void upcast(int i) {
    check = false;
    dfs(arr[1], arr[i]);
}

void upcast(Node *u) {
    if (!visited[u->data] && up_map[u->data]) {
        up_bonus += up_map[u->data];
    }
    visited[u->data] = true;
    changed[u->data] += up_bonus;
    if (u == arr[1]) return;
    upcast(u->parent);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        arr[i] = create_node(i);
    }
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        add(arr[u], arr[v]);
    }
    int q;
    cin >> q;
    if (n <= 1000) {
        while (q--) {
            string s;
            int i;
            cin >> s >> i;
            if (s == "UPCAST") upcast(i);
            else downcast(arr[i]);
        }
        for (int i = 1; i <= n; ++i) cout << (changed[i] & 1);
        return 0;
    }
    while (q--) {
        string s;
        int i;
        cin >> s >> i;
        if (s == "UPCAST") ++up_map[i];
        else ++down_map[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && up_map[i]) {
            up_bonus = 0;
            upcast(arr[i]);
        }
    }
    visited.clear();
    visited.resize(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && down_map[i]) {
            downcast(arr[i], down_map[i]);
        }
    }
    for (int i = 1; i <= n; ++i) cout << (changed[i] & 1);
    return 0;
}