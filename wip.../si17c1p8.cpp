#include <iostream>
using namespace std;
int dp[17][500000];
int val[17];
int n;
int v;
int main(){
    cin >> n >> v;
    for (int i=0;i<n;i++) {
        cin >> val[i];
    }
    for (int i = 0; i <= v; i++) {
        dp[i][0] = 1;
    }
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= v; j++) {
            if (j >= val[i-1])
                dp[i][j] = dp[i-1][j] + dp[i][j-val[i-1]];
        }
    }
    cout << dp[n][v];
    return 0;
}