#include <iostream>
#include <list>
using namespace std;
int r, c;
char rm[41][41];
int a[6];
int vis[41][41];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int y, int x) {
    int cnt = 0; int ind = 0;
    list<int> queue;
    queue.push_back(y);
    queue.push_back(x);
    while (!queue.empty()) {
        int cy = queue.front();
        queue.pop_front();
        int cx = queue.front();
        queue.pop_front();
        vis[cy][cx] = true;
        cnt++;
        for (int i= 0; i < 4; i++) {
            int newy = cy +dy[i];
            int newx = cx+dx[i];
            if (newy >= 1 and newy <= r and newx <= c and newx >=1 and rm[newy][newx] != '#') {
                if (!vis[newy][newx]) {
                    queue.push_back(newy);
                    queue.push_back(newx);
                    if (rm[newy][newx] != '.') {
                        ind = ((int)rm[newy][newx]) - '0';
                    }
                }
            }
        }
    }
    // cout << ind;
    a[ind] = cnt-1;
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
                bfs(i, j);
            }
        }
    }
    for (int i = 1; i<=5; i++) {
        cout << a[i] << endl;
    }
}