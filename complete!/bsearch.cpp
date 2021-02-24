#include <iostream>
#include <cstdlib>
using namespace std;
int len;
int quer;
int x;
// int findmin(long int min[], int l, int e) {
//     int hi = len-1;
//     int lo = 0;
//     int mid = 0;
//     while (lo <= hi and mid != len-1) {
//         mid = (lo + hi)/2;
//         if (min[mid] >= l-e and min[mid-1]<l-e) {
//             return mid;
//         }
//         // cout<<mid<< endl;
//         if (l - min[mid] <= e) {
//             hi = mid-1;
//         } else {
//             lo = mid +1;
//         }
//     }
//     return mid;
// }
//int findmax(int l, int e) {
    // int hi = len;
    // int lo = 1;
    // int mid = 0;
    // while (lo <= hi) {
    //     mid = (lo + hi)/2;
    //     // if (mid == len or mid == 0) {
    //     //     return mid;
    //     // }
    //     // cout<<mid<< endl;
    //     // if (max[mid] - l <=e and max[mid-1] > l-e) {
    //     //     return mid;
    //     // }
    //     if (max[mid] - l <=e and l - min[mid] <= e) {
    //         hi = mid-1;
    //     } else {
    //         lo = mid +1;
    //     }
    // }
//     return lo;
// }
int main() {
    scanf("%d %d", &len, &quer);   
    int al[len];
    for (int i = 1; i <= len; i++) {
        scanf("%d", &x);
        al[i] = x;
    }
    long int max[len+1];
    long int small[len+1];
    int mn = al[len];
    int mx = al[len]; 
    max[len] = mx;
    small[len] =  mn;
    for (int i = len-1; i >0; --i) {
        int cur = al[i];
        if (cur > mx) {
            mx = cur;
        }
        if (cur < mn) {
            mn = cur;
        }
        max[i] = mx;
        small[i] = mn;
    }
    for (int i = 0; i < quer; i++) {
        long int l;
        long int e;
        scanf("%ld %ld", &l, &e);
        int hi = len;
        int lo = 1;
        int mid = 0;
        while (lo <= hi) {
            mid = (lo + hi)/2;
        // if (mid == len or mid == 0) {
        //     return mid;
        // }
        // cout<<mid<< endl;
        // if (max[mid] - l <=e and max[mid-1] > l-e) {
        //     return mid;
        // }
            if (max[mid] - l <=e and l - small[mid] <= e) {
                hi = mid-1;
            } else {
                lo = mid +1;
            }
        }
        cout << len-lo+1 << endl;
        // if(al[len-1] > l+e or al[len-1] < l-e){
        //     cout << 0 << endl;
        // } else {

        // }
    }
}