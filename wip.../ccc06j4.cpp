#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// i dunno ill do this at home? 
vector<int> adj[8];
bool vis[8];
vector<int> actions;
stack<int> bfs(int cur) {
    priority_queue<int> pq;
    stack<int> s;
    pq.push(cur);
    while (!pq.empty()) {
        int u = pq.top();
        s.push(u);
        pq.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            if (!vis[adj[u].at(i)]) {
                vis[adj[u].at(i)] = true;
                pq.push(adj[u].at(i));
            }
        }
    }
    cout << "stack of " << cur << ": ";
    int size = s.size();
    for (int j = 0; j < size; j++) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return s;
}
int main(){
    adj[1].push_back(7);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(5);
    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            break;
        }
        adj[x].push_back(y);
    }
    stack<int> s;
    for (int i = 1; i < 8;i++) {
        for (int j = 1; j < 8; j++) {
            vis[j] = false;
        }
        s = bfs(i);
        // if (s.size() == 7) {
        //     break;
        // }
    }
    int size = s.size();
    // if (size < 7) {
    //     cout << "Cannot complete these tasks. Going to bed." << endl;
    // } else {
    //     for (int i = 0 ; i < size; i++) {
    //         cout << s.top() << " ";
    //         s.pop();
    //     }
    // }
    // top sort maybe? or maybe a dfs with priotiy queue? not sure
    return 0;
}