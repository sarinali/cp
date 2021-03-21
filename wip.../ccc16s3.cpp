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
set<int> adj[100000];
void check() {

}
pi dfs(int node) {
    pi max = make_pair(node, 0);
    stack<int> s;
    s.push(node);
    nodecount = 0;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        nodecount++;
        set<int>::iterator it;
        for (it = adj[cur].begin(); it != adj[cur].end(); it++){
            if (!vis[*it]) {
                s.push(*it);
                vis[*it] = true;
                dis[*it] = dis[cur] +1;
                if (dis[*it] > max.second) {
                    max.first = *it;
                    max.second = dis[*it];
                }
            }
        }
    }
    return max;
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
    // while (true) {
    //     count = n;
    //     for (int i= 0; i < n; i++) {
    //         if (adj[i].size() == 1 && ar[i] == false) {
    //             set<int>::iterator it;
    //             int first;
    //             for (it = adj[i].begin(); it != adj[i].end(); it++){
    //                 first = *it;
    //             }
    //             // if (ar[first] == false) {
    //             adj[first].erase(i);
    //             adj[i].erase(first);
    //             count--;
    //             // }
    //         }
    //     }
    //     if (count == n) {
    //         break;
    //     }
    // } 
    
    // asldkfjalskdjf doesnt work, too slow je pense je vais fixer
    // audjourd'hui
    vis[0] = true;
    int newnode = dfs(0).first;
    for (int i = 0; i < n; i++){
        vis[i] = false;
        dis[i] = false;
    }    
    vis[newnode] = true;
    int diameter = dfs(newnode).second;
    cout << (((nodecount) *2) - diameter) -2<< endl;
    // cout << << endl;
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