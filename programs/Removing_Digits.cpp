/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

vector<int> dp;
int fun(int num){
    if(num == 0) return 0;
    if(num < 0) return 1e9;
    if(dp[num] != -1) return dp[num];
    int temp = num;
    int ans = 1e9;
    while(temp){
        int rem = temp % 10;
        if(rem != 0) ans = min(ans, 1 + fun(num - rem));
        temp /= 10;
    }
    return dp[num] = ans;
}
void solve(){
    int n;
    cin >> n;
    dp.resize(n + 1, -1);
    cout << fun(n) << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
 