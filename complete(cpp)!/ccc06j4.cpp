#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
// i dunno ill do this at home? 
vector<int> adj[8];
bool vis[8];
int in[8];
int main(){
    adj[1].push_back(7);
    in[7]++;
    adj[1].push_back(4);
    in[4]++;
    adj[2].push_back(1);
    in[1]++;
    adj[3].push_back(4);
    in[4]++;
    adj[3].push_back(5);
    in[5]++;
    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) {
            break;
        }
        adj[x].push_back(y);
        in[y]++;
    }
    vector<int> s;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i < 8;i++) {
        if (in[i]==0) {
            pq.push(i);
            vis[i] = true;
        }
    }
    while (!pq.empty()) {
        int cur = pq.top();
        s.push_back(cur);
        pq.pop();
        for (auto i : adj[cur]) {
            in[i]--;
            if (in[i] == 0 && vis[i] != true) {
                pq.push(i);
                vis[i] = true;
            }
        }
    }
    if (s.size() < 7) {
        cout << "Cannot complete these tasks. Going to bed." << endl;
    } else {
        for (int i = 0; i < s.size(); i++) {
            // cout << in[i] << endl;
            cout << s.at(i) << " ";
        }
    }
    return 0;
}