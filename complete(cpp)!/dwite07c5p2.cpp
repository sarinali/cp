#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    for (int i = 0; i < 5; i++) {
        vector<int> v;
        cin >> n;
        cnt = 0;
        for (int j = 2; j <= sqrt(n); j++) {
            while (n % j == 0) {
                v.push_back(j);
                cnt++;
                n /= j;
            }
        }
        if (n >2) {
            cnt++;
            v.push_back(n);
        }
        // for (int j = 0; j < v.size(); j++) {
        //     cout << v.at(j) << " ";
        // }
        // cout << endl;
        if (cnt == 1) {
            cout << 0 << endl;
        } else {
            cout << cnt << endl;
        }
    }
    return 0;
}