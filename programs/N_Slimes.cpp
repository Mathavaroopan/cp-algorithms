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
#define max(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
vector<int> arr(402, 0);
vector<int> prefix(402, 0);
int dp[402][402];

int fun(int l, int r){
    if(l == r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = 1e18;
    for(int k = l + 1; k <= r; k++){
        ans = min(ans, prefix[r + 1] - prefix[l] + fun(l, k - 1) + fun(k, r));
    }
    return dp[l][r] = ans;
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        prefix[i + 1] = arr[i] + prefix[i];
    }
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
 