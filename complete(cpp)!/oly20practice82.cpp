#include <bits/stdc++.h>
using namespace std;
// const int M  = 1e9;
int n, q;
vector<int> ar;
// bool myfunction (int i,int j) { return (i<j); }
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ar.push_back(x);
    }
    sort(ar.begin(), ar.end());
    for (int i = 0; i < q; i++) {
       int l, r;
       cin >> l >> r;
       if (l == r) {
           int cur = lower_bound(ar.begin(), ar.end(), r) - ar.begin();
           if (ar.at(cur) != r) {
               cout << 0 << endl;
           } else {
               cout << 1 << endl;
           }
       } else {
           int hi = upper_bound(ar.begin(), ar.end(), r) - ar.begin();
           int lo = lower_bound(ar.begin(), ar.end(), l) - ar.begin();
           cout << hi - lo << endl;
       }
    }
    return 0;
}