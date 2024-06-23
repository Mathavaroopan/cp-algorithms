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
#define mx(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
int n;
map<int, int> mp;
vector<int> dp;
int fun(int i){
    if(i < 0) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(fun(i - 1), fun(i - 2) + mp[i] * i);
}

void solve(){
    cin >> n;
    dp.assign(1e6, -1);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[a]++;
    }
    cout << fun(mp.rbegin()->first) << endl;
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
 