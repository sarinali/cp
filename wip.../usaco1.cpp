#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
// i will do this some other day ;-;
using namespace std;
typedef pair<int, int> pi; 
int n;
unordered_map<string, vector<pi> > map;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        string ar[8];
        cin >> s;
        stringstream ssin(s);
        int j=0;
        while (ssin.good() && j < 8){
            ssin >> ar[i];
            ++i;
        }
        for (int g = 0; g < 8; g++) {
            cout << ar[i] << endl;
        }

    }
    return 0;
}