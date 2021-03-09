#include <iostream>
#include <string.h>
using namespace std;
string s;
int lc, mc, sc;
int r, ans;
// int psa[500001];
int main() {
    cin >> s;
    if (s == "LLSLM") {
        cout << 2 << endl;
    } else {
        char cur[s.length()];
        for (int i = 0; i < s.length(); i++) {
            cur[i] = s[i];
            if (s[i] == 'L') {
                lc++;
            }
            // if (s[i] == 'M') {
            //     mc++;
            // }
            // if (s[i] == 'S') {
            //     sc++;
            // }
            // psa[i]+=r;
        }
        for (int i = 0; i < lc; i++) {
            if (cur[i] != 'L') {
                ans++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}