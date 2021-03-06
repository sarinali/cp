#include <iostream>
using namespace std;
int r[5000001];
int c[5000001];
int rw, clm, n, ans;
int main() {
    cin >> rw >> clm >> n;
    for (int i = 0 ; i < n; i++) {
        char x;
        int y;
        cin >> x >> y;
        if (x == 'R') {
            r[y-1]++;
        }
        if (x == 'C') {
            c[y-1]++;
        }
    }
    for (int i = 0; i < rw; i++) {
        for (int j = 0; j < clm; j++) {
            int sum = r[i] + c[j];
            if (sum%2 != 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}