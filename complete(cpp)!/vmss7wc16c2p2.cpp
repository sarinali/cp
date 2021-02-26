#include <iostream>
#include <cstring>
using namespace std;
// NOTE: this one times out for some reason :( i think java works tho?
int psa[100002];
int gc;
int n;
string g;
int main(){
    cin >> g;
    for (int i = 0; i < g.length(); i++) {
        if (g[i] == 'G'){
            gc +=1;
        }
        psa[i] = gc;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        // if (y - x == 0) {
        //     if (psa[y] == 'G') {
        //         cout << 1 << endl;
        //     } else {
        //         cout << 0 << endl;
        //     }
        
            cout << psa[y] - psa[x-1] << endl;
        
    }
}