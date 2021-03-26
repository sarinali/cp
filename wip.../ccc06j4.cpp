#include <iostream>
#include <vector>
using namespace std;
// i dunno ill do this at home? 
vector<int> adj[8];
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
    // top sort maybe? or maybe a dfs with priotiy queue? not sure
    return 0;
}