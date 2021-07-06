#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    string s;
    int curcount;
    cin.tie(0); cin.sync_with_stdio(0);
    for (int i = 0; i < 5; i++) {
        getline(cin, s);
        // cout << s << endl;
        n = 0;
        for (int j = 0; j < s.length(); j++) {
            if ((s[j] >= 65 && s[j] < 91) || (s[j] >= 97 && s[j] < 123)) {
                // cout << "counted" << endl;
                curcount++;
            } else {
                if (curcount > 3) {
                    n++;
                }
                curcount = 0;
            }
            // cout << curcount << endl;
        }
        if (curcount > 3) {
            n++;
        }
        curcount = 0;
        cout << n << endl;
    }
    return 0;
}