#include <bits/stdc++.h>
using namespace std;
// typedef long long int;
struct t { 
    int to, time, cm; 
}; 
class tc {
    public: 
        bool operator()(t const& lhs, t const& rhs) const {
        return lhs.time > rhs.time;
        }
};
const int M = 1e5;
vector<t> adj[M+1];
int dis[M+1][201];
int hs[M+1];
bool vis[M+1];
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
    for (int i = 0; i <= nodes; i++) {
        for (int j = 0; j <= hull; j++) {
            dis[i][j] = INT_MAX;
        }
    }
    cin >> a >> b;
    dis[a][hull] = 0;
    hs[a] = hull;
    t start = {a, 0, 0};
    vis[a] = true;
    pq.push(start);
    while (!pq.empty()) {
        t cur = pq.top();
        int node = cur.to;
        pq.pop();
        if (node == b) {
            break;
        }
        int dest = cur.to;  
        for (int i = 0; i < adj[dest].size(); i++) {
            int nxt = adj[dest].at(i).to;
            int cost = adj[dest].at(i).time;
            int hw = adj[dest].at(i).cm;
            if (hs[node] - hw > 0 && dis[nxt][hs[node]-hw] > dis[node][hs[node]] + cost && !vis[nxt]) {
                dis[nxt][hs[node]-hw] = dis[node][hs[node]] + cost;
                hs[nxt] = hs[node] - hw;
                vis[nxt]= true;
                pq.push(adj[dest].at(i));
            }
        }
    }
    if (dis[b][hs[b]] == INT_MAX) {
        cout << -1 << endl;
    }else {
        cout << dis[b][hs[b]] << endl;
    }
    return 0;
}