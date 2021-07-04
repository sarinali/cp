#include <bits/stdc++.h>
using namespace std;
const int M = 1e9;
int lo, mid, hi;
string feedback;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    lo = 1; hi = M; 
    while (lo <= hi) {
        mid = (lo+hi)/2;
        cout << mid << endl << flush;
        cin >> feedback;
        if (feedback == "FLOATS") {
            hi = mid-1;
        } else if (feedback == "SINKS") {
            lo = mid+1;
        } else if (feedback == "OK") {
            break;
        }
    }
    return 0;
}