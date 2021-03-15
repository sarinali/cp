#include <iostream>
#include <stack>
#include <list>
using namespace std;
int r, c;
char rm[41][41];
int a[6];
bool vis[41][41];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int y, int x) {
    int cnt = 0; int ind = 0;
    list <int> queue;
    queue.push_back(x);
    queue.push_back(y);
    while (!queue.empty()) {
        int cx = queue.front();
        queue.pop_front();
        int cy = queue.front();
        queue.pop_front();
        // if (!vis[cy][cx]) {
        // vis[cy][cx] = true;
        cnt++;
        // }
        // cout << cy << " " << cx << " " << endl;
        if (rm[cy][cx] > 46) {
            ind = ((int)rm[cy][cx]) - '0';
        }
        for (int i= 0; i < 4; i++) {
            int newy = cy + dy[i];
            int newx = cx + dx[i];
            if (newy >= 1 and newy <= r and newx <= c and newx >=1 and rm[newy][newx] != '#') {
                if (vis[newy][newx]==false) {
                    queue.push_back(newx);
                    queue.push_back(newy);
                    vis[newy][newx] = true;
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
        for (int j = 1; j<= c; j++) {
            if (rm[i][j]!= '#' and vis[i][j]==false) {
                vis[i][j] = true;
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i<=5; i++) {
        cout << a[i] << endl;
    }
}