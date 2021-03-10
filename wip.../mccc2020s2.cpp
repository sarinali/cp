#include <iostream>
#include <vector>
using namespace std;
int grid[2001][2001];
bool c[2001];
bool r[2001];
int n;
int m;
vector <string> actions;
int main(){
    cin >> n;
    for (int i = 0;i < n; i++) {
        for (int j = 0;j < n; j++) {
            cin >> grid[i][j];
            /* 
            key insight (note to self basically)
            only toggling the first row and first column will guarentee that 
            it will be solved if solveable 
            if it is a lone 1 from the top and left, you cant solve it 
            */
        }
    }
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == 1) {
            r[i] = true;
            m++;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = 1;
                }
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     if (grid[i][0] == 1) {
    //         c[i] = true;
    //         m++;
    //         for (int j = 0; j < n; j++) {
    //             if (grid[j][i] == 1) {
    //                 grid[j][i] = 0;
    //             } else {
    //                 grid[j][i] = 1;
    //             }
    //         }
    //     }
    // }
    for (int i = 0;i < n; i++) {
        cout << endl;
        for (int j = 0;j < n; j++) {
            cout << grid[i][j] << " ";
        }
    }
    return 0;
}