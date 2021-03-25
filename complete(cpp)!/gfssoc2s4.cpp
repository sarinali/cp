#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi; 
int MAX = 999999999;
int n; // build
int m; // road
int revdis[500005];
int dis[500005];
int x;
int y;
int w;
int c;
int cx;
int cy;
int cw;    
priority_queue<pi, vector<pi>, greater<pi> > pq; 
int main() {
    scanf("%d %d", &n, &m); 
    vector<pi> revadj[n+1];
    vector<pi> adj[n+1];
    for (int i = 0; i< m; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        pi p = make_pair(w, y);
        adj[x].push_back(p);
        pi revp = make_pair(w,x);
        revadj[y].push_back(revp);
    }
    for (int i = 1; i <=n; i++) {
        revdis[i] = MAX;
        dis[i] = MAX;
    }
    pi src = make_pair(0, 1);
    dis[1] = 0;
    pq.push(src);
    while (!pq.empty()) {
        pi cur = pq.top();
        pq.pop();
        int node = cur.second;
        for (int i = 0; i < adj[node].size(); i++) {
            pi nxt = adj[node].at(i);
            int nxtnode = nxt.second;
            int nxtweight = nxt.first;
            //dis[nxtnode] = min(dis[nxtnode], dis[node] + nxtweight);
            if (dis[nxtnode] > dis[node] + nxtweight) {
                dis[nxtnode] = dis[node] + nxtweight;
                pq.push(nxt);
            }
        }
    }
    pi rsrc = make_pair(0,n);
    revdis[n] = 0;
    pq.push(rsrc);
    while (!pq.empty()) {
        pi curr = pq.top();
        pq.pop();
        int rnode = curr.second;
        for (int i = 0; i < revadj[rnode].size(); i++) {
            pi rnxt = revadj[rnode].at(i);
            int rnxtnode = rnxt.second;
            int rnxtweight = rnxt.first;
            if (revdis[rnxtnode] > revdis[rnode] + rnxtweight){
                revdis[rnxtnode] = revdis[rnode] + rnxtweight;
                pq.push(rnxt);
            }   
        }
    }
    scanf("%d", &c);
    int a = dis[n];
    for (int i = 0; i < c; i++) {
        scanf("%d %d %d", &cx, &cy, &cw);
        a = min(dis[cx] + revdis[cy] + cw, a);
    }
    if (a == MAX) {
        cout << -1 << endl;
    } else {
        printf("%d\n", a);
    }
    return 0;
}