#include <bits/stdc++.h>
using namespace std;
string n;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    char cur = n[0];
    int count = 1;
    int ans = 1;
    for (int i = 1; i < n.length(); i++) {
        if (cur == n[i]) {
            count++;
            ans = max(count, ans);
        } else {
            count = 1;
        }
        cur = n[i];
    }
    cout << ans << endl;
    
    return 0;
}