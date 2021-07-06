#include <bits/stdc++.h>
using namespace std;
const int M = 186738;
int n, q;
double dis[M+1];
double discalc(int x, int y) {
    double sum = pow((0-x), 2) + pow((0-y),2);
    return sqrt(sum);
    // return 0.0;
}
int bs(int k) {
    int lo = 0; int hi = n-1;
    while(lo <= hi) {
        int mid = (hi+lo)/2;
        if (dis[mid] <= k) {
            lo = mid+1;
        } else if (dis[mid] > k) {
            hi = mid-1;
        }
    }
    return hi+1;
    // return 0;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dis[i] = discalc(x,y);
        // cout << dis[i] << " ";
    }
    sort(dis, dis+n);
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << bs(k) << endl;
    }
    return 0;
}