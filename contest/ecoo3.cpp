#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int ans[2*M+2];
int qval[2*M+2];
int n,m,k;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c>qval[b]) {
            qval[b] = c;
            ans[b] = a;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 0) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
    return 0;
}