#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 2*1e9;
ll lo, mid, hi;
string feedback;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    lo = 1; hi = M; 
    while (lo <= hi) {
        mid = (lo+hi)/2;
        cout << mid << endl;
        cin >> feedback;
        if (feedback == "FLOATS") {
            hi = mid-1;
        } else if (feedback == "SINKS") {
            lo = mid+1;
        } else {
            break;
        }
    }
    return 0;
}