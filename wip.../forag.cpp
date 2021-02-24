#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef pair<long, int> pi; 
long long MAX = 9223372036854775807;
int n; // node
int m; // road
long long x;
long long y;
long long w;
long long c;
long long src;
long long dest;
int ans;
long long dis[100005];
struct tri { 
   long long w, n, l; 
}; 
struct tri_comp {
  bool operator()(tri const& lhs, tri const& rhs) const {
    return lhs.w > rhs.w;
  }
};
vector<tri> adj[100005];
long long djs(int src, int curl) {
  for (int i = 0; i<=n; i++) {
    dis[i]= MAX;
  }
  //memset(dis, MAX, 100005);
  priority_queue<tri, vector<tri>, tri_comp> pq;
  dis[src] = 0;
  tri cur = {0, src, curl};
  pq.push(cur);
  while (!pq.empty()) {
    tri cur = pq.top();
    if (cur.l <= curl) {
      pq.pop();
      int node = cur.n;
      // cout << node << endl;
      for (int i = 0; i < adj[node].size(); i++) {
        tri nxt = adj[node].at(i);
        if (nxt.l <= curl) {
          long long weight = nxt.w;
          long long nxtnode = nxt.n;
          if (dis[nxtnode] > dis[node] + weight) {
            dis[nxtnode] = dis[node] + weight;
            pq.push(nxt);
            //cout << dis[nxtnode];
          }
        }
      }
    } else{
      pq.pop();
    }
  }
  // printf("%lld\n", dis[dest]);
  return dis[dest];

} 
int bsearch() {
  int lo = 0;
  int hi = m-1;
  while (lo <= hi) {
    int mid = (lo + hi)/2;
    long long dislvl = djs(src, mid);
    // printf("%lld\n", dislvl);
    // cout << lo << " " << hi << endl;
    if (dislvl > c) {
      lo = mid+1;
    }
    if (dislvl <= c) {
      ans = mid;
      hi = mid-1;
    }
    // printf("%d\n", mid);
  }
  if (dis[ans+1] == MAX || dis[ans+1] > c) {
    return -1;
  }
  return ans+1;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
      scanf("%lld %lld %lld", &x, &y, &w);
      tri m = {w, x, i};
      adj[y].push_back(m);
      tri m1 = {w, y, i};
      adj[x].push_back(m1);
      // cout << m.w << " " << m.n << " " << m.l << endl;
      // cout << m1.w << " " << m1.n << " " << m1.l << endl;
  }
  scanf("%lld %lld %lld", &src, &dest, &c);
  printf("%d\n", bsearch());
  // bsearch();
  // djs(src, 0);
  return 0;
}