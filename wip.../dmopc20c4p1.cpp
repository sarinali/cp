#include <iostream>
using namespace std;
int t;
int cnt;
int main() {
    cin >> t;
    for (int i =0; i < t; i++) {
        int s =0; int n = 0; 
        cin >> n >> s;
        int num = n/2 * (2 + (n-1));
        num -= s;
        for (int i = 1; i <= num/2; i++) {
            int a = num - i;
            int b = i;
            if (a <= n && b <= n) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}