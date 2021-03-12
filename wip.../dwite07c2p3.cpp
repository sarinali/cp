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
    int cnt, ind;
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
            if (newy > r or newy < 0 or newx > c or newx < 0 or rm[newy][newx]!= '#') {
                continue;
            } else {
                if (!vis[newy][newx]) {
                    queue.push_back(newy);
                    queue.push_back(newx);
                }
                if (rm[newy][newx] != '.') {
                    ind = (int)rm[newy][newx];
                }
            }
        }
    }
    a[ind] = cnt;
    return;
}
int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j =0; i< c; j++) {
            cin >> rm[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j =0; i< c; j++) {
            if (rm[i][j]!= '#') {
                bfs(i, j);
            }
        }
    }
    for (int i = 1; i<=5; i++) {
        cout << a[i] << endl;
    }
}