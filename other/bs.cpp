#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ar[] = {0, 1, 5, 6, 20, 69, 90,310};
    int ar1[] = {0, 1, 5, 6, 20, 69, 90};
    int lo = 1; int hi = 6; int mid;
    int q; int ans; 
    cin >> q;
    while (lo < hi)
    {
        mid = (hi + lo);
        if (mid % 2 == 1) 
            mid++; 
        mid /=2;
        cout << mid << endl;
        // um if time taken is less than what u gotta be under
        if (ar[mid] < q)
        {
            // ans = mid;
            lo = mid;
        }
        else
        {
            hi = mid-1;
        }
    }
    cout << lo << endl;
    return 0;
}