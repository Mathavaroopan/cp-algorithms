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
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
int arr[3003];
int dp[3003][3003];

int fun(int l, int r){
    if(l > r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max(arr[l] - fun(l + 1, r), arr[r] - fun(l, r - 1));
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << fun(0, n - 1) << endl;    
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
 