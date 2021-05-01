#include <bits/stdc++.h>
using namespace std;
string v[M];
const int M = 1e5;
// char vowel[M];
// char cons[M];
string n;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    // int vc = 0; int cc = 0;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n.length()-1; i++) {
        string cur;
        if (n[i] == 'A') {
            // v[count] = string() + 'A';
            if (n[i+1] == 'T' or n[i] == 'G' or n[i] == 'C') {
                v[count]+= string() + 'A' + n[i+1];
                continue;
            }
        }
        if (n[i] == 'T' or n[i] == 'G' or n[i] == 'C') {
            // v[count] = string() + n[i];
        }
        count++;
    }
    return 0;
}