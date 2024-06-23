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
#define max(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
vector<vector<int>> dp(1000000, vector<int>(2, 1));

void pre(){
    for(int i = 1; i < 1e6; i++){
        dp[i][0] = ((2 * dp[i - 1][0]) % mod + dp[i - 1][1]) % mod;
        dp[i][1] = ((4 * dp[i - 1][1]) % mod + dp[i - 1][0]) % mod;
    }
}

void solve(){
    int n; cin >> n;
    cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    pre();
    while (T--) solve();
    return 0;
}
 