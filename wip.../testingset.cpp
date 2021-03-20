#include <iostream>
#include <set>
using namespace std;
int main() {
    set<int> g;
    for (int i = 0; i < 5; i++){
        g.insert(i);
    }
    auto first = g.begin();
    g.erase(1);
    cout << *first << endl;
    // for (it = g.begin(); it!= g.end(); it++) {
    //     cout << *it << endl;
    // }
}