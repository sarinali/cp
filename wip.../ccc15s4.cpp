#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct t { 
    int to, time, cm; 
}; 
struct tc {
    bool operator()(t const& lhs, t const& rhs) const {
    return lhs.time < rhs.time;
    }
};
int main() {
    
    return 0;
}