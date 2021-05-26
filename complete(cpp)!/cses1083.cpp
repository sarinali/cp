#include <bits/stdc++.h>
using namespace std;
int n;
const int M = 2*1e5;
int ar[M];
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> ar[i];
    }
    sort(ar, ar+n-1);
    for (int i = 0; i < n; i++) {
        if (ar[i] != i+1) {
            cout << i+1;
            break;
        }
    }
    return 0;
}