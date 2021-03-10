#include <iostream>
using namespace std;
int grid[2001][2001];
bool c[2001];
bool r[2001];
int n;
int main(){
    cin >> n;
    for (int i = 0;i < n; i++) {
        for (int j = 0;j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                c[i] = true;
                r[j] = true;
            }
        }
    }
    return 0;
}