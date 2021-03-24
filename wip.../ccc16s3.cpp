#include <iostream>
#include <set>
#include <stack>
#include <list>
using namespace std;
int n,m;
bool ar[100000];
bool vis[100000];
int dis[100000];
int numberOfPrune;
int diameter;
int firstpho;
set<int> adj[100000];

void prune() {
    list<int> queue;
    for (int i=0;i<n;++i){
        if (adj[i].size() == 1 && !ar[i]) {
            queue.push_back(i);
        }
    }
    while (!queue.empty())    {
        int leaf = queue.front();
        queue.pop_front();
        int first;
        set<int>::iterator it;
        for (it = adj[leaf].begin(); it != adj[leaf].end(); it++){
            first = *it;
        }
        int parent = first;
        // int parent = adj[leaf];
        adj[parent].erase(leaf);
        adj[leaf].erase(parent);
        numberOfPrune++;
        if (adj[parent].size() ==1 && !ar[parent]){
            queue.push_back(parent);
        }
    }
}

int far (int node) {
    list<int> queue;
    queue.push_back(node);
    vis[node]=true;
    int last=0;
    int count=0;
    while (!queue.empty()) {
        int size = queue.size();
        count++;
        for (int j=0;j<size;j++) {
            int cur = queue.front();
            queue.pop_front();
            set<int>::iterator it;
            for (it = adj[cur].begin(); it != adj[cur].end(); it++){
                if (!vis[*it]) {
						queue.push_back(*it);
						vis[*it]=true;
						last=*it;
				}
            }
        }
    }
    diameter=count;
    return last;
}
int main() {
    cin >> n >> m;
    for (int i =0; i< m; i++) {
        int x;
        cin >> x;
        ar[x] = true;
        firstpho=x;
    }
    for (int i =0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    
    prune();
    
    int a = far(firstpho);
    for (int i = 0; i < n; i++) {
        vis[i] = false;
    }
    int b = far(a);

    int numNodes =  n - numberOfPrune;

    cout << (numNodes*2)-diameter-1<< endl;
    // cout << numNodes<< endl;
    // cout << diameter << endl;
    return 0;
}