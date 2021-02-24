#include <iostream>
using namespace std;
typedef long long ll;
ll n, w;
ll wt[1005];
ll prof[1005];
ll s[1005];
int main() {
    scanf("%lld %lld", &n, &w);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &prof[i], &wt[i]);
    }
    if (n == 1) {
        if (wt[0] > w) { 
            cout << 0 << endl;
        } else{
            cout << wt[0] << endl;
        }
    }else {
        for (int i = 0; i <= n; ++i) {
            for (int j = w;j>=wt[i]; --j) {
                s[j] = max(s[j], prof[i] + s[j-wt[i]]);
            }
        }
    }
    cout << s[w] << endl;
}