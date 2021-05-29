#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int n, m, size[M+1], parent[M+1];
int ms = 0;
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
    if (size[x] > size[y]) {
        parent[y] = x;
        size[x] += size[y];
        ms = max(ms, size[x]);
    } else {
        parent[x] = y;
        size[y] += size[x];
        ms = max(ms, size[y]);
    }
    return;
}
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    int sets = n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a)!=find(b)) {
            sets--;
            unite(a,b);
        }
        cout << sets << " " << ms << endl;
    }
    return 0;
}