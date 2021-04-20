#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
struct tri { 
    int first, second, third; 
}; 
struct tri_comp {
    bool operator()(tri const& lhs, tri const& rhs) const {
    return lhs.third > rhs.third;
    }
};
const int M = 1e5;
vector<p> v;
vector<tri> query;
ll BIT[M+2];
list<int> posq;
int n, t;
void update(int ind, int num) {
    while (ind <= n) {
        BIT[ind] += num;
        ind += ind&-ind;
    }
    return;
}
ll sum(int l) {
    ll cursum = 0;
    while (l >0) {
        cursum += BIT[l];
        l -= l&-l;
    }
    return cursum;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        p cur = make_pair(x, i);
        v.push_back(cur);
    }
    sort(v.begin(), v.end(), greater<p>());
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, q;
        cin >> a >> b >> q;
        tri cur = {a, b, q};
        query.push_back(cur);
    }
    sort(query.begin(), query.end(), tri_comp());
    int j = 0;
    for (int i = 0; i < query.size(); i++) {
        int mx = query.at(i).third;
        for (int k = j; k < v.size(); k++) {
            if (v.at(k).first < mx) {
                update(v.at(k).second, v.at(k).first+1);
                cout << sum(query.at(i).second) - sum(query.at(i).first-1) << endl;
            }
            j++;
        }
    }
    return 0;
}