#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
using namespace std;
int n;
vector<int> adj[7];
bool vis[7];
int dis[7];
stack<int> s;
int dfs(int u) {
    for (int i : adj[u]) {
        if (!vis[i]) {
            vis[i] = true;
            dis[u]*= dfs(i);
        } 
    }
    return dis[u];
}
int main() {
    cin >>n;
    for (int i=0;i<=n;i++){
        dis[i] =1;
    }
    //end ones mulitplied by each other?
    for (int i = 1; i<n; i++) {
        int j;
        cin >> j;
        adj[j].push_back(i);
        // dis[j] *= dis[i]+1;
    }
    // s.push(n);
    // while (!s.empty()) {
    //     int cur = s.top();
    //     s.pop();
    //     if (!vis[cur]){
    //         vis[cur] = true;
    //         for (int i = 0; i < adj[cur].size(); i++) {
    //             dis[n] *= dis[adj[cur].at(i)]+1;
    //             if (!vis[adj[cur].at(i)])
    //                 s.push(adj[cur].at(i));
    //         }
    //     }
    //     dis[cur]+=1;
    // }
    // int ans=1;
    // for (int i = 1; i < n; i++) {
    //     if (adj[i].size()==0) {
    //         ans *= dis[n];
    //     }
    // }
    cout << dis[n] << endl;
    return 0;
}