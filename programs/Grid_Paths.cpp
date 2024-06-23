/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

const int mod = 1e9 + 7;

int fun(int row, int col, vector<string>& arr, vector<vector<int>>& dp){
    if(row < 0 || col < 0 || arr[row][col] == '*') return 0;
    if(row == 0 && col == 0) return 1;
    if(dp[row][col] != -1) return dp[row][col];
    return dp[row][col] = (fun(row - 1, col, arr, dp) + fun(row, col - 1, arr, dp)) % mod;
}

void solve(){
    int n;
    cin >> n;
    vector<string> arr(n);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(string& s : arr) cin >> s;
    cout << fun(n - 1, n - 1, arr, dp) << endl;
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
 