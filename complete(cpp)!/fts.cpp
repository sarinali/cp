#include <bits/stdc++.h>
using namespace std;
// const int M = 1e6;
int n, ans;
string t;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> t;
    ans =1;
    for (int i = 1; i < n; i++) {
        if (t[i] != t[i-1]) {
            ans++;
        }
    }  
    if (t[n-1] == '0') {
        ans--;
    } 
    cout << ans << endl;
    return 0;
}