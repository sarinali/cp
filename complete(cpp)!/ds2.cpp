#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int M = 1e6;
int n, m, ht[M+1], parent[M+1];
bool c;
vector <int> v;
int find(int node) {
    if (parent[node] != node) {
        parent[node] = find(parent[node]);
    }
    return parent[node];
}
void unite(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x==y) {
        return;
    }
    if (ht[x] > ht[y]) {
        parent[y] = x;
        ht[x] = max(ht[x], ht[y]+1);
    } else {
        parent[x] = y;
        ht[y] = max(ht[x]+1, ht[y]);
    }
}
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) != find(b)) {
            unite(a,b);
            v.push_back(i+1);
        }
    }
    int par = parent[1];
    for (int i = 1; i <= n; i++) {
        int u = find(i);
        if (u != par) {
            c = true;
            break;
        }
    }
    if (c) {
        cout << "Disconnected Graph" << endl;
    } else {
        for (int i = 0; i < v.size(); i++) {
            cout << v.at(i) << endl;
        }
    }
    return 0;
}