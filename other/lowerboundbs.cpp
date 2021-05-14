#include <bits/stdc++.h>
using namespace std;
int main() {
    int ar[5] = {34, 56, 90, 230, 600};
    int lo = 0; int hi = 5; int mid;
    int key; // first index greater than this
    cin >> key;
    while (lo<hi) { 
        mid = hi - (hi-lo)/2;
        cout << mid << endl;
        if (key >= ar[mid]) {
            lo = mid;
        }else {
            hi = mid-1;
        }
    }
    if (lo == 5) {
        cout << -1;
    } else {
        cout << lo << endl;
    }
    return 0;
}