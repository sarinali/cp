#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct t { 
    int first, second, third; 
}; 
struct tc {
    bool operator()(t const& lhs, t const& rhs) const {
    return lhs.second < rhs.second;
    }
};
const int M = 1e6; const int MQ = 1e4;
int n, q, ar[M+1];
t query[5*MQ+1];
bool vis[M+1];
unordered_map <int, int> m;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r, val;
        cin >> l >> r >> val;
        t cur = {l, r, val};
        query[i] = cur;
    }
    sort(query, query + q, tc());
    for (int i = 0; i < q; i++) {
        t cur = query[i];
        int s = cur.second;
        int r = cur.first;
        while (s>0 and !vis[s]) {
            vis[s] = true;
            if (s > m[ar[s]]) {
                m[ar[s]] = s;
            }
            s--;
        }
        int val = cur.third;
        bool v = false;
        for (auto& it: m){
            cout<< it.first << ": " << it.second << endl;
        }
        for (int j = 1; j <= sqrt(val); j++) {
            int io;
            if (val % j == 0 && j*j != val) {
                io = val/j;
                if ((m[j] >= r) && (m[io] <=s)) {
                    cout << "YES" << endl;
                    v = true;
                    break;
                }
                // factors, check indexes?
            }
        }
        if (!v) {
            cout << "NO" << endl;
        }
    }
    return 0;
}