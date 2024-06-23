/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int x;
    cin >> x;
    int ans = 1, fans = 1;
    for(int i = 1; i < x; i++){
        if(__gcd(i, x) + i > ans) fans = i;
        ans = max(ans, __gcd(i, x) + i);
    }
    cout << fans << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
 