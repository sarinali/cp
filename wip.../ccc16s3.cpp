#include <iostream>
#include <set>
#include <stack>
using namespace std;
typedef pair<int, int> pi; 
int n,m;
bool ar[100000];
bool vis[100000];
int dis[100000];
int nodecount;
pi d = make_pair(0, 0);
set<int> adj[100000];
void prune(int node) {
    if (!ar[node] && adj[node].size() == 1) {
        set<int>::iterator it;
        int first;
        for (it = adj[node].begin(); it != adj[node].end(); it++){
            first = *it;
        }
        int nxt = first;
        adj[first].erase(node);
        adj[node].erase(first);
        prune(nxt);
    }
    return;
}
pi dfs(pi cur) {
    int c = cur.first;
    set<int>::iterator it;
    for (it = adj[c].begin(); it != adj[c].end(); it++){
        if (!vis[*it]) {
            vis[*it] = true;
            dis[*it] = dis[c] +1;
            if (dis[*it] > d.second) {
                d.first = *it;
                d.second = dis[*it];
            }
            pi nxt = make_pair(*it, dis[*it]);
        }
    }
    return d;
}
int main() {
    cin >> n >> m;
    for (int i =0; i< m; i++) {
        int x;
        cin >> x;
        ar[x] = true;
    }
    for (int i =0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    int count;
    
    for (int i = 0; i < n; i++) {
        prune(i);
    }

    vis[0] = true;
    dis[0] = 1;
    int newnode = dfs(d).first;
    for (int i = 0; i < n; i++){
        vis[i] = false;
        dis[i] = 0;
    }
    vis[newnode] = true;
    dis[newnode] = 1;
    int diameter = dfs(d).second;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 0) {
            nodecount++;
        }
    }
    // cout << diameter <<endl;
    cout << ((nodecount *2) - diameter)<< endl;
    // cout << nodecount << endl;
    // for (int i = 0;i < n; i++) {
    //     cout << i << " ";
    //     set<int>::iterator it;
    //     for (it = adj[i].begin(); it != adj[i].end(); it++) {
    //         cout << *it << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}