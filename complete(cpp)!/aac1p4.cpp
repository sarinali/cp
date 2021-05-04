#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct t { 
    int first, second, third, fourth; 
}; 
struct tc {
    bool operator()(t const& lhs, t const& rhs) const {
    return lhs.second < rhs.second;
    }
};
const int M = 1e6; const int MQ = 1e4;
int n, q, ar[M+1];
string ans[5*MQ+1];
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
        t cur = {l, r, val, i};
        query[i] = cur;
    }
    sort(query, query + q, tc());
    for (int i = 0; i < q; i++) {
        t cur = query[i];
        int r = cur.first;
        int s = cur.second;
        int val = cur.third;
        int count = s;
        while (count>0 and !vis[count]) {
            vis[count] = true;
            if (count > m[ar[count]]) {
                m[ar[count]] = count;
            }
            count--;
        }
        bool v = false;
        // for (auto& it: m){
        //     cout<< it.first << ": " << it.second << endl;
        // }
        for (int j = 1; j <= sqrt(val); j++) {
            int io;
            if (val % j == 0 && j*j != val) {
                io = val/j;
                if ((m[j] <= s && m[j] >=r) && (m[io] >= r && m[io] <= s)) {
                    ans[cur.fourth] = "YES";
                    v = true;
                    break;
                }
                // factors, check indexes?
            }
        }
        if (!v) {
            ans[cur.fourth] = "NO";
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}