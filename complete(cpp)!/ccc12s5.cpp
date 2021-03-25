#include <iostream>
using namespace std;
int r; //rows
int c; // columns
int t; 
int al[30][30];
int dp[30][30];
int x;
int y;
int main() {
    scanf("%d %d", &r, &c);
    scanf("%d", &t);
    for (int i = 0; i< t; i++) {
        scanf("%d %d", &x, &y);
        al[x-1][y-1] = -1;
    }
    for (int i = 0; i< r; i++) {
        if (al[i][0] == -1) {
            break;
        }
        dp[i][0] = 1;
    }
    for (int i = 0; i < c; i++) {
        if (al[0][i] == -1) {
            break;
        }
        dp[0][i] = 1;
    }
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (al[i][j] != -1) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]);
            }
        }
    }
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j< c; j++) {
    //         cout << al[i][j] << " \n"[j == c-1]; 
    //     }
    // }
    printf("%d\n", dp[r-1][c-1]);
    return 0;
}