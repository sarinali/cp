#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int dp[7005];
vector <int> motel;
int mn;
int mx;
int num;
int x;
int main() {
    scanf("%d", &mn);
    scanf("%d", &mx);
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &x);
        motel.push_back(x);
    }
    int h[14] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    for (int i = 0; i < 14; i++) {
        motel.push_back(h[i]);
    }
    sort(motel.begin(), motel.end());
    for (int i = mn; i <= mx; i++) {
        dp[i] = 1;
    }
    for (int i = 0; i < motel.size(); i++) {
        int curm = motel.at(i);
        if (curm == 7000) {
            break;
        }
        for (int j = curm+mn; j <= curm+mx; j++) {
            if (j > 7000) 
                break;
            dp[j] += dp[curm];  
        }
    }
    cout << dp[7000] << endl;
    return 0;
}