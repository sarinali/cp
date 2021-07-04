#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> k;
    // partial mark
    cout << k*2 << " " << k*2+k-1 << endl;
    // n(n-1)/2
    for (int i = 1; i <= k*2; i+=2) {
        cout << i << " " << i+1 << endl;
        cout << i << " " << i+1 << endl;
        if (i+1 < k*2) {
            cout << i+1 << " " << i+2 << endl;
        }
    }
    return 0;
}