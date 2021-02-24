#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;
int n;
int x;
int y;
int dp[10005];
vector<int> adj[10005];
int dfs(int node) {
    if (node == 1) {
        return 1;
    }
    if (dp[node] > 0) {
        return dp[node];
    }
    for (int i = 0; i < adj[node].size(); i++) {
        dp[node] += dfs(adj[node].at(i));
    }
    return dp[node];
}
int main() {
    scanf("%d", &n);
    memset(dp, 0, n+1);
    while (true) {
        scanf("%d %d", &x, &y);
        if (x == 0 && y == 0) {
            break;
        }
        adj[y].push_back(x);
    }
    dfs(n);
    // for (int i = 1; i<= n; i++) {
    //     cout << dp[i] << endl;
    // }
    printf("%d\n", dp[n]);
    return 0;
}