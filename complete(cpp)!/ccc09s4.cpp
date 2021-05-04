#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pi; 
long long MAX = 9223372036854775807;
int n;
long t;
int x;
int y;
int w;
int k;
int penc[5005];
long long dis[5005];
int z;
int zcost;
int dest;
int ind;
vector<pi> adj[5005];
priority_queue<pi, vector<pi>, greater<pi> > pq; 
int main() {
    scanf("%d", &n); 
    scanf("%ld", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &x, &y, &w);
        pi p = make_pair(w, x);
        adj[y].push_back(p);
        pi p1 = make_pair(w, y);
        adj[x].push_back(p1);
    }
    scanf("%d", &k);
    for (int i = 1; i <= n; i++) {
        dis[i] = MAX;
        penc[i] = 0;
    }
    vector<int> temp;
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &z, &zcost);
        penc[z] = zcost;
        temp.push_back(z);
    }
    scanf("%d", &dest);
    pi src = make_pair(0, dest);
    dis[dest] = 0;
    pq.push(src);
    while (!pq.empty()) {
        pi c = pq.top();
        pq.pop();
        int cur = c.second;
        for (int i = 0; i < adj[cur].size(); i++) {
            pi nxt = adj[cur].at(i);
            int weigh = nxt.first;
            int node = nxt.second;
            if (dis[node] > dis[cur] + weigh) {
                dis[node] = dis[cur] + weigh;
                pq.push(nxt);
            }
        }
    }
    //  for (int i = 1; i <= n; i++) {
    //     printf("%d\n", penc[i]);
    //  }
    long long m = MAX;
    for (int i = 0; i < temp.size(); i++) {
        dis[temp.at(i)] += penc[temp.at(i)];
        if (dis[temp.at(i)] < m) {
            m = dis[temp.at(i)];
            //ind = i;
        }
    }
    printf("%lld\n", m);
    return 0;
}