/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

const int mod = 1e9 + 7;
vector<int> dp;
int fun(int sum, vector<int>& arr){
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(dp[sum] != -1) return dp[sum];
    int ans = 0;
    for(int i = 0; i < (int) arr.size(); i++){
        ans = (ans + fun(sum - arr[i], arr)) % mod;
    }
    return dp[sum] = ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int& a : arr) cin >> a;
    dp.resize(k + 1, -1);
    cout << fun(k, arr) << endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) solve();
    return 0;
}
 