#include <iostream>
using namespace std;
int dp[17][500000];
int val[17];
int n;
int v;
int main(){
    cin >> n >> v;
    dp[0][0] = 1;
    for (int i=0;i<n;i++) {
        cin >> val[i];
    }
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= v; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-val[i]];
            cout << j-val[i] << endl;;
        }
    }
    cout << dp[n][v];
    return 0;
}