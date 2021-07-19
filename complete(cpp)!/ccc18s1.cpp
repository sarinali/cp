#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
const int M = 100;
int n;
double ar[M+1], size[M+1];
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar, ar+n);
    size[0] = LLONG_MAX; size[n-1] = LLONG_MAX;
    for (int i = 1; i < n-1; i++) {
        double c = ((ar[i]-ar[i-1])/2) + ((ar[i+1]-ar[i])/2);
        size[i] = c;
        // cout << size[i] << "\n";
    }
    sort(size, size+n);
    printf("%.1f\n", size[0]);
    return 0;
}