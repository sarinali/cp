#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> k;
    // int count = 2;
    cout << k+1 << " " <<  k*2 << endl;
    for (int i = 2; i < k+2; i++) {
        cout << 1 << " " << i << endl;
        cout << i << " " << 1 << endl;
    }
    return 0;
}