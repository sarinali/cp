#include <bits/stdc++.h>
using namespace std;
const int M = 1e2;
int n, ar[M+1];
list<int> v;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar, ar+n);
    int len = n-1;
    if (n%2==0) {
        for (int i = 0; i < n/2; i++) {
            v.push_front(ar[len-i]);
            v.push_front(ar[i]);
        }
        for (auto i : v) {
            cout << i << " ";
        }
    } else {
        for (int i = 1; i <= n/2; i++) {
            v.push_front(ar[len-(i-1)]);
            v.push_front(ar[i]);
        }
        v.push_back(ar[0]);
        for (auto i : v) {
            cout << i << " ";
        }
    }

    return 0;
}