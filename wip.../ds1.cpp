#include <iostream>
using namespace std;
int n, m;
const int M = 10e5;
long long bit[M+1]; long long ar[M+1]; long long freq[M+1];
// need something to store the count? ill worry ab that later
long long sum(int start, int end) {
    long long sum, sumstart,sumend = 0;
    while (start>0) {
        sumstart += bit[start];
        start -= (start&-start);
    }
    while (end>0) {
        sumend += bit[end];
        end -= (end&-end);
    }
    sum = sumend - sumstart;
    return sum;
}
void change(long long ind, long long val) {
    while (ind <= M){
        bit[ind] += val;
        // the right most 1 
        ind += (ind&-ind);
    }
    return;
}
void freqc(long long ind){
    int val = ar[ind];
    while (val<=M) {
        freq[val]++;
        val = (val&-val);
    }
    return;
}
long long freqcount(long long ind){
    long long sum, sumstart,sumend = 0;
    while (ind>0) {
        sumstart += bit[ind];
        ind -= (ind&-ind);
    }
    long long newind = ind-1;
    while (newind>0) {
        sumend += bit[newind];
        newind -= (newind&-newind);
    }
    sum = sumend - sumstart;
    return sum;
}
int main(){
    cin >> n >> m;
    for (int i=0;i < n;++i) {
        cin >> ar[i];
    }
    for (int i=0;i<n;++i) {
        int ind = i+1;
        // construct it from bottom up ish? 
        while (ind<=n){ 
            bit[ind] += ar[i];
            ind += (ind&-ind);
        }
    }
    for (int i=0;i<m;++i){
        char cur; long long x, y;
        cin >> cur >> x;
        if (cur == 'S') {
            cin >> y;
            cout << sum(x-1, y) << endl;
        } else if (cur == 'C') {
            cin >> y;
            change(x, y);
            // freqc(x);
        } else {
            // cout << freqcount(x) << endl;
        }
    }
    return 0;
}