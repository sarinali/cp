#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
typedef pair<int, int> pi; 
const int M = 1e5;
int n;
int bit[M+1];
int in[M+1];
int ar[M+1];
double total;
set <int, greater <int> > s;
// set <int> s;
unordered_map <int, int> map;
void change(int ind) {
    while (ind <= n) {
        bit[ind] += ar[ind];
        ind+=ind&-ind;
    }
}
int sum(int end) {
    int sum = 0; 
    while (end > 0) {
        sum += bit[end];
        end -= end&-end;
    }
    return sum;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        // printf("In val: %d, in time: %d\n", in[i], i);
        s.insert(in[i]);
    }
    set<int>::iterator it;
    int i = 1;
    for (it = s.begin(); it != s.end(); it++){
        map[*it] = i;
        // printf("Key: %d, order: %d\n", *it,i);
        i++;
    }
    // cout << map.size();
    for (int i = 1; i <= n; i++) {
        int x = map[in[i]];
        ar[x] = 1;
        change(x);
        // cout << sum(x-1)+1 << " ";
        total += (double)sum(x-1)+1;
    }
    printf("%.2f\n", total/n);
    return 0;
}
