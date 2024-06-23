#include "bits/stdc++.h"
#define int long long
using namespace std;

int fun(int n, int prev, vector<vector<int>>& arr, vector<vector<int>>& dp){
    if(n < 0) return 0;
    if(prev != -1 && dp[n][prev] != -1) return dp[n][prev];
    int ans = -1e9;
    for(int i = 0; i < 3; i++){
        if(prev != i) ans = max(ans, arr[n][i] + fun(n - 1, i, arr, dp));
    }
    if(prev != -1) dp[n][prev] = ans;
    return ans;
}
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3)), dp(n, vector<int>(3, -1));
    for(int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    
    for(int i = 0; i < n; i++){
        
    }
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

    