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

string s;
int d;
vector<vector<vector<int>>> dp(10005, vector<vector<int>>(2, vector<int>(100, -1)));
int fun(int i, int flag, int sum){
    if(i == s.size()) return sum == 0;
    if(dp[i][flag][sum] != -1) return dp[i][flag][sum];
    int ans = 0;
    for(int j = 0; j <= (flag ? s[i] - '0' : 9); j++){
        ans = ((ans % mod ) + (fun(i + 1, (flag && j == s[i] - '0'), (sum + j) % d) % mod)) % mod;
    }
    return dp[i][flag][sum] = ans % mod;
}

void solve(){
    cin >> s;
    cin >> d;
    cout << (fun(0, 1, 0) + mod - 1) % mod << endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    while (T--) solve();
    return 0;
}
 