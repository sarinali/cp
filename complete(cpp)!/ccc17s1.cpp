#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
int a[M+1], b[M+1], n;
int main() {
    int asum = 0; int bsum = 0; int k = -1;
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        asum += a[i];
        bsum += b[i];
        if (asum == bsum) {
            k = i;
        }
    }
    if (k == -1) {
        cout << 0 << endl;
    } else {
        cout << k+1 <<endl;
    }
    return 0;
}