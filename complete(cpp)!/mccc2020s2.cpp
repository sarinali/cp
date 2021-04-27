#include <iostream>
using namespace std;
// prob could be more efficient :( 
// ill think of something one day
int grid[2001][2001];
bool f;
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
        if (grid[i][0] == 1) {
            string cur = "R " + to_string(i+1);
            actions.push_back(cur);
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
    for (int i = 0; i < n; i++) {
        if (grid[0][i] == 1) {
            string cur = "C " + to_string(i+1);
            actions.push_back(cur);
            m++;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 1) {
                    grid[j][i] = 0;
                } else {
                    grid[j][i] = 1;
                }
            }
        }
    }
    for (int i = 0;i < n; i++) {
        for (int j = 0;j < n; j++) {
            if (grid[i][j] == 1) {
                f = true;
                cout << -1 << endl;
                break;
            }
        }
    }
    if (f != true) { 
        cout << m << endl;
        for (int i = 0; i<m; i++) {
            cout << actions.at(i) << endl;
        }
    }
    return 0;
}