#include <iostream>
using namespace std;
int n;
int len, score;
int main (){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> len >> score;
        char ar[200000] = {};
        for (int j = 0; j < len; j++) {
            cin >> ar[j];
        }
        int gscore = 0; int bscore = 0;
        for (int j = 0; j < len/2; j++) {
            if (ar[j] != ar[(len-1)-j]) {
                gscore++;
            } 
        }
        int req = 0;
        if (gscore == score) {
            req = 0;
        } else if (gscore > score) {
            req = gscore - score;
        } else {
            req = score - gscore;
        }
        cout << "Case #" << i+1 << ": " << req << endl;
        // cout << "Case #" << i << ":" << req-bscore << endl;
    }
}