#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int r, c, rmcount;
char rm[41][41];
// int a[6];
vector<int> a;
bool vis[41][41];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool comp (int i,int j) { 
    return (j<i); 
}
void bfs(int y, int x) {
    int cnt = 0; int ind = 0;
    list <int> queue;
    queue.push_back(x);
    queue.push_back(y);
    while (!queue.empty()) {
        int cx = queue.front();
        queue.pop_front();
        int cy = queue.front();
        queue.pop_front();
        cnt++;
        for (int i= 0; i < 4; i++) {
            int newy = cy +dy[i];
            int newx = cx + dx[i];
            if (newy >= 1 and newy <= r and newx <= c and newx >=1 and rm[newy][newx] != 'I') {
                if (!vis[newy][newx]) {
                    queue.push_back(newx);
                    queue.push_back(newy);
                    vis[newy][newx] = true;
                }
            }
        }
    }
    // cout << ind<< endl;
    a.push_back(cnt);
    return;
}
int main() {
    int x;
    cin >> x >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j =1; j<= c; j++) {
            cin >> rm[i][j];
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j =1; j<= c; j++) {
            if (rm[i][j]!= 'I' and !(vis[i][j])) {
                // rmcount++;
                vis[i][j] = true;
                bfs(i, j);
            }
        }
    }
    sort(a.begin(), a.end(), comp);
    int cnt = 0; int dif = 0;
    for (int i= 0; i < a.size(); i++) {
        x -= a.at(i);
        cnt++;
        if (x < 0) {
            x += a.at(i);
            cnt--;
            break;
        }
    }
    if (cnt == 1) {
        printf("1 room, %d square metre(s) left over", x);
    } else{
        printf("%d rooms, %d square metre(s) left over", cnt, x);
    }
}