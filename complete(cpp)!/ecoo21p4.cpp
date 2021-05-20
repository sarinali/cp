#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <ll> v;
ll k, n, cnt;
bool y;
const ll M = 1e5;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> k;
    k++;
    // ok try prime factorizing first?
    ll cur = 1;
    for (int i = 2; i <= sqrt(k); i++) {
        while (k % i == 0) {
            for (int j = 0; j < i-1; j++) {
                v.push_back(cur);
                cnt++;
                if (v.size() > M) {
                    cout << "Sad Chris" << endl;
                    y = true;
                    break;
                }
            }
            cur++;
            k /= i;
        }
    }
    if (k > 1) {
        for (int i = 0; i < k-1; i++) {
            v.push_back(cur);
            if (v.size() > M) {
                cout << "Sad Chris" << endl;
                y = true;
                break;
            }
            cnt++;
        }
    }
    if (!y) {
        cout << cnt << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v.at(i) << " ";
        }
    }
    return 0;
}