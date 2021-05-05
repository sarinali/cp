#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll dis[M+1];
ll hullsize[M+1];
priority_queue<t, vector<t>, tc> pq; 
int a, b, roads, nodes, hull;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    memset(dis, 1, sizeof(dis));
    cin >> hull >> nodes >> roads;
    for (int i = 0; i < roads; i++) {
        int from, to, time, cm;
        cin >> from >> to >> time >> cm;
        t cur = {to, time, cm};
        adj[from].push_back(cur);
    }
    cin >> a >> b;
    dis[a] = 0;
    hullsize[a] = hull;
    t start = {a, 0, 0};
    pq.push(start);
    while (!pq.empty()) {
        t cur = pq.top();
        int node = cur.to;
        pq.pop();
        if (node == b) {
            break;
        }
        int dest = cur.to; int t = cur.time; int length = cur.cm;
        for (int i = 0; i < adj[dest].size(); i++) {
            int nxt = adj[dest].at(i).to;
            int cost = adj[dest].at(i).time;
            int hull_wear = adj[dest].at(i).cm;
            if (dis[nxt] > dis[node] + cost && hullsize[node] - hull_wear > 0) {
                dis[nxt] = dis[node] + cost;
                hullsize[nxt] = hullsize[node] - hull_wear;
                pq.push(adj[dest].at(i));
            }
        }
    }
    if (dis[b] == 72340172838076673) {
        cout << -1 << endl;
    }else {
        cout << dis[b] << endl;
    }
    return 0;
}