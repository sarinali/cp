#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
const int M = 1e5;
int bit[M+1], ar[M+1], n, t;
list<int> query;
ll sum(int l) {
    ll cursum = 0;
    while (l>0) {
        cursum+=bit[l];
        l-=l&-l;
    }
    return cursum;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    cin >> t;
    int min = M;
    for (int i = 0; i < t; i++) {
        int x, y, h;
        cin >> x >> y >> h;
        query.push_back(x);
        query.push_back(y);
        if (h < min) {
            min = h;
        }
    }
    for (int i = 1; i <= n; i++) {
        int ind = i;
        while (ind <= n) {
            if (ar[i] >= min) {
                bit[ind] += ar[i];
                ind += ind&-ind;
            }
        }
    }
    for (int i = 0; i < t; i++) {
        int x = query.front();
        query.pop_front();
        int y = query.front();
        query.pop_front();
        printf("%lld\n", sum(y+1) - sum(x));
    }
    return 0;
}