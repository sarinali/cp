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
    dis[hull][a] = 0;
    hs[a] = hull;
    t start = {a, 0, 0};
    pq.push(start);
    // int count = 0;
    while (!pq.empty()) {
        t cur = pq.top();
        int node = cur.to;
        pq.pop();
        if (node == b) {
            break;
        }
        int dest = cur.to;  
        // cout << node << endl;
        // for (int i = 1; i <= nodes; i++) {
        //     cout << hs[i] << " ";
        // }
        // cout << endl;
        for (int i = 0; i < adj[dest].size(); i++) {
            int nxt = adj[dest].at(i).to;
            int cost = adj[dest].at(i).time;
            int hw = adj[dest].at(i).cm;
            if (hs[node] - hw > 0 && dis[hs[node]-hw][nxt] > dis[hs[node]][node] + cost) {
                dis[hs[node]-hw][nxt] = dis[hs[node]][node] + cost;
                hs[nxt] = hs[node] - hw;
                pq.push(adj[dest].at(i));
                // cout << adj[dest].at(i).to << " " << adj[dest].at(i).time << " " << adj[dest].at(i).cm << endl;
            }
        }
    }
    // if (dis[hs[b]][b] == INT_MAX) {
    //     cout << -1 << endl;
    // }else {
    //     cout << dis[hs[b]][b] << endl;
    // }
    // for (int i = 1; i <= hull; i++) {
    //     cout << i << ": ";
    //     for (int j = 1; j <= nodes; j++) {
    //         if (dis[i][j] == INT_MAX) {
    //             cout << 0 << " ";
    //         } else {
    //             cout << dis[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    return 0;
}