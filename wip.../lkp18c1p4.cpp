#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct t{
  int to, time, lvl;
};
struct comp {
    bool operator()(t const& lhs, t const& rhs) const {
    return lhs.time > rhs.time;
    }
};
const int M = 1e5;
vector<t> adj[M+1];
ll cst[M+1];
int n, m, a, b, c;
ll djs(int lvl){
  priority_queue<t, vector<t>, comp> pq;
  for (int i = 0; i <= n; i++) {
    cst[i] = LLONG_MAX;
  }
  cst[a] = 0;
  t st = {a, 0, lvl};
  pq.push(st);
  while(!pq.empty()) {
    t u = pq.top();
    pq.pop();
    int v = u.to;
    // cout << v << endl;
    if (v == b) {
      break;
    }
    // int time = u.time;
    int clvl = u.lvl;
    if (clvl > lvl) {
      continue;
    }
    for (t i : adj[v]) {
      ll alt = i.time + cst[v];
      int nxt = i.to;
      if (cst[nxt] > alt){
        cst[nxt] = alt;
        pq.push(i);
      }
    }
  }
  return cst[b];
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r, val;
    cin >> l >> r >> val;
    t g = {l, val, i};
    t h = {r, val, i};
    adj[r].push_back(g);
    adj[l].push_back(h);
  }
  cin >> a >> b >> c;
  int lo = 0; int hi = m-1; int mid; 
  // cout << djs(4) << endl;
  // cout << y << endl;
  // cout << mid << endl;
  while (lo+1<hi) { 
    mid = (hi+lo)/2;
    ll y = djs(mid);
    // um if time taken is less than what u gotta be under
    if (c >= y) {
      hi = mid;
    }else {
      lo = mid;
    }
  }
  // cout << lo << endl;
  if (djs(hi+1) == LLONG_MAX) {
    cout << -1 << endl;
  } else  {
    cout << hi+1 << endl;
  }
  return 0;
}