#include <bits/stdc++.h>
using namespace std;
int n;
vector<double> v;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    while (true) {
        int h; cin >> h;
        if (h == 77) {
            break;
        } else if (h == 88) {
            int y; cin >> y; y--;
            auto it = v.begin();
            v[y] += v[y+1];
            v.erase(it + (y+1));
        } else {
            auto it = v.begin();
            int num; double flow;
            cin >> num >> flow; num--;
            double curflow = v[num];
            double of = curflow * (flow*0.01);
            v[num] = of;
            v.insert(it + num, curflow-of);
        }
    }
    for (auto i : v) {
        cout << i << " ";
    }
    return 0;
}