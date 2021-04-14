#include <iostream>
using namespace std;
typedef long long ll;
const int M = 1e3;
int n;
const int MOD = 1e9+7;
ll sum;
int BIT[M+5][M+5];
ll findsum(int r, int c, int x) {
    ll cursum = 0;
    int ind = x;
    while (ind >0) {
        cursum += BIT[r+c][ind];
        ind -= ind&-ind;
    }
    return cursum;
}
void update(int r, int c, int t) {
    // BIT[r+c][c] += t;
    int ind = c;
    while (ind <= n) {
        BIT[r+c][ind]+=t;
        ind+=ind&-ind;
    }
    return;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int op, r, c, t;
        cin >> op;
        if (op == 1) {
            cin >> r >> c >> t;
            // update(r, c, t);
        } else if (op == 2) {
            cin >> r >> c >> t;
            // sum += findsum(r, c, t);
        }
    }
    printf("%lld", sum%MOD);
    return 0;
}