#include <bits/stdc++.h>
using namespace std;
int s, n, t;
int main() {
    // he checks his messagees 3 times
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> s >> n >> t;
    int check1 = s+n;
    int check2 = s+(2*n);
    int check3 = s+(3*n);
    if (check1 >= t) {
        cout << check1 << endl;
    } else if (check2 >= t) {
        cout << check2 << endl;
    } else if (check3 >= t) { 
        cout << check3 << endl;
    } else {
        cout << "Who knows..." << endl;
    }
    return 0;
}