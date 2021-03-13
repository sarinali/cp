#include <iostream>
#include <stack>
using namespace std;
int r, c;
char rm[41][41];
int a[6];
int vis[41][41];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int y, int x) {
    int cnt = 0; int ind = 0;
    stack<int> queue;
    queue.push(x);
    queue.push(y);
    while (!queue.empty()) {
        int cy = queue.top();
        queue.pop();
        int cx = queue.top();
        queue.pop();
        cout << cy << " " << cx << " " << endl;
        vis[cy][cx] = true;
        // if (rm[cy][cx] > 46) {
        //     ind = ((int)rm[cy][cx]) - '0';
        // }
        cnt++;
        for (int i= 0; i < 4; i++) {
            int newy = cy +dy[i];
            int newx = cx+dx[i];
            if (newy >= 1 and newy <= r and newx <= c and newx >=1 and rm[newy][newx] != '#') {
                if (!vis[newy][newx]) {
                    queue.push(newx);
                    queue.push(newy);
                }
            }
        }
    }
    // cout << ind<< endl;
    a[ind] = cnt;
    return;
}
int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j =1; j<= c; j++) {
            cin >> rm[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j =1; j<= c; j++) {
            if (rm[i][j]!= '#' and !(vis[i][j])) {
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i<=5; i++) {
        cout << a[i] << endl;
    }
}