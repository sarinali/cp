#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct t{
  int to;
  ll time;
  int lvl;
};
struct comp { //what is this for
    bool operator()(t const& lhs, t const& rhs) const {
    return lhs.time > rhs.time;
    }
};

const int M = 1e5;
vector<t> adj[M+1];
ll cst[M+1];
// bool ck[M+1];
int n, m, a, b;
ll c;
ll djs(int lvl){
  priority_queue<t, vector<t>, comp> pq;
//   bool ck[M+1];
  for (int i = 1; i <= n; i++) {
    cst[i] = LLONG_MAX;
  }
  cst[a] = 0;
  // ck[a] = true;
  t st = {a, 0, 0};
  pq.push(st);
  while(!pq.empty()) {
    t u = pq.top();
    pq.pop();
    int v = u.to;
    if (v==b) {
        break;
    }
    // ck[v] = true;
    if (u.time > cst[u.to]) continue;
    for (t i : adj[v]) {
      ll alt = i.time + cst[v];
      int nxt = i.to;
      if (cst[nxt] > alt && i.lvl<=lvl) {
        // ck[nxt] =true;
        cst[nxt] = alt;
        t nt = {nxt, cst[nxt], lvl};
        pq.push(nt);
      }
    }
  }
  return cst[b]; 
}
int main() {
  cin.tie(0); cin.sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int l, r, val;
    cin >> l >> r >> val;
    t g = {l, val, i};
    t h = {r, val, i};
    adj[r].push_back(g);
    adj[l].push_back(h);
  }
  cin >> a >> b >> c;
  int lo = 1; int hi = m; int mid; int ans = m+1;
  while (lo<=hi) { 
    mid = (hi+lo)/2;
    // cout << mid << endl;
    ll y = djs(mid);
    // cout << y << endl;
    // um if time taken is less than what u gotta be under
    if (y<c) {
        ans = mid;
        hi = mid-1;
    }else {
      lo = mid+1;
    }
  }
  if (ans > m) {
    cout << -1 << endl;
  } else  {
    cout << ans << endl;
  }
  return 0;
}