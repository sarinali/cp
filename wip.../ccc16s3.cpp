#include <iostream>
#include <set>
using namespace std;
int n,m;
bool ar[100000];
set<int> adj[100000];
int main() {
    cin >> n >> m;
    for (int i =0; i< m; i++) {
        int x;
        ar[x] = true;
    }
    for (int i =0; i < n-1; i++) {
        int x, y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    int count;
    while (true) {
        count = n;
        for (int i= 0; i < n; i++) {
            if (adj[i].size() == 1) {
                set<int>::iterator it;
                int first;
                for (it = adj[i].begin(); it != adj[i].end(); it++){
                    first = *it;
                }
                if (ar[first] == false) {
                    adj[first].erase(i);
                    adj[i].erase(first);
                    count--;
                }
            }
        }
        if (count == n) {
            break;
        }
    }
    for (int i = 0;i < n; i++) {
        cout << endl;
        set<int>::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << *it << " ";
        }
    }
    return 0;
}