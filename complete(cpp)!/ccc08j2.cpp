#include <bits/stdc++.h>
using namespace std;
list<char> ar;
int b, n;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    ar.push_back('A'); ar.push_back('B'); ar.push_back('C'); ar.push_back('D'); ar.push_back('E');
    while (true) {
        cin >> b >> n;
        if (b == 4 && n == 1) {
            break;
        }
        if (b == 1) {
            for (int j = 0; j < n; j++) {
                char temp = ar.front();
                ar.pop_front();
                ar.push_back(temp);
            }
        } else if (b==2) {
            for (int j = 0; j < n; j++) {
                char temp = ar.back();
                ar.pop_back();
                ar.push_front(temp);
            }
        } else if (b==3) {
            if (n % 2 == 1) {
                char first = ar.front();
                ar.pop_front();
                char second = ar.front();
                ar.pop_front();
                ar.push_front(first);
                ar.push_front(second);
            }
        }
        // for (auto i : ar) {
        //     cout << i << " ";
        // }
        // cout << endl;
    }
    for (auto i : ar) {
        cout << i << " ";
    }
    return 0;
}