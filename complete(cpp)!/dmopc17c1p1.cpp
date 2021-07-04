#include <bits/stdc++.h>
using namespace std;
const int M = 1e3;
int r,c, q;
int check[M+1][M+1];
char ar[M+1][M+1];
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> ar[i][j];
            if (ar[i][j] == 'X') {
                for (int g = 1; g <= c; g++) {
                    check[i][g] = 1;
                }
                for (int g = 1; g <= r; g++) {
                    check[g][j] = 1;
                }
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        // cout << "teset" << endl;
        if (check[y][x] == 1) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}