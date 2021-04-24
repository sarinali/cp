#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
struct quadp { 
    int first, second, third, fourth; 
}; 
struct quadp_comp {
    bool operator()(quadp const& lhs, quadp const& rhs) const {
    return lhs.third > rhs.third;
    }
};
const int M = 1e5;
p v[M+2];
quadp query[M+2];
ll BIT[M+2];
ll ans[M+2];
int n, t;
void update(int ind, int num) {
    while (ind <= n) {
        BIT[ind] += num;
        ind += ind&-ind;
    }
    return;
}
ll sum(int l) {
    ll cursum = 0;
    while (l >0) {
        cursum += BIT[l];
        l -= l&-l;
    }
    return cursum;
}
// basically correct wtf?????
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x;
        p cur = make_pair(x, i);
        v[i] = cur;
    }
    sort(v+1, v+n+1, greater<p>());
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a, b, q;
        cin >> a >> b >> q;
        quadp cur = {a, b, q, i};
        query[i] = cur;
    }
    sort(query+1, query+t+1, quadp_comp());
    int j = 1;
    // for (int i = 1; i<=n; i++) {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    for (int i = 1; i <= t; i++) {
        quadp f = query[i];
        int mx = f.third;
        while (v[j].first >= mx && j <= n) {
            p cur = v[j];
            // cout << cur.first << " " << cur.second << endl;
            update(cur.second, cur.first);
            j++;
        }
        ans[f.fourth] = sum(f.second+1) - sum(f.first);
    }
    for (int i = 1; i <= t; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}