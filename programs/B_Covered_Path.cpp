/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define double long double
#define srt(arr) sort(arr.begin(), arr.end())
#define srtrev(arr) sort(arr.begin(), arr.end(), greater<int>())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define all(arr) arr.begin(), arr.end()
#define input(arr) for(int& a : arr) cin >> a
#define print(arr) for(int i : arr) cout << i << " "
#define var(a) cout << #a << " = " << a << endl
#define min(arr) *min_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
int v1, v2, t, d;
int fun(int v1, int x, map<pair<int, int>, int>& dp){
    if(x == 1) return (v1 == v2) ? v1 : -1e9;
    if(dp.find({v1, x}) != dp.end()) return dp[{v1, x}];
    int ans = -1e9;
    for(int i = v1 - d; i <= v1 + d; i++) ans = max(ans, v1 + fun(i, x - 1, dp)); 
    return dp[{v1, x}] = ans;
}

void solve(){
    cin >> v1 >> v2 >> t >> d;
    map<pair<int, int>, int> dp;
    cout << fun(v1, t, dp) << endl;  
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
 