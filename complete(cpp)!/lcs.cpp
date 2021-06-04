#include <bits/stdc++.h>
using namespace std;
const int M = 1e3;
int n, m, ar1[M+1], ar2[M+1], dp[M+1][M+1];
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> ar1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> ar2[i];
    }
    for (int i = 0; i < n; i++) {
        if (ar1[i] == ar2[0]) {
            dp[i][0] = 1;
        } 
        if (i >0)
            dp[i][0] = max(dp[i-1][0], dp[i][0]);
    }
    for (int i = 0; i < m; i++) {
        if (ar1[0] == ar2[i]) {
            dp[0][i] = 1;
        }
        if (i > 0)
            dp[0][i] = max(dp[0][i-1], dp[0][i]);
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // not equal: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    // equal: dp[i-1][j-1]+1
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (ar1[i] == ar2[j]) {
                // cout << i << " " << j << endl;
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
    return 0;
}