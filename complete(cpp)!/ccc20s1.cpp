#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
typedef pair<double, double> pi;
const int M = 1e5;
pi ar[M+1];
int n;
double t, s;
// ll s;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> s;
        ar[i] = make_pair(t,s);
    }
    sort(ar, ar+n);
    double d = ar[1].second - ar[0].second;
    double time = ar[1].first - ar[0].first;
    for (int i = 2; i < n; i++) {
        double cur = ar[i].second-ar[i-1].second;
        double tm = ar[i].first-ar[i-1].first;
        if (abs(cur/tm) > abs(d/time)) {
            d = abs(cur);
            time = tm;
        }
    }
    cout << abs(d/time) << "\n";
    return 0;
}