#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const int M = 1e3;
int n;
ll dp[M+1][M+1];
char ar[M+1][M+1];
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ar[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (ar[i][0] == '*') {
            break;
        }
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (ar[0][i] == '*') {
            break;
        }
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (ar[i][j]!='*')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }
    cout << dp[n-1][n-1]%MOD << endl;
    return 0;
}