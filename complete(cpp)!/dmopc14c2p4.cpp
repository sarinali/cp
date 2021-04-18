#include <iostream>
using namespace std;
typedef long long ll;
const int M = 1e6;
int q, n;
ll psa[M+1];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        psa[i]= temp + psa[i-1];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a,b;
        cin >> a >> b;
        cout << psa[b+1] - psa[a] << endl;
    }
}