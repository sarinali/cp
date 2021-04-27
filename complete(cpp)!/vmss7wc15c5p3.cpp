// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 2*1e3+5;
int n;
const int MOD = 1e9+7;
ll sum;
ll BIT[M][M];
ll findsum(int r, int c) {
    ll cursum = 0;
    int ind = c;
    while (ind>0) {
        cursum += BIT[r][ind];
        ind-=ind&-ind;
    }
    return cursum;
}
void update(int r, int c, int t) {
    int ind = r;
    while (ind <= M) {
        BIT[r+c][ind]+=t;
        ind+=ind&-ind;
    }
    return;
}
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int op, r, c, t;
        cin >> op;
        if (op == 1) {
            cin >> r >> c >> t;
            update(r, c, t);
        } else if (op == 2) {
            cin >> r >> c >> t;
            sum += findsum(r+c, r)-findsum(r+c, r-t-1)%MOD;
        }
    }
    // SOMEHOW WORKS.
    printf("%lld\n", sum%MOD);
    return 0;
}