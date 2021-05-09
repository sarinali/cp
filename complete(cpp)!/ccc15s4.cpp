#include <bits/stdc++.h>
using namespace std;
struct t { 
    int to, time, cm; 
}; 
class tc {
    public: 
        bool operator()(t const& lhs, t const& rhs) const {
            return lhs.time > rhs.time;
        }
};
vector<t> adj[2001];
int dis[2001][2001];
priority_queue<t, vector<t>, tc> pq; 
int a, b, roads, nodes, hull;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> hull >> nodes >> roads;
    for (int i = 0; i < roads; i++) {
        int from, to, time, cm;
        cin >> from >> to >> time >> cm;
        t cur = {to, time, cm};
        t cur1 = {from, time, cm};
        adj[from].push_back(cur);
        adj[to].push_back(cur1);
    }
    for (int i = 0; i <= hull; i++) {
        for (int j = 0; j <= nodes; j++) {
            dis[i][j] = INT_MAX;
        }
    }
    cin >> a >> b;
    dis[0][a] = 0;
    t start = {a, 0, 0};
    pq.push(start);
    while (!pq.empty()) {
        t cur = pq.top();
        int node = cur.to;
        pq.pop();
        if (node == b) {
            break;
        }
        for (t i : adj[node]) {
            int nxt = i.to;
            int cost = i.time + cur.time;
            int hw = i.cm + cur.cm;
            if (hw >= hull || dis[hw][nxt] <= cost) {
               continue;
            }
            dis[hw][nxt] = cost;
            t g = {nxt, cost, hw};
            pq.push(g);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= hull; i++) {
        ans = min(dis[i][b], ans);
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}